#ifndef ED_HPP
#define ED_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> 

#include <SFML/System.hpp>

using namespace std;

const int GAP = 2;

class ED {
    
    public:    
    
    ED(string a, string b); // a constructor that  accepts  the  two  strings  to  be  compared,  and  allocates  any  data  structures  necessary into order to do the work (e.g., the N×M matrix).
    
    static int penalty(char a, char b); // a static method int penalty(char a, char b) that returns the penalty for aligning chars and b (this will be a 0 or a 1). 
    
    static int min(int a, int b, int c); // a static method int  min(int  a,  int  b,  int  c)  which  returns  the  minimum  of  the  three  arguments.
    
    int OptDistance(); // a method int OptDistance() which populates the matrix based on having the two strings, and returns the optimal distance (from the [0][0] cell of the matrix when done).
    
    string Alignment(); // a method stringAlignment() which traces the matrix and returns a string that can be printed to display the actual alignment. In general, this will be a multi-line string — i.e., with embedded \n's.  
    
    ~ED();
    
    private:
    
    string s1; // two strings for input, as per the prompt
    
    string s2; // second string 
    
    vector < vector < int > > matrix; // i'm planning on using dynamic programming. i believe that the Needleman and Wunsch method works with my skillset
};

#endif 

