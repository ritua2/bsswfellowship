#include<stdio.h>
#include<stdlib.h>
#include "mpi.h"
#define FILESIZE 64

int main(int argc, char **argv){

  int rank, nprocs;
  MPI_File fh, fhw;
  MPI_Status status;
  int bufsize, nints;
  
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  
  bufsize = FILESIZE/nprocs;
  nints = bufsize/sizeof(int);
  int buf[nints];
  buf[0] = 555;
   
  
  MPI_File_open(MPI_COMM_WORLD, "datafile", MPI_MODE_RDONLY, MPI_INFO_NULL, &fh);
  MPI_File_read_at(fh, rank*bufsize, buf, nints, MPI_INT, &status);

  MPI_File_open(MPI_COMM_WORLD, "datafile_written", MPI_MODE_CREATE|MPI_MODE_WRONLY, MPI_INFO_NULL, &fhw);
  
  MPI_File_set_view(fhw, rank*bufsize, MPI_INT, MPI_INT, "native", MPI_INFO_NULL);

  //Replace the  MPI_File_Write_at function call below with MPI_Write_all
  MPI_File_write_at(fhw , rank*bufsize, buf, nints, MPI_INT , &status);

  printf("\nrank: %d, buf[%d]: %d", rank, rank*bufsize, buf[0]);

  MPI_File_close(&fh);
  MPI_File_close(&fhw);
 
  MPI_Finalize();
  return 0;
}

