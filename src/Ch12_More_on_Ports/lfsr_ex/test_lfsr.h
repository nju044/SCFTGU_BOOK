#ifndef TEST_LFSR_H
#define TEST_LFSR_H
//BEGIN test_lfsr.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// See test_lfsr.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <systemc>

SC_MODULE(test_lfsr) {
  // Ports
  sc_out<bool> sample;
  sc_in<sc_uint<32> > signature;
  sc_in<bool> clock;
  sc_out<bool> reset;
  // Constructor
  SC_CTOR(test_lfsr) {
    SC_THREAD(test_lfsr_thread);
    sensitive << clock.pos();
  }
  void test_lfsr_thread();
private:
  void do_reset();
};

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: test_lfsr.h,v 1.1 2004/02/09 13:02:13 dcblack Exp $
