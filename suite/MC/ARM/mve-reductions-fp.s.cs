# CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_V8 | CS_MODE_MCLASS, None
0xee,0xfe,0x86,0xef = vminnmv.f16 lr, q3
0xee,0xee,0x82,0xef = vminnmv.f32 lr, q1
0xec,0xfe,0x80,0xef = vminnmav.f16 lr, q0
0xec,0xee,0x86,0xef = vminnmav.f32 lr, q3
0xee,0xfe,0x02,0xef = vmaxnmv.f16 lr, q1
0xee,0xee,0x02,0xaf = vmaxnmv.f32 r10, q1
0xec,0xfe,0x0c,0x0f = vmaxnmav.f16 r0, q6
0xec,0xee,0x0e,0xef = vmaxnmav.f32 lr, q7
0xec,0xee,0x86,0xef = vminnmavt.f32 lr, q3
0xec,0xee,0x86,0xef = vminnmave.f32 lr, q3
