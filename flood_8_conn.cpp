#include<graphics.h>  // header file that provides functions and data types for graphics programming. here putpixel(),	boundaryFill()
void floodfill(int x,int y,int old,int newcol) //function, which is responsible for performing the flood fill operation 
{  //x & y=starting point coordinates, old= color of the area to be filled  newcol= color to be filled.
                int current;  //variable is used to store the color of the current pixel at coordinates (x, y) using the getpixel function.
                current=getpixel(x,y);  
                if(current==old)  
                {  
                                delay(0.5);  //introduced to control the speed of filling. This delay provides a small pause before filling each pixel, giving a visual effect of the fill operation.
                                putpixel(x,y,newcol);//function is then used to set the color of the current pixel at coordinates (x, y) to the newcol color.  
                                floodfill(x+1,y,old,newcol);  
                                floodfill(x-1,y,old,newcol);  
                                floodfill(x,y+1,old,newcol);  
                                floodfill(x,y-1,old,newcol);  
                                floodfill(x+1,y+1,old,newcol);  
                                floodfill(x-1,y+1,old,newcol);  
                                floodfill(x+1,y-1,old,newcol);  
                                floodfill(x-1,y-1,old,newcol);  
                }  /*floodfill function is recursively called for adjacent pixels in all eight directions (up, down, left, right, and diagonals). 
				This ensures that the fill operation continues until all connected pixels of the same old color are filled with the newcol color.*/
}  
int main()  
{  
                  
                initwindow(1000,1000);  //nitializes a graphics window of size 1000x1000 pixels.
                rectangle(40,40,150,150); //rectangle function is used to draw a rectangle on the graphics window. 
			//	The rectangle's top-left corner is at coordinates (40, 40), and the bottom-right corner is at coordinates (150, 150). 
                floodfill(70,70,0,10);  // floodfill function is called to perform the flood fill operation starting from the point (70, 70).
				// It fills the area enclosed by the rectangle with the color 10, replacing the color 0.
                getch();  
                return 0; //Finally, getch function waits for a keyboard input, and closegraph function closes the graphics window. The program terminates by returning 0.
}  
