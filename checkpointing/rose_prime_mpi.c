int FUNCTION_RELATING_CONDITION_main = 1;
int global_RANK = -1;
int ROSE_RESTART_FLAG = 0;
# include <math.h>
# include "mpi.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[]);
int prime_number(int n,int id,int p);
void timestamp();
/******************************************************************************/

int main(int argc,char *argv[])
/******************************************************************************/
/*
  Purpose:
    MAIN is the main program for PRIME_MPI.
  Discussion:
    This program calls a version of PRIME_NUMBER that includes
    MPI calls for parallel processing.
  Licensing:
    This code is distributed under the GNU LGPL license.
  Modified:
    07 August 2009
  Author:
    John Burkardt
*/
{
  static int FUNCTION_RESTART_FLAG = -1;
  int FUNCTION_LOCATION_CHECKING = 0;
{
int strMatch = strncmp(argv[argc-1], "--r", 3);
if(strMatch==0){
ROSE_RESTART_FLAG=1;
printf("Restart initated.\n");
}
else{
printf("Not running in restart mode.\n");
}
}
  int i;
  int id;
  int ierr;
  int n;
  int n_factor;
  int n_hi;
  int n_lo;
  int p;
  int primes;
  int primes_part;
  double wtime;
  n_lo = 1;
  n_hi = 100000;
  n_factor = 2;
/*
  Initialize MPI.
*/
  MPI_Init(&argc,&argv);
  MPI_Comm_rank( MPI_COMM_WORLD, &global_RANK );
/*
  Get the number of processes.
*/
  MPI_Comm_size(((MPI_Comm )0x44000000),&p);
/*
  Determine this processes's rank.
*/
  MPI_Comm_rank(((MPI_Comm )0x44000000),&id);
  if (id == 0) {
    timestamp();
    printf("\n");
    printf("PRIME_MPI\n");
    printf("  C/MPI version\n");
    printf("\n");
    printf("  An MPI example program to count the number of primes.\n");
    printf("  The number of processes is %d\n",p);
    printf("\n");
    printf("         N        Pi          Time\n");
    printf("\n");
  }
  n = n_lo;
{
    int Checkpoint_iterator_0 = 0;
{/** CHECKPOINTED BLOCK **/
MPI_File*ROSE_FILE;
int arrIterator;
int processor_offset = global_RANK * (1*sizeof(int) + 1*sizeof(int) +  + sizeof(int )* 1 + sizeof(double )* 1 + sizeof(int )* 1 + sizeof(int )* 1 + sizeof(int )* 1);
MPI_Status STATUS;
char fname[26] = ".save1.prime_number.o.txt";
char buf[5];
// variable to determine if this loop is ever checkpointed or not
int written_loop_ = 0;
int loop_index = 0;
int __Restarting__ = 0;
char *string1;
string1 = (char*)malloc((strlen(fname)+strlen(buf)+1) * sizeof(char));
strcpy(string1,fname);
if(ROSE_RESTART_FLAG != 0 &&FUNCTION_RESTART_FLAG){
MPI_File_open( MPI_COMM_WORLD,string1,MPI_MODE_RDONLY,MPI_INFO_NULL,ROSE_FILE);
if(ROSE_FILE== NULL){
printf("Error opening file string1. Cannot restart. Defaulting to Normal mode.\n");
ROSE_RESTART_FLAG=0;
//exit(-1);
}
else{
int offset = processor_offset;
int fread_checking_ = MPI_File_read_at(*ROSE_FILE,offset,&written_loop_,1,MPI_INT,&STATUS);
if (written_loop_== 1 && fread_checking_== 0 ) {
offset+=sizeof(int);
printf("Restarting from file string1.\n");
MPI_File_read_at(*ROSE_FILE,offset,&loop_index,1,MPI_INT,&STATUS);
offset+=sizeof(int);
__Restarting__ = (loop_index) ? 1 : 0 ;
/** RESTART Checkpoint_iterator_0 wtime primes_part primes n **/
MPI_File_read_at(*ROSE_FILE,offset,&Checkpoint_iterator_0,1,MPI_INT,&STATUS);
offset += sizeof(int);
MPI_File_read_at(*ROSE_FILE,offset,&wtime,1,MPI_DOUBLE,&STATUS);
offset += sizeof(double);
MPI_File_read_at(*ROSE_FILE,offset,&primes_part,1,MPI_INT,&STATUS);
offset += sizeof(int);
MPI_File_read_at(*ROSE_FILE,offset,&primes,1,MPI_INT,&STATUS);
offset += sizeof(int);
MPI_File_read_at(*ROSE_FILE,offset,&n,1,MPI_INT,&STATUS);
offset += sizeof(int);
MPI_File_close(ROSE_FILE);
/** END RESTART Checkpoint_iterator_0 wtime primes_part primes n **/
}
else {
printf("file empty or cannot open file: %s\n",string1);
}
}
}
    while(n <= n_hi){
if (!__Restarting__) { loop_index = 0;
}
 if(( Checkpoint_iterator_0%(3) == 0 ) && FUNCTION_RELATING_CONDITION_main && !__Restarting__ ){
MPI_File_open( MPI_COMM_WORLD,string1,MPI_MODE_CREATE,MPI_INFO_NULL,ROSE_FILE);
MPI_File_open( MPI_COMM_WORLD,string1,MPI_MODE_WRONLY,MPI_INFO_NULL,ROSE_FILE);
int write_offset=processor_offset;
//Turn written on
int __w__ = 1;
MPI_File_write_at(*ROSE_FILE,write_offset,&__w__,1,MPI_INT, &STATUS);
 write_offset+=sizeof(int);
//Write loop index
MPI_File_write_at(*ROSE_FILE,write_offset,&loop_index,1,MPI_INT, &STATUS);
write_offset+=sizeof(int);
/** SAVE Checkpoint_iterator_0 wtime primes_part primes n **/
MPI_File_write_at(*ROSE_FILE,write_offset,&Checkpoint_iterator_0,1,MPI_INT, &STATUS);
write_offset+= sizeof(int);
MPI_File_write_at(*ROSE_FILE,write_offset,&wtime,1,MPI_DOUBLE, &STATUS);
write_offset+= sizeof(double);
MPI_File_write_at(*ROSE_FILE,write_offset,&primes_part,1,MPI_INT, &STATUS);
write_offset+= sizeof(int);
MPI_File_write_at(*ROSE_FILE,write_offset,&primes,1,MPI_INT, &STATUS);
write_offset+= sizeof(int);
MPI_File_write_at(*ROSE_FILE,write_offset,&n,1,MPI_INT, &STATUS);
write_offset+= sizeof(int);
MPI_File_close(ROSE_FILE);
/** END SAVE Checkpoint_iterator_0 wtime primes_part primes n **/
}
      if (id == 0) {
        if (!__Restarting__) {
          wtime = MPI_Wtime();
        }
      }
      if (!__Restarting__) {
        MPI_Bcast((&n),1,((MPI_Datatype )0x4c000405),0,((MPI_Comm )0x44000000));
      }
      if (!__Restarting__) {
        primes_part = prime_number(n,id,p);
      }
      if (!__Restarting__) {
        MPI_Reduce((&primes_part),(&primes),1,((MPI_Datatype )0x4c000405),((MPI_Op )0x58000003),0,((MPI_Comm )0x44000000));
      }
      if (id == 0) {
        if (!__Restarting__) {
          wtime = (MPI_Wtime() - wtime);
        }
        if (!__Restarting__) {
          printf("  %8d  %8d  %14f\n",n,primes,wtime);
        }
      }
      if (!__Restarting__) {
        n = (n * n_factor);
      }
      if (!__Restarting__) {
        ++Checkpoint_iterator_0;
      }
    }
/** END CHECKPOINTED BLOCK **/}
  }
/*
  Terminate MPI.
*/
  MPI_Finalize();
/*
  Terminate.
*/
  if (id == 0) {
    printf("\n");
    printf("PRIME_MPI - Master process:\n");
    printf("  Normal end of execution.\n");
    printf("\n");
    timestamp();
  }
  return 0;
}
/******************************************************************************/

int prime_number(int n,int id,int p)
/******************************************************************************/
/*
  Purpose:
    PRIME_NUMBER returns the number of primes between 1 and N.
  Discussion:
    In order to divide the work up evenly among P processors, processor
    ID starts at 2+ID and skips by P.
    A naive algorithm is used.
    Mathematica can return the number of primes less than or equal to N
    by the command PrimePi[N].
                N  PRIME_NUMBER
                1           0
               10           4
              100          25
            1,000         168
           10,000       1,229
          100,000       9,592
        1,000,000      78,498
       10,000,000     664,579
      100,000,000   5,761,455
    1,000,000,000  50,847,534
  Licensing:
    This code is distributed under the GNU LGPL license.
  Modified:
    21 May 2009
  Author:
    John Burkardt
  Parameters:
    Input, int N, the maximum number to check.
    Input, int ID, the ID of this process,
    between 0 and P-1.
    Input, int P, the number of processes.
    Output, int PRIME_NUMBER, the number of prime numbers up to N.
*/
{
  static int FUNCTION_RESTART_FLAG = -1;
  int FUNCTION_LOCATION_CHECKING = 0;
  int i;
  int j;
  int prime;
  int total;
  total = 0;
{
    int Checkpoint_iterator_0 = 0;
    for (i = (2 + id); i <= n; i = (i + p)) {
      prime = 1;
{
        for (j = 2; j < i; j++) {
          if ((i % j) == 0) {
            prime = 0;
            break;
          }
        }
      }
      total = (total + prime);
      ++Checkpoint_iterator_0;
    }
  }
  return total;
}
/******************************************************************************/

void timestamp()
/******************************************************************************/
/*
  Purpose:
    TIMESTAMP prints the current YMDHMS date as a time stamp.
  Example:
    31 May 2001 09:45:54 AM
  Licensing:
    This code is distributed under the GNU LGPL license.
  Modified:
    24 September 2003
  Author:
    John Burkardt
  Parameters:
    None
*/
{
  static int FUNCTION_RESTART_FLAG = -1;
  int FUNCTION_LOCATION_CHECKING = 0;
# define TIME_SIZE 40
  static char time_buffer[40UL];
  const struct tm *tm;
  size_t len;
  time_t now;
  now = time(0);
  tm = (localtime((&now)));
  len = strftime(time_buffer,40,"%d %B %Y %I:%M:%S %p",tm);
  printf("%s\n",time_buffer);
# undef TIME_SIZE
}
