/*
 * Name        : Interface File for Assignment #1.
 * Author      : Ptolemy Linden
 * Description : File containing includes, using statements and function prototypes 
                 for Assignment #1.
 * Sources     : FILL IN
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here

#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// Declare Function Prototypes Here (What goes above main)

bool CheckAlphabetic(const the_string &the_string);

bool EncryptString(string &the_string, int shift);

bool DecryptString(string &the_string, int shift);

double ComputeAverage(double avg[], unsigned int size);

double FindMinValue(double small[], unsigned int size);

double FindMaxValue(double large[], unsigned int size);

#endif /* ASSIGNMENT_1_H */
