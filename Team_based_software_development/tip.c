#include "calculations.h"


// Function to give a custom tip or a tip less than 25% of the subtotal
float calculateTip(float subtotal, int tipOption) {
    float tip = 0.0;
    if (tipOption == 1) { // Custom tip
        printf("Enter your custom tip amount: ");
        int scanfFix = scanf("%f", &tip);
    }
    else if (tipOption == 2) { // Random tip less than 25% of subtotal
        srand(time(0));
        float maxTipPercentage = 0.25;
        float randomPercentage = (rand() % 25) / 100.0; // Generates a random percentage between 0% and 24%
        tip = subtotal * randomPercentage;
    }
    else
        tip = 0.0;
    return tip;
}

float calculateTipCustom(float subtotal, int tipOption, float customTip) {
    float tip = 0.0;
    if (tipOption == 1) { // Custom tip
       // printf("Enter your custom tip amount: ");
       // int scanfFix = scanf("%f", &tip);
        return customTip;
    }
    else if (tipOption == 2) { // Random tip less than 25% of subtotal
        srand(time(0));
        float maxTipPercentage = 0.25;
        float randomPercentage = (rand() % 25) / 100.0; // Generates a random percentage between 0% and 24%
        tip = subtotal * randomPercentage;
    }
    else
        tip = 0.0;
    return tip;
}

