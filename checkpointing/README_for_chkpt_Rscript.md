# R suports the feature of saving and loading the data.
# This code reads a matrix from an input file, updates the matrix, saves the matrix to a file, sleeps for 100 seconds, and updates the matrix again and saves it to a file.
# If the code is interrupted after a checkpoint is written, it can be restarted from the saved or checkpointed data file by providing the name of the checkpoint file and the restart flag along with the name of the new file in which data should be saved or checkpointed.

# To run the code normally
$Rscript testRscript.R
[1] "code is running normally"
     V1 V2 V3 V4 V5
[1,] 52 52 52 52 52
[2,] 52 52 52 52 52
[3,] 52 52 52 52 52
[4,] 52 52 52 52 52
[5,] 52 52 52 52 52
     V1 V2 V3 V4 V5
[1,] 53 53 53 53 53
[2,] 53 53 53 53 53
[3,] 53 53 53 53 53
[4,] 53 53 53 53 53
[5,] 53 53 53 53 53

# To run the code, interrupt it, and resume the code in the restart mode
$ Rscript testRscript.R
[1] "code is running normally"
     V1 V2 V3 V4 V5
[1,] 52 52 52 52 52
[2,] 52 52 52 52 52
[3,] 52 52 52 52 52
[4,] 52 52 52 52 52
[5,] 52 52 52 52 52
^C
Execution halted
$ Rscript testRscript.R --args chkpt.Rdata restart newchkpt.Rdata
     V1 V2 V3 V4 V5
[1,] 53 53 53 53 53
[2,] 53 53 53 53 53
[3,] 53 53 53 53 53
[4,] 53 53 53 53 53
[5,] 53 53 53 53 53
