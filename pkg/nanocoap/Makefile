PKG_NAME=nanocoap
PKG_URL=https://github.com/Ell-i/sock.git
PKG_VERSION=feature-nanocoap-add-resource-to-handler
PKG_LICENSE=LGPL-2.1

.PHONY: all

all: git-download
	@cp Makefile.nanocoap $(PKG_BUILDDIR)/nanocoap/Makefile
	"$(MAKE)" -C $(PKG_BUILDDIR)/nanocoap

include $(RIOTBASE)/pkg/pkg.mk
