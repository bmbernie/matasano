/* __init_stack — entry 0x4400.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___init_stack(MCState *m) {
    switch(m->r[0]) {
    case 0x4400: goto L_4400;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4400: { /* 0x4400: 31400044  mov #0x4400, sp */
        if(!m->budget) return mc_fault(m,0x4400,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4404;
        if(m->mem[0x4400]!=49 || m->mem[0x4401]!=64 || m->mem[0x4402]!=0 || m->mem[0x4403]!=68) return mc_fault(m,0x4400,"code changed; redisassembly required");
        uint16_t src=0x4400;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(src);
        return mc_exit(m,0x4404);
    }
}
