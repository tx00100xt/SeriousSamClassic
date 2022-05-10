#ifndef __BINFSTD_H
#define __BINFSTD_H

#include "binfile.h"

class sbinfile : public binfile
{
private:
#ifndef NOUNISTD
  intm handle;
  boolm trunc;
#else
  FILE *file;
#endif

protected:
  virtual errstat rawclose();
  virtual binfilepos rawread(void *buf, binfilepos len);
  virtual binfilepos rawpeek(void *buf, binfilepos len);
  virtual binfilepos rawwrite(const void *buf, binfilepos len);
  virtual binfilepos rawseek(binfilepos pos);
  virtual binfilepos rawioctl(intm code, void *buf, binfilepos len);

public:
  sbinfile();
  virtual ~sbinfile();

  enum
  {
    openis=0, openos=1, openro=2, openrw=3,
    openex=0, opencr=4, opentr=8, opencn=12,
    openiomode=3,
    opencrmode=12,
  };
  errstat open(const char *name, intm type);
};

#endif
