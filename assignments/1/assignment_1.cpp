/*
 * Name        : Assignment #1
 * Author      : Ptolemy Linden
 * Description : A collection of functions designed to work with strings and arrays.
 * Sources     : https://www.asciitable.com/, 
                 https://en.wikipedia.org/wiki/Caesar_cipher, https://www.tutorialspoint.com/isalpha-and-isdigit-in-c-cplusplus
 */

#include "assignment_1.h"

// Write Function Definitions Here (What goes below main)

/* This function will check to make sure all characters in a given string 
are alphabetic. It returns true if the string is all alphabetic, 
otherwise it returns false. An empty string should also return false. 

@ param the_string - The string being checked. */

bool CheckAlphabetic(const string &the_string) {
  if (the_string.empty()) {
    return false;
  }
  for (unsigned int i = 0; i < the_string.length(); i++) {
    if (!isalpha(the_string[i])) {
      return false;
    }
  }
  return true;
}

/* This function will perform a Caesar Cipher shift 
(http://en.wikipedia.org/wiki/Caesar_cipher). If the string contains
any non-alpha characters do not perform the encryption and return 
false. Otherwise perform the encryption and return true. 

@param string the_string - The string being modified.
@param int shift - The amount being shifted. */

bool EncryptString(string &the_string, int shift) {
  if (!CheckAlphabetic(the_string)) {
    return false;
  }
  shift %= 26;
  string encrypted_string;
  unsigned char shifted_char;
  for (unsigned int i = 0; i < the_string.length(); i++) {
    if (isupper(the_string[i])) {
      shifted_char = static_cast<char>((static_cast<int>(the_string[i]))+shift);

      if (shifted_char < 'A') {
        shifted_char += 26;
      } else if (shifted_char > 'Z') {
        shifted_char -= 26;
      }

    } else {
      shifted_char = static_cast<char>((static_cast<int>(the_string[i]))+shift);
      if (shifted_char < 'a') {
        shifted_char += 26;
      } else if (shifted_char > 'z') {
        shifted_char -= 26;
      }
    }
    encrypted_string += shifted_char;
  }
  the_string = encrypted_string;
  return true;
}

/* This function decrypts a Caesar Cipher shift. If the string contains 
any non-alpha characters do not perform the decryption and return 
false. Otherwise perform the encryption and return true. 

@param string the_string - The string being decrypted.
@param int shift - The amount being shifted.*/

bool DecryptString(string &unlock, int shift) {
  EncryptString(unlock, -shift);
  return false;
}

/* This function will compute the mean average of the values in the 
array. The array will always be at least of size 1. 
@param double avg[] - Array containing ??? 
@param int size - The size of the array. */

double ComputeAverage(double avg[], unsigned int size) {
  double avg_of_array = 0;
  double total = 0;
  for (int i = 0; i < static_cast<signed int>(size); i++) {
    total = avg[i] + total;
  }
  avg_of_array = total / size;
  return avg_of_array;
}

/* This function will find and return the smallest value in an array. The 
array will always be at least of size 1. 

@ param double small[] - The array of floating-point values.
@param unsigned int size - The size of the array.*/

double FindMinValue(double small[], unsigned int size) {
  double min_value = small[0];

  for (int i = 0; i < static_cast<signed int>(size); i++) {
    if (min_value > small[i]) {
      min_value = small[i];
    }
  }
  return min_value;
}

/* This function will find and return the largest value in an array. The 
array will always be at least of size 1.  

@param double large[] - The array of floating-point values.
@param unsigned int size - The size of the array.*/

double FindMaxValue(double large[], unsigned int size) {
  double max_value = large[0];

  for (int i = 0; i < static_cast<signed int>(size); i++) {
    if (max_value < large[i]) {
      max_value = large[i];
    }
  }
  return max_value;
}
