/* __stop_progExec__ — entry 0x4474.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___stop_progExec__(MCState *m) {
    switch(m->r[0]) {
    case 0x4474: goto L_4474;
    case 0x4478: goto L_4478;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4474: { /* 0x4474: 32d0f000  bis #0x00f0, sr */
        if(!m->budget) return mc_fault(m,0x4474,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4478;
        if(m->mem[0x4474]!=50 || m->mem[0x4475]!=208 || m->mem[0x4476]!=240 || m->mem[0x4477]!=0) return mc_fault(m,0x4474,"code changed; redisassembly required");
        uint16_t src=0x00f0;
        uint16_t dst=m->r[2];
        m->r[2]=(uint16_t)(dst|src);
        if(m->r[2]&0x10) return mc_fault(m,0x4478,"CPUOFF set");
        goto L_4478;
    }
L_4478: { /* 0x4478: fd3f  jmp 0x4474 */
        if(!m->budget) return mc_fault(m,0x4478,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x447a;
        if(m->mem[0x4478]!=253 || m->mem[0x4479]!=63) return mc_fault(m,0x4478,"code changed; redisassembly required");
        goto L_4474;
    }
}
