PKG_NAME=nanocoap
PKG_URL=https://github.com/Ell-i/sock.git
PKG_VERSION=fa4569a2aaf825ffdc97cebc34026e50a119d5b3
PKG_LICENSE=LGPL-2.1

.PHONY: all

all: git-download
	@cp Makefile.nanocoap $(PKG_BUILDDIR)/nanocoap/Makefile
	"$(MAKE)" -C $(PKG_BUILDDIR)/nanocoap

include $(RIOTBASE)/pkg/pkg.mk
