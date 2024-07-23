#define _CRT_SECURE_NO_WARNINGS

#include "implementation.h"
#include "printMenu.h"
#include "calculations.h"
#include "receipt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//similar function to print it in a receipt.txt file:
void printReceiptToFile(MenuItem* orderedItems, int orderCount, float subtotal, float tip) {
    FILE* file = fopen("receipt.txt", "w"); // Open the file for writing
    if (file == NULL) {
        printf("Error opening file!\n");
        return; // Exit the function if file cannot be opened
    }

    fprintf(file, "\n\nItems Ordered:\n");
    for (int i = 0; i < orderCount; i++) {
        fprintf(file, "%d. %s\t$%.2f\n", i + 1, orderedItems[i].name, orderedItems[i].price);
    }
    float tax = subtotal * 0.13; // Assuming a tax rate of 13%
    float total = subtotal + tax + tip;

    fprintf(file, "\nSubtotal: $%.2f\n", subtotal);
    fprintf(file, "Tax: $%.2f\n", tax);
    fprintf(file, "Tip: $%.2f\n", tip);
    fprintf(file, "Total: $%.2f\n", total);
    fprintf(file, "\nThank you for your visit! Enjoy your meal!\n");

    fclose(file); // Close the file
}