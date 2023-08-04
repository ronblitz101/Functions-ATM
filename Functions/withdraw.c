

float withdraw(float amnt, float *curr_bal) {
    int wid_conf, rep; // Variables for withdrawal confirmation and repetition

    printf("\n\t>>> You want to withdraw P%.2f.", amnt);
    printf("\n\nDo you want to proceed?");
    printf("\n\t[1] OK\n\t[0] Cancel\n\t>\t");

    do
    {
        if (scanf("%d", &wid_conf) != 1)
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

    if (amnt < 0) {
        printf("\n\nInvalid transaction. You cannot withdraw a negative amount!");
        getch();
    }
    else if (amnt <= *curr_bal) {

        if (wid_conf == 1) {
            processing_screen();
            *curr_bal -= amnt; // Subtract the withdrawal amount from the current balance

            printf("\n\n\t>>> Your current balance is P%.2f", *curr_bal);
            printf("\n\nWithdrawal Successful! Please get your money.");
            getch();
        } else if (wid_conf == 0) {
            printf("\n>> Withdrawal Unsuccessful!");
            getch();
        }
    }
    else {
        printf("\n\nInvalid transaction. Your withdrawn amount is bigger than your current balance!");
        getch();
    }
    printf("\n\n============================================");

    do
    {
        printf("\n\nDo you want to withdraw again?");
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

    return rep; // Return the value indicating whether to repeat the withdrawal or not
}

