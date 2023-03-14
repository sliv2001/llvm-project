//===-- SlivCoreMCTargetDesc.h - SlivCore Target Descriptions -----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides SlivCore specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_SlivCore_MCTARGETDESC_SlivCoreMCTARGETDESC_H
#define LLVM_LIB_TARGET_SlivCore_MCTARGETDESC_SlivCoreMCTARGETDESC_H

#include "llvm/Support/DataTypes.h"

#include <memory>

namespace llvm {
class Target;
class Triple;

extern Target TheSlivCoreTarget;

} // End llvm namespace

// Defines symbolic names for SlivCore registers.  This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "SlivCoreGenRegisterInfo.inc"

// Defines symbolic names for the SlivCore instructions.
#define GET_INSTRINFO_ENUM
#include "SlivCoreGenInstrInfo.inc"

#endif
