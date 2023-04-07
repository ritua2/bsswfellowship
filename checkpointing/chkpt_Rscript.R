args = commandArgs(trailingOnly = TRUE)
if (length(args)==0) {
   print("code is running normally")
   dd = read.csv("input.csv",header = FALSE)
   mat = as.matrix(dd)
   mat = mat +1
   print(mat)
   save(mat, file="chkpt.Rdata")

   Sys.sleep(100)

   mat = mat +1
   print(mat)
   save(mat, file="chkpt.Rdata")
 } else if(length(args) == 4 & args[3] == "restart") {
   load(args[2])
   mat = mat+1
   print(mat)
   save(mat, file=args[4])
 }else{
   print("Correct usage of this code in restart mode is: Rscript testRscript.R --args chkpt.Rdata restart newchkput.Rdata")
   print("The restart flag is passed through the command-line")
 }
