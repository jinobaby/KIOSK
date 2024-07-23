#include "calculations.h"
#include "printMenu.h"
#include "implementation.h"

// Function to compute sub-total for the order:
float computeSubtotal(MenuItem orderedItems[], int orderCount) {
    float subtotal = 0.0;
    for (int i = 0; i < orderCount; i++) {
        subtotal += orderedItems[i].price;
    }
    return subtotal;
}