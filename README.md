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
To run the serial code, run the sbatch_serial file with the command sbatch sbatch_serial. <br />
To run the OpenMP multicore code, run the sbatch_openmp file with the command sbatch sbatch_openmp. <br />
In order to change the number of threads uncoment the number of threads you wish in the sbatch_openmp file and comment the unused code.<br />
To run the OpenACC multicore code, run the sbatch_multicore file with the command sbatch sbatch_multicore <br />
In order to change the number of threads uncoment the number of threads you wish in the sbatch_multicore file and comment the unused code.<br />
To run the OpenACC GPU code, run the sbatch_openacc file with the command sbatch sbatch_openacc <br />
After you batch your the code you will get a slurm-#.out file to see our output times you will have to use the command cat slurm-#.out <br />

