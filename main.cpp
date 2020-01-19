#include <iostream>
#include <string>
#include <vector>

#include "Calculator.h"

using namespace std;

int main() {

    Calculator calculator;
    string userInput;
    
    cout << "Welcome to the Roman Numeral converter tool!" << endl;
    
    while (userInput != "done") {
        //Promt the user for options
        cout << "What would you like to do?" << endl;
        cin >> userInput;
        
        //process input
        if (userInput == "Roman") {
            string letters;
            cout << "Enter in a roman numeral" << endl;
            cin >> letters;
            
            //convert to uppercase
            for (unsigned int i = 0; i < letters.size(); i++) {
                letters.at(i) = toupper(letters.at(i));
            }
            
            int totalValue = calculator.convertFromRoman(letters);
            
            if (totalValue != -1) {
                cout << "Number: " << totalValue << endl;
            }
            
        }
        else if (userInput == "Number") {
            
            int userNumber = 0;
            cout << "Enter a positive number" << endl;
            cin >> userNumber;
            
            cout << "Roman Numeral: " << calculator.convertToRoman(userNumber) << endl;
        }
        else if (userInput == "done") {
            //exit the program
            break;
        }
        else {
            
            //print the options if invalid command is used
            
            cout << "Invalid command" << endl;
            cout << "Roman - convert roman numerals to numbers" << endl;
            cout << "Number - convert number to roman numerals" << endl;
            cout << "done - exit the program" << endl;
        }
    }
    
    cout << "GoodBye!" << endl;

    return 0;
}

