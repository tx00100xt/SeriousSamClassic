// binfile - class library for files/streams - linux sound playback
// Copyright (c) 1997-99 Niklas Beisert
// See COPYING (GNU Library General Public License 2) for license

#ifndef LINUX
#error must compile for LINUX
#endif
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>
#include <string.h>
#include <fcntl.h>
#include "binfpllx.h"

int linuxplaybinfile::open(int rate, int stereo, int bit16)
{
  close();

  wavehnd=::open("/dev/dsp", O_WRONLY);
  if (wavehnd<0)
    return -1;
  ::ioctl(wavehnd, SNDCTL_DSP_RESET, 0);
  ::ioctl(wavehnd, SNDCTL_DSP_STEREO, &stereo);
  ::ioctl(wavehnd, SNDCTL_DSP_SPEED, &rate);
  int sample_size=bit16?16:8;
  ::ioctl(wavehnd, SNDCTL_DSP_SAMPLESIZE,&sample_size);
  int fmts=bit16?AFMT_S16_LE:AFMT_U8;
  ::ioctl(wavehnd, SNDCTL_DSP_SETFMT, &fmts);

  openmode(modewrite,0,0);
  return 0;
}

errstat linuxplaybinfile::rawclose()
{
  closemode();
  ::close(wavehnd);
  return 0;
}

binfilepos linuxplaybinfile::rawwrite(const void *buf, binfilepos len)
{
  return ::write(wavehnd, buf, len);
}

linuxplaybinfile::linuxplaybinfile()
{
}

linuxplaybinfile::~linuxplaybinfile()
{
  close();
}
