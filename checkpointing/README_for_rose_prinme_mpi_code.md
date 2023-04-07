This code was generated using the prototype of our tool named ITALC and here is the citation for the tool: "Ritu Arora and Trung Nguyen Ba. 2017. ITALC: Interactive Tool for Application-Level Checkpointing. In Proceedings of the Fourth International Workshop on HPC User Support Tools (HUST'17). Association for Computing Machinery, New York, NY, USA, Article 2, 1–11. https://doi.org/10.1145/3152493.3152558"
  
This is C + MPI code. The base version of the code was taken from the following URL: https://people.sc.fsu.edu/~jburkardt/c_src/prime_mpi/prime_mpi.html
  
# To compile the code: 
 mpicc -o rose_prime_number rose_prime_number.c 
 
 
# To run the code normally:
$ mpirun -np 4 rose_prime_number
```
PRIME_MPI
  C/MPI version

  An MPI example program to count the number of primes.
  The number of processes is 4

         N        Pi          Time

         1         0        0.001861
         2         1        0.000015
         4         2        0.000012
         8         4        0.000646
        16         6        0.000015
        32        11        0.000012
        64        18        0.000671
       128        31        0.000032
       256        54        0.000075
       512        97        0.000858
      1024       172        0.000795
      2048       309        0.002849
      4096       564        0.011072
      8192      1028        0.036676
     16384      1900        0.136230
     32768      3512        0.502941
     65536      6542        1.870533

PRIME_MPI - Master process:
  Normal end of execution.
```

 # To run the code and interrupt with ctrl+C 
$ mpirun -np 4 rose_prime_number

```
PRIME_MPI
  C/MPI version

  An MPI example program to count the number of primes.
  The number of processes is 4

         N        Pi          Time

         1         0        0.000089
         2         1        0.000015
         4         2        0.000009
         8         4        0.000787
        16         6        0.000016
        32        11        0.000011
        64        18        0.000646
       128        31        0.000036
       256        54        0.000078
       512        97        0.000917
      1024       172        0.000816
      2048       309        0.002853
      4096       564        0.010889
      8192      1028        0.036485
     16384      1900        0.136121
^C Sending Ctrl-C to processes as requested
Press Ctrl-C again to force abort
```
# Restarting after interrupting

$ mpirun -np 4 rose_prime_number --r
```
PRIME_MPI
  C/MPI version

  An MPI example program to count the number of primes.
  The number of processes is 4

         N        Pi          Time
         
Restarting from file string1.
Restarting from file string1.
Restarting from file string1.
Restarting from file string1.
     32768      3512        0.501680
     65536      6542        1.872939

PRIME_MPI - Master process:
  Normal end of execution.
```
