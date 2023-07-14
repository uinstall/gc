#include<graphics.h> 
#include<conio.h> 
#include<iostream>
#include<math.h> 
 using namespace std; 
 class polygon
{
public:
void DDA(float x1,float y1,float x2,float y2); void boundary_4(int x, int y, int f_cl, int b_cl); void boundary_8(int x, int y, int f_cl, int b_cl); void flood_4(int x,int y,int f_cl, int d_cl);
void flood_8(int x,int y,int f_cl, int d_cl); void scanline_algo();
};


void polygon::DDA(float x1,float y1,float x2,float y2)



{
float x,y,dx,dy,step; dx=(x2-x1);
dy=(y2-y1); if(abs(dx)>=abs(dy))
{



}
else
{


}

step=abs(dx);





step=abs(dy);

dx=dx/step; dy=dy/step; x=x1; y=y1;
putpixel(x,y,WHITE); int i=1; while(i<=step)
{

putpixel(x,y,WHITE); x+=dx;
y+=dy; i+=1;
}
}





void polygon::boundary_4(int x, int y, int f_cl, int b_cl)
{
if(getpixel(x,y)!=b_cl && getpixel(x,y)!=f_cl) { putpixel(x,y,f_cl);
boundary_4(x+1, y, f_cl, b_cl); boundary_4(x, y+1, f_cl, b_cl); boundary_4(x-1, y, f_cl, b_cl); boundary_4(x, y-1, f_cl, b_cl);
}
}


void polygon:: boundary_8(int x, int y, int f_cl,int b_cl)
{

if(getpixel(x, y) != b_cl && getpixel(x, y) != f_cl)
{

putpixel(x, y, f_cl); boundary_8(x + 1, y, f_cl, b_cl); boundary_8(x, y + 1, f_cl, b_cl); boundary_8(x - 1, y, f_cl, b_cl); boundary_8(x, y - 1, f_cl, b_cl);
boundary_8(x - 1, y - 1, f_cl, b_cl); boundary_8(x - 1, y + 1, f_cl, b_cl); boundary_8(x + 1, y - 1, f_cl, b_cl); boundary_8(x + 1, y + 1, f_cl, b_cl);
}



}


void polygon:: flood_4(int x,int y,int f_cl, int d_cl)
{

if(getpixel(x,y)==d_cl)
{

putpixel(x,y,f_cl); flood_4(x+1,y,f_cl,d_cl); flood_4(x-1,y,f_cl,d_cl); flood_4(x,y+1,f_cl,d_cl); flood_4(x,y-1,f_cl,d_cl);
}
}


void polygon:: flood_8(int x,int y,int f_cl, int d_cl)
{

if(getpixel(x,y)==d_cl)
{

putpixel(x,y,f_cl); flood_8(x+1,y,f_cl,d_cl); flood_8(x-1,y,f_cl,d_cl); flood_8(x,y+1,f_cl,d_cl); flood_8(x,y-1,f_cl,d_cl); flood_8(x+1,y+1,f_cl,d_cl); flood_8(x-1,y+1,f_cl,d_cl); flood_8(x+1,y-1,f_cl,d_cl);



flood_8(x-1,y-1,f_cl,d_cl);


}
}


void polygon:: scanline_algo()
{

int n, x[10], y[10], k=0, y_min=1000000, y_max=0, Y, dx, dy, xi[100], gm, gd, temp;
float slope[100];
printf("\nEnter the number of vertices of polygon :"); scanf("%d",&n);
printf("\nEnter the coordinates of vertices of polygon :"); for(int i=0;i<n;i++)
{

scanf("%d%d",&x[i],&y[i]); if(y[i]>y_max)
y_max=y[i]; if(y[i]<y_min) y_min=y[i];
}

x[n]=x[0];y[n]=y[0]; for(int i=0;i<n;i++)
{

line(x[i],y[i],x[i+1],y[i+1]);
}



for(int i=0;i<n;i++)
{

dx=x[i+1]-x[i];
dy=y[i+1]-y[i]; if(dy==0) slope[i]=1.0; if(dx==0) slope[i]=0.0; if(dx!=0 && dy!=0) slope[i]=(float)dx/dy;
}

for(int j=0;j<=y_max;j++)
{

int k=0;
for(int i=0;i<n;i++)
{

if(((y[i]<=j) && (y[i+1]>j)) || ((y[i]>j) && (y[i+1]<=j)))
{

xi[k]=(int)(x[i]+slope[i]*(j-y[i])); k++;
}
}

for(int m=0;m<k-1;m++)
{

for(int i=0;i<k-1;i++)
{



if(xi[i]>xi[i+1])
{

temp=xi[i]; xi[i]=xi[i+1]; xi[i+1]=temp;
}
}
setcolor(5);
for(int i=0;i<k;i+=2)
{

line(xi[i],j,xi[i+1]+1,j); delay(100);
}
}
}
}


int main()
{
int gd = DETECT ,gm; initgraph(&gd, &gm, (char*)"");
cout<<"DIFFERENT TYPES OF POLYGON FILLING ALGORITHM ARE AS FOLLOWS : ";
cout<<"\n\t1. DDA Algorithm\n\t2.Boundary Fill Algo(4)\n\t3.Boundary Fill Algo(8)\n\t4.Flood Fill Algo(4)\n\t5.Flood Fill Algo(8)\n\t6.Scanline Algo";
int choice=0, choice1=0;



do
{
cout<<"\nENTER YOUR CHOICE : ";
cin>>choice; switch(choice)
{

case 1:
polygon obj1; obj1.DDA(200, 200, 200,400);
polygon obj2; obj2.DDA(200, 400, 400,400);
polygon obj3; obj3.DDA(400, 400, 400,200);
polygon obj4; obj4.DDA(400, 200, 200,200); break;

case 2:
polygon a1; a1.boundary_4(201, 201, 9, 15); break;

case 3:
polygon a2; a2.boundary_8(201, 201, 3, 15); break;

case 4:
polygon a3; a3.flood_4(201, 201, 6, 0);



break; case 5:
polygon a4; a4.flood_8(201, 201, 4, 0);
break; case 6:
polygon a5; a5.scanline_algo(); break;
default:
cout<<"\nPLEASE ENTER CORRECT CHOICE!!!";
}
cout<<"\nPRESS 1 TO CONTINUE	";
cin >> choice1;
}

while(choice1==1); getch(); closegraph(); return 0;
}

