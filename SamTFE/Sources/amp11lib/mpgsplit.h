#include "binfile.h"

class mpegsplitstream : public binfile
{
private:
  binfile *file;
  int sub;
  int left;
  int end;
  int scanall;

  int nextblock();

protected:
  virtual errstat rawclose();
  virtual binfilepos rawread(void *buf, binfilepos len);
  virtual binfilepos rawpeek(void *buf, binfilepos len);
  virtual binfilepos rawioctl(intm code, void *buf, binfilepos len);

public:
  mpegsplitstream();
  virtual ~mpegsplitstream();

  errstat open(binfile &f, int n, int scanall);
};
