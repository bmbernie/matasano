/* __do_clear_bss — entry 0x4424.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___do_clear_bss(MCState *m) {
    switch(m->r[0]) {
    case 0x4424: goto L_4424;
    case 0x4428: goto L_4428;
    case 0x442a: goto L_442a;
    case 0x442c: goto L_442c;
    case 0x4430: goto L_4430;
    case 0x4432: goto L_4432;
    case 0x4436: goto L_4436;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4424: { /* 0x4424: 3f400800  mov #0x0008, r15 */
        if(!m->budget) return mc_fault(m,0x4424,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4428;
        if(m->mem[0x4424]!=63 || m->mem[0x4425]!=64 || m->mem[0x4426]!=8 || m->mem[0x4427]!=0) return mc_fault(m,0x4424,"code changed; redisassembly required");
        uint16_t src=0x0008;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4428;
    }
L_4428: { /* 0x4428: 0f93  cmp #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x4428,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x442a;
        if(m->mem[0x4428]!=15 || m->mem[0x4429]!=147) return mc_fault(m,0x4428,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        (void)mc_sub(m,dst,src,1,16);
        goto L_442a;
    }
L_442a: { /* 0x442a: 0624  jz 0x4438 */
        if(!m->budget) return mc_fault(m,0x442a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x442c;
        if(m->mem[0x442a]!=6 || m->mem[0x442b]!=36) return mc_fault(m,0x442a,"code changed; redisassembly required");
        if(m->r[2]&MC_Z) {
            return mc_exit(m,0x4438);
        }
        goto L_442c;
    }
L_442c: { /* 0x442c: 82455c01  mov r5, &0x015c */
        if(!m->budget) return mc_fault(m,0x442c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4430;
        if(m->mem[0x442c]!=130 || m->mem[0x442d]!=69 || m->mem[0x442e]!=92 || m->mem[0x442f]!=1) return mc_fault(m,0x442c,"code changed; redisassembly required");
        uint16_t src=m->r[5];
        uint16_t dst_addr=0x015c;
        uint16_t dst=rd16(m,dst_addr);
        wr16(m,dst_addr,src);
        goto L_4430;
    }
L_4430: { /* 0x4430: 1f83  sub #0x0001, r15 */
        if(!m->budget) return mc_fault(m,0x4430,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4432;
        if(m->mem[0x4430]!=31 || m->mem[0x4431]!=131) return mc_fault(m,0x4430,"code changed; redisassembly required");
        uint16_t src=0x0001;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(mc_sub(m,dst,src,1,16));
        goto L_4432;
    }
L_4432: { /* 0x4432: cf430024  mov.b #0x0000, 0x2400(r15) */
        if(!m->budget) return mc_fault(m,0x4432,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4436;
        if(m->mem[0x4432]!=207 || m->mem[0x4433]!=67 || m->mem[0x4434]!=0 || m->mem[0x4435]!=36) return mc_fault(m,0x4432,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x2400);
        uint16_t dst=rd8(m,dst_addr);
        wr8(m,dst_addr,src);
        goto L_4436;
    }
L_4436: { /* 0x4436: fa23  jnz 0x442c */
        if(!m->budget) return mc_fault(m,0x4436,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4438;
        if(m->mem[0x4436]!=250 || m->mem[0x4437]!=35) return mc_fault(m,0x4436,"code changed; redisassembly required");
        if(!(m->r[2]&MC_Z)) {
            goto L_442c;
        }
        return mc_exit(m,0x4438);
    }
}
