/*CSCI 261 Assignment 5 - PPM Image Editor
 *
 *
 * Program Name: PPM Image Editor
 * Author: Lauren Sherburne
 * Skip Days Used: 1
 * Skip Days Remaining: 4
 *
 * Description: First, the program inputs all the information from an image file that the user indicated. Then, it asks
 *              the user if they would like to convert their image to greyscale or invert the colors. Finally, the
 *              program modifies the image accordingly and places all of the new image's information in a new file.
 *
 *
 * Date: October 23, 2019
 *
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    //Create a struct named pixel that stores red, green, and blue as integers
    struct pixel {
        int red;
        int green;
        int blue;
    };

    //Declare variables for the image type, height, and the maximum value for each color
    string imageType;
    int imageHeight;
    int imageWidth;
    int maxColorValue;


    //Create an empty vector of vectors of pixels
    vector< vector< pixel > > image;

    //Prompt the user to enter the file name of the image they with to open
    string filename;
    cout << "Enter the name of the image file you wish to open: " << endl;
    getline(cin, filename);

    //Open file stream and check for error
    ifstream openFile (filename);

    if (openFile.fail()) {
        cerr << "Error opening file to read." << endl;
        return -1;
    }

    //Read in the file's image data using file input and for loops

        //read in image type, height, and width
    openFile >> imageType;
    openFile >> imageHeight;
    openFile >> imageWidth;
    openFile >> maxColorValue;

        //for each row, create a row, for each column, create a pixel, read in pixel info, add pixel to row, add row to image
    for (int i = 0; i < imageHeight; i++) {
        vector <pixel> row;
        for (int j = 0; j < imageWidth; j++) {
            pixel dot;
            openFile >> dot.red;
            openFile >> dot.green;
            openFile >> dot.blue;
            row.push_back(dot);
        }
        image.push_back(row);
    }

        //close file
    openFile.close();

    //Ask user how they would like to format the image and cin their choice
    int userChoice;
    cout << "Which image manipulation would you like to perform?" << endl;
    cout << "1. Convert to grayscale" << endl;
    cout << "2. Invert the colors" << endl;
    cout << "Please enter either 1 or 2 below: " << endl;
    cin >> userChoice;

    //Ensure that the user enters a valid choice
    while ((userChoice != 1) || (userChoice != 2)) {
        cout << "I'm sorry, but you're choice was invalid." << endl;
        cout << "Please enter \"1\" to convert the image to grayscale or \"2\" to invert the image's colors" << endl;
        cin >> userChoice;
    }

    //remove the file type end of the file name so that the manipulated image can be renamed
    filename = filename.substr(0, filename.length() - 4);

    //create integer variables for red, green, blue, and grey
    int red, green, blue, grey;

    //If the user chooses greyscale...
    if (userChoice == 1) {
        //create a new name for the modified image
        string modifiedImage = filename + "_grayscale.ppm";

        //open file stream and check for error
        ofstream greyOutput(modifiedImage);

        if(greyOutput.fail()){
            cerr << "Error opening file to write." << endl;
            return -1;
        }

        //output the image type, height, width, and maximum color value
        greyOutput << imageType << " ";
        greyOutput << imageHeight << " ";
        greyOutput << imageWidth << " ";
        greyOutput << maxColorValue << " ";

        //using for loops, modify the values of each pixel in the image and output them to the new image file
        for (int i = 0; i < image.size(); i++){
            for (int j = 0; j < image.at(i).size(); j++){
                red = image[i][j].red;
                green = image[i][j].green;
                blue = image[i][j].blue;
                grey = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
                greyOutput << grey << " " << grey << " " << grey << " ";
            }
        }

        //close file
        greyOutput.close();

    } else if (userChoice == 2){    //If the user chooses to invert the colors
        //create a new name for the modified image
        string modifiedImage = filename + "_inverted.ppm";

        //open file stream and check for error
        ofstream invertColorsOutput(modifiedImage);

        if(invertColorsOutput.fail()){
            cerr << "Error opening file to write." << endl;
            return -1;
        }

        //output the image type, height, width, and maximum color value
        invertColorsOutput << imageType << " ";
        invertColorsOutput << imageHeight << " ";
        invertColorsOutput << imageWidth << " ";
        invertColorsOutput << maxColorValue << " ";

        //using for loops, modify the values of each pixel in the image and output them to the new image file
        for (int i = 0; i < image.size(); i++){
            for (int j = 0; j < image.at(i).size(); j++){
                red = maxColorValue - image[i][j].red;
                green = maxColorValue - image[i][j].green;
                blue = maxColorValue - image[i][j].blue;
                invertColorsOutput << red << " " << green << " " << blue << " ";
            }
        }

        //close file
        invertColorsOutput.close();
    }


    //return 0 signals the operating system that our program ended ok.
    return 0;
}