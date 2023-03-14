//===-- SlivCore.td - Describe the SlivCore Target Machine ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This is the top level entry point for the SlivCore target.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Target-independent interfaces
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Target-dependent interfaces
//===----------------------------------------------------------------------===//

include "SlivCoreRegisterInfo.td"

//===----------------------------------------------------------------------===//
// Calling Conv, Instruction Descriptions
//===----------------------------------------------------------------------===//

include "SlivCoreInstrInfo.td"
def SlivCoreInstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// SlivCore processors supported.
//===----------------------------------------------------------------------===//

// Will generate SlivCoreGenAsmWrite.inc included by SlivCoreInstPrinter.cpp, contents
//  as follows,
// void SlivCoreInstPrinter::printInstruction(const MCInst *MI, raw_ostream &O) {...}
// const char *SlivCoreInstPrinter::getRegisterName(unsigned RegNo) {...}
def SlivCore : Target {
  let InstructionSet = SlivCoreInstrInfo;
}
