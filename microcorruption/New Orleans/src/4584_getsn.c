/* getsn — entry 0x4584.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_getsn(MCState *m) {
    switch(m->r[0]) {
    case 0x4584: goto L_4584;
    case 0x4586: goto L_4586;
    case 0x4588: goto L_4588;
    case 0x458a: goto L_458a;
    case 0x458e: goto L_458e;
    case 0x4592: goto L_4592;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4584: { /* 0x4584: 0e12  push r14 */
        if(!m->budget) return mc_fault(m,0x4584,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4586;
        if(m->mem[0x4584]!=14 || m->mem[0x4585]!=18) return mc_fault(m,0x4584,"code changed; redisassembly required");
        uint16_t src=m->r[14];
        mc_push(m,src);
        goto L_4586;
    }
L_4586: { /* 0x4586: 0f12  push r15 */
        if(!m->budget) return mc_fault(m,0x4586,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4588;
        if(m->mem[0x4586]!=15 || m->mem[0x4587]!=18) return mc_fault(m,0x4586,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        mc_push(m,src);
        goto L_4588;
    }
L_4588: { /* 0x4588: 2312  push #0x0002 */
        if(!m->budget) return mc_fault(m,0x4588,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x458a;
        if(m->mem[0x4588]!=35 || m->mem[0x4589]!=18) return mc_fault(m,0x4588,"code changed; redisassembly required");
        uint16_t src=0x0002;
        mc_push(m,src);
        goto L_458a;
    }
L_458a: { /* 0x458a: b0123045  call #0x4530 */
        if(!m->budget) return mc_fault(m,0x458a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x458e;
        if(m->mem[0x458a]!=176 || m->mem[0x458b]!=18 || m->mem[0x458c]!=48 || m->mem[0x458d]!=69) return mc_fault(m,0x458a,"code changed; redisassembly required");
        uint16_t src=0x4530;
        mc_push(m,0x458e);
        return mc_exit(m,src);
    }
L_458e: { /* 0x458e: 31500600  add #0x0006, sp */
        if(!m->budget) return mc_fault(m,0x458e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4592;
        if(m->mem[0x458e]!=49 || m->mem[0x458f]!=80 || m->mem[0x4590]!=6 || m->mem[0x4591]!=0) return mc_fault(m,0x458e,"code changed; redisassembly required");
        uint16_t src=0x0006;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_4592;
    }
L_4592: { /* 0x4592: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x4592,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4594;
        if(m->mem[0x4592]!=48 || m->mem[0x4593]!=65) return mc_fault(m,0x4592,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x4594;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
