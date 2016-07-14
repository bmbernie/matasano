/* get_password — entry 0x44b2.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_get_password(MCState *m) {
    switch(m->r[0]) {
    case 0x44b2: goto L_44b2;
    case 0x44b6: goto L_44b6;
    case 0x44ba: goto L_44ba;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_44b2: { /* 0x44b2: 3e406400  mov #0x0064, r14 */
        if(!m->budget) return mc_fault(m,0x44b2,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44b6;
        if(m->mem[0x44b2]!=62 || m->mem[0x44b3]!=64 || m->mem[0x44b4]!=100 || m->mem[0x44b5]!=0) return mc_fault(m,0x44b2,"code changed; redisassembly required");
        uint16_t src=0x0064;
        uint16_t dst=m->r[14];
        m->r[14]=(uint16_t)(src);
        goto L_44b6;
    }
L_44b6: { /* 0x44b6: b0128445  call #0x4584 */
        if(!m->budget) return mc_fault(m,0x44b6,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44ba;
        if(m->mem[0x44b6]!=176 || m->mem[0x44b7]!=18 || m->mem[0x44b8]!=132 || m->mem[0x44b9]!=69) return mc_fault(m,0x44b6,"code changed; redisassembly required");
        uint16_t src=0x4584;
        mc_push(m,0x44ba);
        return mc_exit(m,src);
    }
L_44ba: { /* 0x44ba: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x44ba,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44bc;
        if(m->mem[0x44ba]!=48 || m->mem[0x44bb]!=65) return mc_fault(m,0x44ba,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x44bc;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
