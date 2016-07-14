/* unlock_door — entry 0x44d6.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_unlock_door(MCState *m) {
    switch(m->r[0]) {
    case 0x44d6: goto L_44d6;
    case 0x44da: goto L_44da;
    case 0x44de: goto L_44de;
    case 0x44e0: goto L_44e0;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_44d6: { /* 0x44d6: 30127f00  push #0x007f */
        if(!m->budget) return mc_fault(m,0x44d6,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44da;
        if(m->mem[0x44d6]!=48 || m->mem[0x44d7]!=18 || m->mem[0x44d8]!=127 || m->mem[0x44d9]!=0) return mc_fault(m,0x44d6,"code changed; redisassembly required");
        uint16_t src=0x007f;
        mc_push(m,src);
        goto L_44da;
    }
L_44da: { /* 0x44da: b0123045  call #0x4530 */
        if(!m->budget) return mc_fault(m,0x44da,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44de;
        if(m->mem[0x44da]!=176 || m->mem[0x44db]!=18 || m->mem[0x44dc]!=48 || m->mem[0x44dd]!=69) return mc_fault(m,0x44da,"code changed; redisassembly required");
        uint16_t src=0x4530;
        mc_push(m,0x44de);
        return mc_exit(m,src);
    }
L_44de: { /* 0x44de: 2153  add #0x0002, sp */
        if(!m->budget) return mc_fault(m,0x44de,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44e0;
        if(m->mem[0x44de]!=33 || m->mem[0x44df]!=83) return mc_fault(m,0x44de,"code changed; redisassembly required");
        uint16_t src=0x0002;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_44e0;
    }
L_44e0: { /* 0x44e0: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x44e0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44e2;
        if(m->mem[0x44e0]!=48 || m->mem[0x44e1]!=65) return mc_fault(m,0x44e0,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x44e2;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
