//FILE:report.cpp (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See report.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "report.h"
extern char* simulation_name;
// Constructor
SC_HAS_PROCESS(report);
report::report(sc_module_name nm) //{{{
: sc_module(nm)
{
  // Process registration
  SC_THREAD(report_thread);
}//endconstructor }}}
// Processes
void report::report_thread() { //{{{
  wait(2,SC_NS);
  SC_REPORT_INFO(simulation_name,"Sample info");
  SC_REPORT_WARNING(simulation_name,"Sample warning");
  SC_REPORT_ERROR(simulation_name,"Sample error");
  SC_REPORT_INFO(simulation_name,"Another info");
  SC_REPORT_ERROR(simulation_name,"Another error");
  SC_REPORT_FATAL(simulation_name,"Sample fatal");
}//endthread report::report_thread}}}
//Portions COPYRIGHT (C) 2004,2007 Eklectic Ally, Inc. DBA ESLX Inc. ----------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: report.cpp,v 1.5 2004/02/22 19:58:20 dcblack Exp $
