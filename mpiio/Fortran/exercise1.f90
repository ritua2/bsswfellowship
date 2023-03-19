PROGRAM main 
use mpi
integer ierr, i, myrank, BUFSIZE, thefile
parameter (BUFSIZE=100)
integer buf(BUFSIZE)
integer(kind=MPI_OFFSET_KIND) disp 

call MPI_INIT(ierr)
call MPI_COMM_RANK(MPI_COMM_WORLD, myrank, ierr)

do i = 0, BUFSIZE
    buf(i) = myrank * BUFSIZE + i
enddo 

!after this line, open a file named "datafile_written", in MPI_MODE_CREATE or
!MPI_MODE_WRONLY, and the file handle is "thefile"


call MPI_TYPE_SIZE(MPI_INTEGER, intsize, ierr)

disp = myrank * BUFSIZE * intsize

call MPI_FILE_SET_VIEW(thefile, disp, MPI_INTEGER, MPI_INTEGER, 'native', MPI_INFO_NULL, ierr)

call MPI_FILE_WRITE(thefile, buf, BUFSIZE, MPI_INTEGER, MPI_STATUS_IGNORE, ierr)

!insert the MPI call for closing the file opened for writting - the file-handle
!is "thefile"

call MPI_FINALIZE(ierr) 

END PROGRAM main
