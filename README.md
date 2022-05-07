# Homework2022: ShuffleDeck

## Completion List
- [X] Write ShuffleDeck Program
- [X] Write a unit test for ShuffleDeck Program
- [X] Write a makefile for easier compilation and linking
- [X] Write a multi-stage dockerfile - one stage for building and the other stage for the docker app
- [X] Populate README.md
- [X] Write a Jenkinsfile


## Preqrequistes
1. Linux Distro
2. Install Docker
```
Ubuntu: sudo apt-get install docker
Mac: brew cask install docker
```
> Disclaimer: I have not had the opportunity to develop on a Mac yet (my M1 16" is still being ordered)

## How to build the executable:
Build the docker image, which will also build the project for you
```
docker build . -f  docker/Dockerfile --tag shuffle-service
```

## How to run the docker app:
```
docker run -it shuffle-service
```

## How to compile and debug the program:
1. You can enter the build environment. You can use the previous multi stage that was left behind or just tag a new one
```
docker build . -f docker/Dockerfile --target shuffle-buildenv --tag buildenv
docker run -it -u $(id -u):$(id -g) -w ${PWD}:${PWD} -v ${PWD} shuffle-buildenv /bin/bash
```

2. You can compile the project when you're inside the build environment
```
make clean
make -j8
make exec #this will run the binary for you
```
> Running make's default target will run two targets (shuffle and test)
3. You can also run the targets individually
```
make shuffle
make test
```
4. There is also a target for generating coverage
```
make coverage
```

## Improvements that could be made
- [ ] Fix code coverage (sometimes it shows 0% for src)
- [ ] Deliver a local Jenkins
- [ ] Add a documenting tool
- [ ] Fix makefile to create object files so they can be linked to unit tests
