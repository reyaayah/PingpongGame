#include<stdio.h>
#include<graphics.h>
void update();
void help();
struct ball{
	int x,y;
	float xspeed;
	float yspeed;
	int r;
}b;
struct bar{
	int x,y,w,l,g,h;
}b1,b2;
struct score{
	int s;
}s1,s2;
void update(){
	replay:
	
	//ball coordinate//
	b.r=15;
	b.xspeed=2.5;
	b.yspeed=5;
	b.x=getmaxx()/2;
	b.y=getmaxy()/2;
	//bat on left//
	b1.x=0;
	b1.y=100;
	b1.w=8;
	b1.l=20;
	b1.g=50;
	b1.h=b1.y-b1.l;
	//bat on right//
	b2.x=getmaxx();
	b2.y=100;
	b2.w=b2.x-8;
	b2.l=20;
	b2.g=50;
	b2.h=b2.y-b2.l;
	//score//
	s1.s=0;
	s2.s=0;
	
	char right[50], left[50];
		
	
	while(1){
				
	//score print//
	settextstyle(3,0,1);
	sprintf(right,"%d",s1.s);
	outtextxy(20,10,right);
	sprintf(left,"%d",s2.s);
	outtextxy(getmaxx()-50,10,left);
	bar(0,443,getmaxx(),443);
	b.x=b.x+b.xspeed;
	b.y=b.y+b.yspeed;
	if(b.y+b.r<0||b.y+b.r>getmaxy()){
		b.yspeed*=-1;
	}
	
	if(b.x+b.r>getmaxx()){
		s1.s++;
		b.x=getmaxx()/2;
		b.y=getmaxy()/2;
		
	}
	if(b.x+b.r<0){
		s2.s++;
		b.x=getmaxx()/2;
		b.y=getmaxy()/2;
	}
	circle(b.x,b.y,b.r);
	floodfill(b.x,b.y,WHITE);
	delay(30);
	cleardevice();
	bar(b1.x,b1.y,b1.w,b1.l);
	bar(b2.x,b2.y,b2.w,b2.l);
	if(kbhit()){
		int c=getch();
		if(c=='u'){
			b1.y-=b1.g;
			b1.l-=b1.g;
		}
		if(c=='d'){
			b1.y+=	b1.g;
			b1.l+=b1.g;
		}
		if(c=='p'){
			b2.y-=b2.g;
			b2.l-=b2.g;
		}
		if(c=='o'){
			b2.y+=	b2.g;
			b2.l+=b2.g;
		}
		delay(15);
	}
	if(b.x+b.r>b2.w&&b.y<b2.y&&b.y>b2.l){
		b.xspeed*=-1;
		delay(30);
	}
	if(b.x-b.r<b1.w&&b.y<b1.y&&b.y>b1.l){
		b.xspeed*=-1;
		delay(30);
	}
	if(s1.s==5||s2.s==5){
		cleardevice();
		break;
	}
	}
	outtextxy(getmaxx()/2-50,getmaxy()/2,"GAME OVER");
	delay(1000);
	cleardevice();
	if(s1.s==5){
		outtextxy(getmaxx()/2-50,getmaxy()/2,"PLAYER 1 WINS");
	}
	else{
		outtextxy(getmaxx()/2-5050,getmaxy()/2,"PLAYER 2 WINS");
	}
	delay(800);
	cleardevice();
	settextstyle(2,0,5);
    outtextxy(getmaxx()/2-50,200,"PLAY AGAIN (p)");
    outtextxy(getmaxx()/2-50,220,"QUIT (q)");
    if(kbhit){
  	int c=getch();
  	if(c==112)
  	{
  		goto replay;
  	}

  	else if(c==113)
  	{ 
  		exit(0);
  	}
  	}

}
void loading(){
	settextstyle(2,0,5);
	outtextxy(getmaxx()/2-150,getmaxy()/2-50,"WELCOME TO PING PONG GAME");
	outtextxy(250,350,"Loading");
	rectangle(240,330,332,338);
	for(int i=0;i<=86;i++){
		line(240+i,332,240+i,338);
		delay(50);
	}
	cleardevice();
}
void menu()  // prints options
	{
		settextstyle(2,0,7);
		outtextxy(230,155,"MAIN MENU");
		settextstyle(2,0,5);
		outtextxy(220,195,"Play Game(p)");
		outtextxy(220,215,"Help(h)");
		outtextxy(220,235,"Exit(e)");
		while(1){
			if(kbhit()){
				int c=getch();
					if(c==112){
						update();	
					}
			else if(c==104){
				help();
			}
			else if(c==101){
				exit(0);
			}
		}
		}
		
	}
void help()
{
	cleardevice();
	outtextxy(80,115,"INSTRUCTIONS");
	outtextxy(60,135," For left paddle(Player 1): ");
	outtextxy(70,155,"u key: Move up");
	outtextxy(70,175,"d key   : Move dowm");
	outtextxy(60,195,"For right paddle(Player 2) :");
	outtextxy(70,215,"o key    : Move up");
	outtextxy(70,235,"p key       : Move down");
	outtextxy(60,325,"Press esc to return to the main menu");
	outtextxy(60,285,"Who is the winner?");
	outtextxy(70,305,"The player scoring 5 at first win the game");
	while(1){
		if(kbhit()){
			int c=getch();
			if(c==27){
				cleardevice();
				menu();
				
			}
		}
	}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm," ");
	loading();
	menu();
	
	getch();
	closegraph();
}
