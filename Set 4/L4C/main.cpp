/* CSCI 261: Fix Loop Errors
 *
 * Author: Lauren Sherburne
 *
 *    This program illustrates a variety of common loop errors.
 *    Fix the errors in each section.

Copyright 2019 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */


#include <iostream>
using namespace std;

int main() {

cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = The loop did not add the numIter to the final sum since the loop only ran when when i < numIter, so by adding =
//       to the for test (i <= numIter) the loop added the numIter to the sum.
// TESTS:  cin:     sum:
//          4       10
//          12      78
//          7       28

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int sum;      // Accumulates the total
    int i;        // Used as loop control variable
    int numIter;  // The number of times to iterate
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> numIter;
    for (i = 1; i <= numIter; ++i) {
        sum += i;
    }
    cout << "The sum of the numbers from 1 to " << numIter << " (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Each time the code looped, it reset "total" to zero which means that in the end. The "total" is just the price
//       of the last item. Thus, by removing the line 84, the loop is fixed and accurately provides a "total" price.
// TESTS:   #items      prices              output
//          2           3,5                 8
//          3           22,9,11             42
//          6           90,3,5,802,6,2      908

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    double total;     // Accumulates total
    double price;     // Gets next price from user
    int numItems;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    while (counter <= numItems) {
        //total = 0; (this line caused the problem in the loop)
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        cout << endl;
        total += price;
        counter++;
    }
    cout << "The total price is: " << total << endl;


// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = Since the loop test statement tested whether counter2, which is always 1, is less or equal to sum2, which is
//       incremented by 1 in each loop and therefore is always greater than counter2, the loop is infinite. It was fixed
//       by changing the loop test to "counter2 <= numIter2" and by adding a line of code to add 1 to the counter each loop.
// TESTS:       numIter2    sum2
//              4           10
//              32          528
//              9           45


    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    int sum2 = 0;
    int counter2 = 1;
    int numIter2;

    cout << "What number do you wish me to sum to?" << endl;
    cin >> numIter2;

    do {
        sum2 += counter2;
        cout << "Sum so far: " << sum2 << endl;
        counter2++;
    } while (counter2 <= numIter2);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << numIter2 << " (inclusive) as " << sum2 << endl;




// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = The loop test was incorrect so I changed it to (int i = 1; i <= numIter3; i++) in order to fix the code.
// TESTS:   numIter     sum3
//          2           5
//          8           204
//          42          25585



    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of squares from 1 to ? (inclusive)" << endl;

    int numIter3;
    cin >> numIter3;

    int sum3 = 0;
    for (int i = 1; i <= numIter3; i++) {
        sum3 += i*i;
    }

    cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3 << endl;



// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = The loop did not work properly since the loop ran 10 times no matter what the user entered as a parameter. Thus,
//       the solution is to change the loop test to (counter4 <= numIter4) and place "counter4++" within the loop.
// TESTS:       numIter4    sum4
//              2           9
//              3           36
//              7           784

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of cubes from 1 to ? (inclusive)" << endl;

    int numIter4;
    cin >> numIter4;

    int sum4 = 0;
    int counter4 = 1;

    while (counter4 <= numIter4) {
        sum4 += (counter4 * counter4 * counter4);
        counter4++;
    }

    //counter4++;

    cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}