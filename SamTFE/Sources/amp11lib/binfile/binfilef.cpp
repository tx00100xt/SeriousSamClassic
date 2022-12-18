// binfile - class library for files/streams - float functions
// Copyright (c) 1997-99 Niklas Beisert
// See COPYING (GNU Library General Public License 2) for license

#include "binfile.h"

floatmax getf4(binfile &f) { float874 v; if (f.eread(&v,4)) return v; else return 0; }
floatmax getf8(binfile &f) { float878 v; if (f.eread(&v,8)) return v; else return 0; }
floatmax getf10(binfile &f) { float8710 v; if (f.eread(&v,10)) return v; else return 0; }
boolm putf4(binfile &f, floatmax v) { float874 v2=v; return f.ewrite(&v2, 4); }
boolm putf8(binfile &f, floatmax v) { float878 v2=v; return f.ewrite(&v2, 8); }
boolm putf10(binfile &f, floatmax v) { float8710 v2=v; return f.ewrite(&v2, 10); }
