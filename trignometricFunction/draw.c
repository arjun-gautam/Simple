#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#define PI 3.1415926
#define PATH "C:\\TC\\BGI" //bgi folder path
#define SIZE 100

struct center{
int x,y;
};
struct center center;
double sinDeg(int angle); //function to count sin in degree.
//default sin function in C uses radian.
//this function use default sin function to calculate sin in degree
double cosDeg(int angle);
void createGraph();
void drawAxisLine();

int main()
{
int gd=DETECT,gm;

initgraph(&gd,&gm,PATH);
drawAxisLine();
createGraph();
closegraph();

return 0;
}

double sinDeg(int angle)
{
return sin((PI/180)*angle);
}

double cosDeg(int angle)
{
return cos((PI/180)*angle);
}

void createGraph()
{
int angle;
double y,x,r;


//use any one of the polar function below. Comment other while using a particular one
for(angle=0;angle<360;angle++)
{
//r=(sinDeg(angle)+cosDeg(angle))*SIZE; // r=sin(theta)+cos(theta)
r=(1+cosDeg(angle))*SIZE; // r=1+cos(theta)
//r=(sinDeg(2*angle)+cosDeg(angle))*SIZE; // sin(2 theta) + cos(theta)
//r=(sinDeg(2*angle)+cosDeg(2*angle))*SIZE; // sin(2 theta) + cos(2 theta)
//r=(sinDeg(5*angle)+1)*SIZE; // sin(5 theta) + 1

x=r*cosDeg(angle)+center.x;
y=r*sinDeg(angle)+center.y;
putpixel(x,y,YELLOW);
delay(20);
}
printf("Press any key to exit");
getch();
}

void drawAxisLine()
{
int maxX,maxY;
setcolor(RED);

maxX=getmaxx();
maxY=getmaxy();

center.x=maxX/2;
center.y=maxY/2;

line(center.x,0,center.x,maxY);
line(0,center.y,maxX,center.y);
}

