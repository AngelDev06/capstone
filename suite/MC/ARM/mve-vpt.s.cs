# CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_V8 | CS_MODE_MCLASS, None
0x41,0xfe,0x02,0x2f = vpteee.i8 eq, q0, q1
0x21,0xfe,0x03,0x3f = vptttt.s32 gt, q0, q1
0x71,0xfe,0x82,0xef = vptete.f16 ne, q0, q1
0x1c,0xff,0x54,0x2f = vmaxnmt.f16 q1, q6, q2
