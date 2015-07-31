#!/usr/bin/make
all:
	@make -f Makefile-server

QEMU=~/homebrew/bin/qemu-system-i386
M_HOME=~/MatrixOS2
run: all
	@. ~/.profile; $(QEMU) -serial stdio -cdrom  $(M_HOME)/MatrixOS2.iso
