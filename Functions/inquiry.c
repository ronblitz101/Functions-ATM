

int inquiry(float *curr_bal) {
    int rep; // Variable for repetition choice

    processing_screen(); // Simulate processing

    printf("\n\n\t>>> Your current balance is P%.2f", *curr_bal); // Display the current balance
    getch();

    printf("\n\n============================================");
    printf("\n\nDo you want to inquire your balance again?");

    do {
        printf("\n\t[1] Yes\n\t[0] No\n\t>\t");
        if (scanf("%d", &rep) != 1)
        { // Check if the input is a valid integer
            printf("\n\t>> Invalid input. Please enter 0 or 1.\n");
            getch();
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);

    printf("\n");

    return rep; // Return the value indicating whether to repeat the inquiry or not
}
