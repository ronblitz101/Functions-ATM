

int aborting_screen(void) {
    printf("\n\n\t    Exiting");

    for (int i = 0; i < 10; i++) {
        printf("..");
        fflush(stdout);  // Flush the output buffer

        // Add a delay to simulate loading
        usleep(100000);  // Sleep for 100 milliseconds (0.1 seconds)

        printf("\b");  // Move the cursor back by one character
    }
}