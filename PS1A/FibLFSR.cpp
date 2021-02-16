#include <iostream>
#include "FibLFSR.h"

using namespace std;

FibLFSR::FibLFSR(string seed) { str = seed; } // initializes the seed string by changing the value held in the variable

int FibLFSR::step(){ // function simulates one step of the LFSR and returns the rightmost bit as an integer(0 or 1)

    int compare;
    compare = 0;
    
    byte3 = str.at(2) - '0'; 
    byte2 = str.at(3) - '0';
    byte1 = str.at(5) - '0';
    byte4 = str.at(0) - '0';

    if ((byte4 == 1 && byte3 == 1) || (byte4 == 0 && byte3 == 0)){ compare = 0; }
    else{ compare = 1; }
    if (compare == byte2){ compare = 0; }
    else { compare = 1; }
    if (compare == byte1){ compare = 0; }
    else { compare = 1; }
    
    str.erase(str.begin());        // make the bit spot at the beginning open
    str.push_back(compare + '0');  // push back tge output 
    return compare; // return the result, which is the comparison
}

int FibLFSR::generate(int k){
    
    int i, j; // initizialzation variables 
    j = 0;
    
    for (i = 0; i < k; i++){
        
        j = j * 2; // generation as described by the prompt 
        j += step();
    }
    
    return j;
}

FibLFSR::~FibLFSR(){ memory.clear(); } // deallocate any leftover memory from the constructor

ostream &operator <<(std::ostream &out, const FibLFSR &fibLFSR) { return out << fibLFSR.str; } // overload the << stream insertion operator to display its current register value in printable form
