#include<graphics.h>// header file that provides functions and data types for graphics programming. here putpixel()
#include<iostream>// header file that provides input and output operations in C++.
using namespace std; // This line is a using directive that allows you to use names from the std namespace without specifying the namespace explicitly.

void circleDrawing(int xc,int yc,int x,int y)
{  /*This is a function definition for circle Drawing 
void bresenhams_circle(int xc,int yc,int r) function takes 4 parameters  
x & y= current coordinates within the circle.
xc & yc= center coordinates of the circle
*/
	putpixel(x+xc,y+yc,RED);
	putpixel(x+xc,-y+yc,BLUE); 8 
	putpixel(-x+xc,-y+yc,GREEN);
	putpixel(-x+xc,y+yc,RED);
	putpixel(y+xc,x+yc,12);
	putpixel(y+xc,-x+yc,13);
	putpixel(-y+xc,-x+yc,14);
	putpixel(-y+xc,x+yc,15);
}// 8 symmetric points 

{ //parameter is used to determine the next pixel to be plotted.
	int x=0, y=r,d=3-(2*r); //r is radius ...Set decision parameter d to d = 3 – (2 * r).
	circleDrawing(xc,yc,x,y);//calls the circleDrawing function to draw the initial 8 symmetric points on the circle.
	
	while(x<=y)
	{
		if(d<=0)
		{
			d=d+(4*x)+6;
		}
		else
		{
			d=d+(4*x)-(4*y)+10;
			y=y-1;
		}
		x=x+1;
		/* If d < 0
            then d = d + 4x + 6
            increment x = x + 1
            If d = 0
            then d = d + 4 (x - y) + 10
            increment x = x + 1
            decrement y = y - 1*/
		circleDrawing(xc,yc,x,y); //after updation again calls the circleDrawing function to draw the initial 8 symmetric points on the circle.
	}
}

int main(void)
{
	cout<<"Name : Vinti Ashok Patel :";
	cout<<"Roll No : 240\nClass : DSY CE\n";
	int xc,yc,r;
	
	initwindow(1000,1000); //initializes a graphics window of size 1000x1000 pixels.
	
	cout<<"Enter the value of xc and yc : ";
	cin>>xc;
	cin>>yc;
	cout<<"Enter the value of radius : ";
	cin>>r;
	bresenhams_circle(xc,yc,r);//calls the bresenhams_circle function to draw the circle based on the user-provided inputs.
	
	
	getch(); //line waits for a keyboard input.
	closegraph(); // line closes the graphics window.
	return 0; // indicates the successful termination of the program.
}
