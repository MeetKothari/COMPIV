#include "ED.hpp"

#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

ED::ED(string a, string b){ // a constructor that  accepts  the  two  strings  to  be  compared,  and  allocates  any  data  structures  necessary into order to do the work (e.g., the N×M matrix).
    
    vector <int> temp;

    s1 = a; // set values using the private members of the class  // temp vector to use to store
    s2 = b;
    
    auto return_push = [&](int n) { temp.push_back(0); }; // lambda, got my inspiration from the Microsoft website, i.e., 'auto a = [ptr = move(pNums)](){ // use ptr };'
    
    for (unsigned j = 0; j < s2.length() + 1; j++){ return_push(0); } // begin to fill the matrix with 0's
    for (unsigned i = 0; i < s1.length() + 1; i++){ matrix.push_back(temp); } // fill the other string with the temp

}

ED::~ED(){} // destructor

int ED::penalty(char a, char b){ // return the penalty for aligning chars and b (this will be a 0 or a 1). 
    
    if (a == b) return 0; // if aligned, return 0
    
    else return 1; // else return 1

}

int ED::min(int a, int b, int c){  // returns  the  minimum  of  the  three  arguments.
  
  if (a <= b && a <= c) return a; 
  
  else if (b <= c) return b; 
  
  else return c; 

}

int ED::OptDistance(){ // int OptDistance() which populates the matrix based on having the two strings, and returns the optimal distance (from the [0][0] cell of the matrix when done).
  
  int a, b, c, i, j; // a b and c will represent the three values and i and j will be indices for the strings
  int str1, str2; // values to help initialzie the strings
  
  i = 0; // initialize
  j = 0;
  
  str1 = s1.length(); // initialize
  str2 = s2.length();
  
  for (i = str1; i >= 0; i--) matrix[i][str2] = GAP * (str1 - i); // fill the bottom row and last column with gap penalty
  for (j = str2; j >= 0; j--) matrix[str1][j] = GAP * (str2 - j);
  
  for (i = (str1 - 1); i >= 0; i--){ // fill the inside of the matrix
    
    for (j = (str2 - 1); j >= 0; j--){
      
      a = GAP + matrix[i + 1][j];
      b = GAP + matrix[i][j + 1];
      c = matrix[i + 1][j + 1] + penalty(s1[i], s2[j]);
      
      matrix[i][j] = min(a, b, c);
    
    }
  
  }
  
  return matrix[0][0];
}

string ED::Alignment(){ // a method stringAlignment() which traces the matrix and returns a string that can be printed to display the actual alignment. In general, this will be a multi-line string — i.e., with embedded \n's.  
  
  stringstream return_string; // inherit from ostream functionality

  int a, b, i, j; // indices for strings and other basic variables
  int str1, str2; // to access strings
  int position; // to represent the current position
  int penalty_result; // penalty result
  
  i = 0; // initialize at 0
  j = 0;

  str1 = s1.length(); // start accessing columns
  str2 = s2.length(); // start accessing rows
  
  while (i < str1 || j < str2){ // as long as the matrix hasn't been filled, 
    
    position = matrix[i][j]; // set position 
    
    a = i < str1 ? GAP + matrix[i + 1][j] : -1; // get to aligning
    b = j < str2 ? GAP + matrix[i][j + 1] : -1;
    penalty_result = penalty(s1[i], s2[j]);
    
    if (position == a){ // in case we need to mve down
      
      return_string << s1[i] << " - " <<  "2\n";
      
      i++;
  } 
  
  else if (position == b){ // in case we need to move right
    
    return_string << "- " << s2[j] << " 2\n";
    
    j++;
  
  } 
  
  else { // in case we need to move diagonal
    
    return_string << s1[i] << " " << s2[j] << " " << penalty_result << " \n";
    
    i++;
    j++;

  }

  }
  
  string result_string = return_string.str();
  
  return result_string;
}