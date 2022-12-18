#ifndef __BINFHTTP_H
#define __BINFHTTP_H

#include "binftcp.h"

class httpbinfile : public binfile
{
private:
  tcpbinfile file;

public:
  httpbinfile();
  virtual ~httpbinfile();

  errstat open(const char *addr, const char *proxy, binfilepos off, binfilepos len);
};

#endif
