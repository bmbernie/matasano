/* create_password — entry 0x447e.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_create_password(MCState *m) {
    switch(m->r[0]) {
    case 0x447e: goto L_447e;
    case 0x4482: goto L_4482;
    case 0x4488: goto L_4488;
    case 0x448e: goto L_448e;
    case 0x4494: goto L_4494;
    case 0x449a: goto L_449a;
    case 0x44a0: goto L_44a0;
    case 0x44a6: goto L_44a6;
    case 0x44ac: goto L_44ac;
    case 0x44b0: goto L_44b0;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_447e: { /* 0x447e: 3f400024  mov #0x2400, r15 */
        if(!m->budget) return mc_fault(m,0x447e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4482;
        if(m->mem[0x447e]!=63 || m->mem[0x447f]!=64 || m->mem[0x4480]!=0 || m->mem[0x4481]!=36) return mc_fault(m,0x447e,"code changed; redisassembly required");
        uint16_t src=0x2400;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4482;
    }
L_4482: { /* 0x4482: ff4065000000  mov.b #0x0065, 0x0000(r15) */
        if(!m->budget) return mc_fault(m,0x4482,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4488;
        if(m->mem[0x4482]!=255 || m->mem[0x4483]!=64 || m->mem[0x4484]!=101 || m->mem[0x4485]!=0 || m->mem[0x4486]!=0 || m->mem[0x4487]!=0) return mc_fault(m,0x4482,"code changed; redisassembly required");
        uint16_t src=0x0065;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0000);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_4488;
    }
L_4488: { /* 0x4488: ff4045000100  mov.b #0x0045, 0x0001(r15) */
        if(!m->budget) return mc_fault(m,0x4488,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x448e;
        if(m->mem[0x4488]!=255 || m->mem[0x4489]!=64 || m->mem[0x448a]!=69 || m->mem[0x448b]!=0 || m->mem[0x448c]!=1 || m->mem[0x448d]!=0) return mc_fault(m,0x4488,"code changed; redisassembly required");
        uint16_t src=0x0045;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0001);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_448e;
    }
L_448e: { /* 0x448e: ff4047000200  mov.b #0x0047, 0x0002(r15) */
        if(!m->budget) return mc_fault(m,0x448e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4494;
        if(m->mem[0x448e]!=255 || m->mem[0x448f]!=64 || m->mem[0x4490]!=71 || m->mem[0x4491]!=0 || m->mem[0x4492]!=2 || m->mem[0x4493]!=0) return mc_fault(m,0x448e,"code changed; redisassembly required");
        uint16_t src=0x0047;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0002);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_4494;
    }
L_4494: { /* 0x4494: ff404a000300  mov.b #0x004a, 0x0003(r15) */
        if(!m->budget) return mc_fault(m,0x4494,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x449a;
        if(m->mem[0x4494]!=255 || m->mem[0x4495]!=64 || m->mem[0x4496]!=74 || m->mem[0x4497]!=0 || m->mem[0x4498]!=3 || m->mem[0x4499]!=0) return mc_fault(m,0x4494,"code changed; redisassembly required");
        uint16_t src=0x004a;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0003);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_449a;
    }
L_449a: { /* 0x449a: ff4021000400  mov.b #0x0021, 0x0004(r15) */
        if(!m->budget) return mc_fault(m,0x449a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44a0;
        if(m->mem[0x449a]!=255 || m->mem[0x449b]!=64 || m->mem[0x449c]!=33 || m->mem[0x449d]!=0 || m->mem[0x449e]!=4 || m->mem[0x449f]!=0) return mc_fault(m,0x449a,"code changed; redisassembly required");
        uint16_t src=0x0021;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0004);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_44a0;
    }
L_44a0: { /* 0x44a0: ff4026000500  mov.b #0x0026, 0x0005(r15) */
        if(!m->budget) return mc_fault(m,0x44a0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44a6;
        if(m->mem[0x44a0]!=255 || m->mem[0x44a1]!=64 || m->mem[0x44a2]!=38 || m->mem[0x44a3]!=0 || m->mem[0x44a4]!=5 || m->mem[0x44a5]!=0) return mc_fault(m,0x44a0,"code changed; redisassembly required");
        uint16_t src=0x0026;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0005);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_44a6;
    }
L_44a6: { /* 0x44a6: ff4025000600  mov.b #0x0025, 0x0006(r15) */
        if(!m->budget) return mc_fault(m,0x44a6,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44ac;
        if(m->mem[0x44a6]!=255 || m->mem[0x44a7]!=64 || m->mem[0x44a8]!=37 || m->mem[0x44a9]!=0 || m->mem[0x44aa]!=6 || m->mem[0x44ab]!=0) return mc_fault(m,0x44a6,"code changed; redisassembly required");
        uint16_t src=0x0025;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0006);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_44ac;
    }
L_44ac: { /* 0x44ac: cf430700  mov.b #0x0000, 0x0007(r15) */
        if(!m->budget) return mc_fault(m,0x44ac,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44b0;
        if(m->mem[0x44ac]!=207 || m->mem[0x44ad]!=67 || m->mem[0x44ae]!=7 || m->mem[0x44af]!=0) return mc_fault(m,0x44ac,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x0007);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_44b0;
    }
L_44b0: { /* 0x44b0: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x44b0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44b2;
        if(m->mem[0x44b0]!=48 || m->mem[0x44b1]!=65) return mc_fault(m,0x44b0,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x44b2;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
