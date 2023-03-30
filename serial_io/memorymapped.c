#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int *mPtr;
  size_t pageSize = (size_t)sysconf(_SC_PAGESIZE);
  int fp = open("inputFile.txt", O_RDWR);
  ftruncate(fp, pageSize);
  mPtr = (int*)mmap(NULL, 65, PROT_READ|PROT_WRITE, MAP_SHARED, fp, 0);
  printf("\ncontents of mPtr are:\n%.*s\n", 65, mPtr);
  munmap(mPtr, 128);
  close(fp);
  return 0;
}
