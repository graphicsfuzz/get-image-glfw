#!/bin/sh
set -e
set -x
set -u

IMAGE=get-image-glfw-image
CONTAINER=get-image-glfw-container

docker build -t ${IMAGE} .

docker stop ${CONTAINER} || true
docker rm ${CONTAINER} || true

docker create -e CI_BUILD_REF -e GITHUB_TOKEN -ti --name ${CONTAINER} ${IMAGE}
docker start -a ${CONTAINER} | cat

