//===- ARMInstPrinter.h - Convert ARM MCInst to assembly syntax -*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an ARM MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef CS_ARMINSTPRINTER_H
#define CS_ARMINSTPRINTER_H

#include <capstone/platform.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ARMMapping.h"

#include "../../MCInst.h"
#include "../../MCInstPrinter.h"
#include "../../MCRegisterInfo.h"
#include "../../SStream.h"
#include "../../utils.h"
#define CONCAT(a, b) CONCAT_(a, b)
#define CONCAT_(a, b) a##_##b

bool applyTargetSpecificCLOption(const char *Opt);
void printInst(const MCInst *MI, uint64_t Address, const char *Annot,
	       SStream *O);
void printRegName(SStream *OS, unsigned RegNo);
// Autogenerated by tblgen.
MnemonicBitsInfo getMnemonic(const MCInst *MI, SStream *O);
void printInstruction(const MCInst *MI, uint64_t Address, SStream *O);
bool printAliasInstr(const MCInst *MI, uint64_t Address, SStream *O);
void printCustomAliasOperand(const MCInst *MI, uint64_t Address, unsigned OpIdx,
			     unsigned PrintMethodIdx, SStream *O);
void printOperand(const MCInst *MI, unsigned OpNo, SStream *O);
void printOperandAddr(const MCInst *MI, uint64_t Address, unsigned OpNum,
		      SStream *O);
void printSORegRegOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printSORegImmOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printAddrModeTBB(const MCInst *MI, unsigned OpNum, SStream *O);
void printAddrModeTBH(const MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode2Operand(const MCInst *MI, unsigned OpNum, SStream *O);
void printAM2PostIndexOp(const MCInst *MI, unsigned OpNum, SStream *O);
void printAM2PreOrOffsetIndexOp(const MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode2OffsetOperand(const MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAddrMode3Operand(AlwaysPrintImm0)                         \
  void CONCAT(printAddrMode3Operand,                                           \
	      AlwaysPrintImm0)(const MCInst *MI, unsigned OpNum, SStream *O);
DECLARE_printAddrMode3Operand(false) DECLARE_printAddrMode3Operand(true)

    void printAddrMode3OffsetOperand(const MCInst *MI, unsigned OpNum,
				     SStream *O);
void printAM3PreOrOffsetIndexOp(const MCInst *MI, unsigned Op, SStream *O,
				bool AlwaysPrintImm0);
void printPostIdxImm8Operand(const MCInst *MI, unsigned OpNum, SStream *O);
void printPostIdxRegOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printPostIdxImm8s4Operand(const MCInst *MI, unsigned OpNum, SStream *O);
void printLdStmModeOperand(const MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAddrMode5Operand(AlwaysPrintImm0)                         \
  void CONCAT(printAddrMode5Operand,                                           \
	      AlwaysPrintImm0)(const MCInst *MI, unsigned OpNum, SStream *O);
DECLARE_printAddrMode5Operand(false) DECLARE_printAddrMode5Operand(true)

#define DECLARE_printAddrMode5FP16Operand(AlwaysPrintImm0)                     \
  void CONCAT(printAddrMode5FP16Operand,                                       \
	      AlwaysPrintImm0)(const MCInst *MI, unsigned OpNum, SStream *O);
    DECLARE_printAddrMode5FP16Operand(false)

	void printAddrMode6Operand(const MCInst *MI, unsigned OpNum,
				   SStream *O);
void printAddrMode7Operand(const MCInst *MI, unsigned OpNum, SStream *O);
void printAddrMode6OffsetOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printBitfieldInvMaskImmOperand(const MCInst *MI, unsigned OpNum,
				    SStream *O);
void printMemBOption(const MCInst *MI, unsigned OpNum, SStream *O);
void printInstSyncBOption(const MCInst *MI, unsigned OpNum, SStream *O);
void printTraceSyncBOption(const MCInst *MI, unsigned OpNum, SStream *O);
void printShiftImmOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printPKHLSLShiftImm(const MCInst *MI, unsigned OpNum, SStream *O);
void printPKHASRShiftImm(const MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAdrLabelOperand(scale)                                    \
  void CONCAT(printAdrLabelOperand, scale)(const MCInst *MI, unsigned OpNum,   \
					   SStream *O);
DECLARE_printAdrLabelOperand(0) DECLARE_printAdrLabelOperand(2)

#define DEFINE_printAdrLabelOperandAddr(scale)                                 \
  void CONCAT(printAdrLabelOperandAddr, scale)(                                \
      const MCInst *MI, uint64_t Address, unsigned OpNum, SStream *O)          \
  {                                                                            \
    CONCAT(printAdrLabelOperand, scale)(MI, OpNum, O);                         \
  }
    DEFINE_printAdrLabelOperandAddr(0) DEFINE_printAdrLabelOperandAddr(2)

	void printThumbS4ImmOperand(const MCInst *MI, unsigned OpNum,
				    SStream *O);
void printThumbSRImm(const MCInst *MI, unsigned OpNum, SStream *O);
void printThumbITMask(const MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeRROperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printThumbAddrModeImm5SOperand(const MCInst *MI, unsigned OpNum,
				    SStream *O, unsigned Scale);
void printThumbAddrModeImm5S1Operand(const MCInst *MI, unsigned OpNum,
				     SStream *O);
void printThumbAddrModeImm5S2Operand(const MCInst *MI, unsigned OpNum,
				     SStream *O);
void printThumbAddrModeImm5S4Operand(const MCInst *MI, unsigned OpNum,
				     SStream *O);
void printThumbAddrModeSPOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printT2SOOperand(const MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printAddrModeImm12Operand(AlwaysPrintImm0)                     \
  void CONCAT(printAddrModeImm12Operand,                                       \
	      AlwaysPrintImm0)(const MCInst *MI, unsigned OpNum, SStream *O);
DECLARE_printAddrModeImm12Operand(false) DECLARE_printAddrModeImm12Operand(true)

#define DECLARE_printT2AddrModeImm8Operand(AlwaysPrintImm0)                    \
  void CONCAT(printT2AddrModeImm8Operand,                                      \
	      AlwaysPrintImm0)(const MCInst *MI, unsigned OpNum, SStream *O);
    DECLARE_printT2AddrModeImm8Operand(true)
	DECLARE_printT2AddrModeImm8Operand(false)

#define DECLARE_printT2AddrModeImm8s4Operand(AlwaysPrintImm0)                  \
  void CONCAT(printT2AddrModeImm8s4Operand,                                    \
	      AlwaysPrintImm0)(const MCInst *MI, unsigned OpNum, SStream *O);
	    DECLARE_printT2AddrModeImm8s4Operand(false)
		DECLARE_printT2AddrModeImm8s4Operand(true)

		    void printT2AddrModeImm0_1020s4Operand(const MCInst *MI,
							   unsigned OpNum,
							   SStream *O);
void printT2AddrModeImm8OffsetOperand(const MCInst *MI, unsigned OpNum,
				      SStream *O);
void printT2AddrModeImm8s4OffsetOperand(const MCInst *MI, unsigned OpNum,
					SStream *O);
void printT2AddrModeSoRegOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printSetendOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printCPSIMod(const MCInst *MI, unsigned OpNum, SStream *O);
void printCPSIFlag(const MCInst *MI, unsigned OpNum, SStream *O);
void printMSRMaskOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printBankedRegOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printPredicateOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printMandatoryPredicateOperand(const MCInst *MI, unsigned OpNum,
				    SStream *O);
void printMandatoryRestrictedPredicateOperand(const MCInst *MI, unsigned OpNum,
					      SStream *O);
void printMandatoryInvertedPredicateOperand(const MCInst *MI, unsigned OpNum,
					    SStream *O);
void printSBitModifierOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printRegisterList(const MCInst *MI, unsigned OpNum, SStream *O);
void printNoHashImmediate(const MCInst *MI, unsigned OpNum, SStream *O);
void printPImmediate(const MCInst *MI, unsigned OpNum, SStream *O);
void printCImmediate(const MCInst *MI, unsigned OpNum, SStream *O);
void printCoprocOptionImm(const MCInst *MI, unsigned OpNum, SStream *O);
void printFPImmOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printVMOVModImmOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printImmPlusOneOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printRotImmOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printModImmOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printGPRPairOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printPCLabel(const MCInst *MI, unsigned OpNum, SStream *O);
void printThumbLdrLabelOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printFBits16(const MCInst *MI, unsigned OpNum, SStream *O);
void printFBits32(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorIndex(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListOne(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwo(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwoSpaced(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListThree(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFour(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListOneAllLanes(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwoAllLanes(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListThreeAllLanes(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFourAllLanes(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListTwoSpacedAllLanes(const MCInst *MI, unsigned OpNum,
				      SStream *O);
void printVectorListThreeSpacedAllLanes(const MCInst *MI, unsigned OpNum,
					SStream *O);
void printVectorListFourSpacedAllLanes(const MCInst *MI, unsigned OpNum,
				       SStream *O);
void printVectorListThreeSpaced(const MCInst *MI, unsigned OpNum, SStream *O);
void printVectorListFourSpaced(const MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printMVEVectorList(NumRegs)                                    \
  void CONCAT(printMVEVectorList, NumRegs)(const MCInst *MI, unsigned OpNum,   \
					   SStream *O);
DECLARE_printMVEVectorList(2) DECLARE_printMVEVectorList(4)

#define DECLARE_printComplexRotationOp(Angle, Remainder)                       \
  void CONCAT(printComplexRotationOp, CONCAT(Angle, Remainder))(               \
      const MCInst *MI, unsigned OpNum, SStream *O);
    DECLARE_printComplexRotationOp(90, 0)
	DECLARE_printComplexRotationOp(180, 90)

    // MVE
    void printVPTPredicateOperand(const MCInst *MI, unsigned OpNum, SStream *O);
void printVPTMask(const MCInst *MI, unsigned OpNum, SStream *O);
#define DECLARE_printMveAddrModeRQOperand(shift)                               \
  void CONCAT(printMveAddrModeRQOperand, shift)(const MCInst *MI,              \
						unsigned OpNum, SStream *O);
DECLARE_printMveAddrModeRQOperand(0) DECLARE_printMveAddrModeRQOperand(3)
    DECLARE_printMveAddrModeRQOperand(1) DECLARE_printMveAddrModeRQOperand(2)

	void printMveSaturateOp(const MCInst *MI, unsigned OpNum, SStream *O);

#endif // CS_ARMINSTPRINTER_H
