//Name :Patel Vinit Ashok
//Roll no:240

#include <graphics.h>// header file that provides functions and data types for graphics programming. here putpixel(),	boundaryFill()
void boundaryFill4(int x, int y, int fill_color,int boundary_color)
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
		putpixel(x, y, fill_color); // sets the color of the pixel at coordinates (x, y) to the fill_color. This fills the pixel with the desired color.
		boundaryFill4(x + 1, y, fill_color, boundary_color);//right of current pixel
		boundaryFill4(x, y + 1, fill_color, boundary_color);//below
		boundaryFill4(x - 1, y, fill_color, boundary_color);//left
		boundaryFill4(x, y - 1, fill_color, boundary_color);//above
	}//boundary fill()  are used to recursively fill the adjacent pixels in the four cardinal directions (right, down, left, up).
}
int main()
{
	initwindow(1000,1000);//initializes a graphics window of size 1000x1000 pixels.
	int x = 500, y = 500, radius = 100;//x & y center cordinates
	circle(x, y, radius);//draws a circle on the graphics window using the circle function. The circle is centered at (x, y) with the specified radius.
	boundaryFill4(x, y, 6, 15);/*calls the boundaryFill4 function to fill the area inside the circle. The fill_color is set to 6 and the boundary_color is set to 15.
	 The fill color will be applied to the area inside the circle, while the boundary color represents the boundary of the circle.*/
	delay(10000);// delay of 10000 milliseconds (10 seconds) to the program execution. It pauses the program for a certain amount of time before proceeding.
	getch();
	closegraph();
	return 0;
}
/* getch();: This line waits for a keyboard input.

closegraph();: This line closes the graphics window.

return 0;: This line indicates the successful termination of the program.*/
