//===-- SlivCoreTargetInfo.cpp - SlivCore Target Implementation -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "SlivCore.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target llvm::TheSlivCoreTarget;

extern "C" void LLVMInitializeSlivCoreTargetInfo() {
  RegisterTarget<llvm::Triple::SlivCore,
                 /*HasJIT=*/false>
      X(TheSlivCoreTarget, "SlivCore", "SlivCore (32-bit Yet another special arch by Ivan Sladkov)", "SlivCore");
}
