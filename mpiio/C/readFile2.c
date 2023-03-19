#include<stdio.h>
#include "mpi.h"
#define FILESIZE 80    //Total size of the datafile

int main(int argc, char **argv)
{  
	int rank, size, bufsize, nints;
  	MPI_File fh;
  	MPI_Status status;
  
	MPI_Init(&argc, &argv);
  	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  	MPI_Comm_size(MPI_COMM_WORLD, &size);
  
	bufsize = FILESIZE/size;       //Size to read per task
  	nints = bufsize/sizeof(int);   //Number of ints to read per task
  	int buf[nints];
  
	MPI_File_open(MPI_COMM_WORLD,"datafile1",MPI_MODE_RDONLY,MPI_INFO_NULL,&fh);
  	MPI_File_seek(fh, rank * bufsize, MPI_SEEK_SET);       // Calculate the offset and updates individual file pointers 
  	MPI_File_read(fh, buf, nints, MPI_INT, &status);       // Read from the datafile

  	printf("\nrank: %d, buf[%d]: %d\n", rank, rank*bufsize, buf[0]);
  	MPI_File_close(&fh);
  	MPI_Finalize();
  	return 0;
}

