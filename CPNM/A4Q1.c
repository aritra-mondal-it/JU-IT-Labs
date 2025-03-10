#include <stdio.h>
#include <math.h>
float dist(int x1,int y1,int x2, int y2);
float areacal(float a,float b,float c);
int isInside(float area,float area1,float area2,float area3);
void main()
{
    int x1,y1,x2,y2,x3,y3,x,y;
    printf("Enter the the value of x1,y1,x2,y2,x3,y3,x,y :");
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x,&y);
    float ab=dist(x1,y1,x2,y2);
    float bc=dist(x2,y2,x3,y3);
    float ca=dist(x3,y3,x1,y1);
    float pa=dist(x,y,x1,y1);
    float pb=dist(x,y,x2,y2);
    float pc=dist(x,y,x3,y3);
    float area=areacal(ab,bc,ca);
    float area1=areacal(pa,pb,ab);
    float area2=areacal(pb,pc,bc);
    float area3=areacal(pa,pc,ca);
    if (isInside(area,area1,area2,area3) == 1)
        printf("The point is inside the triangle !!");
    else    
        printf("The point lies outside the triangle!!");
}
float dist(int x1,int y1,int x2, int y2)
{
    float dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return dist;
}
float areacal(float a,float b,float c)
{
    float s=(a+b+c)/2;
    float area=sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}
int isInside(float area,float area1,float area2,float area3)
{
    if (area==(area1+area2+area3))
        return 1;
    else
        return 0;
}
