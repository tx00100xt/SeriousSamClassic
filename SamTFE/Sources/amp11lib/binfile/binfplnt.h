#ifndef WIN32
#error must compile for NT
#endif

#ifndef __NTPLAYBINFILE_H
#define __NTPLAYFILEPLAY_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <mmsystem.h>
#include "binfile.h"

class ntplaybinfile : public binfile
{
protected:
  HWAVEOUT wavehnd;
  int blklen;
  int nblk;
  WAVEHDR *hdrs;
  char *playbuf;
  int curbuf;
  int curbuflen;
  int linger;
  int blocking;

  virtual errstat rawclose();
  virtual binfilepos rawwrite(const void *buf, binfilepos len);
  virtual binfilepos rawioctl(intm code, void *buf, binfilepos len);

public:
  ntplaybinfile();
  virtual ~ntplaybinfile();

  // get descriptive name of a wave device
  static int getdevicename(int device, char *namebuffer, int bufferlen);

  int open(int rate, int stereo, int bit16, int blen, int nb, int device=-1);
};

#endif
