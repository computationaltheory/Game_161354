#include <stdio.h>
#include <windows.h>  
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}  

void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

			//		//		//		//			//			//
void intart(int x, int y, int x2, int y2, int &x1, int &y1, int &count, int vel)
{
	float d13=0, d23=0;
	
	gotoxy(x1, y1);
	printf("&");
	
	d13=(sqrt(pow((x-x1), 2)+pow((y-y1), 2)));
	
	d23=(sqrt(pow((x2-x1), 2)+pow((y2-y1), 2)));
	
	
	if(d13<=d23)
	{
		if(x<x1)
		{
			count++;
			if(count==vel)
			{
				x1--;
				count=0;
			}
		}
		
		if(x>x1)
		{
			count++;
			if(count==vel)
			{
				x1++;
				count=0;
			}
		}
		
		if(y<y1)
		{
			count++;
			if(count==vel)
			{
				y1--;
				count=0;
			}
		}
		
		if(y>y1)
		{
			count++;
			if(count==vel)
			{
				y1++;
				count=0;
			}
		}
	}
	
	if(d23<d13)
	{
		if(x2<x1)
		{
			count++;
			if(count==vel)
			{
				x1--;
				count=0;
			}
		}
		
		if(x2>x1)
		{
			count++;
			if(count==vel)
			{
				x1++;
				count=0;
			}
		}
		
		if(y2<y1)
		{
			count++;
			if(count==vel)
			{
				y1--;
				count=0;
			}
		}
		
		if(y2>y1)
		{
			count++;
			if(count==vel)
			{
				y1++;
				count=0;
			}
		}
	}
}
