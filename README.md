***gBolt***
==============

[![Build Status](https://travis-ci.org/Jokeren/gBolt.svg?branch=gbolt-1.0)](https://travis-ci.org/Jokeren/gBolt)
<a href="https://github.com/Jokeren/gBolt/tree/v1.0"><img src="https://img.shields.io/badge/v1.0-gBolt-brightgreen.svg"></a>

   * [<em><strong>gBolt</strong></em>](#gbolt)
      * [Features](#features)
      * [Install](#install)
      * [Usage](#usage)
      * [Input Specification](#input-specification)
      * [Reference](#reference)
      * [Citation](#citation)
      * [Extension](#extension)

***gBolt***--a fast, memory efficient, and light-weight implementation for gSpan algorithm in data mining

## Features

***gBolt*** is up to 100x faster (see detailed [experiments](https://github.com/Jokeren/gBolt/blob/master/docs/experiments.md)) than [Yan's](https://www.cs.ucsb.edu/~xyan/software/gSpan.htm) original implementation with multi-threading on a single machine. ***gBolt*** also reduces more than 200 folds memory usage, running efficiently on personal computers.  

***gBolt*** is ***fast*** because it:

1. Adopts *OpenMP* task-based parallel programming;
2. Incorporates **C++11** hastable and hashset;
3. Uses contiguous memory storage;
4. Uses partial pruning.

***gBolt*** is ***memory efficient*** because it:

1. Incorporates **C++11** emplace_back method;
2. Reconstructs a graph with frequent edges and nodes before mining;
3. Uses a customized [*Path*](https://github.com/Jokeren/gBolt/blob/master/include/path.h) data structure to reuse memory in recursive procedures.

***gBolt*** is ***light-weight*** because it:

1. Can be installed without any heavy third-party library;
2. Delivers cross-platform performance without utilizing architectural features.

***gBolt*** is ***correct*** because:

1. We have ran [*experiments*](https://github.com/Jokeren/gBolt/blob/master/docs/experiments.md) for `extern/data/Compound_422` and `extern/data/Chemical_340` with minimal support from 0.1 to 0.9. The results generated by ***gBolt*** are exactly the same as Yan's gSpan-64. 


## Install

***Required***:

- *cmake*: `sudo apt-get install cmake` or install from [source](https://cmake.org/).
- *gcc >= 4.9*

***Optional***:

- *jemalloc*: install from [source](https://github.com/jemalloc/jemalloc).
- *OpenMP Environment*: enable multi-threading

***Steps***:

    mkdir build && cd build
    cmake ..
    make
    
***Build Options***:
    
- `-DGBOLT_SERIAL=ON`: serial execution without *OpenMP*
- `-DGBOLT_PERFORMANCE=ON`: display simple performance information and use hash map
- `-DJEMALLOC_DIR=/path/to/dir`: use jemalloc for memory management
- `-DCMAKE_BUILD_TYPE=<Release> or <RelWithDebInfo>`: config build type
    
## Usage

***Run an example***:

    ./build/gbolt -i extern/data/Chemical_340 -s 0.2 
    
***Arguments help***:

    ./build/gbolt -h

***Multi-threading config***:

    export OMP_NUM_THREADS=<hardware core num for recommendation>
    
## Input Specification

***Examples***:

    ./extern/data
    
***Format***:

    t # <graph-id>
    v <vertex-id> <vertex-label>
    ...
    e <vertex-id> <vertex-id> <edge-label>
    ...
    
1. `<graph-id>` must be contiguous without gaps, which means ***gBolt*** only supports `t # <id>` followed by `t # <id + 1>`.

2. `<vertex-id>` must be contiguous without gaps, which means ***gBolt*** only supports `v # <id>` followed by `v # <id + 1>`.

3. All the `<id>` fields must be non-negative integers starting from 0. 

4. All the `<label>` fields must be non-negative integers. 
    
## Reference

Yan, Xifeng, and Jiawei Han. "gspan: Graph-based substructure pattern mining." Data Mining, 2002. ICDM 2003. Proceedings. 2002 IEEE International Conference on. IEEE, 2002.

## Citation

    @misc{zhou_2019, title={Jokeren/gBolt}, url={https://github.com/Jokeren/gBolt}, journal={GitHub}, author={Zhou, Keren}, year={2019}, month={March}} 
    
## Extension

***gBolt*** is designed for efficiency, so we have not developed utilities for it. Your are welcome to implement `Python`, `C`, or graphical interfaces.
