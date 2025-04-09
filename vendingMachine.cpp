#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Vending Machine Item Inventory
// PRICE, NAME, SKU, qtyLeft
struct Item {
    float price;
    string name;
    int sku;
    int qtyLeft;
};
Item inventory[9];
const int invSize = 9; // 9 is the FINAL size

void initVendingMachine();
void displayItems();
int selectItem();
void decrementQty(int x);
bool processPayment(int y);
void calculateChange(float a, float b);
void runVendingMachine();
void dispenseItem(int h);

void initVendingMachine() {
    inventory[0] = {1.50, "Soda", 101, 5};
    inventory[1] = {1.00, "Chips", 102, 8};
    inventory[2] = {2.00, "Candy", 103, 9};
    inventory[3] = {0.75, "Gum", 104, 5};
    inventory[4] = {1.25, "Water", 105, 3};
    inventory[5] = {1.75, "Energy Drink", 106, 2};
    inventory[6] = {0.50, "Cookie", 107, 5};
    inventory[7] = {2.50, "Sandwich", 108, 5};
    inventory[8] = {1.10, "Pretzels", 109, 0};
}

void displayItems() {
    // Top border and title
    cout << "+-------------------------------+" << endl;
    cout << "|     VENDING MACHINE           |" << endl;
    cout << "+-------------------------------+" << endl;

    // Column headers
    cout << "| SKU | ITEM          | PRICE  |" << endl;
    cout << "+-------------------------------+" << endl;

    // Display each item
    for (int i = 0; i < 9; i++) {
        cout << "| "; // Left border
        cout << setw(3) << inventory[i].sku << " | "; // SKU (3 chars wide)
        cout << left << setw(13) << inventory[i].name << " | "; // Name (13 chars wide, left-aligned)
        cout << "$" << fixed << setprecision(2) << setw(4) << inventory[i].price << " | "; // Price ($X.XX format)

        // Stock status (outside the main table for simplicity)
        if (inventory[i].qtyLeft > 0) {
            cout << "(" << inventory[i].qtyLeft << " left)";
        } else {
            cout << "(OUT)";
        }
        cout << endl;
    }

    // Bottom border and prompt
    cout << "+-------------------------------+" << endl;
    cout << "| Enter SKU to select item:     |" << endl;
    cout << "+-------------------------------+" << endl;
}

// selectItem Function
    // Take user input SKU
    // search array for matching SKU
    // return the index if found and stock > 0 else return 0
int selectItem() {
    int sku;
    cout << "What would you like to buy?";
    while (true) {
        cin >> sku;
        if (sku == 0) return -1;
        if (sku > 109 || sku < 101) {
            cout << "Invalid SKU. Please try again." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        for (int i = 0; i < 9; i++) {
            if (inventory[i].sku == sku) {
                if (inventory[i].qtyLeft > 0) {
                    decrementQty(i);
                    return i;
                }
                cout << inventory[i].name << " is out of stock.." << endl;
                displayItems();
                break;
                }
            }

        }
    }

// decrementQty Function
    // decrement qty of sku
void decrementQty(int x) {
    inventory[x].qtyLeft -= 1;
}

// processPayment Function
bool processPayment(int y) {
    float itemPrice = inventory[y].price;
    float cashInserted = 0;
    float input;

    cout << "This item costs $" << itemPrice << "\n" << endl;
    cout << "Please insert cash($1, $2, $5, $20) or coins(.01, .05, .10, .25)" << endl;

    while (cashInserted < itemPrice) {
        cin >> input;

        if (input == 0) {
            cout << "Payment canceled." << endl;
            return false;
        }
        if (input != 1.00 && input != 2.00 && input != 5.00 && input != 20.00 &&
            input != 0.01 && input != 0.05 && input != 0.10 && input != 0.25) {
            cout << "Invalid amount! Use $1, $2, $5, $20, or coins 0.01, 0.05, 0.10, 0.25: ";
            cin.clear();
            cin.ignore();
            continue;
            }

        cashInserted += input;
        cout << "Total: $" << fixed << setprecision(2) << cashInserted;
        if (cashInserted < itemPrice) {
            cout << ", Need $" << (itemPrice - cashInserted) << " more: ";
        } else {
            cout << " - Payment complete!" << endl;
        }
    }

    calculateChange(cashInserted, itemPrice);
    return true;

    }

// calculateChange Function
void calculateChange(float a, float b) {
    cout << "Your change is: " << a - b << endl;
}

// dispenseItem Function
void dispenseItem(int h) {
    cout << "Dispensing " << inventory[h].name << endl;
    cout << "Thank you for ordering with us!" << endl;

}



// runVendingMachine Function
void runVendingMachine() {
    initVendingMachine();
    displayItems();
    bool processPaymentValue = true;
    while (processPaymentValue) {
        int invIndex;
        invIndex = selectItem();
        if (invIndex == -1) {
            break;
        }
        processPaymentValue = processPayment(invIndex);
        dispenseItem(invIndex);
    }
}

int main() {
    runVendingMachine();
    return 0;
}
