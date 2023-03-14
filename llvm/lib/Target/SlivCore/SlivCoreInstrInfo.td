//===- SlivCoreInstrInfo.td - Target Description for SlivCore Target -*- tablegen -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the SlivCore implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// SlivCore profiles and nodes
//===----------------------------------------------------------------------===//

def SDT_SlivCoreRet          : SDTypeProfile<0, 1, [SDTCisInt<0>]>;

// Return
def SlivCoreRet : SDNode<"SlivCoreISD::Ret", SDTNone,
                     [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "SlivCoreInstrFormats.td"

//===----------------------------------------------------------------------===//
// SlivCore Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instructions specific format
//===----------------------------------------------------------------------===//

//@Branches {
let isBranch=1, isTerminator=1, isBarrier=1, hasDelaySlot = 1,
    isIndirectBranch = 1 in
class Branches<bits<8> op, string instr_asm, RegisterClass RC>:
  SlivCoreInst<op, (outs), (ins RC:$r1),
     !strconcat(instr_asm, "\t$r1"), [(brind RC:$r1)]> {
}
//@Branches }

// Return instruction
class RetBase<RegisterClass RC>: Branches<0x3c, "RET", RC> {
  let isReturn = 1;
  let isCodeGenOnly = 1;
  let hasCtrlDep = 1;
  let hasExtraSrcRegAllocReq = 1;
}


//===----------------------------------------------------------------------===//
// Instruction definition
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// SlivCore Instructions
//===----------------------------------------------------------------------===//

def RET     : RetBase<CPURegs>;

/// No operation
def NOP   : SlivCoreInst<0, (outs), (ins), "nop", []>;
