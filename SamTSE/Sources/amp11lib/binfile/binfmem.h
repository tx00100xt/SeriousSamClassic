#ifndef __BINFMEM_H
#define __BINFMEM_H

#include "binfile.h"

class mbinfile : public binfile
{
private:
  uint1 *filebuf;

  binfilepos *flen;
  void **fbuf;
  binfilepos rawlen;
  binfilepos rawpos;
  binfilepos fbuflen;
  intm fleninc;
  boolm freemem;
  binfilepos chsize(binfilepos);
  boolm trunc;

protected:
  virtual errstat rawclose();
  virtual binfilepos rawread(void *buf, binfilepos len);
  virtual binfilepos rawpeek(void *buf, binfilepos len);
  virtual binfilepos rawwrite(const void *buf, binfilepos len);
  virtual binfilepos rawseek(binfilepos pos);
  virtual binfilepos rawioctl(intm code, void *buf, binfilepos len);

public:
  mbinfile();
  virtual ~mbinfile();

  enum { openro=0, openrw=1, openfree=2 };

  errstat open(void *buf, binfilepos len, intm type);
  errstat opencs(void *&buf, binfilepos &len, intm inc);
};

#endif
