## BSSw Fellowship
This repository contains the deliverables associated with my BSSw Fellowship.

Note: The PDF file named "optimizing_IO_part1_part2_part3_combined_updated.pdf" contains 100 pages and have been moved to the documents folder. Please feel free to click on "More Pages" if you are opening this document on GitHub and scrolling down.

As a part of my fellowship, I created videos, articles/blogs, and examples/exercises to demonstrate how to optimize I/O in scientific applications including the applications from the area of AI/machine learning and have delivered a 3-day tutorial on these topics. Specifically, I have covered the following topics:
(1) Optimizing I/O in serial and parallel applications
(2) Optimally writing and reading checkpoints in serial and parallel applications
(3) Optimizing I/O and checkpointing AI/machine learning models/applications
(4) Techniques for leveraging the features in the underlying hardware and filesystems (e.g., Lustre) for optimizing applications’ I/O while being aware of portability issues.

## Directory Structure
The directory (or folder) names in this repository are metadata that give an indication about the type of content inside them.

The code samples related to the topic of checkpointing in serial and parallel applications including AI/machine learning models are shared through the directory named "checkpointing": https://github.com/ritua2/bsswfellowship/tree/main/checkpointing 

The documents (articles/blog and presentations) related to the content developed in this fellowship are shared through the directory named "documents": https://github.com/ritua2/bsswfellowship/tree/main/documents

The repository named "mpiio" contains the code samples related to reading and writing file using MPI I/O: https://github.com/ritua2/bsswfellowship/tree/main/mpiio

The directory named "serial_io" contains the code for demonstrating optimization in serial code : https://github.com/ritua2/bsswfellowship/tree/main/serial_io 

The videos recorded for this fellowship are posted on YouTube and their links are included in the directory named "videos": https://github.com/ritua2/bsswfellowship/tree/main/videos

## Prerequisites
For optimizations in serial and parallel applications: familiarity with Linux, C/C++ programming, and MPI 
For AI/machine learning related content: familiarity with Tensorflow, PyTorch, and Keras 

## Target Audience
The target audience of the material developed as a part of this fellowship includes those who are engaged in scientific software development but do not have prior experience with parallel filesystems, MPI I/O, and application-level checkpointing.

## Tutorial agenda and schedule
June 12, 2023, 12:30 PM CST - 2:30 PM CST: (1) Strategies and practices for reducing inefficient I/O in serial and parallel applications, including AI frameworks, and (2) Introduction to Parallel Filesystems (Lustre)

June 13, 2023, 12:30 PM CST - 2:30 PM CST: Reading and writing files in parallel using MPI

June 14, 2023, 12:30 PM CST - 2:30 PM CST: Checkpointing serial and parallel applications
