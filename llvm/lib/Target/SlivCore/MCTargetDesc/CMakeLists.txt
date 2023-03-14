add_llvm_component_library(LLVMSlivCoreDesc
  SlivCoreMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  SlivCoreInfo
  Support

  ADD_TO_COMPONENT
  SlivCore
  )
