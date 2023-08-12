/* CSCI 261: Fix Function Errors
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

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// input: integer
// output: none
// adds five to the given parameter
void addFive( int &x ) {
    x += 5;
}

//input: none
//output: prints smiley face
void printSmileyFace() {
    cout << "  |   |  " << endl;
    cout << "    |    " << endl;
    cout << "00     00" << endl;
    cout << " 00   00 " << endl;
    cout << "  00000  " << endl;
}

// input: none
// output: a random number
int generateRandomNumber(int z) {;
    z = rand() % 100;
    return z;
}

// input: three integers
// output: the sum of all three parameters
int sum( int x, int y, int z ) {
    return x + y + z;
}

// input: two doubles
// output: the product of the two doubles
double multiply( double a, double b );

int main() {
    cout << "Welcome to Function World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = In the addFive function, there must be an "&" before the variable name "x" so that the program used
//       pass-by-reference to update numTrees
// TESTS:   input   output
//          7       12
//          2       7
//          18      23

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int numTrees;
    cout << "How many trees do you currently have? ";
    cin >> numTrees;
    cout << "There are initially " << numTrees << " trees." << endl;
    addFive( numTrees );
    cout << "We planted five trees, there are now " << numTrees << " trees." << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = The function "printSmileyFace()" did not exist in the program so I declared it above the main function
// TESTS: *run program* output: smiley face

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    printSmileyFace();

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = Rand cannot be seeded within the function otherwise the output of the function will be the same each time. I
//       seeded rand outside of the generateRandomNumber function but before it was called to fix the problem.
// TESTS: *run program* output:
//      55  58  0   87  64
//      24  55  94  73  47
//      51  6   6   50  37

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    srand(time(0));
    rand();

    cout << "Five different random numbers are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        int x = 0;
        cout << "\t" << generateRandomNumber(x) << endl;
    }


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = In the call for function sum, the code only inputted 2 integers, when the function requires 3. I fixed the issue
//       by adding "num3" to "sum( num1, num2)". Also, the function itself was incorrect since it only added the first
//       number three times without even using the other variables.
// TESTS:   input:          output:
//          1 2 3           6
//          3 5 7           15
//          6 9 0           15

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum( num1, num2, num3 ) << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = The "generateRandomNumber" function requires a variable and since the code below was lacking such a variable,
//       the computer evaluated the function as true and outputted "1" instead of a random number. Thus, I fixed the
//       function by adding a variable when the function was called.
// TESTS:*run code* output: 8, 47, 27, 4

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;


    int h = 0;
    cout << "Another random number is " << generateRandomNumber(h) << endl;

// SECTION VI: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = The function was declared above "main", but the program did not contain the actual code within the "multiply"
//       function which I fixed by adding below "main".
// TESTS:   input:          output:
//          .25     .9      .225
//          .33     .68     .2244
//          29.7    6.11    181.467

    cout << endl;
    cout << "******************" << endl;
    cout << "Section VI" << endl;
    cout << "******************" << endl;

    double doub1, doub2;
    cout << "Enter two doubles: ";
    cin >> doub1 >> doub2;
    cout << "Their product is: " << multiply( doub1, doub2 ) << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}

double multiply( double a, double b ) {
    return (a * b);
}