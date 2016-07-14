/* main — entry 0x4438.
 * 
 * Reconstructed from memory.bin; original labels retained where available.
 * Address labels and fixed-width state preserve wraparound and aliasing.
 */
#include "reconstructed.h"
uint16_t fn_main(MCState *m) {
    switch(m->r[0]) {
    case 0x4438: goto L_4438;
    case 0x443c: goto L_443c;
    case 0x4440: goto L_4440;
    case 0x4444: goto L_4444;
    case 0x4448: goto L_4448;
    case 0x444a: goto L_444a;
    case 0x444e: goto L_444e;
    case 0x4450: goto L_4450;
    case 0x4454: goto L_4454;
    case 0x4456: goto L_4456;
    case 0x4458: goto L_4458;
    case 0x445c: goto L_445c;
    case 0x4460: goto L_4460;
    case 0x4462: goto L_4462;
    case 0x4466: goto L_4466;
    case 0x446a: goto L_446a;
    case 0x446e: goto L_446e;
    case 0x4470: goto L_4470;
    default: return mc_fault(m,m->r[0],"entry outside function");
    }
L_4438: { /* 0x4438: 31509cff  add #0xff9c, sp */
        if(!m->budget) return mc_fault(m,0x4438,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x443c;
        if(m->mem[0x4438]!=49 || m->mem[0x4439]!=80 || m->mem[0x443a]!=156 || m->mem[0x443b]!=255) return mc_fault(m,0x4438,"code changed; redisassembly required");
        uint16_t src=0xff9c;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        goto L_443c;
    }
L_443c: { /* 0x443c: b0127e44  call #0x447e */
        if(!m->budget) return mc_fault(m,0x443c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4440;
        if(m->mem[0x443c]!=176 || m->mem[0x443d]!=18 || m->mem[0x443e]!=126 || m->mem[0x443f]!=68) return mc_fault(m,0x443c,"code changed; redisassembly required");
        uint16_t src=0x447e;
        mc_push(m,0x4440);
        return mc_exit(m,src);
    }
L_4440: { /* 0x4440: 3f40e444  mov #0x44e4, r15 */
        if(!m->budget) return mc_fault(m,0x4440,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4444;
        if(m->mem[0x4440]!=63 || m->mem[0x4441]!=64 || m->mem[0x4442]!=228 || m->mem[0x4443]!=68) return mc_fault(m,0x4440,"code changed; redisassembly required");
        uint16_t src=0x44e4;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4444;
    }
L_4444: { /* 0x4444: b0129445  call #0x4594 */
        if(!m->budget) return mc_fault(m,0x4444,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4448;
        if(m->mem[0x4444]!=176 || m->mem[0x4445]!=18 || m->mem[0x4446]!=148 || m->mem[0x4447]!=69) return mc_fault(m,0x4444,"code changed; redisassembly required");
        uint16_t src=0x4594;
        mc_push(m,0x4448);
        return mc_exit(m,src);
    }
L_4448: { /* 0x4448: 0f41  mov sp, r15 */
        if(!m->budget) return mc_fault(m,0x4448,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x444a;
        if(m->mem[0x4448]!=15 || m->mem[0x4449]!=65) return mc_fault(m,0x4448,"code changed; redisassembly required");
        uint16_t src=m->r[1];
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_444a;
    }
L_444a: { /* 0x444a: b012b244  call #0x44b2 */
        if(!m->budget) return mc_fault(m,0x444a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x444e;
        if(m->mem[0x444a]!=176 || m->mem[0x444b]!=18 || m->mem[0x444c]!=178 || m->mem[0x444d]!=68) return mc_fault(m,0x444a,"code changed; redisassembly required");
        uint16_t src=0x44b2;
        mc_push(m,0x444e);
        return mc_exit(m,src);
    }
L_444e: { /* 0x444e: 0f41  mov sp, r15 */
        if(!m->budget) return mc_fault(m,0x444e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4450;
        if(m->mem[0x444e]!=15 || m->mem[0x444f]!=65) return mc_fault(m,0x444e,"code changed; redisassembly required");
        uint16_t src=m->r[1];
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4450;
    }
L_4450: { /* 0x4450: b012bc44  call #0x44bc */
        if(!m->budget) return mc_fault(m,0x4450,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4454;
        if(m->mem[0x4450]!=176 || m->mem[0x4451]!=18 || m->mem[0x4452]!=188 || m->mem[0x4453]!=68) return mc_fault(m,0x4450,"code changed; redisassembly required");
        uint16_t src=0x44bc;
        mc_push(m,0x4454);
        return mc_exit(m,src);
    }
L_4454: { /* 0x4454: 0f93  cmp #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x4454,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4456;
        if(m->mem[0x4454]!=15 || m->mem[0x4455]!=147) return mc_fault(m,0x4454,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        (void)mc_sub(m,dst,src,1,16);
        goto L_4456;
    }
L_4456: { /* 0x4456: 0520  jnz 0x4462 */
        if(!m->budget) return mc_fault(m,0x4456,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4458;
        if(m->mem[0x4456]!=5 || m->mem[0x4457]!=32) return mc_fault(m,0x4456,"code changed; redisassembly required");
        if(!(m->r[2]&MC_Z)) {
            goto L_4462;
        }
        goto L_4458;
    }
L_4458: { /* 0x4458: 3f400345  mov #0x4503, r15 */
        if(!m->budget) return mc_fault(m,0x4458,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x445c;
        if(m->mem[0x4458]!=63 || m->mem[0x4459]!=64 || m->mem[0x445a]!=3 || m->mem[0x445b]!=69) return mc_fault(m,0x4458,"code changed; redisassembly required");
        uint16_t src=0x4503;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_445c;
    }
L_445c: { /* 0x445c: b0129445  call #0x4594 */
        if(!m->budget) return mc_fault(m,0x445c,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4460;
        if(m->mem[0x445c]!=176 || m->mem[0x445d]!=18 || m->mem[0x445e]!=148 || m->mem[0x445f]!=69) return mc_fault(m,0x445c,"code changed; redisassembly required");
        uint16_t src=0x4594;
        mc_push(m,0x4460);
        return mc_exit(m,src);
    }
L_4460: { /* 0x4460: 063c  jmp 0x446e */
        if(!m->budget) return mc_fault(m,0x4460,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4462;
        if(m->mem[0x4460]!=6 || m->mem[0x4461]!=60) return mc_fault(m,0x4460,"code changed; redisassembly required");
        goto L_446e;
    }
L_4462: { /* 0x4462: 3f402045  mov #0x4520, r15 */
        if(!m->budget) return mc_fault(m,0x4462,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4466;
        if(m->mem[0x4462]!=63 || m->mem[0x4463]!=64 || m->mem[0x4464]!=32 || m->mem[0x4465]!=69) return mc_fault(m,0x4462,"code changed; redisassembly required");
        uint16_t src=0x4520;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4466;
    }
L_4466: { /* 0x4466: b0129445  call #0x4594 */
        if(!m->budget) return mc_fault(m,0x4466,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x446a;
        if(m->mem[0x4466]!=176 || m->mem[0x4467]!=18 || m->mem[0x4468]!=148 || m->mem[0x4469]!=69) return mc_fault(m,0x4466,"code changed; redisassembly required");
        uint16_t src=0x4594;
        mc_push(m,0x446a);
        return mc_exit(m,src);
    }
L_446a: { /* 0x446a: b012d644  call #0x44d6 */
        if(!m->budget) return mc_fault(m,0x446a,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x446e;
        if(m->mem[0x446a]!=176 || m->mem[0x446b]!=18 || m->mem[0x446c]!=214 || m->mem[0x446d]!=68) return mc_fault(m,0x446a,"code changed; redisassembly required");
        uint16_t src=0x44d6;
        mc_push(m,0x446e);
        return mc_exit(m,src);
    }
L_446e: { /* 0x446e: 0f43  mov #0x0000, r15 */
        if(!m->budget) return mc_fault(m,0x446e,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4470;
        if(m->mem[0x446e]!=15 || m->mem[0x446f]!=67) return mc_fault(m,0x446e,"code changed; redisassembly required");
        uint16_t src=0x0000;
        uint16_t dst=m->r[15];
        m->r[15]=(uint16_t)(src);
        goto L_4470;
    }
L_4470: { /* 0x4470: 31506400  add #0x0064, sp */
        if(!m->budget) return mc_fault(m,0x4470,"instruction budget exhausted");
        --m->budget;
        m->r[0]=0x4474;
        if(m->mem[0x4470]!=49 || m->mem[0x4471]!=80 || m->mem[0x4472]!=100 || m->mem[0x4473]!=0) return mc_fault(m,0x4470,"code changed; redisassembly required");
        uint16_t src=0x0064;
        uint16_t dst=m->r[1];
        m->r[1]=(uint16_t)(mc_add(m,dst,src,0,16));
        return mc_exit(m,0x4474);
    }
}
