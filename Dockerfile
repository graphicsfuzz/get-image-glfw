FROM ubuntu:14.04

RUN \
  apt-get update && \
  apt-get -y install \
    gcc-mingw-w64 \
    g++ libxrandr-dev libxinerama-dev libxcursor-dev libgl1-mesa-dev \
    cmake \
    zip git golang && \
  apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

ENV \
  GOPATH=/data/gopath \
  PATH=/data/gopath/bin:${PATH}

COPY . /data

WORKDIR /data

RUN \
  mkdir -p ${GOPATH} && \
  go get github.com/c4milo/github-release

CMD ["./build_and_release.sh"]
#CMD ["bash"]

