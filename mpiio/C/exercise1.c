#include<stdio.h>
#include<stdlib.h>
#include "mpi.h"
#define FILESIZE 64

int main(int argc, char **argv){

  int rank, nprocs;
  MPI_File fh;
  //declare an additional file pointer named fhw that will be used for opening a file for writing purposes
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

  //after this line, open a file named "datafile_written", in MPI_MODE_CREATE or MPI_MODE_WRONLY, and the file handle is "fhw"
  
  MPI_File_set_view(fhw, rank*bufsize, MPI_INT, MPI_INT, "native", MPI_INFO_NULL);
  //fill the arguments of the MPI_File_Write_at function call below to pass the missing file-handle, offset, and datatype -- remember a file view was used with this file
  MPI_File_write_at(<file-handle> , <offset>, buf, nints,<datatype>  , &status);
  printf("\nrank: %d, buf[%d]: %d", rank, rank*bufsize, buf[0]);

  MPI_File_close(&fh);
  //insert the MPI call for closing the file opened for writting - the file-handle is "fhw"

  MPI_Finalize();
  return 0;
}

