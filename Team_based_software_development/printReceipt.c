#define _CRT_SECURE_NO_WARNINGS

#include "implementation.h"
#include "printMenu.h"
#include "calculations.h"
#include "receipt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print the receipt
void printReceipt(MenuItem* orderedItems, int orderCount, float subtotal, float tip) {
    printf("\n\nItems Ordered:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d. %s\t$%.2f\n", i + 1, orderedItems[i].name, orderedItems[i].price);
    }
    float tax = subtotal * 0.13;
    float total = subtotal + tax + tip;

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax); //Assuming a tax rate of 13 %
    printf("Tip: $%.2f\n", tip);
    printf("Total: $%.2f\n", total);
    printf("\nThank you for your visit! Enjoy your meal!\n");
}