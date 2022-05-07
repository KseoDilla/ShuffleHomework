#!/bin/bash

export SSH_PUB_KEY_PLACEHOLDER="$(cat ~/.ssh/id_rsa.pub)"
docker-compose up

#need to modify the SSH agent docker image to have git and docker installed
#need to automate the skip of installation wizard
#need to automate the addition of a node
