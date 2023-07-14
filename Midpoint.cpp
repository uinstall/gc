// Name : Vinit Patel
// Roll no: 240
#include<graphics.h>// header file that provides functions and data types for graphics programming. here putpixel()
#include<iostream>// header file that provides input and output operations in C++.
using namespace std; // This line is a using directive that allows you to use names from the std namespace without specifying the namespace explicitly.


void midPoint(int xcenter, int ycenter, int radius)/*  This line defines the midPoint function, which is responsible for drawing a circle using the midpoint circle drawing algorithm. 
It takes three parameters: xcenter and ycenter are the coordinates of the center of the circle, and radius is the radius of the circle.*/
{
   int x = 0;
   int y = radius;
   int p = 1 - radius;//p represents the decision parameter based on the initial radius.
   void plotpoints(int, int , int, int);//plotpoints function, which is responsible for plotting the eight symmetric points on the circle.
   plotpoints(xcenter, ycenter, x, y);/* calls the plotpoints function to plot the initial eight symmetric points on the circle using the provided
    center coordinates (xcenter, ycenter) and the current coordinates (x, y).*/
   while(x<y){
      x++;
      if(p<0){
	 p = p + 2*x + 1;
      }
      else{
	y--;
	p = p + 2*(x-y) + 1;
      }
      plotpoints(xcenter, ycenter, x, y);
   }
}
/* These lines implement the midpoint circle drawing algorithm using a while loop. The loop continues until x becomes greater than or equal to y.
Inside the loop, x is incremented by 1, and the decision parameter p is updated based on its value. If p is less than 0, the updated value of p is 
calculated using the formula p = p + 2*x + 1. Otherwise, if p is greater than or equal to 0, y is decremented by 1,
 and the updated value of p is calculated using the formula p = p + 2*(x-y) + 1.
After updating the values, the plotpoints function is called again to plot the updated eight symmetric points on the circle.*/

void plotpoints(int xcenter, int ycenter, int x, int y){
    putpixel(xcenter+x, ycenter+y, RED);//represents a point on the circle in the first quadrant.
    putpixel(xcenter-x, ycenter+y, GREEN);//2nd quadrant
    putpixel(xcenter+x, ycenter-y, BLUE);//3rd quadrant
    putpixel(xcenter-x, ycenter-y, WHITE);//4th quadrant
    putpixel(xcenter+y, ycenter+x, WHITE);//1st octant
    putpixel(xcenter-y, ycenter+x, BLUE);//2nd octant
    putpixel(xcenter+y, ycenter-x, GREEN);//8th octant
    putpixel(xcenter-y, ycenter-x, RED);//7th octant
}

int main(){
	initwindow(1000,1000);//initializes a graphics window of size 1000x1000 pixels.
	int r, xc, yc, pk, x, y;
	cout<<" Mid-Point Circle Drawing Algorithm \n\n";
	cout<<"Enter the center co-ordinates\nX= ";
	cin>>xc;	
	cout<<"Y= ";
	cin>>yc;
	cout<<"Enter the radius of circle = ";
	cin>>r;
  	midPoint(xc, yc, r);//midPoint function is then called with the provided inputs to draw the circle using the midpoint circle drawing algorithm.

  getch();
  return 0;
}//Finally, getch function waits for a keyboard input, and closegraph function closes the graphics window. The program terminates by returning 0.
