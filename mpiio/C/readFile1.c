#include<stdio.h>
#include "mpi.h"
#define FILESIZE 80

int main(int argc, char **argv)
{  
	int rank, size, bufsize, nints;
  	MPI_File fh;
  	MPI_Status status;

  	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  	MPI_Comm_size(MPI_COMM_WORLD, &size);
  
	bufsize = FILESIZE/size;
  	nints = bufsize/sizeof(int);
  	int buf[nints];
  
	MPI_File_open(MPI_COMM_WORLD,"datafile1",MPI_MODE_RDONLY,MPI_INFO_NULL,&fh);
  	MPI_File_read_at(fh, rank*bufsize, buf, nints, MPI_INT, &status);
  	printf("\nrank: %d, buf[%d]: %d\n", rank, rank*bufsize, buf[0]);

  	MPI_File_close(&fh);
  	MPI_Finalize();
  	return 0;
}

