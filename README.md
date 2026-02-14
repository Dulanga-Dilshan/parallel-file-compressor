# Multithreaded File Compression Tool in C

A systems-level file compression project written in C, designed to
support multiple compression algorithms within a multithreaded
architecture.

⚠️ **Project Status: Work in Progress**

This repository represents an active development stage of the compressor
and is being incrementally built as part of my low-level systems
programming practice.

------------------------------------------------------------------------

## Architecture Goal

The long-term goal is to build a modular compression framework that:

-   Supports multiple compression algorithms
-   Uses a multithreaded processing pipeline
-   Allows algorithm selection via CLI
-   Enables performance benchmarking between implementations

------------------------------------------------------------------------

## Current Implementation

-   File reading
-   Frequency table generation
-   Huffman tree construction
-   Core data structures implemented manually in C

Currently, **Huffman coding is the only implemented algorithm**.

------------------------------------------------------------------------

## In Progress

-   Multithreaded file reading using `pthread`
-   Parallel frequency aggregation
-   Designing algorithm abstraction layer

------------------------------------------------------------------------

## Planned Algorithms

-   Optimized Huffman encoding + decoding
-   Custom compression algorithm (research phase)
-   Experimental transform-based approaches
-   Pluggable algorithm interface design

------------------------------------------------------------------------

## Planned Features

-   Bit-level encoding of compressed output
-   Custom binary file format
-   Decompression support
-   Performance benchmarking
-   Memory profiling and optimization
-   Eventually replacing external libraries with custom implementations

------------------------------------------------------------------------

## Build

``` bash
make
```

------------------------------------------------------------------------

## Purpose

This project is part of my systems programming portfolio, focusing on:

-   Manual memory management
-   Thread synchronization and parallel design
-   Efficient file I/O
-   Data structure implementation from scratch
-   Algorithm experimentation and design
-   Performance-oriented programming in C
