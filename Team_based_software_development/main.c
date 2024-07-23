#define _CRT_SECURE_NO_WARNINGS

#include "implementation.h"
#include "printMenu.h"
#include "calculations.h"
#include "receipt.h"
#include "reviews.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s <number_of_orders>\n", argv[0]);
        return 1;
    }
    int numOrders = atoi(argv[1]); // Convert the argument to an integer
    if (numOrders <= 0) {
        printf("The number of orders must be a positive integer.\n");
        return 1;
    }

    MenuItem mainMenu[] = {
        {"Cheeseburger", 10.99, 300},
        {"Double Cheeseburger", 12.00, 450},
        {"Hotdog", 8.99, 250},
        {"BLT Sandwich", 7.99, 400},
        {"Chicken burger", 7.99, 350}
    };

    MenuItem sideMenu[] = {
        {"Fries", 3.49, 200},
        {"Sweet Potato Fries", 3.99, 220},
        {"Onion Rings", 3.49, 180}
    };

    MenuItem drinkMenu[] = {
        {"Lemonade", 2.49, 120},
        {"Iced Tea", 2.99, 100},
        {"Orange Juice", 2.99, 150},
        {"Apple Juice", 2.99, 150}
    };

    MenuItem dessertMenu[] = {
        {"Doughnut", 2.49, 250},
        {"Choco Chip Cookie", 1.49, 180},
        {"Cinnamon Roll", 2.99, 300}
    };

    // Max orders = user choice in command line argument
    MenuItem* orderedItems = malloc(sizeof(MenuItem) * numOrders);
    if (!orderedItems) {
        printf("Failed to allocate memory.\n");
        return 1; // Handle memory allocation failure
    }


    //Review system:
    float reviews[MAX_ITEMS][MAX_REVIEWERS];
    initializeReviews(reviews);

    int orderCount = 0;
    printf("========================\n");
    printf("Welcome to E-Restaurant!\n");
    printf("========================\n");
    
    int menuDecision;
    int selectCheckout = 0;
    while (!selectCheckout && (orderCount < numOrders)) {
        printf("=============\n");
        printf("Select Menu:\n1. Main Menu\n2. Sides Menu\n3. Drinks Menu\n4. Desserts Menu\n5. Checkout\n6. Cancel Order\n");
        printf("=============\n");
        int scanfFIX = scanf("%d", &menuDecision);
        switch (menuDecision) {
        case 1:
            orderedItems[orderCount++] = mainMenu[printMenu(mainMenu, sizeof(mainMenu) / sizeof(mainMenu[0]), "Main")];
            break;
        case 2:
            orderedItems[orderCount++] = sideMenu[printMenu(sideMenu, sizeof(sideMenu) / sizeof(sideMenu[0]), "Sides")];
            break;
        case 3:
            orderedItems[orderCount++] = drinkMenu[printMenu(drinkMenu, sizeof(drinkMenu) / sizeof(drinkMenu[0]), "Drinks")];
            break;
        case 4:
            orderedItems[orderCount++] = dessertMenu[printMenu(dessertMenu, sizeof(dessertMenu) / sizeof(dessertMenu[0]), "Desserts")];
            break;
        case 5:
            selectCheckout = 1;
            break;
        case 6:
            printf("Are you sure you wish to cancel the order? (yes/no)\n");
            char cancelDecision[10];
            char* scanfFIX = scanf("%s", cancelDecision);
            if ((strcmp(cancelDecision, "yes")) == 0) {
                printf("\nCanceling Order...\n\n");
                free(orderedItems);
                exit(EXIT_FAILURE);
            }
            else
                printf("\n");
            break;
        default:
            printf("Invalid input, please try again...\n");
            break;
        }
    }

    if (orderCount == 0) {
        printf("\nNo selections made. We look forward to your next visit. Have a nice day!\n");
        return 0;
    }
    
    //Review:
    char reviewChoice;
    printf("Would you like to leave a review for your selected item? (y/n): ");
    int scanfFIX = scanf(" %c", &reviewChoice); // Notice the space before %c to consume any leftover newline character
    if (reviewChoice == 'y' || reviewChoice == 'Y') {
        float score;
        printf("Please enter your rating for the item (1-5): ");
        int scanfFIX4 = scanf("%f", &score);
        int lastItemIndex = orderCount - 1;
        addReview(reviews, lastItemIndex, score);
    }
    
    
    //subtotal
    float subtotal = computeSubtotal(orderedItems, orderCount);

    //tip
    printf("\nYour subtotal is $%.2f\nWould you like to add a tip?\n", subtotal);
    printf("1. Yes, I'll enter a custom tip amount.\n");
    printf("2. Yes, add a random tip less than 25%% of the subtotal.\n");
    printf("3. No tip.\n");
    printf("Please enter your choice: ");
    int choice;
    int scanfFix2 = scanf("%d", &choice);
    float tip = calculateTip(subtotal, choice);

    //total
    printReceipt(orderedItems, orderCount, subtotal, tip);
    printReceiptToFile(orderedItems, orderCount, subtotal, tip);
    printf("\nPrinting Receipt...\n");
    free(orderedItems);
    return 0;
}
