/* check_password — entry 0x44bc.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_check_password(MCState *m) {
    switch(m->r[0]) {
    case 0x44bc: goto L_44bc;
    case 0x44be: goto L_44be;
    case 0x44c0: goto L_44c0;
    case 0x44c2: goto L_44c2;
    case 0x44c6: goto L_44c6;
    case 0x44c8: goto L_44c8;
    case 0x44ca: goto L_44ca;
    case 0x44cc: goto L_44cc;
    case 0x44ce: goto L_44ce;
    case 0x44d0: goto L_44d0;
    case 0x44d2: goto L_44d2;
    case 0x44d4: goto L_44d4;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_44bc: { /* 0x44bc: 0e43  mov #0x0000, r14 */
        if(!m->budget) return mc_fault(m,0x44bc,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44be;
        if(m->mem[0x44bc]!=14 || m->mem[0x44bd]!=67) return mc_fault(m,0x44bc,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[14];
        m->r[14]=(uint16_t)(src);
        goto L_44be;
    }
L_44be: { /* 0x44be: 0d4f  mov r15, r13 */
        if(!m->budget) return mc_fault(m,0x44be,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44c0;
        if(m->mem[0x44be]!=13 || m->mem[0x44bf]!=79) return mc_fault(m,0x44be,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        uint16_t dst=m->r[13];
        m->r[13]=(uint16_t)(src);
        goto L_44c0;
    }
L_44c0: { /* 0x44c0: 0d5e  add r14, r13 */
        if(!m->budget) return mc_fault(m,0x44c0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44c2;
        if(m->mem[0x44c0]!=13 || m->mem[0x44c1]!=94) return mc_fault(m,0x44c0,"code changed; redisassembly required");
        uint16_t src=m->r[14];
        uint16_t dst=m->r[13];
        m->r[13]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_44c2;
    }
L_44c2: { /* 0x44c2: ee9d0024  cmp.b @r13, 0x2400(r14) */
        if(!m->budget) return mc_fault(m,0x44c2,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44c6;
        if(m->mem[0x44c2]!=238 || m->mem[0x44c3]!=157 || m->mem[0x44c4]!=0 || m->mem[0x44c5]!=36) return mc_fault(m,0x44c2,"code changed; redisassembly required");
        uint16_t src_addr=m->r[13];
        uint16_t src=rd8(m,src_addr);
        uint16_t dst_addr=(uint16_t)(m->r[14]+0x2400);
        uint16_t dst=rd8(m,dst_addr);
        (void)mc_sub(m,dst,src,1,8);
        goto L_44c6;
    }
L_44c6: { /* 0x44c6: 0520  jnz 0x44d2 */
        if(!m->budget) return mc_fault(m,0x44c6,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44c8;
        if(m->mem[0x44c6]!=5 || m->mem[0x44c7]!=32) return mc_fault(m,0x44c6,"code changed; redisassembly required");
        if(!(m->r[2]&MC_Z)) {
            goto L_44d2;
        }
        goto L_44c8;
    }
L_44c8: { /* 0x44c8: 1e53  add #0x0001, r14 */
        if(!m->budget) return mc_fault(m,0x44c8,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44ca;
        if(m->mem[0x44c8]!=30 || m->mem[0x44c9]!=83) return mc_fault(m,0x44c8,"code changed; redisassembly required");
        uint16_t src=0x0001;
        uint16_t dst=m->r[14];
        m->r[14]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_44ca;
    }
L_44ca: { /* 0x44ca: 3e92  cmp #0x0008, r14 */
        if(!m->budget) return mc_fault(m,0x44ca,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44cc;
        if(m->mem[0x44ca]!=62 || m->mem[0x44cb]!=146) return mc_fault(m,0x44ca,"code changed; redisassembly required");
        uint16_t src=0x0008;
        uint16_t dst=m->r[14];
        (void)mc_sub(m,dst,src,1,16);
        goto L_44cc;
    }
L_44cc: { /* 0x44cc: f823  jnz 0x44be */
        if(!m->budget) return mc_fault(m,0x44cc,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44ce;
        if(m->mem[0x44cc]!=248 || m->mem[0x44cd]!=35) return mc_fault(m,0x44cc,"code changed; redisassembly required");
        if(!(m->r[2]&MC_Z)) {
            goto L_44be;
        }
        goto L_44ce;
    }
L_44ce: { /* 0x44ce: 1f43  mov #0x0001, r15 */
        if(!m->budget) return mc_fault(m,0x44ce,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44d0;
        if(m->mem[0x44ce]!=31 || m->mem[0x44cf]!=67) return mc_fault(m,0x44ce,"code changed; redisassembly required");
        uint16_t src=0x0001;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_44d0;
    }
L_44d0: { /* 0x44d0: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x44d0,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44d2;
        if(m->mem[0x44d0]!=48 || m->mem[0x44d1]!=65) return mc_fault(m,0x44d0,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x44d2;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
L_44d2: { /* 0x44d2: 0f43  mov #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x44d2,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44d4;
        if(m->mem[0x44d2]!=15 || m->mem[0x44d3]!=67) return mc_fault(m,0x44d2,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_44d4;
    }
L_44d4: { /* 0x44d4: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x44d4,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x44d6;
        if(m->mem[0x44d4]!=48 || m->mem[0x44d5]!=65) return mc_fault(m,0x44d4,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x44d6;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
