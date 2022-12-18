#ifndef DOS
#error must compile for DOS4G or DJGPP
#endif

#ifndef __SBPLAYBINFILE_H
#define __SBPLAYBINFILE_H

#include "binfile.h"

class sbplaybinfile : public binfile
{
protected:
  virtual errstat rawclose();
  virtual binfilepos rawwrite(const void *buf, binfilepos len);

public:
  sbplaybinfile();
  virtual ~sbplaybinfile();

  int open(int rate, int stereo, int bit16, int buflen);
};

#endif
