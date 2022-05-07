########################
#### BUILDENV STAGE ####
########################

FROM alpine:3.14 as shuffle-buildenv
RUN apk add --no-cache \
    bash=5.1.16-r0 \
    gcc=10.3.1_git20210424-r2 \
    gcovr=4.2-r4 \
    gtest=1.11.0-r0 \
    gtest-dev=1.11.0-r0 \
    g++=10.3.1_git20210424-r2 \
    make=4.3-r0 \
    musl-dev=1.2.2-r3

WORKDIR /tmp/homework
COPY . /tmp/homework
RUN make -j8 && \
    cp /tmp/homework/bin/shuffle /tmp/shuffle && \
    rm -rf /tmp/homework

#########################
## Install shuffle ###
#########################
FROM alpine:3.14 as shuffle-service
COPY --from=shuffle-buildenv /tmp/shuffle /usr/local/bin
RUN apk add --no-cache \
  bash=5.1.16-r0 \
  gcc=10.3.1_git20210424-r2 \
  g++=10.3.1_git20210424-r2 \
  musl-dev=1.2.2-r3


USER root 
ENTRYPOINT ["/usr/local/bin/shuffle"]
