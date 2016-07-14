/* Inferred low-level C. 16-bit MSP430 state; not recovered original C.
 * No host pointers into guest memory. Each function runs until a control-flow
 * transfer outside its recovered blocks. dispatch.c resumes the target.
 * Service behavior at 0x0010 and runtime-generated code are external boundaries.
 * See README.md for limitations and the original assembly for the authority. */
#ifndef MC_RECONSTRUCTED_H
#define MC_RECONSTRUCTED_H
#include <stdint.h>
#include <stddef.h>
enum { MC_C=1, MC_Z=2, MC_N=4, MC_V=256 };
typedef struct MCState MCState;
struct MCState {
    uint16_t r[16];
    uint8_t mem[65536];
    uint64_t budget;
    int halted;
    const char *reason;
    void (*service)(MCState *); /* simulator interrupt hook, including HSM */
};
static inline uint16_t rd16(MCState *m,uint16_t a){return (uint16_t)(m->mem[a]|((uint16_t)m->mem[(uint16_t)(a+1)]<<8));}
static inline uint16_t rd8(MCState *m,uint16_t a){return m->mem[a];}
static inline void wr16(MCState *m,uint16_t a,uint16_t v){m->mem[a]=(uint8_t)v;m->mem[(uint16_t)(a+1)]=(uint8_t)(v>>8);}
static inline void wr8(MCState *m,uint16_t a,uint16_t v){m->mem[a]=(uint8_t)v;}
static inline void mc_push(MCState *m,uint16_t v){m->r[1]-=2;wr16(m,m->r[1],v);}
static inline uint16_t mc_pop(MCState *m){uint16_t v=rd16(m,m->r[1]);m->r[1]+=2;return v;}
static inline uint16_t mc_exit(MCState *m,uint16_t pc){m->r[0]=pc;return pc;}
static inline uint16_t mc_fault(MCState *m,uint16_t pc,const char *why){m->halted=1;m->reason=why;return mc_exit(m,pc);}
static inline void mc_flags(MCState *m,uint16_t x,unsigned bits,unsigned c,unsigned v){
    unsigned mask=bits==8?255:65535,sign=1u<<(bits-1);x&=mask;
    m->r[2]=(uint16_t)((m->r[2]&~(MC_C|MC_Z|MC_N|MC_V))|(c?MC_C:0)|(x?0:MC_Z)|((x&sign)?MC_N:0)|(v?MC_V:0));
}
static inline uint16_t mc_add(MCState *m,uint16_t a,uint16_t b,unsigned c,unsigned bits){
    uint32_t mask=bits==8?255:65535, sign=1u<<(bits-1);a&=mask;b&=mask;
    uint32_t wide=(uint32_t)a+b+c;uint16_t x=wide&mask;
    mc_flags(m,x,bits,wide>mask,((~(a^b)&(a^x))&sign)!=0);return x;
}
static inline uint16_t mc_sub(MCState *m,uint16_t a,uint16_t b,unsigned c,unsigned bits){
    uint32_t mask=bits==8?255:65535,sign=1u<<(bits-1);a&=mask;b&=mask;
    uint32_t wide=(uint32_t)a+(b^mask)+c;uint16_t x=wide&mask;
    mc_flags(m,x,bits,wide>mask,(((a^b)&(a^x))&sign)!=0);return x;
}
static inline uint16_t mc_logic(MCState *m,uint16_t x,unsigned bits,unsigned v){mc_flags(m,x,bits,(x&(bits==8?255:65535))!=0,v);return x;}
static inline uint16_t mc_dadd(MCState *m,uint16_t a,uint16_t b,unsigned bits){
    unsigned c=(m->r[2]&MC_C)!=0,x=0;
    for(unsigned i=0;i<bits;i+=4){unsigned n=((a>>i)&15)+((b>>i)&15)+c;if(n>9)n+=6;c=n>15;x|=(n&15)<<i;}
    /* V is architecturally undefined for DADD; preserve it, do not infer a branch. */
    mc_flags(m,(uint16_t)x,bits,c,(m->r[2]&MC_V)!=0);return (uint16_t)x;
}
uint16_t mc_dispatch(MCState *m);
#endif
