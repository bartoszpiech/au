#!/bin/sh

CC=gcc
CFLAGS="-Wall -pedantic -std=c11 -g"
INC=au.c
OBJ=au.o
SRC=au_tests.c
BIN=tests

$CC $CFLAGS -c $INC -o $OBJ

$CC $CFLAGS $SRC $OBJ -o $BIN
