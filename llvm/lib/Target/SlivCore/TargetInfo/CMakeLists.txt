add_llvm_component_library(LLVMSlivCoreInfo
  SlivCoreTargetInfo.cpp

  LINK_COMPONENTS
  Support

  ADD_TO_COMPONENT
  SlivCore
  )
