//===-- SlivCoreInstrFormats.td - SlivCore Instruction Formats -----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Describe SlivCore instructions format
//
//  CPU INSTRUCTION FORMATS
//
//  FF FF FF FF
//        ^^ ^^ - r3_imm - third reg or imm
//      ^       - r2     - second reg
//     ^        - r1     - first reg
//  ^^          - opcode - operation code
//
//===----------------------------------------------------------------------===//

// Generic SlivCore Format
class SlivCoreInst<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "SlivCore";
  let DecoderNamespace = "SlivCore";
  let Size = 6;

  field bits<48> Inst;

  bits<8> Opcode = op;
  bits<8>  r1 = 0;
  bits<32> r2_imm = 0;

  let Inst{47-40} = Opcode;
  let Inst{39-32} = r1;
  let Inst{31-0}  = r2_imm;

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;

}

// Pseudo instructions format
class SlivCorePseudoInst<dag outs, dag ins, string asmstr, list<dag> pattern>
   : SlivCoreInst<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}
