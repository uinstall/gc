//Name:Patel Vinit Ashok
//Roll no:240

#include <graphics.h>// // header file that provides functions and data types for graphics programming. here putpixel(),	boundaryFill()
void flood(int x, int y, int new_col, int old_col)/* This line defines the flood function, which is responsible for performing the flood fill operation. 
It takes four parameters: x and y represent the starting point coordinates, new_col represents the new color to be filled, and old_col represents the old color to be replaced.*/
{
	if (getpixel(x, y) == old_col) //checking if the current pixel at coordinates (x, y) has the same color as the old_col.
	{

		putpixel(x, y, new_col);

		flood(x + 1, y, new_col, old_col);

		flood(x - 1, y, new_col, old_col);

		flood(x, y + 1, new_col, old_col);

		flood(x, y - 1, new_col, old_col);
	}
}
/* If the condition is true, it means the current pixel needs to be filled. So, the putpixel function is used to set the color of the current pixel at coordinates (x, y) to the new_col.
After filling the current pixel, the flood function is recursively called for adjacent pixels in four directions (up, down, left, and right) by updating the coordinates accordingly. 
This ensures that the fill operation continues until all connected pixels of the same old_col are filled with the new_col.*/
int main()
{

	initwindow(1000,1000);//initializes a graphics window of size 1000x1000 pixels.
	int top, left, bottom, right;
	top = left = 50;
	bottom = right = 300;
	rectangle(left, top, right, bottom);
	int x = 51;
	int y = 51;
	int newcolor = 5;
	int oldcolor = 0;
	flood(x, y, newcolor, oldcolor);
	getch();
	return 0;
}

/*The rectangle function is used to draw a rectangle on the graphics window. The rectangle's top-left corner is at coordinates (left, top), and the
 bottom-right corner is at coordinates (right, bottom).The variables x and y represent the starting point coordinates for the flood fill operation. 
 The variable newcolor represents the new color to be filled, and oldcolor represents the old color to be replaced.
The flood function is called with the provided parameters to perform the flood fill operation starting from the point (x, y). 
It fills the area enclosed by the rectangle with the color newcolor, replacing the color oldcolor.
Finally, getch function waits for a keyboard input, and closegraph function closes the graphics window. The program terminates by returning 0.*/

