# CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_V8 | CS_MODE_MCLASS, None
0xe2,0xee,0x10,0x0a = vmsr fpscr_nzcvqc, r0
0xf2,0xee,0x10,0xaa = vmrs r10, fpscr_nzcvqc
0xfe,0xee,0x10,0x0a = vmrs r0, fpcxtns
0xee,0xee,0x10,0xaa = vmsr fpcxtns, r10
0xef,0xee,0x10,0x5a = vmsr fpcxts, r5
0xfe,0xee,0x10,0x3a = vmrs r3, fpcxtns
0xff,0xee,0x10,0x0a = vmrs r0, fpcxts
0xfc,0xee,0x10,0x0a = vmrs r0, vpr
0xfd,0xee,0x10,0x4a = vmrs r4, p0
0xec,0xee,0x10,0x0a = vmsr vpr, r0
0xed,0xee,0x10,0x4a = vmsr p0, r4
