#ifndef __BINFARC_H
#define __BINFARC_H

#include "binfile.h"

class abinfile : public binfile
{
protected:
  binfile *f;
  binfilepos fofs;
  binfilepos rawpos;
  binfilepos rawlen;

  virtual binfilepos rawread(void *buf, binfilepos len);
  virtual binfilepos rawpeek(void *buf, binfilepos len);
  virtual binfilepos rawwrite(const void *buf, binfilepos len);
  virtual binfilepos rawseek(binfilepos pos);

public:
  abinfile();
  virtual ~abinfile();

  int open(binfile &fil, binfilepos ofs, binfilepos len);
};

#endif
