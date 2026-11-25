#!/usr/bin/env bash

PORT=1337

echo "listening on $PORT"
nc -lk -p $PORT
