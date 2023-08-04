

void PINrecheck (const char PIN[6]) {
    int re_enter, p = 0;
    char PIN_comp[6] = {};
    do
    {
        printf("\n\tEnter your current PIN: ");
        do
        {
            PIN_comp[p] = getch();
            if (PIN_comp[p] != '\r')
            {
                printf("*");
            }
            p++;
        } while (PIN_comp[p - 1] != '\r' && p <= 6);
        PIN_comp[p - 1] = '\0';

        re_enter = PINcompare(PIN, PIN_comp);

        if (re_enter == 1)
        {
            printf("\n\n\t\t>> PIN do not match!\n");
            getch();

            for (int i = 0; i < 6; i++)
            {
                PIN_comp[i] = '\0';
            }
            p = 0;
        }

    } while (re_enter == 1);

    printf("\n\n\t>> Proceeding with your chosen menu...\n");
}

