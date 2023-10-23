//FILE:ea_heartport.h (systemc)
//# vim600:sw=2:tw=0:fdm=marker
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See processor.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef EA_HEARTPORT_H
#define EA_HEARTPORT_H
#include "ea_heartbeat_if.h"
struct ea_heartport: public sc_port<ea_heartbeat_if,1> {
  sc_event_finder& pos() const {
      return *new sc_event_finder_t<ea_heartbeat_if>(
          *this, &ea_heartbeat_if::posedge_event
      );
  }//end pos()
};
#endif

//Portions COPYRIGHT (C) 2004 Eklectic Ally, Inc.------------------{{{//
// Permission granted for anybody to use this template provided this  //
// acknowledgement of Eklectic Ally, Inc. remains.                    //
//-----------------------------------------------------------------}}}//
//END $Id: ea_heartport.h,v 1.0 2004/39/21 20:39:04 dcblack Exp $

