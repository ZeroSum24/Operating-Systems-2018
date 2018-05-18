# Operating-Systems-2018

The goal of the Operating Systems practical coursework was to implement important functionality
in an existing research operating system called InfOS. This coursework involved programming in C++. For each task, I implemented a piece of core operating system functionality which was loaded into the InfOS kernel.

This coursework was split into three main tasks:
* Task 1: Implement a process scheduler. 
* Task 2: Implement a page-based memory allocator. 
* Task 3: Implement a file-system driver. 

InfOS is the research operating system that is the subject of this coursework. It has been developed specifically for this course. It is a 64-bit x86 operating that has been written from scratch in C++, and is not based on any other particular OS.
InfOS is structured as a monolithic kernel, similar to Linux, but as it is written in C++, it employs object-oriented principles in its implementation. It is not a Unix-like system, and does not subscribe to the POSIX standards. It is modular in the sense that functionality can be plugged in/out at compile time, but does not currently support dynamically loadable kernel
modules.

