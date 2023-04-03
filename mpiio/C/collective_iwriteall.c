#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define SIZE 64

int main(int argc, char **argv){
    int *buf, *buf2, i, rank, size, nints, len, offset;

    MPI_File fh;
    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    buf = (int *) malloc(SIZE);
    buf2= (int *) malloc(SIZE);
    nints = SIZE/sizeof(int);
    for (i=0; i<nints; i++){
      buf[i] = rank*200 + i;
    }

    offset = rank*(SIZE/size)*sizeof(int);

    //open a file for writing the contents of the buffer named buf
    MPI_File_open(MPI_COMM_WORLD,"testing_async3.out", MPI_MODE_CREATE | MPI_MODE_RDWR, MPI_INFO_NULL, &fh);
    MPI_File_set_view(fh, offset, MPI_INT, MPI_INT, "native", MPI_INFO_NULL);
    MPI_File_iwrite_all(fh, buf, nints, MPI_INT , &request);
    MPI_Wait( &request, &status );
    MPI_File_close(&fh);

    //reopen the file and read the data into buf2
    for (i=0; i<nints; i++){
      buf2[i] = 0;
    }
    MPI_File_open(MPI_COMM_WORLD, "testing_async3.out", MPI_MODE_CREATE | MPI_MODE_RDWR, MPI_INFO_NULL, &fh);
    MPI_File_set_view(fh, offset, MPI_INT, MPI_INT, "native", MPI_INFO_NULL);
    MPI_File_iread_all(fh, buf2, nints, MPI_INT, &request);
    MPI_Wait( &request, &status );
    MPI_File_close(&fh);

    //check the data read into buf2
    for (i=0; i<nints; i++) {
       printf("\nProcess %d, read: %d, stored: %d\n", rank, buf2[i], rank*200+i);
    }
    free(buf);
    free(buf2);
    free(fh);
    MPI_Finalize();
    return 0;
}
