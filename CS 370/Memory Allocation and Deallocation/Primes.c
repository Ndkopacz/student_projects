/*
w1. Dynamically allocate and deallocate a random sized array for each iteration.
2. Populate elements in the array with random integers.
3. For each iteration, check all the elements in the array and determine whether each element is
prime or not, and if so, count it.
4. Calculate the ratio of primes to composites given by
Ratio = count of primes / count of composites
5. At the end, print the iteration number with maximum count of primes.
6. Return the average value of the ratio for all iterations to Driver.
*/

/*
get_running_ratio() - handles all of the above functions

int random_in_range(int lower_bound, int upper_bound) -  takes a lower
limit (inclusive) and an upper limit (exclusive) and returns a random integer value between
them

int get_prime_count(int *array, int arraySize) - iterate over the elements of the array and
check if how many primes they contain. Return the number of primes counted.
*/

/*
All print statements must mention the program that is responsible for generating them. To do this,
please prefix your print statements with the program name i.e. Driver or Primes.
*/