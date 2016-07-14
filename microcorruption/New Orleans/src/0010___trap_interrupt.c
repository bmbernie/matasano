/* __trap_interrupt — entry 0x0010.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___trap_interrupt(MCState *m) {
    switch(m->r[0]) {
    case 0x0010: goto L_0010;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_0010: { /* 0x0010: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x0010,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x0012;
        if(m->mem[0x0010]!=48 || m->mem[0x0011]!=65) return mc_fault(m,0x0010,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x0012;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
