#include <iostream>
using namespace std;

int main() {
    string hello = "Hello";
    
    for (unsigned int i = 0; i < hello.size(); i++) {
        
        cout << hello.at(i) << endl;
    }
    
    
    return 0;
}