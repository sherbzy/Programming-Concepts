/*CSCI 261 Lab 5D - Array of Structures
 *
 *
 * Program Name: Array of Structures
 * Author: Lauren Sherburne
 *
 * Description: The program prompts the user to enter the title, author, cost, and publication year of 5 separate books.
 *              Then, it asks the user which book number they would like the information for before printing the
 *              corresponding book's info.
 *
 * Date: October 23, 2019
 *
*/

#include <iostream>
using namespace std;

int main() {
    //Create a struct called Book with title, author, cost, and publication year
    struct Book {
        string title;
        string author;
        double cost;
        long int publicationYear;
    };

    //Create an array of type Book that stores 5 books (array of structures)
    Book bookInfo [5];

    //User enters all of the information for each book
    cout << "Please enter each book's title, author name, cost, and publication year below." << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << "'s title:";
        getline(cin, bookInfo[i].title);
        cout << "Book " << i + 1 << "'s author:";
        getline(cin, bookInfo[i].author);
        cout << "Book " << i + 1 << "'s cost:";
        cin >> bookInfo[i].cost;
        cout << "Book " << i + 1 << "'s publication year:";
        cin >> bookInfo[i].publicationYear;
        string dummy;
        getline(cin, dummy);
    }

    //Ask the user which number book they want information for
    cout << "Which book would you like to access? Please enter a number between 1 and 5:" << endl;

        //Create a variable for the user's inputted book ID and input it's value
    int bookID;
    cin >> bookID;
    bookID--; //changes the user's input to the corresponding book's index within bookInfo array

    //Print the corresponding book's information to the screen
    cout << "Book " << bookID + 1 << ":" << endl;
    cout << "   Title: " << bookInfo[bookID].title << endl;
    cout << "   Author: " << bookInfo[bookID].author << endl;
    cout << "   Cost: " << bookInfo[bookID].cost << endl;
    cout << "   Year of Publication: " << bookInfo[bookID].publicationYear << endl;


    //return 0 signals the operating system that our program ended ok
    return 0;
}