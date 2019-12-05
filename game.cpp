#include "iancon.h"

		//		NAVES		//
#define NAVE1 printf("%c=%c=%c", 123, 145, 125);//nave del jugador
#define NAVE2 printf("<=%c=>",190);
#define NAVE3 printf("%c-%c-%c", 174, 207, 175);

		//		ARMAS		//
//GUN//
#define GUN1 printf("- -%c", 207);
#define GUN2 printf("%c- -", 207);
//KNIFE//
#define KNIFE1 printf("%c%c%c", 175, 175, 175);
#define KNIFE2 printf("%c%c%c", 174, 174, 174);
//LASER//
#define LASER printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
//BOW//
#define BOW1 printf("%c%c>", 196, 196);
#define BOW2 printf("<%c%c", 196, 196);

	int vP1=3;	//vidas de lso jugadores
	int vP2=3;
	int players=0;//numero de jugadores
	
	//		Weapon's	//
	int Pw1=0, Pw2=0;
	
	int P1dir=1, P2dir=1;
	int wdir1, wdir2;
	
	int w1=0, w2=0;// armas de jugador 1 y 2
	int wdur1=0, wdur2=0;
	int xw1, yw1, xw2, yw2;
	
	int wxrand, wyrand, wrand, wgot=0;
	
	

void move(int &, int &, int &, int &, char , int &, int &);
void intart(int , int , int , int , int &, int &, int &, int , int, int, int);
void weapon(int , int , int, int);

int main()
{
	system("mode CON: COLS=150 LINES=25");
	int i, j, k;
	
	int win=0;
	
	//		Player's	//
	int x=10, y=10;
	int x1=10, y1=15;
	char P;
	
	//		IA's		//
	int ia, speed, wait;//ia para la cantidad de enemigos y velocidad
	int count[10];
	int iax[10], iay[10], iaV[10];
	
	printf("IA's: ");
	scanf("%d", &ia);
	printf("Velocidad de IA's: ");
	scanf("%d", &speed);
	printf("Jugadores: ");
	scanf("%d", &players);
	
	if(players==1)
		vP2=0;
			
	for(i=0; i<ia; i++){
		iaV[i]=3;
		count[i]=0;
		iax[i]=0;
		iay[i]=5;
	}
	
	wxrand=rand()%100+1;
	wyrand=rand()%40+1;
	wrand=rand()&4+1;
	
	color(163);
	printf ("START\n");
	system("pause");
	system("color 0A");
	
	while((vP1>0 || vP2>0) && win==0){//si la vida del jugador es mayor a 0
		wait++;
		
		gotoxy(5, 2);
		color(15);
		printf("Life(s) P1:\t");
		color(11);
		printf("%d", vP1);
		if(players==2){
			color(15);
			printf("\t\t\tLife(s) P2:\t");
			color(11);
			printf("%d", vP2);
		}
		
		gotoxy(5, 3);
		
		color(15);
		printf("Weapon:\t\t");
		color(11);
		if(w1==0){// 0 es que no tiene arma
			printf("Empty");
		}
		if(w1==1){// 1 es pistala
			printf("Gun");
		}
		if(w1==2){// 2 es cuchillo
			printf("Knife");
		}
		if(w1==3){// 3 es laser
			printf("Laser");
		}
		if(w1==4){// 4 es arco
			printf("Bow");
		}
		if(players==2){
			color(15);
			printf("\t\t\tWeapon:\t\t");
			color(11);
			if(w2==0)
			{
				printf("Empty");
			}
			if(w2==1)
			{
				printf("Gun");
			}
			if(w2==2)
			{
				printf("Knife");
			}
			if(w2==3)
			{
				printf("Laser");
			}
			if(w2==4)
			{
				printf("Bow");
			}
		}
		
		
		system("cls");
			
		if(vP1>0 || vP2>0)
			move(x, y, x1, y1, P, P1dir, P2dir);
			
		if(wait%500==0 || wgot==1){
			wgot=1;
			
			gotoxy(wxrand, wyrand);
			
			color(110);
			if(wrand==1)
			{
				printf("G");
			}
			if(wrand==2)
			{
				printf("K");
			}
			if(wrand==3)
			{
				printf("L");
			}
			if(wrand==4)
			{
				printf("B");
			}
			
			if(((wxrand>=x && wxrand<=x+4) && y==wyrand) || wrand==0){
				w1=wrand;
				wgot=0;
				
				wxrand=wait%120+1;
				wyrand=wait%25+6;
				wrand=wait%4+1;
			}
			if(((wxrand>=x1 && wxrand<=x1+4) && y1==wyrand)){
				w2=wrand;
				
				wgot=0;
				wxrand=wait%120+1;
				wyrand=wait%25+6;
				wrand=wait%4+1;
			}
		}
		
//		if(level==5)
//		{
			color(15);
			
			//		for para IA's	//
			for(i=0; i<ia; i++){
				if(i==0 && iaV[i]>0)
				{
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
				
				if(i==1 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
				
				if(i==2 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
					
				if(i==3 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
				
				if(i==4 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
					
				if(i==5 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
				
				if(i==6 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
					
				if(i==7 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
					
				if(i==8 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
					
				if(i==9 && wait>=i*150 && iaV[i]>0){
					if(iaV[i]==3)
						color(10);
						
					if(iaV[i]==2)
						color(14);
						
					if(iaV[i]==1)
						color(12);
					
					intart(x, y, x1, y1, iax[i], iay[i], count[i], speed, players, vP1, vP2);
				}
			}
			
			//		for para NO EMPALMAR IA's	//
			for(j=0; j<10; j++){
				for(i=0; i<10; i++){
					if(i==j){
						continue;
					}
					if((iax[j]==iax[i]) && (iay[j]==iay[i])){
						iax[j]+=3;
						iay[i]--;
					}
				}
			}
			
			//		for para DAÑO	//
			for(i=0; i<10; i++){
				if(vP1>0){
					if((iax[i]>=x && iax[i]<=x+4) && y==iay[i] && iaV[i]>0){
						vP1--;
						x=4;
						y=5;
						w1=0;
						break;
					}
				}
				
				if(vP2>0){
					if((iax[i]>=x1 && iax[i]<=x1+4) && y1==iay[i] && iaV[i]>0){
						vP2--;
						x1=4;
						y1=8;
						w2=0;
						break;
					}
				}
				
				if(iaV[i]>0){
					if((w1==1 || w1==4) && Pw1==1){
						if(wdir1==1){
							if(xw1+wdur1==iax[i] && yw1==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
						
						if(wdir1==2){
							if(xw1-wdur1==iax[i] && yw1==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
					}
					
					if(w1==2 && Pw1==1){
						if(wdir1==1){
							if((iax[i]>x+4 && iax[i]<x+8) && y==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
						
						if(wdir1==2){
							if((iax[i]>x-4 && iax[i]<x) && y==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
					}
					
					if(w1==3 && Pw1==1){
						if(wdir1==1){
							if((iax[i]>x+4 && iax[i]<x+17) && y==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
						
						if(wdir1==2){
							if((iax[i]>x-13 && iax[i]<x) && y==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
					}
					
					if((w2==1 || w2==4) && Pw2==1){
						if(wdir2==1){
							if(xw2+wdur2==iax[i] && yw2==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
						
						if(wdir2==2){
							if(xw2-wdur2==iax[i] && yw2==iay[i] && iaV[i]>0){
								iaV[i]--;
							}
						}
					}
					
					if(w2==2 && Pw2==1){
						if(wdir2==1){
							if((iax[i]>x1+4 && iax[i]<x1+8) && y1==iay[i] && iaV[i]>0)
							{
								iaV[i]--;
							}
						}
						
						if(wdir2==2)
						{
							if((iax[i]>x1-4 && iax[i]<x1) && y1==iay[i] && iaV[i]>0)
							{
								iaV[i]--;
							}
						}
					}
					
					if(w2==3 && Pw2==1)
					{
						if(wdir2==1)
						{
							if((iax[i]>x1+4 && iax[i]<x1+17) && y1==iay[i] && iaV[i]>0)
							{
								iaV[i]--;
							}
						}
						
						if(wdir2==2)
						{
							if((iax[i]>x1-13 && iax[i]<x1) && y1==iay[i] && iaV[i]>0)
							{
								iaV[i]--;
							}
						}
					}
				}
			}
			//		for DAÑO	//
			
			//		for para VICTORIA	//
			for(i=0; i<ia; i++)	{
				if(iaV[i]<=0){
					if(i==ia-1){
						win=1;
					}
				}
				else
				{
					break;
				}
			}
			
			//		Portal de VICTORIA		//
			
			//		PORTAL		//
			
//		}
	}
	
	if(vP1<=0 && vP2<=0)
	{
		system("color 4C");
		printf("Perdiste!!!");
	}
	if(win==1)
	{
		system("cls");
		system("color B0");
		printf("GANASTE");
	}
	
	getchar();
	getchar();
	
	return 0;
}

void move(int &x, int &y, int &x1, int &y1, char P, int &P1dir, int &P2dir)
{
	color(10);
	
	if(kbhit()){
		if(vP1>0){
			system("cls");
			P=getch();
			
			if(P=='w'){
				y--;
				if(y<5){
					y++;
				}
			}
			if(P=='a'){
				x--;
				if(x<0){
					x++;
				}
				P1dir=2;
			}
			if(P=='s')
			{
				y++;
			}
			if(P=='d')
			{
				x++;
				P1dir=1;
			}
			if(P=='q' && Pw1==0)
			{
				Pw1=1;
			}
		}
		
		if(players==2 && vP2>0)
		{
			if(P==72)
			{
				y1--;
				if(y1<5)
				{
					y1++;
				}
			}
			if(P==75)
			{
				x1--;
				if(x1<0)
				{
					x1++;
				}
				P2dir=2;
			}
			if(P==80)
			{
				y1++;
			}
			if(P==77)
			{
				x1++;
				P2dir=1;
			}
			if(P==45 && Pw2==0)
			{
				Pw2=1;
			}
		}
	}
	
	if(vP1>0){
		gotoxy(x, y);
		NAVE1;//impresion de la nave
	}
	if(vP2>0){
		gotoxy(x1, y1);
		NAVE2;
	}
		
	
	//ARMAS Y DISPAROS//	P1//
	if(w1>0 && Pw1==1 && vP1>0)
	{
		if(wdur1==0)
		{
			xw1=x;
			yw1=y;
			wdir1=P1dir;
		}
		wdur1++;
		
		// GUN	//
		if(w1==1)
		{
			if(wdir1==1)
			{
				gotoxy(xw1+wdur1, yw1);
				GUN1;
			}
			if(wdir1==2)
			{
				if(xw1-wdur1>=0)
				{
					gotoxy(xw1-wdur1, yw1);
					GUN2;
				}
			}
		}
		
		//	KNIFE	//
		if(w1==2)
		{
			if(wdir1==1)
			{
				gotoxy(x+5, y);
				KNIFE1;
			}
			if(wdir1==2)
			{
				if(x-3>=0)
				{
					gotoxy(x-3, y);
					KNIFE2;
				}
			}
		}
		
		//	LASER	//
		if(w1==3)
		{
			if(wdir1==1)
			{
				gotoxy(xw1+5, yw1);
				LASER;
			}
			if(wdir1==2)
			{
				if(xw1-wdur1>=0)
				{
					gotoxy(xw1-15, yw1);
					LASER;
				}
			}
		}
		
		//	BOW	//
		if(w1==4)
		{
			if(wdir1==1)
			{
				gotoxy(xw1+wdur1, yw1);
				BOW1;
			}
			if(wdir1==2)
			{
				if(xw1-wdur1>=0)
				{
					gotoxy(xw1-wdur1, yw1);
					BOW2;
				}
			}
		}
		
		if(wdur1==30)
		{
			wdur1=0;
			Pw1=0;
		}
	}
		
	//ARMAS Y DISPAROS//	P2//
	
	if(w2>0 && Pw2==1 && vP2>0)
	{
		if(wdur2==0)
		{
			xw2=x1;
			yw2=y1;
			wdir2=P2dir;
		}
		wdur2++;
		
		//	GUN	//
		if(w2==1)
		{
			if(wdir2==1)
			{
				gotoxy(xw2+wdur2, yw2);
				GUN1;
			}
			if(wdir2==2)
			{
				if(xw2-wdur2>=0)
				{
					gotoxy(xw2-wdur2, yw2);
					GUN2;
				}
				
			}
		}
		
		//	KNIFE	//
		if(w2==2)
		{
			if(wdir2==1)
			{
				gotoxy(x1+5, y1);
				KNIFE1;
			}
			if(wdir2==2)
			{
				if(x1-3>=0)
				{
					gotoxy(x1-3, y1);
					KNIFE2;
				}
			}
		}
		
		//	LASER	//
		if(w2==3)
		{
			if(wdir2==1)
			{
				gotoxy(xw2+5, yw2);
				LASER;
			}
			if(wdir2==2)
			{
				if(xw2-wdur2>=0)
				{
					gotoxy(xw2-15, yw2);
					LASER;
				}
			}
		}
		
		//	BOW	//
		if(w2==4)
		{
			if(wdir2==1)
			{
				gotoxy(xw2+wdur2, yw2);
				BOW1;
			}
			if(wdir2==2)
			{
				if(xw2-wdur2>=0)
				{
					gotoxy(xw2-wdur2, yw2);
					BOW2;
				}
			}
		}
			
		if(wdur2==30)
		{
			wdur2=0;
			Pw2=0;
		}
	}
}

			//		//		//		//			//			//
void intart(int x, int y, int x2, int y2, int &x1, int &y1, int &count, int vel, int pl, int vP1, int vP2)
{
	float d13=0, d23=0;
	
	gotoxy(x1, y1);
	printf("&");
	
	d13=(sqrt(pow((x-x1), 2)+pow((y-y1), 2)));
	
	d23=(sqrt(pow((x2-x1), 2)+pow((y2-y1), 2)));
	
	if(d13<=d23 || vP2<=0 && vP1>0)
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
	
	if((d23<d13 || vP1<=0) && players==2 && vP2>0)
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
