// Name : Vinit Patel
// Roll no: 240
#include<iostream>
#include<graphics.h>
using namespace std;

void midPoint(int xcenter, int ycenter, int radius){
   int x = 0;
   int y = radius;
   int p = 1 - radius;
   void plotpoints(int, int , int, int);
   plotpoints(xcenter, ycenter, x, y);
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

void plotpoints(int xcenter, int ycenter, int x, int y){
    putpixel(xcenter+x, ycenter+y, RED);
    putpixel(xcenter-x, ycenter+y, GREEN);
    putpixel(xcenter+x, ycenter-y, BLUE);
    putpixel(xcenter-x, ycenter-y, WHITE);
    putpixel(xcenter+y, ycenter+x, WHITE);
    putpixel(xcenter-y, ycenter+x, BLUE);
    putpixel(xcenter+y, ycenter-x, GREEN);
    putpixel(xcenter-y, ycenter-x, RED);
}

int main(){
	initwindow(1000,1000);
	int r, xc, yc, pk, x, y;
	cout<<" Mid-Point Circle Drawing Algorithm \n\n";
	cout<<"Enter the center co-ordinates\nX= ";
	cin>>xc;	
	cout<<"Y= ";
	cin>>yc;
	cout<<"Enter the radius of circle = ";
	cin>>r;
  	midPoint(xc, yc, r);

  getch();
  return 0;
}
