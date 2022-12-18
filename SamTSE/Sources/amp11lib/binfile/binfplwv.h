#ifndef __WAVPLAYBINFILE_H
#define __WAVPLAYBINFILE_H

#include "binfile.h"

class wavplaybinfile : public binfile
{
protected:
  binfile *file;
  virtual errstat rawclose();
  virtual binfilepos rawwrite(const void *buf, binfilepos len);

public:
  wavplaybinfile();
  virtual ~wavplaybinfile();

  int open(binfile &f, int rate, int stereo, int bit16, int len);
};

#endif
