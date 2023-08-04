

void exit_menu(int conf) {
    if (conf == 1) {
        printf("\n#####################################################################################\n");
        processing_screen(); // Simulate processing
        printf("\n\n>>> Please get your card.");
        aborting_screen(); //Simulate exiting
        printf("\n\n>>> Thank you for using R2 Banking!\n\n");
    }
}

