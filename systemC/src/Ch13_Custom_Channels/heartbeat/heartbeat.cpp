//BEGIN heartbeat.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See heartbeat.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <systemc>
using namespace sc_core;
using std::cout;
using std::endl;
#include "heartbeat.h"

void heartbeat::heartbeat_method(void) {
  cout << "Received a tick at " << sc_time_stamp()<< "." << endl;
}//end heartbeat_PROCESS()

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: heartbeat.cpp,v 1.3 2004/02/02 12:29:38 dcblack Exp $
