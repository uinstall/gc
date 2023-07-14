#include <iostream>
#include <graphics.h>// header files to use input/output operations and graphics functions 

using namespace std;
// declares that the program is using the std namespace, which allows you to use standard library functions and objects without specifying the namespace explicitly.
int main()
{
int n,i,j,k,gd,gm,dy,dx;//n= no of edges of polygon  i, j, k =loop control variables ,gd =graphics driver gm =graphics mode, dy and dx represent the differences in y and x coordinates
int x,y,temp; //x and y = temporary variables, temp=temporary variable for swapping,
int a[20][2],xi[20];//a 2d array of size to store the coordinates of the polygon
float slope[20]; //xi and slope are arrays to store intermediate values for the scanline algorithm.

cout<<"\n\n\tEnter the no. of edges of polygon : ";
cin>>n;

cout<<"\n\n\tEnter the cordinates of polygon :\n\n\n";
for(i=0;i<n;i++)
 {
printf("\tX%d Y%d : ",i,i);
scanf("%d %d",&a[i][0],&a[i][1]);
 }//prompt the user to enter the number of edges of the polygon (n) and the coordinates of the polygon vertices (a[i][0] and a[i][1]). 
 //The user is asked to enter the x and y coordinates of each vertex.
 
a[n][0]=a[0][0];
a[n][1]=a[0][1];
//set the last vertex of the polygon to be the same as the first vertex. This is done to close the polygon when drawing lines later.
initwindow(1000,1000);// initializes a graphics window of size 1000x1000 pixels

for(i=0;i<n;i++)
{
 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
}
//These lines draw the polygon on the graphics window by connecting the vertices using the line function.
getch();// waits for a keypress to allow the user to view the polygon before proceeding.

for(i=0;i<n;i++)
{
dy=a[i+1][1]-a[i][1];
dx=a[i+1][0]-a[i][0];
if(dy==0) slope[i]=1.0;
if(dx==0) slope[i]=0.0;
if((dy!=0)&&(dx!=0)) 
{
 slope[i]=(float) dx/dy;
}
}
//These lines calculate the slope of each edge of the polygon and store it in the slope array. 
//The slope is calculated using the differences in y and x coordinates of consecutive vertices. 
//If the slope is vertical (dx=0), it is set to 0.0, and if the slope is horizontal (dy=0), it is set to 1.0.
for(y=0;y< 480;y++)
{
 k=0;
 for(i=0;i<n;i++)

 {
if( ((a[i][1]<=y)&&(a[i+1][1]>y))||
((a[i][1]>y)&&(a[i+1][1]<=y)))
{
xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
k++;
}
 }
for(j=0;j<k-1;j++) 
for(i=0;i<k-1;i++)
{
 if(xi[i]>xi[i+1])
 {
temp=xi[i];
xi[i]=xi[i+1];
xi[i+1]=temp;
}
}
setcolor(3);
for(i=0;i<k;i+=2)
{
line(xi[i],y,xi[i+1]+1,y);
getch();
}
}
}
/*These lines implement the scanline algorithm for filling the polygon. For each scanline (y-coordinate), it checks if the scanline intersects any edge of the polygon. If it does, it calculates the intersection point with that edge and stores it in the xi array.

After finding all the intersection points, the xi array is sorted in ascending order.

Then, for each pair of consecutive intersection points, a horizontal line is drawn between them using the line function, effectively filling that scanline segment.

The setcolor(3) function sets the color of the lines to be drawn on the graphics window.

Finally, the getch() function waits for a keypress after each line is drawn, allowing the user to view the filling process*/
