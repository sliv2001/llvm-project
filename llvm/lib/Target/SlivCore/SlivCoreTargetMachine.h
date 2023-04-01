/*
 * SlivCoreTargetMachine.h
 *
 *  Created on: 1 апр. 2023 г.
 *      Author: ivans
 */

#ifndef SLIVCORETARGETMACHINE_H_
#define SLIVCORETARGETMACHINE_H_

#include "SlivCoreInstrInfo.h"
#include "SlivCoreSubtarget.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class SlivCoreTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  SlivCoreSubtarget Subtarget;
  // mutable StringMap<std::unique_ptr<SlivCoreSubtarget>> SubtargetMap;

public:
  SlivCoreTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                    CodeGenOpt::Level OL, bool JIT);
  ~SlivCoreTargetMachine() override;

  const SlivCoreSubtarget *getSubtargetImpl() const { return &Subtarget; }
  const SlivCoreSubtarget *getSubtargetImpl(const Function &) const override {
    return &Subtarget;
  }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }

#if 0
  bool
  addPassesToEmitFile(PassManagerBase &, raw_pwrite_stream &,
                      raw_pwrite_stream *, CodeGenFileType,
                      bool /*DisableVerify*/ = true,
                      MachineModuleInfoWrapperPass *MMIWP = nullptr) override {
    return false;
  }
#endif
  // TargetTransformInfo getTargetTransformInfo(const Function &F) override;
};
} // end namespace llvm



#endif /* SLIVCORETARGETMACHINE_H_ */
