

float deposit(float amnt, float *curr_bal) {
    int depo_conf, rep; // Variables for deposit confirmation and repetition

    printf("\n\t>>> You want to deposit P%.2f.", amnt);
    printf("\n\nDo you want to proceed?");
    printf("\n\t[1] OK\n\t[0] Cancel\n\t>\t");

    do
    {
        if (scanf("%d", &depo_conf) != 1)
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

    if (amnt >= 0) {
        if (depo_conf == 1) {
            processing_screen();
            printf("\n\n\tDeposit Successful!");

            *curr_bal += amnt; // Add the deposited amount to the current balance

            printf("\n\n>>> Your current balance is P%.2f", *curr_bal);
            getch();
        } else if (depo_conf == 0) {
            printf("\n\n>> Deposit Unsuccessful!");
            getch();
        }
    }
    else {
        printf("\n\nInvalid transaction. You cannot deposit a negative amount!");
        getch();
    }
    printf("\n\n============================================");

    do
    {
        printf("\n\nDo you want to deposit again?");
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

    return rep; // Return the value indicating whether to repeat the deposit or not
}
