#ifndef MEM_ARCH_H
#define MEM_ARCH_H
//BEGIN: mem_arch.h (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See hier_chan.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "bus_if.h"

extern unsigned errors;

struct mem_arch: public sc_channel, bus_if {
  // Constructors & destructor
  explicit mem_arch(sc_module_name nm,
               unsigned ba, unsigned sz) 
  : sc_channel(nm), m_base(ba), m_size(sz)
  { m_mem = new unsigned[m_size]; }
  ~mem_arch() { delete [] m_mem; }
  // Interface implementations
  void write(unsigned addr, unsigned data) {
    if (m_base <= addr && addr < m_base+m_size) {
      m_mem[addr-m_base] = data;
    }
  }
  unsigned read(unsigned addr) {
    if (m_base <= addr && addr < m_base+m_size) {
      return m_mem[addr-m_base];
    } else {
      cout << "ERROR:"<<name()<<"@"<<sc_time_stamp()
           << ": Illegal address: " << addr << endl;
      errors++;
      //sc_stop();
      return 0L;
    }
  }
private:
  unsigned   m_base;
  unsigned   m_size;
  unsigned*  m_mem;
  mem_arch(const mem_arch&); // Disable
};
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: mem_arch.h,v 1.1 2004/02/22 19:50:50 dcblack Exp $
