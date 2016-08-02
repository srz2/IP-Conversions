IP Conversions
==============

## Introduction

IP Conversions is a simple utility to convert IP Addresses, network decimals, and host decimals to each other. I created this
program as a tool to help me teach myself how to convert everything to different types. I personally only needed two of the six
conversions but found it helpful to implement the rest in order to drill the concepts.

To get started, build the app with "make" and then run the application "make run" to get to the menu seleciton
Play with the different options and see what values are generated and reference the source code to understand
the procedure to convert different values from one to another

The premise of this values and their conversions come into play with networking and working with network sockets
and understanding the conversions will help to to understand how to best give functionality to your user

## Concepts

### Big/Little Endian

The concept of [endianness](https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Data/endian.html) is overlooked in programming nowadays but in certain concepts of computer science and engineering, it is important to understand.

When it comes to networking, especially on a low level, it is very important to understand. I would recommended researching
about it if you are interested in it (see the link above), but basically it is the ordering of bits. For different architectures
across networks or even processor types, big or little endian can be used. If you communicate with several different platforms
you must understand if your endianness changes, otherwise your applications can fail.

### Networking

The main aspect of this program is dealing with networking and converting between different types and endians. The endianness
of sending something to the network (i.e. through socket) can be different than the host computer and the application running on it.

To help with conversions there are special functions to help us:

`struct sockaddr_in` and `struct in_addr` are structures which hold network information; `in_addr` is contained within `sockaddr_in`.

`inet_pton()` is a function which puts and ascii formatted address ("192.168.0.1") into a binary form. The third argument I use for this function includes its binary or decimal form inside of the `struct sockaddr_in`.

Two other functions which are important are `htonl()` and `ntohl()` functions. The first function converts an unsigned 32-bit number from the hosted endiann to a 32-bit network based endian. The second does the same thing but in reverse, network endian to host endian.

## Build Commands

	This project has several commands to allow the user to run the software of the project.

### make
	
	Makes the project and an executable called 'ip-conversions'

### make clean
	
	Removes the executable file

### make run

	Runs the executable file

### make help

	Displays the introduction along with the features which are able to be performed
