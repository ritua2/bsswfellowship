#include<stdio.h>
#include "mpi.h"

int main(int argc, char **argv)
{  
	int i, rank, size, offset, nints, N=20, N_blocks;
  	MPI_File fhw;
  	MPI_Status status;
	MPI_Datatype etype, filetype;
  
	MPI_Init(&argc, &argv);
  	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  	MPI_Comm_size(MPI_COMM_WORLD, &size);
  
	int buf[N];
  	for ( i=0;i<N;i++)
        	buf[i] = i ;
  	
	offset = rank*sizeof(int);
        N_blocks = N/size;  

        MPI_Type_vector(N_blocks, 1, 4, MPI_INT, &filetype);
        MPI_Type_commit( &filetype); 
        etype = MPI_INT; 
	
	MPI_File_open(MPI_COMM_WORLD, "datafile3", MPI_MODE_CREATE|MPI_MODE_WRONLY, MPI_INFO_NULL, &fhw);
  	MPI_File_set_view(fhw, offset, etype, filetype, "native", MPI_INFO_NULL);
  
	MPI_File_write(fhw, buf+rank*N_blocks, N_blocks, MPI_INT, &status);
  	MPI_File_close(&fhw);
  	MPI_Finalize();
  	return 0;
}
