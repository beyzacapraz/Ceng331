# Ceng331
Introduction to computer organization, data and information representation and processing, machine-level representation of programs, instruction set architecture, pipelining, optimization program performance, memory hierarchy, cache memories, virtual memory.

# Attack Lab
This assignment involves generating a total of four attacks, code injection attacks and return-oriented programming, on two programs having different security vulnerabilities.

-- Target Files --
ctarget: An executable program vulnerable to code-injection attacks
rtarget: An executable program vulnerable to return-oriented-programming attacks
cookie.txt: An 8-digit hex code that you will use as a unique identifier in your attacks.
farm.c: The source code of your target’s “gadget farm,” which you will use in generating return-oriented programming attacks.
hex2raw: A utility to generate attack strings.

Outcomes you will gain from this lab include:
• I learned different ways that attackers can exploit security vulnerabilities when programs do not safeguard
themselves well enough against buffer overflows.
• Through this, I got a better understanding of how to write programs that are more secure, as well as
some of the features provided by compilers and operating systems to make programs less vulnerable.
• I gained a deeper understanding of the stack and parameter-passing mechanisms of x86-64 machine code.
• I gained a deeper understanding of how x86-64 instructions are encoded.
• I gained more experience with debugging tools such as GDB and OBJDUMP.

# Architecture Lab

In this lab, I learned about the design and implementation of a pipelined Y86-64 processor, optimizing both it and
a benchmark program to maximize performance.  When I completed the lab, I had a keen appreciation for the interactions
between code and hardware that affect the performance of the programs.
The lab is organized into three parts, each with its own handin. In Part A I wrote some simple Y86-64 programs
and become familiar with the Y86-64 tools. In Part B, I extended the SEQ simulator with a new instruction. These
two parts prepared me for Part C  I optimized the Y86-64 benchmark program and the processor design.

# Performance Lab

This assignment deals with optimizing memory intensive code. Image processing and matrix operations offer many
examples of functions that can benefit from optimization. My objective in this homework is to optimize  Batched Matrix
Multiplication and Point Reflection functions as much as possible.

