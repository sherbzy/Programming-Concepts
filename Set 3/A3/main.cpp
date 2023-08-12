/*CSCI 261 Assignment 3 - Sprockets-R-Us Shopping Cart
 *
 * Program Name: Sprockets-R-Us Shopping Cart
 * Description: The program reads the sprockets product information from the external file. Then, it asks the user for order
 * information before creating an order receipt.
 *
 * Author: Lauren Sherburne
 * Date: September 17, 2019
 *
 */

//use standard namespace and include the following libraries: iostream, iomanip, fstream, cmath
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


int main () {
//Read product information from external file.
    //Declare variables for the price per individual Sprocket, the sales tax percentage, the three shipping rates, and
    //the minimum amount to qualify for free shipping
    double pricePerSprocket, salesTaxPercent, freeShipMin;
    double shipMinOne, shipRateOne, shipMinTwo, shipRateTwo, shipMinThree, shipRateThree;

    //Assign values to the variables using the external file.
    //Open file
    ifstream sprocketsFileInput ("product_public.txt");

    //Check for error
    if (sprocketsFileInput.fail()) {
        cerr << "Error opening file to read." << endl;
        return -1;
    }

    //Read input
    sprocketsFileInput >> pricePerSprocket;
    sprocketsFileInput >> salesTaxPercent;
    sprocketsFileInput >> shipMinOne >> shipRateOne;
    sprocketsFileInput >> shipMinTwo >> shipRateTwo;
    sprocketsFileInput >> shipMinThree >> shipRateThree;
    sprocketsFileInput >> freeShipMin;

    //Close file
    sprocketsFileInput.close();

//Ask the user for order information
    //Declare a variable for how many sprockets the user orders
    int userOrderNum;

    //Welcome the user and prompt them to input the number of sprockets they wish to order. Store this value in userOrderNum
    cout << "Welcome to Sprockets-R-Us!" << endl;
    cout << "We sell round sprockets, square sprockets, and triangle sprockets." << endl;
    cout << "The cost of a single sprocket is " << fixed << setprecision(2) << pricePerSprocket << endl;
    cout << "How many sprockets do you wish to order?" << endl;
    cout << "> ";
    cin >> userOrderNum;

    //Print the number of sprockets the user ordered to the screen
    cout << "Thank you for your order of " << userOrderNum << " sprockets! One moment while we prepare your receipt..."<< endl;

//Create a receipt for the user
    //Declare variables for: product/order price, user's shipping fee, first subtotal, sales tax decimal, sales tax for
    // the order, second subtotal, donationAnswer, donation amount, grand total
    double orderPrice;
    double orderShippingFee;
    double firstSubtotal;
    double salesTaxDeci = salesTaxPercent / 100;
    double orderSalesTax;
    double secondSubtotal;
    char donationAnswer;
    double donationAmount;
    double grandTotal;

    //Determine the product/order price
    orderPrice = pricePerSprocket * userOrderNum;

    //Determine the shipping fee
    if ((orderPrice >= shipMinOne) && (orderPrice < shipMinTwo)) {
        orderShippingFee = shipRateOne;
    } else if ((orderPrice >= shipMinTwo) && (orderPrice < shipMinThree)) {
        orderShippingFee = shipRateTwo;
    } else if ((orderPrice >= shipMinThree) && (orderPrice < freeShipMin)) {
        orderShippingFee = shipRateThree;
    } else {
        orderShippingFee = 0.0;
        //If the user qualifies for free shipping, thank them for their large purchase
        cout << "Due to your large purchase, you qualify for free shipping. Thank you!!" << endl;
    }

    //Compute the user's first subtotal: product/order price and shipping fee
    firstSubtotal = orderPrice + orderShippingFee;

    //Determine the sales tax for the order
    orderSalesTax = firstSubtotal * salesTaxDeci;

    //Round the fraction of a penny up or down as needed
    orderSalesTax = orderSalesTax * 100;
    orderSalesTax = round(orderSalesTax);
    orderSalesTax = orderSalesTax / 100;


    //Compute the user's second subtotal: product/order price, shipping fee, and sales tax
    secondSubtotal = firstSubtotal + orderSalesTax;

    //If the second subtotal is not an even dollar amount, ask the user if they want to make a donation and round up
    //their total to the nearest dollar amount.

    if ((secondSubtotal - (round(secondSubtotal))) != 0) {
        cout << "Do you wish to make a donation to the human fund and round your subtotal " << secondSubtotal;
        cout << " to the nearest dollar amount?" << endl;
        cout << "Enter \"Y\" for \"Yes\" and \"N\" for \"No\":" << endl;
        cout << "> ";

        cin >> donationAnswer;

        while (donationAnswer != 'n' && donationAnswer != 'Y' && donationAnswer != 'y' && donationAnswer != 'N') {
            cout << "I'm sorry. This was not a valid answer, please enter \"Y\" for \"Yes\" and \"N\" for \"No\":" << endl;
            cout << "> ";
            cin >> donationAnswer;
        }
    }


    //Compute the grand total of the order
    if (donationAnswer == 'Y' || donationAnswer == 'y') {
        donationAmount = ceil(secondSubtotal) - secondSubtotal;
        grandTotal = ceil(secondSubtotal);
    } else {
        donationAmount = 0;
        grandTotal = secondSubtotal;
    }

    cout << "Thank you for your order. Your total is $" << grandTotal << "." << endl;

    //Print the receipt with all its calculations to an outside file
        //open file stream
        ofstream receiptOutput ("receipt.txt");

        //check for error
        if (receiptOutput.fail()) {
            cerr << "Error opening file to write." << endl;
            return -1;
        }

        //output receipt information to file
            //receipt header
        receiptOutput << setw(28) << setfill ('-') << "-" << endl;
        receiptOutput << "Sprockets-R-Us Order Receipt " << endl;
        receiptOutput << setw(28) << setfill ('-') << "-" << endl;
            //price per unit
        receiptOutput << setw(17) << setfill (' ') << left << "Price Per Unit: $";
        receiptOutput << setw(11) << right << fixed << setprecision(2) << pricePerSprocket << endl;

        //quantity ordered
        receiptOutput << setw(17) << left << "Quantity Ordered:";
        receiptOutput << setw(11) << right << userOrderNum << endl;

        //unit subtotal
        receiptOutput << setw(16) << left << "Unit Subtotal: $";
        receiptOutput << setw(12) << right << fixed << setprecision(2) << firstSubtotal << endl;
        receiptOutput << setw(28) << setfill('-') << "-" << setfill (' ') << endl;

        //shipping fee
        receiptOutput << setw(15) << left << "Shipping Fee: $";
        receiptOutput << setw(13) << right << fixed << setprecision(2) << orderShippingFee << endl;
        receiptOutput << setw(28) << setfill('-') << "-" << setfill (' ') << endl;

        //sales tax
        receiptOutput << left << "Sales Tax (" << fixed << setprecision(2) << salesTaxPercent << "%): $";
        receiptOutput << setw(8) << right << fixed << setprecision(2) << orderSalesTax << endl;
        receiptOutput << setw(28) << setfill('-') << "-" << setfill(' ') << endl;

        //donation information
        receiptOutput << setw(9) << left << "Donation?";
        receiptOutput << setw(19) << right << donationAnswer << endl;
        receiptOutput << setw(14) << left << "Donation Amount: $";
        receiptOutput << setw(11) << right << donationAmount << endl;

        //grandtotal
        receiptOutput << setw(28) << setfill('=') << "=" << setfill (' ') << endl;
        receiptOutput << setw(14) << left << "Grand Total: $";
        receiptOutput << setw(14) << right << grandTotal << endl;
        receiptOutput << setw(28) << setfill('=') << "=" << endl;

        //close file stream
        receiptOutput.close();

    //return 0 signals the operating system that the program ended ok
    return 0;
}