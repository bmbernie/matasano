/* __do_copy_data — entry 0x440e.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn___do_copy_data(MCState *m) {
    switch(m->r[0]) {
    case 0x440e: goto L_440e;
    case 0x4412: goto L_4412;
    case 0x4414: goto L_4414;
    case 0x4416: goto L_4416;
    case 0x441a: goto L_441a;
    case 0x441c: goto L_441c;
    case 0x4422: goto L_4422;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_440e: { /* 0x440e: 3f400000  mov #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x440e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4412;
        if(m->mem[0x440e]!=63 || m->mem[0x440f]!=64 || m->mem[0x4410]!=0 || m->mem[0x4411]!=0) return mc_fault(m,0x440e,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4412;
    }
L_4412: { /* 0x4412: 0f93  cmp #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x4412,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4414;
        if(m->mem[0x4412]!=15 || m->mem[0x4413]!=147) return mc_fault(m,0x4412,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        (void)mc_sub(m,dst,src,1,16);
        goto L_4414;
    }
L_4414: { /* 0x4414: 0724  jz 0x4424 */
        if(!m->budget) return mc_fault(m,0x4414,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4416;
        if(m->mem[0x4414]!=7 || m->mem[0x4415]!=36) return mc_fault(m,0x4414,"code changed; redisassembly required");
        if(m->r[2]&MC_Z) {
            return mc_exit(m,0x4424);
        }
        goto L_4416;
    }
L_4416: { /* 0x4416: 82455c01  mov r5, &0x015c */
        if(!m->budget) return mc_fault(m,0x4416,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x441a;
        if(m->mem[0x4416]!=130 || m->mem[0x4417]!=69 || m->mem[0x4418]!=92 || m->mem[0x4419]!=1) return mc_fault(m,0x4416,"code changed; redisassembly required");
        uint16_t src=m->r[5];
        uint16_t dst_addr=0x015c;
        uint16_t dst=rd16(m,dst_addr);
        wr16(m,dst_addr,src);
        goto L_441a;
    }
L_441a: { /* 0x441a: 2f83  sub #0x0002, r15 */
        if(!m->budget) return mc_fault(m,0x441a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x441c;
        if(m->mem[0x441a]!=47 || m->mem[0x441b]!=131) return mc_fault(m,0x441a,"code changed; redisassembly required");
        uint16_t src=0x0002;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(mc_sub(m,dst,src,1,16));
        goto L_441c;
    }
L_441c: { /* 0x441c: 9f4fc2450024  mov 0x45c2(r15), 0x2400(r15) */
        if(!m->budget) return mc_fault(m,0x441c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4422;
        if(m->mem[0x441c]!=159 || m->mem[0x441d]!=79 || m->mem[0x441e]!=194 || m->mem[0x441f]!=69 || m->mem[0x4420]!=0 || m->mem[0x4421]!=36) return mc_fault(m,0x441c,"code changed; redisassembly required");
        uint16_t src_addr=(uint16_t)(m->r[15]+0x45c2);
        uint16_t src=rd16(m,src_addr);
        uint16_t dst_addr=(uint16_t)(m->r[15]+0x2400);
        uint16_t dst=rd16(m,dst_addr);
        wr16(m,dst_addr,src);
        goto L_4422;
    }
L_4422: { /* 0x4422: f923  jnz 0x4416 */
        if(!m->budget) return mc_fault(m,0x4422,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4424;
        if(m->mem[0x4422]!=249 || m->mem[0x4423]!=35) return mc_fault(m,0x4422,"code changed; redisassembly required");
        if(!(m->r[2]&MC_Z)) {
            goto L_4416;
        }
        return mc_exit(m,0x4424);
    }
}
