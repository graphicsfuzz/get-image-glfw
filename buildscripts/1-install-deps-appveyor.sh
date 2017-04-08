#!/bin/bash
set -x
set -e
set -u

mkdir temp
cd temp

curl -fsSL -o github-release.tar.gz https://github.com/paulthomson/github-release/releases/download/v1.0.9.1/github-release_v1.0.9.1_windows_amd64.tar.gz

7z x github-release.tar.gz
7z x github-release.tar
cd ..


