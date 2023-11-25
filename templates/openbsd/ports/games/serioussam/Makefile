# The source code also contains definitions for
# architectures riscv64 s390x powerpc64le.
# Building code for them workd.
# Work on real hardware has been 
# tested for architectures: armv7 aaarch64 under Linux

ONLY_FOR_ARCHS =	amd64 i386

GH_ACCOUNT =		tx00100xt
GH_PROJECT =		SeriousSamClassic
GH_TAGNAME =		1.10.6b

COMMENT =		Open source version of game Serious Sam Classic
N=			serioussam
V=			1.10.6b
PKGNAME =		${N}-${V}
DISTNAME =		SeriousSamClassic-${V}
CATEGORIES =		games
REVISION =		1

HOMEPAGE =		https://github.com/tx00100xt/SeriousSamClassic

MAINTAINER =		YOUR NAME <YOUR MAIL>

# GPLv2
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} SDL2 c m z pthread

MODULES =		devel/cmake

COMPILER =		base-clang ports-gcc

CONFIGURE_ARGS +=	-DUSE_SYSTEM_INSTALL=ON

BUILD_DEPENDS =		devel/sdl2 \
			devel/bison \
			audio/libvorbis \
			audio/libogg \
			graphics/ImageMagick

# Libraries loaded with dlopen(3)
LIB_DEPENDS =		devel/sdl2 \
			audio/libvorbis \
			audio/libogg \

NO_TEST =		Yes

# Unocmment this for aarch64 and armv7 architectures
#.if ${MACHINE_ARCH} == aarch64 || ${MACHINE_ARCH} == armv7
#CONFIGURE_ARGS +=	-DRPI4=ON
#.endif

.if ${MACHINE_ARCH} == amd64
CONFIGURE_ARGS +=	-DUSE_ASM=ON
.endif

.if ${MACHINE_ARCH}== i386
CONFIGURE_ARGS +=	-DUSE_ASM=ON -DUSE_I386_NASM_ASM=ON
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/bsd/serioussam.1 ${PREFIX}/man/man1/serioussam.1
	${INSTALL_MAN} ${WRKSRC}/man/bsd/serioussamclassic.1 ${PREFIX}/man/man1/serioussamclassic.1

.include	<bsd.port.mk>
