/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template                        *
 **********************************************************************/

Name: Meet Kothari
Hours to complete assignment: 8 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.  *
 **********************************************************************/

The goal of this assignment was to create an SFML window and fill it with the contents of planets.txt using two classes, Universe and CelestialBody. 
Universe is a class which contains a vector of CelestialBody(s) and also has a function to draw the planets by accessing a vector.
For extra credit, I added a background image called "Starry Night" and used smart pointers to avoid data leaks.


/**************************************************************************************************************
 *  Discuss one or more key algorithms, data structures, or OO designs that were central to the assignment.   *
 **************************************************************************************************************/

The class Universe was a vector of CelestialBody which was used to hold all the planets that were fed into the program from planets.txt. 

/***********************************************************************
 *  Briefly explain the workings of the features you implemented.      *
 *  Describe if and how do you used the smart pointers                 *
 *  Include code excerpts.                                             *
 **********************************************************************/

 unique_ptr <universe> u(new universe());
 
 I used a smart pointer to represent the universe, closing off the possibilities of memory issues. The universe was allocated through the following for loop:
 
 for(i = 0; i < bodies; i++){
      
      body = new CelestialBody();
      
      cin >> *body;
      
      (*u).pushback(*body);
      
      cout << *body;
    }
	
I had to make a pushback function in order to assign CelestialBody(s) to the vector. I learnt this method online, via https://en.cppreference.com/book/intro/smart_pointers

/*********************************************************************************************
 * List whatever help (if any) you received from the instructor, classmates, or anyone else. *
 *********************************************************************************************/

 I had a conversation with a few of my peers about the steps needed to implement smart pointers, and they also helped me understand why we needed them in this assignment.

 I used quite a few online tutorials/articles to understand smart pointers: 

 https://en.cppreference.com/book/intro/smart_pointers - this one gave me the inspiration for the implementation of the smart pointer in my main function.
 https://en.cppreference.com/w/cpp/memory/unique_ptr   - this one gave me some good background information.
 http://www.cplusplus.com/reference/memory/unique_ptr/ - this one helped me gain a better picture in my head due to the 'template parameter' section.
 https://youtu.be/UOB7-B2MfwA                          - this man, the Cherno, is God's gift to all C++ programmers. 
 https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm - this link was provided in the assignment for overloading help.

 Besides that, I did all of the work on my own.


/**********************************************************************
 *  Describe any serious problems you encountered.                    *                   
 **********************************************************************/

 Originally, I did this assignment without the use of smart pointers (~ 4 hours), but then, I decided to use smart pointers
 because I really wanted the extra credit. That, and I realized that if I used them now, it would be good practice for later
 (the Professor made some good points in our lecture today).



/**********************************************************************
 *  List any other comments here.                                     *                                    
 **********************************************************************/

 I am not very good at using smart pointers. This successful implementation took entirely too long for me to do.
