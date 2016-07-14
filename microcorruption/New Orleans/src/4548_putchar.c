/* putchar — entry 0x4548.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_putchar(MCState *m) {
    switch(m->r[0]) {
    case 0x4548: goto L_4548;
    case 0x454a: goto L_454a;
    case 0x454c: goto L_454c;
    case 0x454e: goto L_454e;
    case 0x4552: goto L_4552;
    case 0x4556: goto L_4556;
    case 0x455a: goto L_455a;
    case 0x455e: goto L_455e;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4548: { /* 0x4548: 2183  sub #0x0002, sp */
        if(!m->budget) return mc_fault(m,0x4548,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x454a;
        if(m->mem[0x4548]!=33 || m->mem[0x4549]!=131) return mc_fault(m,0x4548,"code changed; redisassembly required");
        uint16_t src=0x0002;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_sub(m,dst,src,1,16));
        goto L_454a;
    }
L_454a: { /* 0x454a: 0f12  push r15 */
        if(!m->budget) return mc_fault(m,0x454a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x454c;
        if(m->mem[0x454a]!=15 || m->mem[0x454b]!=18) return mc_fault(m,0x454a,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        mc_push(m,src);
        goto L_454c;
    }
L_454c: { /* 0x454c: 0312  push #0x0000 */
        if(!m->budget) return mc_fault(m,0x454c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x454e;
        if(m->mem[0x454c]!=3 || m->mem[0x454d]!=18) return mc_fault(m,0x454c,"code changed; redisassembly required");
        uint16_t src=0x0000;
        mc_push(m,src);
        goto L_454e;
    }
L_454e: { /* 0x454e: 814f0400  mov r15, 0x0004(r1) */
        if(!m->budget) return mc_fault(m,0x454e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4552;
        if(m->mem[0x454e]!=129 || m->mem[0x454f]!=79 || m->mem[0x4550]!=4 || m->mem[0x4551]!=0) return mc_fault(m,0x454e,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        uint16_t dst_addr=(uint16_t)(m->r[1]+0x0004);
        uint16_t dst=rd16(m,dst_addr);
        wr16(m,dst_addr,src);
        goto L_4552;
    }
L_4552: { /* 0x4552: b0123045  call #0x4530 */
        if(!m->budget) return mc_fault(m,0x4552,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4556;
        if(m->mem[0x4552]!=176 || m->mem[0x4553]!=18 || m->mem[0x4554]!=48 || m->mem[0x4555]!=69) return mc_fault(m,0x4552,"code changed; redisassembly required");
        uint16_t src=0x4530;
        mc_push(m,0x4556);
        return mc_exit(m,src);
    }
L_4556: { /* 0x4556: 1f410400  mov 0x0004(r1), r15 */
        if(!m->budget) return mc_fault(m,0x4556,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x455a;
        if(m->mem[0x4556]!=31 || m->mem[0x4557]!=65 || m->mem[0x4558]!=4 || m->mem[0x4559]!=0) return mc_fault(m,0x4556,"code changed; redisassembly required");
        uint16_t src_addr=(uint16_t)(m->r[1]+0x0004);
        uint16_t src=rd16(m,src_addr);
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_455a;
    }
L_455a: { /* 0x455a: 31500600  add #0x0006, sp */
        if(!m->budget) return mc_fault(m,0x455a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x455e;
        if(m->mem[0x455a]!=49 || m->mem[0x455b]!=80 || m->mem[0x455c]!=6 || m->mem[0x455d]!=0) return mc_fault(m,0x455a,"code changed; redisassembly required");
        uint16_t src=0x0006;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_455e;
    }
L_455e: { /* 0x455e: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x455e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4560;
        if(m->mem[0x455e]!=48 || m->mem[0x455f]!=65) return mc_fault(m,0x455e,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x4560;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
