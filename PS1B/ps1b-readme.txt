**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Meet Kothari

Hours to complete assignment: 2 Hours

/**********************************************************************
*  Briefly discuss the assignment itself and what you accomplished.   *
**********************************************************************/

The objective of this program was to write  a  C++  program  to  read  three  arguments  from  the  command  line:  source  image  filename, output image filename, and FibLFSR seed.
and then use SFML to load the source image from the disk and display it in its own window,
then make it negative and save in a different file.

I implemented the transform function, which would take two arguments, an image and a 
FibLFSR object. After finding the size, each pixel was xor'ed by the 
bit->generate function(8), shifting each bit 8 times.


/***********************************************************************************************/
*  If you did any implementation for extra credit, describe it here and why it is interesting. */                                 
************************************************************************************************/
I did not.



/********************************************************************************************/
*  List whatever help (if any) you received from the instructor, classmates, or anyone else.*/                                      
*********************************************************************************************/

 I watched quite a few youtube videos on the XOR operator, and a few generally centered around
 the encoding and decoding for the picture.


/**********************************************************************
 *  Describe any serious problems you encountered.                    *
 **********************************************************************/

 Not many. From last project, my weakness with the XOR operator was a bit of a hindrance.
 Unlike the last program, I couldn't work my way around it because I knew the use of the operator
 would make the function implementation easier, so I had to spend some time gaining a deeper understanding of 
 it. Other than that, I felt that the rest of the program was straightforward enough.


/**********************************************************************
 *  List any other comments here.                                     *
 **********************************************************************/

 Hi. I have attached two pictures; in both, I have the enocde.png and decode.png
 windows showing, and it should show that everything is in order, but if any other
 screenshots are needed, I will happily provide them.
