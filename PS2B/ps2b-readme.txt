/**********************************************************************
*  N-Body Simulation ps2b-readme.txt template                         *
**********************************************************************/

Name: Meet Kothari

Hours to complete assignment: ~6 Hours

/**********************************************************************
*  Briefly discuss the assignment itself and what you accomplished.   *
**********************************************************************/
I made the step function as defined by the homework prompt.

My step functiion contains all the net forces acting on each planet fed to it via the file name. Each loop, it goes through and initializes each planet with
acceleration, net force, force, gravitational force, x and y positions, mass, and x and y velocity. 

I rectified my mistakes from the previous assignment in which I did not sufficiently define a universe class.

I was able to implement smart pointers, unique_ptr, create a new object, and pushback.

Beyond that, I also got my file to play a sound; I chose, by random, a copyright-free sound from an online site.

I also got my program top continously display the elapsed time at the bottom. As long as it's running, the clock will keep up.




/***************************************************************************************************
*  If you created your own universe for extra credit, describe it here and why it is interesting.  *
***************************************************************************************************/

I did not do this; I had exams coming up so I did not want to spend too much time, as it would cut out of my study time, sadly.

/***********************************************************************************************
*  List whatever help (if any) you received from the instructor, classmates, or anyone else.   *
***********************************************************************************************/

I looked at some Youtube videos to gain a better understanding of the step function and i looked on the 
SFML website for a better understanding of how I could try to display elapsed time and how to play sound.  


/**********************************************************************
*  Describe any serious problems you encountered.                     *       
**********************************************************************/

Not problems per se, but I had to rework my definiton of the 'Universe' class as per the comments on my ps2a. That involved alot of reworking
with some of the classes, but since i had the work from before, it wasn't too difficult. The bulk of my time was spent there.

/**********************************************************************
*  List any other comments here.                                      *                              
**********************************************************************/

 I was not using the ".hpp" suffix for my NBody header file. I have fixed this mistake in this iteration of the program.