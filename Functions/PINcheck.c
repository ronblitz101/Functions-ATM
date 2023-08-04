
int PINcheck(char PIN[6]) {
    char PINconfirm[6] = {}; // Array to store the confirmed PIN
    int p = 0, not_match = 0; // Counter variable and mismatch count

    printf("\n\n\tConfirm your PIN");
    printf("\n\n\t\tRe-Enter PIN: ");
    do {
        PINconfirm[p] = getch(); // Read a character from input
        if (PINconfirm[p] != '\r') { // If the character is not the carriage return
            printf("*"); // Print an asterisk to mask the input
        }
        p++;
    } while (PINconfirm[p - 1] != '\r' && p <= 6); // Continue until carriage return or maximum length is reached
    PINconfirm[p - 1] = '\0'; // Terminate the confirmed PIN string

    for (int i = 0; i < 6; i++) {
        if (PIN[i] != PINconfirm[i]) { // Compare each character of the original and confirmed PIN
            not_match++; // Increment the mismatch count
        }
    }
    printf("\n");

    return not_match; // Return the number of mismatches
}
