# CISC-372-Final-Project

TEAM MEMBERS:

Jagrav Naik (jnaik@udel.edu) @jagravnaik

Sebastian Gomez (sgomez@udel.edu) @sebanasho

INTRODUCTION TO CODE:
* We create 2 matrices
* First matrix with 3000 rows and 3000 columns
* Second matrix with 3000 rows and 2700 colums
* Multiply the matrices 10 times, the result will be a third matrix
* Compiling with GNU GCC takes ~14 minutes
* Compiling with NVHPC compiles takes ~16 minutes (without any pragmas) 
* Our goal is to reduce the time to run the code by parallelzing it with OpenMP and OpenACC


Required modules: \
gcc/10.2.0 <br />
nvhpc/21.7 <br />
cuda/11.1.1 <br />

To load the modules on bridges2, use the following commands:
<br />
module load gcc/10.2.0 <br />
module load nvhpc/21.7 <br />
module load cuda/11.1.1 <br />

EXCECUTING CODES: 

* To run the serial code, run the "**sbatch_serial**" file with the command "**sbatch sbatch_serial**". <br />
* To run the OpenMP multicore code, run the "**sbatch_openmp**" file with the command "**sbatch sbatch_openmp**". In order to change the number of threads uncoment the number of threads you wish in the "**sbatch_openmp**" file and comment the unused code.<br />
* To run the OpenACC multicore code, run the "**sbatch_multicore**" file with the command "**sbatch sbatch_multicore**". In order to change the number of threads uncoment the number of threads you wish in the "**sbatch_multicore**" file and comment the unused code.<br />
* To run the OpenACC GPU code, run the "**sbatch_openacc**" file with the command sbatch "**sbatch_openacc**". <br />
* After you batch your the code you will get a "**slurm-#.out**" file to see our output times you will have to use the command "**cat slurm-#.out**". <br />

ISSUES: 
* Using OpenMP multicore, "**matrix_openmp.c**" time increases when adding more threads, tried **#pragma omp parallel schedule(dynamic, 2)** in order to distribute the loop iterations, and go trough the first matrix then the second, with the chunk size of 2. sadly this method did not work, giving us a segmentation fault error. trying to add **#pragma omp parallel shared(row_matrix_1, col_matrix_1, col_matrix_2, col_matrix_3)** we wanted to share the data of this variables in order to threads have access to the copy in order to make the program hava better timming, using shared clause, also ended in a segmentation fault error. Finally after trying a lot we added what gave us the best timing and runned. 

