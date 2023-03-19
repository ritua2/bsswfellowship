#!/bin/bash
#SBATCH -J myMPI # Job Name
#SBATCH -o myMPI.o%j # Name of the output file 
#SBATCH -n 16 # Requests 16 tasks/node
#SBATCH -N 1 #Requests 1 node
#SBATCH -p normal # Queue name normal
#SBATCH -t 00:10:00 # Run time (hh:mm:ss) - 10 minutes

set -x # Echo commands

mpirun ./mpiExample4 # Run the MPI executable
