

int processing_screen(void) {
    printf("\n\t    Processing");

    for (int i = 0; i < 10; i++) {
        printf("..");
        fflush(stdout);  // Flush the output buffer

        // Add a delay to simulate loading
        usleep(250000);  // Sleep for 250 milliseconds (0.25 seconds)

        printf("\b");  // Move the cursor back by one character
    }
}
