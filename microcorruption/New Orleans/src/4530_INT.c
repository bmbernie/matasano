/* INT — entry 0x4530.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_INT(MCState *m) {
    switch(m->r[0]) {
    case 0x4530: goto L_4530;
    case 0x4534: goto L_4534;
    case 0x4536: goto L_4536;
    case 0x4538: goto L_4538;
    case 0x453a: goto L_453a;
    case 0x453c: goto L_453c;
    case 0x4540: goto L_4540;
    case 0x4544: goto L_4544;
    case 0x4546: goto L_4546;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4530: { /* 0x4530: 1e410200  mov 0x0002(r1), r14 */
        if(!m->budget) return mc_fault(m,0x4530,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4534;
        if(m->mem[0x4530]!=30 || m->mem[0x4531]!=65 || m->mem[0x4532]!=2 || m->mem[0x4533]!=0) return mc_fault(m,0x4530,"code changed; redisassembly required");
        uint16_t src_addr=(uint16_t)(m->r[1]+0x0002);
        uint16_t src=rd16(m,src_addr);
        uint16_t dst=m->r[14];
        m->r[14]=(uint16_t)(src);
        goto L_4534;
    }
L_4534: { /* 0x4534: 0212  push sr */
        if(!m->budget) return mc_fault(m,0x4534,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4536;
        if(m->mem[0x4534]!=2 || m->mem[0x4535]!=18) return mc_fault(m,0x4534,"code changed; redisassembly required");
        uint16_t src=m->r[2];
        mc_push(m,src);
        goto L_4536;
    }
L_4536: { /* 0x4536: 0f4e  mov r14, r15 */
        if(!m->budget) return mc_fault(m,0x4536,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4538;
        if(m->mem[0x4536]!=15 || m->mem[0x4537]!=78) return mc_fault(m,0x4536,"code changed; redisassembly required");
        uint16_t src=m->r[14];
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4538;
    }
L_4538: { /* 0x4538: 8f10  swpb r15 */
        if(!m->budget) return mc_fault(m,0x4538,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x453a;
        if(m->mem[0x4538]!=143 || m->mem[0x4539]!=16) return mc_fault(m,0x4538,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        m->r[15]=(uint16_t)((uint16_t)((src<<8)|(src>>8)));
        goto L_453a;
    }
L_453a: { /* 0x453a: 024f  mov r15, sr */
        if(!m->budget) return mc_fault(m,0x453a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x453c;
        if(m->mem[0x453a]!=2 || m->mem[0x453b]!=79) return mc_fault(m,0x453a,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        uint16_t dst=m->r[2];
        m->r[2]=(uint16_t)(src);
        if(m->r[2]&0x10) return mc_fault(m,0x453c,"CPUOFF set");
        goto L_453c;
    }
L_453c: { /* 0x453c: 32d00080  bis #0x8000, sr */
        if(!m->budget) return mc_fault(m,0x453c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4540;
        if(m->mem[0x453c]!=50 || m->mem[0x453d]!=208 || m->mem[0x453e]!=0 || m->mem[0x453f]!=128) return mc_fault(m,0x453c,"code changed; redisassembly required");
        uint16_t src=0x8000;
        uint16_t dst=m->r[2];
        m->r[2]=(uint16_t)(dst|src);
        if(m->r[2]&0x10) return mc_fault(m,0x4540,"CPUOFF set");
        goto L_4540;
    }
L_4540: { /* 0x4540: b0121000  call #0x0010 */
        if(!m->budget) return mc_fault(m,0x4540,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4544;
        if(m->mem[0x4540]!=176 || m->mem[0x4541]!=18 || m->mem[0x4542]!=16 || m->mem[0x4543]!=0) return mc_fault(m,0x4540,"code changed; redisassembly required");
        uint16_t src=0x0010;
        mc_push(m,0x4544);
        return mc_exit(m,src);
    }
L_4544: { /* 0x4544: 3241  mov @r1+, sr */
        if(!m->budget) return mc_fault(m,0x4544,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4546;
        if(m->mem[0x4544]!=50 || m->mem[0x4545]!=65) return mc_fault(m,0x4544,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=m->r[2];
        m->r[2]=(uint16_t)(src);
        if(m->r[2]&0x10) return mc_fault(m,0x4546,"CPUOFF set");
        goto L_4546;
    }
L_4546: { /* 0x4546: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x4546,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4548;
        if(m->mem[0x4546]!=48 || m->mem[0x4547]!=65) return mc_fault(m,0x4546,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x4548;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
