
int PINcompare(const char PIN[6], const char PIN2[6]) {
    int match = 0; // Variable to count the number of matching digits

    // Iterate over each digit in the PINs
    for (int i = 0; i < 6; i++) {
        if (PIN[i] == PIN2[i]) {
            match++; // Increment the count if the digits match
        }
    }

    // Check if all digits match or not
    if (match != 6) {
        return 1; // Return 1 if the PINs don't match
    } else {
        return 0; // Return 0 if the PINs match
    }
}
