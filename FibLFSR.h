#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FibLFSR {
    
    public:
    
    FibLFSR(string seed); // constructor to create LFSR with the given initial seed and tap

    int step(); // simulate one step and return the new bit as 0 or 1

    int generate(int k); // simulate k steps and return k-bit integer

    ~FibLFSR(); // a destructor to deallocate the dynamically allocated memory from the constructor

    friend std::ostream &operator<<(ostream &out, const FibLFSR &fibLFSR); // overloads the << stream insertion operator to display its current register value in printable form
    
    private : 
    
    string str; // string for comparison
    
    vector <int> memory; // for de-allocating memory at the end, will be used in destructor
    
    int byte1, byte2, byte3, byte4; // variables to match the diagram provided in the prompt 
};

#endif //FIBLFSR_H
