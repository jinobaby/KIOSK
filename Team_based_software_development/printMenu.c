#define _CRT_SECURE_NO_WARNINGS


#include "implementation.h"
#include "printMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a menu and return the selected item
int printMenu(MenuItem menuItems[], int itemCount, char menuName[]) {
    printf("\n%s Menu:\n\n", menuName);
    for (int i = 0; i < itemCount; i++) {
        // Include calories in the displayed information
        printf("%2d. %-25s $%6.2f %5d calories\n", i + 1, menuItems[i].name, menuItems[i].price, menuItems[i].calories);
    }

    int choice = 0;
    while (1) {
        printf("\nEnter your choice: ");
        int scanfResult = scanf("%d", &choice); // Store the result of scanf to check for successful input
        // Flush stdin in case of overflow input
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { /* discard */ }

        if (choice > 0 && choice <= itemCount) {
            printf("\n%s Selected! - $%.2f\n\n", menuItems[choice - 1].name, menuItems[choice - 1].price);
            break;
        }
        else {
            printf("\nInvalid input, try again...\n");
        }
    }

    return choice - 1; // Return the index of the chosen item
}
