#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <...\processing_screen.c>
#include <...\aborting_screen.c>
#include "...\PINcheck.c"
#include "...\PINcompare.c"
#include "...\PINrecheck.c"
#include "...\withdraw.c"
#include "...\deposit.c"
#include "...\inquiry.c"
#include "...\exit_menu.c"

** Remove "..." and replace with the file path on your computer**


float curr_bal = 5000;

int main (int argc, char *argv[]) {

    char PIN[6] = {};
    char PIN_comp[6] = {};
    int PINpass = 0, p = 0;
    int check, x = 0;
    int rep, choice = 0, exit_conf = 0, re_enter = 0;
    float depo, wid_amt;

    printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\t\tR2 Banking");
    printf("\n::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\n      Welcome to R2 ATM! Your 24/7 bank. \n\n");

    processing_screen();

    for (int i = 0; i < 6; i++)
    {
        if (PIN[i] == '\0')
        {
            PINpass++;
        }
    }

    if (PINpass != 0)
    {
        printf("\n\n\n---------------------------------------------------");
        printf("\n\n\tPlease create a 4- or 6-digit PIN");
        printf("\n\n\t\tEnter PIN: ");

        do
        {
            PIN[p] = getch();
            if (PIN[p] != '\r')
            {
                printf("*");
            }
            p++;
        } while (PIN[p - 1] != '\r' && p <= 6);
        PIN[p - 1] = '\0';

        do
        {
            check = PINcheck(PIN);
            if(check > 0)
            {
                check = 0;
                printf("\n\t>> Error!");
                x = 1;
                getch();
            }
            else if (check == 0)
            {
                break;
            }
        } while (x == 1);
    }
    while (choice == 0||choice==1||choice==2||choice==3||choice==4||exit_conf==0)
    {
        printf("\n\n#####################################################################################");
        printf("\n\nWhat do you want to do?\n");

        do
        {
            printf("\n|\t1. Deposit\t|\t2. Withdrawal\t|\t3. Change PIN\t|\n");
            printf("\n|\t4. Inquiry\t|\t5. Exit\t\n\n>\t");

            if (scanf("%d", &choice) != 1)
            {
                printf("\n\t\t>> Invalid input. Try again.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue; // Restart the loop
            }

            if (choice < 1 || choice > 5) {
                printf("\n\t\t>> Invalid input. Try again.\n");
                getch();
            }
        } while (choice < 1 || choice > 5);


        if (choice == 1)
        {
            PINrecheck (PIN);

            do
            {
                printf("\n#####################################################################################\n");
                printf("\nChosen Menu: Deposit\n\n");
                printf("\tEnter amount: ");
                scanf("%f", &depo);

                rep = deposit(depo, &curr_bal);

            } while (rep == 1);
        }

        else if (choice == 2)
        {
            PINrecheck (PIN);

            do
            {
                printf("\n#####################################################################################\n");
                printf("\nChosen Menu: Withdrawal\n\n");
                printf("\tEnter amount: ");
                scanf("%f", &wid_amt);

                rep = withdraw(wid_amt, &curr_bal);

            } while (rep == 1);

        }
        
        else if (choice == 3)
        {
            printf("\n#####################################################################################\n");
            printf("\nChosen Menu: Change PIN\n\n");

            PINrecheck(PIN);

            p = 0;
            x = 0;

            for (int i = 0; i < 6; i++)
            {
                PIN[i] = '\0';
            }

            printf("\n\n\t----------------------------------------------------");
            printf("\n\n\tPlease enter your new 4- or 6-digit PIN");
            printf("\n\n\t\tEnter PIN: ");
            do
            {
                PIN[p] = getch();
                if (PIN[p] != '\r')
                {
                    printf("*");
                }
                p++;
            } while (PIN[p - 1] != '\r' && p <= 6);
            PIN[p - 1] = '\0';

            do
            {
                check = PINcheck(PIN);
                if(check > 0)
                {
                    check = 0;
                    printf("\n\t\t>> Error!");
                    x = 1;
                    getch();
                }
                else if (check == 0)
                {
                    break;
                }
            } while (x == 1);
        }

        else if (choice == 4)
        {
            PINrecheck (PIN);

            do
            {
                printf("\n#####################################################################################\n");
                printf("\nChosen Menu: Inquiry\n");

                rep = inquiry(&curr_bal);

            } while (rep == 1);
        }

        else if (choice == 5)
        {
            printf("\n#####################################################################################\n");
            do
            {
                printf("\n\nAre you sure you want to exit?");
                printf("\n\t[1] Yes\n\t[0] No\n\t>\t");

                if (scanf("%d", &exit_conf) != 1)
                {
                    printf("\n\t\t>> Invalid input. Try again.\n");
                    getch();
                    // Clear the input buffer
                    while (getchar() != '\n');
                }
            } while (exit_conf != 0 && exit_conf != 1);

            exit_menu(exit_conf);
        }

        else
        {
            printf("\n\t>> Invalid input. Please try again.\n\n");
            getch();
        }
    }
    return 0;
}
