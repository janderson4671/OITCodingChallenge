#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Class that performs the conversion from Roman numerals to numbers and vice versa
class Calculator {

private:
    vector<char> romanNumerals;  //vector that holds the given Roman Numerals in order

public:
    Calculator();  //constructor
    int convertFromRoman(string letters); //converts to decimal
    string convertToRoman(int number); //converts to roman
    void addUpRomanNumerals(string letters, int& totalValue); //function to verify the validity of the inputed numeral
    void f0(string letters, int currIndex, int& totalValue);  //state f0 in finite state machine
    void f1(string letters, int currIndex, int& totalValue, char lastLetter);  //state f1 in finite state machine
    int getRomanValue(char letter); //returns the integer value of a roman numeral
    int getRomanIndex(char letter); //returns the index number of the roman numeral in the vector
    char getNextRomanValue(int indexNum, bool secondTry); //gets the next roman value with some added rules
};



#endif
