/* __ctors_end — entry 0x447a.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___ctors_end(MCState *m) {
    switch(m->r[0]) {
    case 0x447a: goto L_447a;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_447a: { /* 0x447a: 3040c045  mov #0x45c0, pc */
        if(!m->budget) return mc_fault(m,0x447a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x447e;
        if(m->mem[0x447a]!=48 || m->mem[0x447b]!=64 || m->mem[0x447c]!=192 || m->mem[0x447d]!=69) return mc_fault(m,0x447a,"code changed; redisassembly required");
        uint16_t src=0x45c0;
        uint16_t dst=0x447c;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
