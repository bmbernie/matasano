/* _unexpected_ — entry 0x45c0.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn__unexpected_(MCState *m) {
    switch(m->r[0]) {
    case 0x45c0: goto L_45c0;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_45c0: { /* 0x45c0: 0013  reti  */
        if(!m->budget) return mc_fault(m,0x45c0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45c2;
        if(m->mem[0x45c0]!=0 || m->mem[0x45c1]!=19) return mc_fault(m,0x45c0,"code changed; redisassembly required");
        m->r[2]=mc_pop(m);
        return mc_exit(m,mc_pop(m));
    }
}
