--------------------- File Descriptions ---------------
This project contains four programs:

1. Generator.c - This is the main program that forks child processes and executes Fibonacci, Perrin, and Composite.
2. Fibonacci.c - This program calculates the sum of the first n Fibonacci numbers.
3. Perrin.c - This program calculates the sum of the first n Perrin sequence numbers.
4. Composite.c - This program calculates the sum of the first n composite numbers.

To compile the programs, run `make`.
To clean the compiled files, run `make clean`.

----------------------- WARNING --------------------
The sample output of HW2.pdf does NOT match what the expected output of the file. 
-> The sample output directly contradicts itself
-> "sum of the first n Fibonacci Numbers and the nth Fibonacci number" (Note the nth fibonacci number is supposed to be added)
-> Sample output "Sum of first 5 Fibonacci numbers is 7"
-> Sample output "The nth Fibonacci number is 5"
-> These two lines directly contradict themselves as if the nth number is considered the sum would actually be 12!

-> This problem exists for the Fibonacci and for the Perrin sequences

Also please note, there are two different interpretations of these sequences with the first number (0) sometimes being ommited and sometimes not.

*The programs created in this assignment are tailored to match the sample output text and NOT the description*

------------------------- OUTPUTS - Expected ---------------------------
===========================================
Generator Process: Processing line "5"
===========================================
Waiting for the Child Process: (PID: 89005)
Fibonacci: Sum of first 5 Fibonacci numbers is 7
Fibonacci: The nth Fibonacci number is 5
./Fibonacci Process finished (PID: 89005). Returned: 7

Waiting for the Child Process: (PID: 89006)
Perrin: Sum of first 7 Perrin numbers is 20
Perrin: The nth Perrin number is 5
./Perrin Process finished (PID: 89006). Returned: 20

Waiting for the Child Process: (PID: 89007)
Composite: Sum of first 20 Composite numbers is 367
Composite: The nth Composite number is 32
./Composite Process finished (PID: 89007). Returned: 20

===========================================
Generator Process: Processing line "10"
===========================================
Waiting for the Child Process: (PID: 89008)
Fibonacci: Sum of first 10 Fibonacci numbers is 88
Fibonacci: The nth Fibonacci number is 55
./Fibonacci Process finished (PID: 89008). Returned: 10

Waiting for the Child Process: (PID: 89009)
Perrin: Sum of first 10 Perrin numbers is 49
Perrin: The nth Perrin number is 12
./Perrin Process finished (PID: 89009). Returned: 49

Waiting for the Child Process: (PID: 89010)
Composite: Sum of first 49 Composite numbers is 1846
Composite: The nth Composite number is 69
./Composite Process finished (PID: 89010). Returned: 49

------------------------- OUTPUTS - TRUE ---------------------------
===========================================
Generator Process: Processing line "5"
===========================================
Waiting for the Child Process: (PID: 89089)
Fibonacci: Sum of first 5 Fibonacci numbers is 12
Fibonacci: The nth Fibonacci number is 5
./Fibonacci Process finished (PID: 89089). Returned: 12

Waiting for the Child Process: (PID: 89090)
Perrin: Sum of first 12 Perrin numbers is 117
Perrin: The nth Perrin number is 29
./Perrin Process finished (PID: 89090). Returned: 12

Waiting for the Child Process: (PID: 89091)
Composite: Sum of first 12 Composite numbers is 153
Composite: The nth Composite number is 21
./Composite Process finished (PID: 89091). Returned: 153

===========================================
Generator Process: Processing line "10"
===========================================
Waiting for the Child Process: (PID: 89092)
Fibonacci: Sum of first 10 Fibonacci numbers is 143
Fibonacci: The nth Fibonacci number is 55
./Fibonacci Process finished (PID: 89092). Returned: 10

Waiting for the Child Process: (PID: 89093)
Perrin: Sum of first 10 Perrin numbers is 66
Perrin: The nth Perrin number is 17
./Perrin Process finished (PID: 89093). Returned: 66

Waiting for the Child Process: (PID: 89094)
Composite: Sum of first 66 Composite numbers is 3222
Composite: The nth Composite number is 91
./Composite Process finished (PID: 89094). Returned: 66