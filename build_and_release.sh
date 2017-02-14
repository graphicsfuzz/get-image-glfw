#!/bin/bash
set -x
set -e
set -u

rm -rf out/build_release || true

mkdir -p out/build_release/Linux/bin/
pushd build
./build-linux
popd
cp out/linux/install/bin/* out/build_release/Linux/bin/

mkdir -p out/build_release/Windows/bin/
pushd build
./build-x86_64-w64-mingw32
popd
cp out/x86_64-w64-mingw32/install/bin/* out/build_release/Windows/bin/

cp simple.frag out/build_release/

cd out/build_release
zip -r ../get-image-glfw.zip *
cd ..

github-release \
  paulthomson/get-image-glfw \
  v-${CI_BUILD_REF} \
  ${CI_BUILD_REF} \
  "$(echo -e "Automated build.\n$(git log --graph -n 3 --abbrev-commit --pretty='format:%h - %s <%an>')")" \
  'get-image-glfw.zip'

