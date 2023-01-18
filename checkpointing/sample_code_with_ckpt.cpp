#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void b (int &);
void d (int &);

int restart_b=0;
int restart_d=0;
static int rose_count_b=0;
static int rose_count_d=0;
int main(int argc, char *argv[]) {
       if(argc > 1 && *argv[1] == 'r'){
         restart_b=1;
         restart_d=1;
         printf("\nThe file will be opened in the restart mode.\n");
       }
       int i1 = 10;
       int i2 = 20;
       rose_count_d =0;
       rose_count_d =0;
       rose_count_d++;  //need to be increased by one every time b() gets called
       d(i1);
       rose_count_b++; //need to be increased by one every time b() gets called
       b(i2);
       rose_count_b++;
       b(i1);
       printf("Final i1 = %d\n", i1);
      printf("Final i2 = %d\n", i2);
       return 1;
}

void b (int & v) {
       int rose_start=0;
       
       static int rose_count_in_file=0;
       static int rose_start_from_file=0;
       static int rose_v_from_file=0;
     

       if(restart_b==1){
          char line[80];
          FILE *fp2;
          fp2 = fopen ("chkpt_b.txt", "r"); 

           if(fgets(line, 80, fp2) != NULL){
              sscanf (line, "%d", &rose_count_in_file);
              
              fgets(line, 80, fp2);
              sscanf (line, "%d", &rose_start_from_file);
              

              fgets(line, 80, fp2);
              sscanf (line, "%d", &rose_v_from_file);
           }  
          fclose(fp2);
          restart_b=0;
       }
   
       printf ("\nrose_count_in_file: %d, rose_count: %d\n",rose_count_in_file, rose_count_b);
       FILE * fp;
       if(rose_count_in_file==rose_count_b){
         rose_start = rose_start_from_file;
         v = rose_v_from_file; 
       }        
         for(int i = rose_start ; i < 10; i++) {
                 
                 if(i==rose_start){
                         printf("\nstarting out from i= %d\n", i);
                 }
                 if(i%5==0){
                         fp = fopen ("chkpt_b.txt", "w");
                         //get the data type of the values to be checkpointed as specified by the user
                         fprintf(fp, "%d\n", rose_count_b);
                         fprintf(fp, "%d\n", i);
                         fprintf(fp, "%d\n", v);
                         fclose(fp);
                 }
                 v+=i;
                 printf("Value changed to %d\n", v );
                 sleep(1);
         }
}

void d (int & v) {
 int rose_start;
 static int rose_count_in_file=0;
 static int rose_start_from_file=0;
 static int rose_v_from_file=0;


 if(restart_d==1){
    char line[80];
    FILE *fp2;
    fp2 = fopen ("chkpt_d.txt", "r"); 

     if(fgets(line, 80, fp2) != NULL){
        sscanf (line, "%d", &rose_count_in_file);
        printf ("\nrose_count_in_file: %d\n",rose_count_in_file);

        fgets(line, 80, fp2);
        sscanf (line, "%d", &rose_start_from_file);
        printf ("\nrose_start_from_file: %d\n",rose_start_from_file );

        fgets(line, 80, fp2);
        sscanf (line, "%d", &rose_v_from_file);
        printf ("\nv_of_d_function: %d\n",rose_v_from_file );
    }
    fclose(fp2);
    restart_d=0;
 }
 FILE* fp;
 if(rose_count_in_file==rose_count_d){
       rose_start = rose_start_from_file;
       v = rose_v_from_file;
 }
              
       
       printf("\nv_D is: %d\n", v);
       for(int i = rose_start ; i < 10; i++) {
               if(i==rose_start){
                       printf("\nstarting out from i= %d\n", i);
               }
               {//Checkpoint must be done before the b() is called. Otherwise, inconsistency occurs 
                       fp = fopen ("chkpt_d.txt", "w");
                       //get the data type of the values to be checkpointed as specified by the user
                       fprintf(fp, "%d\n", rose_count_d);
                       fprintf(fp, "%d\n", i);
                       fprintf(fp, "%d\n", v);
                       fclose(fp);
               }
               
      rose_count_b++;        //needs to be increased by one before the funtion get called, even inside another rountine
               b(v);
               
       }
}
