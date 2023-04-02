add_llvm_component_group(SlivCore)

set(LLVM_TARGET_DEFINITIONS SlivCore.td)

tablegen(LLVM SlivCoreGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM SlivCoreGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM SlivCoreGenCallingConv.inc -gen-callingconv)
tablegen(LLVM SlivCoreGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM SlivCoreGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM SlivCoreGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM SlivCoreGenDAGISel.inc -gen-dag-isel)

add_public_tablegen_target(SlivCoreCommonTableGen)

add_llvm_target(SlivCoreCodeGen
  SlivCoreAsmPrinter.cpp
  SlivCoreInstrInfo.cpp
  SlivCoreISelDagToDag.cpp
  SlivCoreISelLowering.cpp
  SlivCoreRegisterInfo.cpp
  SlivCoreTargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  Core
  MC
  SlivCoreDesc
  SlivCoreInfo
  SelectionDAG
  Support
  Target
  GlobalISel

  ADD_TO_COMPONENT
  SlivCore
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
