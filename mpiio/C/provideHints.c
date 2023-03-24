#include<stdio.h>
#include "mpi.h"
int main(int argc, char **argv){
   int i, rank, size, offset, N=160000;
   MPI_File fhw;
   MPI_Status status;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   int buf[N];
   for ( i=0;i<N;i++){
        buf[i] = i ;
   }
   offset = rank*(N/size)*sizeof(int);

   MPI_Info myinfo;
   MPI_Info_create (&myinfo);
   MPI_Info_set(myinfo,"striping_factor","4");
   MPI_Info_set(myinfo, "striping_unit","4194304");

   MPI_File_open(MPI_COMM_WORLD, "datafile_striped22", MPI_MODE_CREATE|MPI_MODE_WRONLY, myinfo, &fhw);
   printf("\nRank: %d, Offset: %d\n", rank, offset);

   MPI_File_write_at(fhw, offset, buf, (N/size), MPI_INT, &status);
   MPI_File_close(&fhw);
   MPI_Info_free(&myinfo);
   MPI_Finalize();
   return 0;
}
