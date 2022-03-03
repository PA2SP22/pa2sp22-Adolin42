/*
 * Name        : Assignment #2
 * Author      : Ptolemy Linden
 * Description : Simulate UNIX "cat" utility
 */
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;

int main(int argc, char *argv[]) {
  string line;
  ifstream fin;
  // 1 CLA - echo
  if (argc == 1) {
    while (!cin.eof()) {
      getline(cin, line);
      cout << line << endl;
    }

    // 2+ CLA - Open File(s) and spit out contents
  } else {
    // cout << "We have some files!" << endl;
    // Loop throught the command arguments (which should be filenames)
    for (int i = 1; i < argc; i++) {
      // (1) Open the file
      fin.open(argv[i]);
      // (2) Check to make sure the file exists, if not, crash
      if (fin.fail()) {
        // Inform the users
        cout << "Invalid file name." << endl;
        return 1;
      }
      // (3) Close the file
      fin.close();
    }
    for (int i = 1; i < argc; i++) {
      // (1) Open the file
      fin.open(argv[i]);
      // (2) Output the contents of the file
      while (!fin.eof()) {
        getline(fin, line);
        cout << line << endl;
    }
      // (3) Close the file
      fin.close();
    }
  }
  return 0;
} 
