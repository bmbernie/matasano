/* puts — entry 0x4594.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_puts(MCState *m) {
    switch(m->r[0]) {
    case 0x4594: goto L_4594;
    case 0x4596: goto L_4596;
    case 0x4598: goto L_4598;
    case 0x459a: goto L_459a;
    case 0x459c: goto L_459c;
    case 0x459e: goto L_459e;
    case 0x45a0: goto L_45a0;
    case 0x45a2: goto L_45a2;
    case 0x45a6: goto L_45a6;
    case 0x45a8: goto L_45a8;
    case 0x45aa: goto L_45aa;
    case 0x45ac: goto L_45ac;
    case 0x45ae: goto L_45ae;
    case 0x45b2: goto L_45b2;
    case 0x45b4: goto L_45b4;
    case 0x45b8: goto L_45b8;
    case 0x45ba: goto L_45ba;
    case 0x45bc: goto L_45bc;
    case 0x45be: goto L_45be;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4594: { /* 0x4594: 0b12  push r11 */
        if(!m->budget) return mc_fault(m,0x4594,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4596;
        if(m->mem[0x4594]!=11 || m->mem[0x4595]!=18) return mc_fault(m,0x4594,"code changed; redisassembly required");
        uint16_t src=m->r[11];
        mc_push(m,src);
        goto L_4596;
    }
L_4596: { /* 0x4596: 0b4f  mov r15, r11 */
        if(!m->budget) return mc_fault(m,0x4596,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4598;
        if(m->mem[0x4596]!=11 || m->mem[0x4597]!=79) return mc_fault(m,0x4596,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        uint16_t dst=m->r[11];
        m->r[11]=(uint16_t)(src);
        goto L_4598;
    }
L_4598: { /* 0x4598: 073c  jmp 0x45a8 */
        if(!m->budget) return mc_fault(m,0x4598,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x459a;
        if(m->mem[0x4598]!=7 || m->mem[0x4599]!=60) return mc_fault(m,0x4598,"code changed; redisassembly required");
        goto L_45a8;
    }
L_459a: { /* 0x459a: 1b53  add #0x0001, r11 */
        if(!m->budget) return mc_fault(m,0x459a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x459c;
        if(m->mem[0x459a]!=27 || m->mem[0x459b]!=83) return mc_fault(m,0x459a,"code changed; redisassembly required");
        uint16_t src=0x0001;
        uint16_t dst=m->r[11];
        m->r[11]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_459c;
    }
L_459c: { /* 0x459c: 8f11  sxt r15 */
        if(!m->budget) return mc_fault(m,0x459c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x459e;
        if(m->mem[0x459c]!=143 || m->mem[0x459d]!=17) return mc_fault(m,0x459c,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        m->r[15]=(uint16_t)(mc_logic(m,(uint16_t)(int16_t)(int8_t)src,16,0));
        goto L_459e;
    }
L_459e: { /* 0x459e: 0f12  push r15 */
        if(!m->budget) return mc_fault(m,0x459e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45a0;
        if(m->mem[0x459e]!=15 || m->mem[0x459f]!=18) return mc_fault(m,0x459e,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        mc_push(m,src);
        goto L_45a0;
    }
L_45a0: { /* 0x45a0: 0312  push #0x0000 */
        if(!m->budget) return mc_fault(m,0x45a0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45a2;
        if(m->mem[0x45a0]!=3 || m->mem[0x45a1]!=18) return mc_fault(m,0x45a0,"code changed; redisassembly required");
        uint16_t src=0x0000;
        mc_push(m,src);
        goto L_45a2;
    }
L_45a2: { /* 0x45a2: b0123045  call #0x4530 */
        if(!m->budget) return mc_fault(m,0x45a2,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45a6;
        if(m->mem[0x45a2]!=176 || m->mem[0x45a3]!=18 || m->mem[0x45a4]!=48 || m->mem[0x45a5]!=69) return mc_fault(m,0x45a2,"code changed; redisassembly required");
        uint16_t src=0x4530;
        mc_push(m,0x45a6);
        return mc_exit(m,src);
    }
L_45a6: { /* 0x45a6: 2152  add #0x0004, sp */
        if(!m->budget) return mc_fault(m,0x45a6,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45a8;
        if(m->mem[0x45a6]!=33 || m->mem[0x45a7]!=82) return mc_fault(m,0x45a6,"code changed; redisassembly required");
        uint16_t src=0x0004;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_45a8;
    }
L_45a8: { /* 0x45a8: 6f4b  mov.b @r11, r15 */
        if(!m->budget) return mc_fault(m,0x45a8,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45aa;
        if(m->mem[0x45a8]!=111 || m->mem[0x45a9]!=75) return mc_fault(m,0x45a8,"code changed; redisassembly required");
        uint16_t src_addr=m->r[11];
        uint16_t src=rd8(m,src_addr);
        uint16_t dst=(m->r[15]&0xff);
        m->r[15]=(uint8_t)(src);
        goto L_45aa;
    }
L_45aa: { /* 0x45aa: 4f93  cmp.b #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x45aa,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45ac;
        if(m->mem[0x45aa]!=79 || m->mem[0x45ab]!=147) return mc_fault(m,0x45aa,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=(m->r[15]&0xff);
        (void)mc_sub(m,dst,src,1,8);
        goto L_45ac;
    }
L_45ac: { /* 0x45ac: f623  jnz 0x459a */
        if(!m->budget) return mc_fault(m,0x45ac,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45ae;
        if(m->mem[0x45ac]!=246 || m->mem[0x45ad]!=35) return mc_fault(m,0x45ac,"code changed; redisassembly required");
        if(!(m->r[2]&MC_Z)) {
            goto L_459a;
        }
        goto L_45ae;
    }
L_45ae: { /* 0x45ae: 30120a00  push #0x000a */
        if(!m->budget) return mc_fault(m,0x45ae,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45b2;
        if(m->mem[0x45ae]!=48 || m->mem[0x45af]!=18 || m->mem[0x45b0]!=10 || m->mem[0x45b1]!=0) return mc_fault(m,0x45ae,"code changed; redisassembly required");
        uint16_t src=0x000a;
        mc_push(m,src);
        goto L_45b2;
    }
L_45b2: { /* 0x45b2: 0312  push #0x0000 */
        if(!m->budget) return mc_fault(m,0x45b2,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45b4;
        if(m->mem[0x45b2]!=3 || m->mem[0x45b3]!=18) return mc_fault(m,0x45b2,"code changed; redisassembly required");
        uint16_t src=0x0000;
        mc_push(m,src);
        goto L_45b4;
    }
L_45b4: { /* 0x45b4: b0123045  call #0x4530 */
        if(!m->budget) return mc_fault(m,0x45b4,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45b8;
        if(m->mem[0x45b4]!=176 || m->mem[0x45b5]!=18 || m->mem[0x45b6]!=48 || m->mem[0x45b7]!=69) return mc_fault(m,0x45b4,"code changed; redisassembly required");
        uint16_t src=0x4530;
        mc_push(m,0x45b8);
        return mc_exit(m,src);
    }
L_45b8: { /* 0x45b8: 2152  add #0x0004, sp */
        if(!m->budget) return mc_fault(m,0x45b8,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45ba;
        if(m->mem[0x45b8]!=33 || m->mem[0x45b9]!=82) return mc_fault(m,0x45b8,"code changed; redisassembly required");
        uint16_t src=0x0004;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_45ba;
    }
L_45ba: { /* 0x45ba: 0f43  mov #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x45ba,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45bc;
        if(m->mem[0x45ba]!=15 || m->mem[0x45bb]!=67) return mc_fault(m,0x45ba,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_45bc;
    }
L_45bc: { /* 0x45bc: 3b41  mov @r1+, r11 */
        if(!m->budget) return mc_fault(m,0x45bc,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45be;
        if(m->mem[0x45bc]!=59 || m->mem[0x45bd]!=65) return mc_fault(m,0x45bc,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=m->r[11];
        m->r[11]=(uint16_t)(src);
        goto L_45be;
    }
L_45be: { /* 0x45be: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x45be,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x45c0;
        if(m->mem[0x45be]!=48 || m->mem[0x45bf]!=65) return mc_fault(m,0x45be,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x45c0;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
