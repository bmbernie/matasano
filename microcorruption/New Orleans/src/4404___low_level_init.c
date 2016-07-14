/* __low_level_init — entry 0x4404.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___low_level_init(MCState *m) {
    switch(m->r[0]) {
    case 0x4404: goto L_4404;
    case 0x4408: goto L_4408;
    case 0x440a: goto L_440a;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4404: { /* 0x4404: 15425c01  mov &0x015c, r5 */
        if(!m->budget) return mc_fault(m,0x4404,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4408;
        if(m->mem[0x4404]!=21 || m->mem[0x4405]!=66 || m->mem[0x4406]!=92 || m->mem[0x4407]!=1) return mc_fault(m,0x4404,"code changed; redisassembly required");
        uint16_t src_addr=0x015c;
        uint16_t src=rd16(m,src_addr);
        uint16_t dst=m->r[5];
        m->r[5]=(uint16_t)(src);
        goto L_4408;
    }
L_4408: { /* 0x4408: 75f3  and.b #0xffff, r5 */
        if(!m->budget) return mc_fault(m,0x4408,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x440a;
        if(m->mem[0x4408]!=117 || m->mem[0x4409]!=243) return mc_fault(m,0x4408,"code changed; redisassembly required");
        uint16_t src=0xffff;
        uint16_t dst=(m->r[5]&0xff);
        m->r[5]=(uint8_t)(mc_logic(m,dst&src,8,0));
        goto L_440a;
    }
L_440a: { /* 0x440a: 35d0085a  bis #0x5a08, r5 */
        if(!m->budget) return mc_fault(m,0x440a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x440e;
        if(m->mem[0x440a]!=53 || m->mem[0x440b]!=208 || m->mem[0x440c]!=8 || m->mem[0x440d]!=90) return mc_fault(m,0x440a,"code changed; redisassembly required");
        uint16_t src=0x5a08;
        uint16_t dst=m->r[5];
        m->r[5]=(uint16_t)(dst|src);
        return mc_exit(m,0x440e);
    }
}
