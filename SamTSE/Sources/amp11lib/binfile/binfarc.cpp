// binfile - class library for files/streams - archive files
// Copyright (c) 1997-99 Niklas Beisert
// See COPYING (GNU Library General Public License 2) for license

#include "binfarc.h"

abinfile::abinfile()
{
}

abinfile::~abinfile()
{
  close();
}

errstat abinfile::open(binfile &fil, binfilepos ofs, binfilepos len)
{
  close();
  int fmode=fil.getmode()&~modeappend;
  if (!fmode)
    return -1;
  f=&fil;
  if (!(fmode&modeseek))
  {
    fmode&=~modewrite;
    if (!(fmode&moderead)||(ofs!=f->ioctl(f->ioctlrtell)))
      return -1;
  }
  else
  {
    fofs=ofs;
    long l=f->length();
    if (fofs>l)
      fofs=l;
    if ((fofs+len)>l)
      len=l-fofs;
  }
  rawpos=0;
  rawlen=len;
  openmode(fmode, rawpos, rawlen);
  return 0;
}

binfilepos abinfile::rawread(void *buf, binfilepos len)
{
  if ((rawpos+len)>rawlen)
    len=rawlen-rawpos;
  if (mode&modeseek)
    f->seek(fofs+rawpos);
  len=f->read(buf, len);
  rawpos+=len;
  return len;
}

binfilepos abinfile::rawpeek(void *buf, binfilepos len)
{
  if ((rawpos+len)>rawlen)
    len=rawlen-rawpos;
  len=f->peek(buf, len);
  return len;
}

binfilepos abinfile::rawwrite(const void *buf, binfilepos len)
{
  if ((rawpos+len)>rawlen)
    len=rawlen-rawpos;
  f->seek(fofs+rawpos);
  len=f->write(buf, len);
  rawpos+=len;
  return len;
}

binfilepos abinfile::rawseek(binfilepos pos)
{
  rawpos=(pos>rawlen)?rawlen:pos;
  return rawpos;
}
