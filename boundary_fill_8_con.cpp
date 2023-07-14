//Name:Patel Vinit Ashok
//Roll no:240
#include <graphics.h>// header file that provides functions and data types for graphics programming. here putpixel(),	boundaryFill()

void boundaryFill8(int x, int y, int fill_color,int boundary_color)
/*x & y= current coordinates within the circle.
fill_color= color to be filled
boundary_color=boundary color
*/
{
	if(getpixel(x, y) != boundary_color &&
	getpixel(x, y) != fill_color)
		/*if the current pixel at coordinates (x, y) is not equal to the boundary_color and is also not equal to the fill_color. 
	This condition ensures that the pixel is not already filled and not on the boundary.  */
	{
		putpixel(x, y, fill_color);// sets the color of the pixel at coordinates (x, y) to the fill_color. This fills the pixel with the desired color.
		boundaryFill8(x + 1, y, fill_color, boundary_color);//right 
		boundaryFill8(x, y + 1, fill_color, boundary_color);//below current pixel
		boundaryFill8(x - 1, y, fill_color, boundary_color);//left 
		boundaryFill8(x, y - 1, fill_color, boundary_color);//above 
		boundaryFill8(x - 1, y - 1, fill_color, boundary_color);// top-left 
		boundaryFill8(x - 1, y + 1, fill_color, boundary_color);// bottom-left 
		boundaryFill8(x + 1, y - 1, fill_color, boundary_color);//top-right
		boundaryFill8(x + 1, y + 1, fill_color, boundary_color);//bottom-right
	}//boundary fill()  are used to recursively fill the adjacent pixels in the 8 cardinal directions (right, down, left, up).
}
}


int main()
{
	initwindow(1000,1000);// initializes a graphics window of size 1000x1000 pixels.
	rectangle(50, 150, 200, 200);/*This line draws a rectangle on the graphics window using the rectangle function. 
	The rectangle's top-left corner is at coordinates (50, 150), and the bottom-right corner is at coordinates (200, 200).*/
	boundaryFill8(55, 155, 4, 15); /*calls the boundaryFill8 function to fill the area inside the rectangle. 
	The starting point is at coordinates (55, 155). The fill_color is set to 4, and the boundary_color is set to 15.*/
	delay(10000);//delay of 10000 milliseconds (10 seconds) to the program execution. It pauses the program for a certain amount of time before proceeding.
	getch();
	closegraph();
	return 0;
}
/*getch();: This line waits for a keyboard input.

closegraph();: This line closes the graphics window.

return 0;: This line indicates the successful termination of the program.*/
