//===-- SlivCoreTargetMachine.cpp - Define TargetMachine for SlivCore -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about SlivCore target spec.
//
//===----------------------------------------------------------------------===//

#include "SlivCore.h"
#include "SlivCoreTargetMachine.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/Attributes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

#define DEBUG_TYPE "SlivCore"

extern "C" void LLVMInitializeSlivCoreTarget() {
	RegisterTargetMachine<SlivCoreTargetMachine> X(getTheSlivCoreTarget());
}

static Reloc::Model getRelocModel(Optional<Reloc::Model> RM) {
  return RM.getValueOr(Reloc::Static);
}

/// SlivCoreTargetMachine ctor - Create an ILP32 Architecture model
SlivCoreTargetMachine::SlivCoreTargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     Optional<Reloc::Model> RM,
                                     Optional<CodeModel::Model> CM,
                                     CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T,
                        "E-m:e-p:32:32-i1:32:32-i8:32:32-i16:32:32-i32:32:32-"
                        "f32:32:32-i64:32-f64:32-a:0:32-n32",
                        TT, CPU, FS, Options, getRelocModel(RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  initAsmInfo();
}
//Big endian
//All datas are 32 bit

SlivCoreTargetMachine::~SlivCoreTargetMachine() = default;

namespace {

/// SlivCore Code Generator Pass Configuration Options.
class SlivCorePassConfig : public TargetPassConfig {
public:
  SlivCorePassConfig(SlivCoreTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  SlivCoreTargetMachine &getSlivCoreTargetMachine() const {
    return getTM<SlivCoreTargetMachine>();
  }

  bool addInstSelector() override;
  //void addPreEmitPass() override;
  //void addPreRegAlloc() override;
};

}

TargetPassConfig *SlivCoreTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new SlivCorePassConfig(*this, PM);
}

bool SlivCorePassConfig::addInstSelector() {
  addPass(createSlivCoreISelDag(getSlivCoreTargetMachine(), getOptLevel()));
  return false;
}

//void SlivCorePassConfig::addPreEmitPass() { llvm_unreachable("preEmitPass added which is not implemented"); }
//
//void SlivCorePassConfig::addPreRegAlloc() { llvm_unreachable("addPreRegAlloc added which is not implemented"); }

#if 0
TargetTransformInfo SlivCoreTargetMachine::getTargetTransformInfo(const Function &F) {
	llvm_unreachable("Called some wierd function");
	return TargetTransformInfo(SlivCoreTTIImpl(this, F));
}
#endif
