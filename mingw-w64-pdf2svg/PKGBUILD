# This is an example PKGBUILD file. Use this as a start to creating your own,
# and remove these comments. For more information, see 'man PKGBUILD'.
# NOTE: Please fill out the license field for your package! If it is unknown,
# then please put 'unknown'.

# Maintainer: Yusuke Sasaki <y_sasaki@nuem.nagoya-u.ac.jp>

_realname=pdf2svg
pkgbase="mingw-w64-${_realname}"
pkgname="${MINGW_PACKAGE_PREFIX}-${_realname}"
pkgver=0.2.3
pkgrel=1
pkgdesc="A simple PDF to SVG converter using the Poppler and Cairo libraries"
arch=('any')
url="https://github.com/db9052/pdf2svg"
license=('GPL')
makedepends=("make"
             "${MINGW_PACKAGE_PREFIX}-gcc")
depends=("${MINGW_PACKAGE_PREFIX}-poppler"
         "${MINGW_PACKAGE_PREFIX}-cairo")
source=(
  "https://github.com/db9052/pdf2svg/archive/v0.2.3.tar.gz"
)
md5sums=(SKIP)

build() {
  cd "${srcdir}/pdf2svg-$pkgver"
  ./configure --prefix=${MINGW_PREFIX}
  make
}

package() {
  cd "${srcdir}/pdf2svg-$pkgver"
  make DESTDIR="$pkgdir/" install
}

# vim: set ft=sh ts=2 sw=2 et :
