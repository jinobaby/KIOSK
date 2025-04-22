# E-Restaurant Kiosk System

This project is a console-based E-Restaurant Kiosk System that allows users to place orders, leave reviews, and generate receipts. It is implemented in C and includes unit tests for key functionalities.

## Project Structure

### Main Application
The main application is located in the `Team_based_software_development` folder and contains the following files:

- **`main.c`**: Entry point of the application. Handles user interaction, menu selection, and order processing.
- **`printMenu.c`**: Displays menus and handles user selection.
- **`printReceipt.c`**: Prints the receipt to the console.
- **`receiptFile.c`**: Saves the receipt to a file (`receipt.txt`).
- **`subtotal.c`**: Calculates the subtotal of the order.
- **`tip.c`**: Handles tip calculation, including custom and random tips.
- **`reviews.c`**: Manages reviews for menu items.
- **Header Files**:
  - `calculations.h`: Declares calculation-related functions.
  - `implementation.h`: Defines the `MenuItem` structure.
  - `printMenu.h`: Declares the menu printing function.
  - `receipt.h`: Declares receipt-related functions.
  - `reviews.h`: Declares review-related functions.

### Unit Testing
The unit tests are located in the `TestingKiosk` folder and include:

- **`TestingKiosk.cpp`**: Contains unit tests for:
  - Subtotal calculation.
  - Tip calculation.
  - Review initialization and addition.
- **`pch.h`** and **`pch.cpp`**: Precompiled headers for faster compilation.

## Features

1. **Menu Selection**:
   - Users can select items from four menus: Main, Sides, Drinks, and Desserts.
   - Each menu displays item names, prices, and calorie counts.

2. **Order Processing**:
   - Users can place multiple orders up to a specified limit.
   - Orders are stored in memory and processed at checkout.

3. **Receipt Generation**:
   - Receipts are printed to the console and saved to a file (`receipt.txt`).
   - Includes subtotal, tax, tip, and total.

4. **Tip Calculation**:
   - Users can choose a custom tip or a random tip less than 25% of the subtotal.

5. **Review System**:
   - Users can leave reviews for menu items.
   - Reviews are stored in a 2D array.

6. **Unit Testing**:
   - Includes tests for subtotal calculation, tip calculation, and review functionality.


## Console Output
```
========================
Welcome to E-Restaurant!
========================
Select Menu:
1. Main Menu
2. Sides Menu
3. Drinks Menu
4. Desserts Menu
5. Checkout
6. Cancel Order
```
## Receipt Output

```
Items Ordered:
1. Cheeseburger $10.99

Subtotal: $10.99
Tax: $1.43
Tip: $0.00
Total: $12.42

Thank you for your visit! Enjoy your meal!
```
