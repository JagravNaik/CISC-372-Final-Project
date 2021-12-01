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

