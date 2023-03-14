//===-- SlivCore.h - Top-level interface for SlivCore representation ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM SlivCore back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_SlivCore_SlivCore_H
#define LLVM_LIB_TARGET_SlivCore_SlivCore_H

#include "MCTargetDesc/SlivCoreMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class SlivCoreTargetMachine;
  class FunctionPass;

} // end namespace llvm;

#endif
