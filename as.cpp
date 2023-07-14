#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
using namespace std;
int ch;
class Transformation
{
float x[20],y[20],xm,ym,ref[2][2],shx,shy;
int i,j,k,n;
float sx,sy,tx,ty,ang;
float xtmp[20],ytmp[20];
public:
void scale();
void rotate();
void reflect();
void shear();
void takeinput();
void menu();
void mapgraph();
void plotint();
void translate();
void plotfinal();
};
void Transformation::translate()
{
for(i=0;i<n;i++)
{
xtmp[i]=x[i]+tx;
ytmp[i]=y[i]+ty;
}
}
void Transformation::plotfinal()
{
for(i=0;i<n-1;i++)
{
circle(xtmp[i]+xm,(-ytmp[i]+ym),2);
circle(xtmp[n-1]+xm,(-ytmp[n-1]+ym),2);
line(xtmp[i]+xm,(-ytmp[i]+ym),xtmp[i+1]+xm,(-
ytmp[i+1]+ym));
}
line(xtmp[n-1]+xm,(-ytmp[n-1]+ym),xtmp[0]+xm,(-
ytmp[0]+ym));
}
void Transformation::takeinput()
{
cout<<"Enter the number of sides/vertices : ";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter the "<<i+1<<" coordinates(x,y) : ";
cin>>x[i]>>y[i];
}}
void Transformation::menu()
{
int z,kk;
cout<<"\n MAIN MENU\n ";
cout<<"\n1:Translation\n2:Scaling\n3:Rotation\n4:Reflection\n5:Shearing\n6:Exit\nEnter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter tx : ";
cin>>tx;
cout<<"\nEnter ty : ";
cin>>ty;
break;
case 2:
cout<<"\nEnter sx : ";
cin>>sx;
cout<<"\nEnter sy : ";
cin>>sy;
break;
case 3:
cout<<"\nEnter the angle of rotation : ";
cin>>ang;
break;
case 4:
{
cout<<"\nReflection Menu";
cout<<"\n1:X-Plane\n2:YPlane\n3:Origin\n4:Y=X Plane\n5:Y=-X Plane\nEnter your choice : ";
cin>>z;
switch(z)
{
case 1:
ref[0][0]=1;
ref[0][1]=0;
ref[1][0]=0;
ref[1][1]=-1;
break;
case 2:
ref[0][0]=-1;
ref[0][1]=0;
ref[1][0]=0;
ref[1][1]=1;
break;
case 3:
ref[0][0]=-1;
ref[0][1]=0;
ref[1][0]=0;
ref[1][1]=-1;
break;
case 4:
ref[0][0]=0;
ref[0][1]=1;
ref[1][0]=1;
ref[1][1]=0;
break;
case 5:
ref[0][0]=0;
ref[0][1]=1;
ref[1][0]=-1;
ref[1][1]=0;
break;
}
break;
}
case 5:
{
cout<<"\nShearing Menu\n1:X-DIR\n2:YDIR\n3:X,Y-DIR\nEnter your choice : ";
cin>>kk;
switch(kk)
{
case 1:
cout<<"Enter shx : ";
cin>>shx;
ref[0][0]=1;
ref[0][1]=0;
ref[1][0]=shx;
ref[1][1]=1;
break;
case 2:
cout<<"Enter shy : ";
cin>>shy;
ref[0][0]=1;
ref[0][1]=shy;
ref[1][0]=0;
ref[1][1]=1;
break;
case 3:
cout<<"Enter shx : ";
cin>>shx;
cout<<"Enter shy : ";
cin>>shy;
ref[0][0]=1;
ref[0][1]=shy;
ref[1][0]=shx;
ref[1][1]=1;
break;
}
break;
}}}
void Transformation::mapgraph()
{
xm=getmaxx()/2;
ym=getmaxy()/2;
line(xm,0,xm,2*ym);
line(0,ym,2*xm,ym);
}
void Transformation::plotint()
{
for(i=0;i<n-1;i++)
{
circle(x[i]+xm,-y[i]+ym,2);
circle(x[n-1]+xm,-y[n-1]+ym,2);
line(x[i]+xm,(-y[i]+ym),x[i+1]+xm,(-y[i+1]+ym));
}
line(x[n-1]+xm,(-y[n-1]+ym),x[0]+xm,(-y[0]+ym));
}
void Transformation::scale()
{
float a[2][2],mxy[7][2],rxy[7][2];
a[0][0]=sx;
a[0][1]=0;
a[1][0]=0;
a[1][1]=sy;
tx=-x[0];
ty=-y[0];
translate();
k=0;
for(i=0;i<n;i++)
{
j=0;
mxy[i][j]=xtmp[k];
mxy[i][j+1]=ytmp[k];
k++;
}
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
rxy[i][j]=0;
for(k=0;k<2;k++)
{
rxy[i][j]+=mxy[i][k]*a[k][j];
}}}
j=0;k=0;
for(i=0;i<n;i++)
{
j=0;
x[k]=rxy[i][j];
y[k]=rxy[i][j+1];
k++;
}
tx=-tx;
ty=-ty;
translate();
}
void Transformation::rotate()
{
float r[2][2],mxy[7][2],rxy[7][2],tmp;
tmp=22/7;
tmp=(tmp*ang)/180;
r[0][0]=cos(tmp);
r[0][1]=sin(tmp);
r[1][0]=cos(tmp);
r[1][1]=sy;
tx=-x[0];
ty=-y[0];
translate();
k=0;
for(i=0;i<n;i++)
{
j=0;
mxy[i][j]=xtmp[k];
mxy[i][j+1]=ytmp[k];
k++;
}
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
rxy[i][j]=0;
for(k=0;k<2;k++)
{
rxy[i][j]+=mxy[i][k]*r[k][j];
}}}
j=0;k=0;
for(i=0;i<n;i++)
{
j=0;
x[k]=rxy[i][j];
y[k]=rxy[i][j+1];
k++;
}
tx=-tx;
ty=-ty;
translate();
}
void Transformation::shear()
{
float mxy[7][2],rxy[7][2],tmp;
tx=0;
ty=0;
translate ();
k=0;
for(i=0;i<n;i++)
{
j=0;
mxy[i][j]=xtmp[k];
mxy[i][j+1]=ytmp[k];
k++;
}
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
rxy[i][j]=0;
for (k=0;k<2;k++)
{
rxy[i][j]+=mxy[i][k]*ref[k][j];
}}}
j=0;
k=0;
for(i=0;i<n;i++)
{
j=0;
x[k]=rxy[i][j];
y[k]=rxy[i][j+1];
k++;
}
tx=-tx;
ty=-ty;
translate ();
}
void Transformation::reflect()
{
float mxy[7][2],rxy[7][2],tmp;
tx=0;
ty=0;
translate();
k=0;
for(i=0;i<n;i++)
{
j=0;
mxy[i][j]=xtmp[k];
mxy[i][j+1]=ytmp[k];
k++;
}
for(i=0;i<n;i++)
{
for(j=0;j<2;j++)
{
rxy[i][j]=0;
for(k=0;k<2;k++)
{
rxy[i][j]+=mxy[i][k]*ref[k][j];
}}}
j=0;
k=0;
for(i=0;i<n;i++)
{
j=0;
x[k]=rxy[i][j];
y[k]=rxy[i][j+1];
k++;
}
tx=-tx;
ty=-ty;
translate();
}
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,(char*)"");
Transformation t1;
t1.takeinput();
t1.menu();
t1.mapgraph();
t1.plotint();
do
{
switch(ch)
{
case 1:
setcolor(10);
t1.plotint();
t1.translate();
setcolor(11);
t1.plotfinal();
break;
case 2:
setcolor(10);
t1.plotint();
t1.scale();
setcolor(11);
t1.plotfinal();
break;
case 3:
setcolor(10);
t1.plotint();
t1.rotate();
setcolor(11);
t1.plotfinal();
break;
case 4:
setcolor(10);
t1.plotint();
t1.reflect();
setcolor(11);
t1.plotfinal();
break;
case 5:
setcolor(10);
t1.plotint();
t1.shear();
setcolor(11);
t1.plotfinal();
break;
case 6:
exit(0);
}
getch();
t1.plotfinal();
getch();
closegraph();
return 0;}
while(ch>=4);
}
