refresher on dynamic memory allocations and deallocations using the Heap using C while avoiding resource leaks


## Assigment Requirements
General
- All print statements
- Valgrind
    - Use Valgrind to ensure there is no memory leak (copy output to readme)
    - Create a memory leak by deleting the dealocation statment (copy output to readme)

## Server neccessary commands
```sudo apt-get install zip```
```sudo apt-get install valgrind```

## Valgrind running
must compile with the -g  flag (debugging information)_
```valgrind --leak-check=full --show-leak-kinds=all ./Driver 12345```
