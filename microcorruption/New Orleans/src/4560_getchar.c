/* getchar — entry 0x4560.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_getchar(MCState *m) {
    switch(m->r[0]) {
    case 0x4560: goto L_4560;
    case 0x4562: goto L_4562;
    case 0x4564: goto L_4564;
    case 0x4566: goto L_4566;
    case 0x4568: goto L_4568;
    case 0x456c: goto L_456c;
    case 0x456e: goto L_456e;
    case 0x4570: goto L_4570;
    case 0x4572: goto L_4572;
    case 0x4576: goto L_4576;
    case 0x457a: goto L_457a;
    case 0x457c: goto L_457c;
    case 0x4580: goto L_4580;
    case 0x4582: goto L_4582;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4560: { /* 0x4560: 0412  push r4 */
        if(!m->budget) return mc_fault(m,0x4560,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4562;
        if(m->mem[0x4560]!=4 || m->mem[0x4561]!=18) return mc_fault(m,0x4560,"code changed; redisassembly required");
        uint16_t src=m->r[4];
        mc_push(m,src);
        goto L_4562;
    }
L_4562: { /* 0x4562: 0441  mov sp, r4 */
        if(!m->budget) return mc_fault(m,0x4562,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4564;
        if(m->mem[0x4562]!=4 || m->mem[0x4563]!=65) return mc_fault(m,0x4562,"code changed; redisassembly required");
        uint16_t src=m->r[1];
        uint16_t dst=m->r[4];
        m->r[4]=(uint16_t)(src);
        goto L_4564;
    }
L_4564: { /* 0x4564: 2453  add #0x0002, r4 */
        if(!m->budget) return mc_fault(m,0x4564,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4566;
        if(m->mem[0x4564]!=36 || m->mem[0x4565]!=83) return mc_fault(m,0x4564,"code changed; redisassembly required");
        uint16_t src=0x0002;
        uint16_t dst=m->r[4];
        m->r[4]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_4566;
    }
L_4566: { /* 0x4566: 2183  sub #0x0002, sp */
        if(!m->budget) return mc_fault(m,0x4566,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4568;
        if(m->mem[0x4566]!=33 || m->mem[0x4567]!=131) return mc_fault(m,0x4566,"code changed; redisassembly required");
        uint16_t src=0x0002;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_sub(m,dst,src,1,16));
        goto L_4568;
    }
L_4568: { /* 0x4568: 3f40fcff  mov #0xfffc, r15 */
        if(!m->budget) return mc_fault(m,0x4568,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x456c;
        if(m->mem[0x4568]!=63 || m->mem[0x4569]!=64 || m->mem[0x456a]!=252 || m->mem[0x456b]!=255) return mc_fault(m,0x4568,"code changed; redisassembly required");
        uint16_t src=0xfffc;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_456c;
    }
L_456c: { /* 0x456c: 0f54  add r4, r15 */
        if(!m->budget) return mc_fault(m,0x456c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x456e;
        if(m->mem[0x456c]!=15 || m->mem[0x456d]!=84) return mc_fault(m,0x456c,"code changed; redisassembly required");
        uint16_t src=m->r[4];
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_456e;
    }
L_456e: { /* 0x456e: 0f12  push r15 */
        if(!m->budget) return mc_fault(m,0x456e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4570;
        if(m->mem[0x456e]!=15 || m->mem[0x456f]!=18) return mc_fault(m,0x456e,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        mc_push(m,src);
        goto L_4570;
    }
L_4570: { /* 0x4570: 1312  push #0x0001 */
        if(!m->budget) return mc_fault(m,0x4570,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4572;
        if(m->mem[0x4570]!=19 || m->mem[0x4571]!=18) return mc_fault(m,0x4570,"code changed; redisassembly required");
        uint16_t src=0x0001;
        mc_push(m,src);
        goto L_4572;
    }
L_4572: { /* 0x4572: b0123045  call #0x4530 */
        if(!m->budget) return mc_fault(m,0x4572,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4576;
        if(m->mem[0x4572]!=176 || m->mem[0x4573]!=18 || m->mem[0x4574]!=48 || m->mem[0x4575]!=69) return mc_fault(m,0x4572,"code changed; redisassembly required");
        uint16_t src=0x4530;
        mc_push(m,0x4576);
        return mc_exit(m,src);
    }
L_4576: { /* 0x4576: 5f44fcff  mov.b 0xfffc(r4), r15 */
        if(!m->budget) return mc_fault(m,0x4576,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x457a;
        if(m->mem[0x4576]!=95 || m->mem[0x4577]!=68 || m->mem[0x4578]!=252 || m->mem[0x4579]!=255) return mc_fault(m,0x4576,"code changed; redisassembly required");
        uint16_t src_addr=(uint16_t)(m->r[4]+0xfffc);
        uint16_t src=rd8(m,src_addr);
        uint16_t dst=(m->r[15]&0xff);
        m->r[15]=(uint8_t)(src);
        goto L_457a;
    }
L_457a: { /* 0x457a: 8f11  sxt r15 */
        if(!m->budget) return mc_fault(m,0x457a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x457c;
        if(m->mem[0x457a]!=143 || m->mem[0x457b]!=17) return mc_fault(m,0x457a,"code changed; redisassembly required");
        uint16_t src=m->r[15];
        m->r[15]=(uint16_t)(mc_logic(m,(uint16_t)(int16_t)(int8_t)src,16,0));
        goto L_457c;
    }
L_457c: { /* 0x457c: 31500600  add #0x0006, sp */
        if(!m->budget) return mc_fault(m,0x457c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4580;
        if(m->mem[0x457c]!=49 || m->mem[0x457d]!=80 || m->mem[0x457e]!=6 || m->mem[0x457f]!=0) return mc_fault(m,0x457c,"code changed; redisassembly required");
        uint16_t src=0x0006;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_4580;
    }
L_4580: { /* 0x4580: 3441  mov @r1+, r4 */
        if(!m->budget) return mc_fault(m,0x4580,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4582;
        if(m->mem[0x4580]!=52 || m->mem[0x4581]!=65) return mc_fault(m,0x4580,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=m->r[4];
        m->r[4]=(uint16_t)(src);
        goto L_4582;
    }
L_4582: { /* 0x4582: 3041  mov @r1+, pc */
        if(!m->budget) return mc_fault(m,0x4582,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4584;
        if(m->mem[0x4582]!=48 || m->mem[0x4583]!=65) return mc_fault(m,0x4582,"code changed; redisassembly required");
        uint16_t src_addr=m->r[1];
        uint16_t src=rd16(m,src_addr);
        m->r[1]+=2;
        uint16_t dst=0x4584;
        m->r[0]=(uint16_t)(src);
        return mc_exit(m,m->r[0]);
    }
}
