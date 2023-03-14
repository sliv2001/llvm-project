add_llvm_component_group(SlivCore)

set(LLVM_TARGET_DEFINITIONS SlivCore.td)

tablegen(LLVM SlivCoreGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM SlivCoreGenInstrInfo.inc -gen-instr-info)

add_public_tablegen_target(SlivCoreCommonTableGen)

add_llvm_target(SlivCoreCodeGen
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
