// binfile - class library for files/streams - WAV format writer
// Copyright (c) 1997-99 Niklas Beisert
// See COPYING (GNU Library General Public License 2) for license

#include "binfplwv.h"

int wavplaybinfile::open(binfile &f, int rate, int stereo, int bit16, int len)
{
  close();

  file=&f;
  file->write("RIFF", 4);
  putil4(*file, len+38);
  file->write("WAVE", 4);
  file->write("fmt ", 4);
  putil4(*file, 18);
  putil2(*file, 1);
  putil2(*file, stereo?2:1);
  putil4(*file, rate);
  putil4(*file, rate*(stereo?2:1)*(bit16?2:1));
  putil2(*file, (stereo?2:1)*(bit16?2:1));
  putil2(*file, bit16?16:8);
  putil2(*file, 0);
  file->write("data", 4);
  putil4(*file, len);

  openmode(modewrite,0,0);
  return 0;
}

errstat wavplaybinfile::rawclose()
{
  if (file->getmode()&modeseek)
  {
    file->seek(4);
    putil4(*file, file->length()-8);
    file->seek(42);
    putil4(*file, file->length()-46);
  }

  closemode();
  return 0;
}

binfilepos wavplaybinfile::rawwrite(const void *buf, binfilepos len)
{
  return file->write(buf, len);
}

wavplaybinfile::wavplaybinfile()
{
}

wavplaybinfile::~wavplaybinfile()
{
  close();
}
