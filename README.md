## BSSw Fellowship: Optimizing I/O for Better Performance
This repository contains the deliverables associated with my [BSSw Fellowship](https://bssw.io/fellows/ritu-arora).

Optimizing I/O of scientific applications can be critical for performance but is usually an afterthought in application development. As a part of my fellowship, I created videos, articles/blogs, and examples/exercises to demonstrate how to optimize I/O in scientific applications including the applications from the area of AI/machine learning and have delivered a 3-part tutorial on these topics. Specifically, I have covered the following topics:

(1) Optimizing I/O in serial and parallel applications

(2) Optimally writing and reading checkpoints in serial and parallel applications

(3) Optimizing I/O and checkpointing AI/machine learning models/applications

(4) Techniques for leveraging the features in the underlying hardware and filesystems (e.g., Lustre) for optimizing applications’ I/O while being aware of portability issues.

## Target Audience
The target audience of the material developed as a part of this fellowship includes those who are engaged in scientific software development but do not have prior experience with parallel filesystems, MPI I/O, and application-level checkpointing.

## Prerequisites
For the content on optimizations in serial and parallel applications: familiarity with Linux, C/C++ programming, and MPI 

For the content on AI/machine learning: familiarity with Tensorflow, PyTorch, and Keras 

## Directory Structure
The directory (or folder) names in this repository are metadata that give an indication about the type of content inside them.

The code samples related to the topic of checkpointing in serial and parallel applications including AI/machine learning models are shared through the directory named "checkpointing": https://github.com/ritua2/bsswfellowship/tree/main/checkpointing 

The documents (articles/blog and presentations) related to the content developed in this fellowship are shared through the directory named "documents": https://github.com/ritua2/bsswfellowship/tree/main/documents

The repository named "mpiio" contains the code samples related to reading and writing file using MPI I/O: https://github.com/ritua2/bsswfellowship/tree/main/mpiio

The directory named "serial_io" contains the code for demonstrating optimization in serial code : https://github.com/ritua2/bsswfellowship/tree/main/serial_io 

The videos recorded for this fellowship are posted on YouTube and their links are included in the directory named "videos": https://github.com/ritua2/bsswfellowship/tree/main/videos

The code samples and exercises in the different folders supplement the slides at the following link but can be used independently as well as a reference to understand how the different API/function calls are used for I/O or checkpointing work: https://github.com/ritua2/bsswfellowship/blob/main/documents/optimizing_IO_part1_part2_part3_combined.pdf . The instructions for compiling/running the code samples should be in the README files within the respective folders.

## Using this Repository
The code shared through this repository is released under the LGPL-2.1 license. The presentation slides are released under the CC BY-NC 2.0 license.

The content included in this repository is meant to be an anthology of the different strategies to address the optimization of I/O in serial and parallel applications from the hardware to the software level. The wide breadth of the content covered includes topics such as optimal programming language/library functions for doing I/O, using an optimal data transfer protocol, efficiently leveraging the parallel and distributed filesystems and the storage hardware, creating job dependencies for setting up automated workflows for checkpointing-and-restart (which is a critical piece due to the amount of I/O it involves), and leveraging the features of the machine learning/AI frameworks for doing I/O optimally. 

If you would like to learn about the topic of Optimizing I/O in the tutorial mode, then please refer to the slides at the following link: https://github.com/ritua2/bsswfellowship/blob/main/documents/optimizing_IO_part1_part2_part3_combined.pdf . The content in these slides is divided into three parts, and you should be able to start with any part at any point in time as long as the prerequisites are met. These parts are as follows:

Part-1: (1) Strategies and practices for reducing inefficient I/O in serial and parallel applications, including AI frameworks, and (2) Introduction to Parallel Filesystems (Lustre). The topics covered in this part are as follows:


      - Why should we optimize I/O?  (general review)

      - How can we optimize I/O?  (general review plus one example code in C)

      - General I/O strategies for working on High Performance Computing (HPC) platforms  (general review)

      - Introduction to the Lustre parallel file system (general review and demo of some Lustre commands)


Part-2: Reading and writing files in parallel using MPI
         
      - Introduction to parallel I/O patterns
      
      - Introduction to MPI I/O

Part-3: Checkpointing serial and parallel applications

      - I/O in the context of checkpointing and AI

The links to the video-recordings of the different parts of the tutorial are included in the videos folder. 

Instead of starting with the slides, if you prefer a gentle and verbose introduction to the different topics related to optimizing I/O in serial and parallel applications, you can start with the following LinkedIn article: https://www.linkedin.com/feed/update/urn:li:activity:7078166039275974656/ . This article is also accessible through the following link: https://github.com/ritua2/bsswfellowship/blob/main/documents/Optimizing_IO_updated.pdf

If you are interested in an introduction to checkpointing and how it is related to I/O, then please refer to part-3 of the slides at the following link: https://github.com/ritua2/bsswfellowship/blob/main/documents/optimizing_IO_part1_part2_part3_combined.pdf . 

For a gentle introduction to checkpointing and how application-level checkpointing can be implemented in serial and parallel applications including the machine learning/AI models, you may start with the content in the following sequence:

1. What is checkpointing? https://www.linkedin.com/pulse/what-checkpointing-ritu-arora/?trackingId=6HuYtfGvRB%2ByZ0%2B6tmowpw%3D%3D 

   
2. Checkpointing in Python: https://www.linkedin.com/pulse/checkpointing-python-ritu-arora/?trackingId=6HuYtfGvRB%2ByZ0%2B6tmowpw%3D%3D 


3. Checkpointing and Saving States of AI models: https://www.linkedin.com/posts/ritu-a-59b58ab_checkpointing-and-saving-the-states-of-ai-activity-7072375016528506880-ZTu_?utm_source=share&utm_medium=member_desktop

## Agenda and schedule of the tutorial delivered in June 2023
June 12, 2023, 12:30 PM CST - 2:30 PM CST: (1) Strategies and practices for reducing inefficient I/O in serial and parallel applications, including AI frameworks, and (2) Introduction to Parallel Filesystems (Lustre)

June 13, 2023, 12:30 PM CST - 2:30 PM CST: Reading and writing files in parallel using MPI

June 14, 2023, 12:30 PM CST - 2:30 PM CST: Checkpointing serial and parallel applications

## URLs to the LinkedIn Articles and Posts
1. What is checkpointing? https://www.linkedin.com/pulse/what-checkpointing-ritu-arora/?trackingId=6HuYtfGvRB%2ByZ0%2B6tmowpw%3D%3D
   
2. Checkpointing in Python: https://www.linkedin.com/pulse/checkpointing-python-ritu-arora/?trackingId=6HuYtfGvRB%2ByZ0%2B6tmowpw%3D%3D

3. Checkpointing and Saving States of AI models: https://www.linkedin.com/posts/ritu-a-59b58ab_checkpointing-and-saving-the-states-of-ai-activity-7072375016528506880-ZTu_?utm_source=share&utm_medium=member_desktop

4. Optimizing I/O: https://www.linkedin.com/pulse/optimizing-io-ritu-arora/?trackingId=6HuYtfGvRB%2ByZ0%2B6tmowpw%3D%3D

## Acknowledgement
This work was supported by the Better Scientific Software Fellowship Program, funded by the Exascale Computing Project (17-SC-20-SC), a collaborative effort of the U.S. Department of Energy (DOE) Office of Science and the National Nuclear Security Administration; and by the National Science Foundation (NSF) under Grant No. 2154495. Any opinions, findings, and conclusions or recommendations expressed in this material are those of the author(s) and do not necessarily reflect the views of the DOE or NSF.

