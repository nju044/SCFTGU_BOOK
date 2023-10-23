//FILE: stimulus.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See processor.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef STIMULUS_H
#define STIMULUS_H
#include "opcodes.h"
#include "mem_arch.h"
// Module definition
SC_MODULE(stimulus) {
  // Ports
  sc_port<bus_if>   bus_p;
  sc_inout_resolved reset_p;
  sc_out<bool>      abort_p;
  // Constructor declarations
  stimulus(sc_module_name nm);
  // Process declarations
  void stimulus_thread();
  void monitor_method();
  // Helper functions
  void write_instr(
    unsigned opcode, unsigned operand1=0, unsigned operand2=0
  );
  unsigned pc;
};
#endif
//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: processor.h,v 1.4 2004/02/21 21:04:35 dcblack Exp $
