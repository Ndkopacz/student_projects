#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Reading the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Fore each line in the file when it returns true
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Convert the ascii to integer
        int n = atoi(line);

        printf("===========================================\nGenerator Process: Processing line \"%d\"\n===========================================\n", n);

        // Fork for Fibonacci process
        pid_t pid1 = fork();
        if (pid1 == 0) {
            // This is the child process
            execlp("./Fibonacci", "Fibonacci", line, NULL);
            perror("Error executing Fibonacci");
            exit(1);
        }

        int status1;
        printf("Waiting for the Child Process: (PID: %d)\n", pid1);
        waitpid(pid1, &status1, 0);
        int fib_result = WEXITSTATUS(status1);
        printf("./Fibonacci Process finished (PID: %d). Returned: %d\n\n", pid1, fib_result);

        // Fork for Perrin process
        pid_t pid2 = fork();
        if (pid2 == 0) {
            char arg[16];
            snprintf(arg, sizeof(arg), "%d", fib_result);
            execlp("./Perrin", "Perrin", arg, NULL);
            perror("Error executing Perrin");
            exit(1);
        }

        int status2;
        printf("Waiting for the Child Process: (PID: %d)\n", pid2);
        waitpid(pid2, &status2, 0);
        int perrin_result = WEXITSTATUS(status2);
        printf("./Perrin Process finished (PID: %d). Returned: %d\n\n", pid2, perrin_result);

        // Fork for Composite process
        pid_t pid3 = fork();
        if (pid3 == 0) {
            char arg[16];
            snprintf(arg, sizeof(arg), "%d", perrin_result);
            execlp("./Composite", "Composite", arg, NULL);
            perror("Error executing Composite");
            exit(1);
        }

        int status3;
        printf("Waiting for the Child Process: (PID: %d)\n", pid3);
        waitpid(pid3, &status3, 0);
        int composite_result = WEXITSTATUS(status3);
        printf("./Composite Process finished (PID: %d). Returned: %d\n\n", pid3, composite_result);
    }

    fclose(file);
    return 0;
}