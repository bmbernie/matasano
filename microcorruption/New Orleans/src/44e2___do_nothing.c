/* __do_nothing — entry 0x44e2.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___do_nothing(MCState *m) {
    switch(m->r[0]) {
    case 0x44e2: goto L_44e2;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_44e2: { /* 0x44e2: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x44e2,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44e4;
        if(m->mem[0x44e2]!=48 || m->mem[0x44e3]!=65) return mc_fault(m,0x44e2,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x44e4;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
