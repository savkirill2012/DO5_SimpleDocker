#!/bin/bash

gcc -o server server.c -lfcgi
spawn-fcgi -p 8080 ./server

service nginx start

while true; do
    sleep 1
done