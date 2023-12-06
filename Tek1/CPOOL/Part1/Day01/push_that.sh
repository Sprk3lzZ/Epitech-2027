#!/bin/bash

git add *
if [ "$#" -ne 1 ];
    then git commit -am "commit message by default"
else
    git commit -m "$1"
fi
git push
