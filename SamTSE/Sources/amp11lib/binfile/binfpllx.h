#ifndef LINUX
#error must compile for LINUX
#endif

#ifndef __LINUXPLAYBINFILE_H
#define __LINUXPLAYBINFILE_H

#include "binfile.h"

class linuxplaybinfile : public binfile
{
protected:
  int wavehnd;
  virtual errstat rawclose();
  virtual binfilepos rawwrite(const void *buf, binfilepos len);

public:
  linuxplaybinfile();
  virtual ~linuxplaybinfile();

  int open(int rate, int stereo, int bit16);
};

#endif
