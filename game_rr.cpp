
#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<stdio.h>

using namespace std ;
void obstacle(int , int );
int check(int , int , int , int , int , int );
void gameover_rr(int );
void game_rr();
void pause();
int score=0;


void obstacle(int bx , int by )
    {
        //setcolor(YELLOW);
        //bar(bx-100,by,bx-50,by+60);
        bar(bx,by,bx+70,by+50);
        bar(bx+180,by+30,bx+220,by+70);
        bar(bx+300,by,bx+350,by+50);
        bar(bx+410,by,bx+500,by+30);
        bar(bx+560,by,bx+620,by+40);
    }
int  check(int x,int y,int i1 , int j1 , int i2 , int j2 )
{
    if(x>i1&&x<i2)
    {
        if(y>j1&&y<j2)
           {
             return 1;
           }
    }
    else
        return 0 ;
}

void gameover_rr(int score)
{

/*   setactivepage(1-page);
    setvisualpage(page);*/
    cleardevice();
    //cout<<"score =" << score ;
    settextstyle(1,HORIZ_DIR,4);
    outtextxy(250,200, "GAME OVER" );
    delay(1000);
    //exit(0);
    //system("PAUSE");

}

void game_rr()
{
    char scr[30];
    int m =4;
    int r = 17 ;
    int bx=0,by=50,ch,by1=50,bx1=0,by2=50,bx2=1000,by3=50;
    int cx,cy ;
    int maxx=getmaxx(),maxy=getmaxy();
    int page = 0 ;


    cx=maxx/2,cy =maxy/2;

    settextstyle(1,HORIZ_DIR,3);
    int p = 5;
    while(1)

        {
            setactivepage(page);
            setvisualpage(1-page);

            cleardevice();
            setcolor(GREEN);
            sprintf(scr,"SCORE:  %d",score);
            outtextxy(350,10,scr);

            score++ ;

            setcolor(1);
            setfillstyle(1,1);
            circle(cx,cy+200,r);
            floodfill(cx,cy+200,1);
            setcolor(RED);
            setfillstyle(1,RED);
            rectangle(0,maxy-10,maxx,maxy);
            floodfill(maxx/2,maxy-5,RED);

            setcolor(YELLOW);
            setfillstyle(4,YELLOW);
            obstacle(bx , by);
            obstacle(bx+30 , by-100);
            obstacle(bx-50, by-240);
            obstacle(bx+30, by-360);
            obstacle(bx+90 , by-500);
            obstacle(bx-100 , by-620);
            by = by+2;

            if(GetAsyncKeyState(VK_UP))
            {
                cy=cy-m;
            }
                if(GetAsyncKeyState(VK_DOWN))
            {
                cy=cy+m;
            }
                if(GetAsyncKeyState(VK_LEFT))
            {
                cx=cx-m;
            }
            if(GetAsyncKeyState(VK_RIGHT))
            {
                cx=cx+m;
            }
            if(
               //cx+r
                  (check(cx+r , cy+210,bx,by,bx+70,by+50) ==1)
               || (check(cx+r , cy+210 , bx+180,by+30,bx+220,by+70)==1)
               || (check(cx +r, cy+210 , bx+300,by,bx+350,by+50)==1)
               || (check(cx +r, cy+210, bx+410,by,bx+500,by+30)==1)
               || (check(cx +r, cy+210 , bx+560,by,bx+620,by+40)==1)
               ||(check(cx +r,  cy+210,    bx+30,by-100,bx+70 +30,by+50 -100) ==1)
               || (check(cx+r , cy+210 , bx+180 +30,by+30 -100,bx+220 +30,by+70 -100)==1)
               || (check(cx +r, cy+210 , bx+300 +30,by -100,bx+350 +30,by+50 -100)==1)
               || (check(cx+r , cy+210 , bx+410 +30,by -100,bx+500 +30,by+30 -100)==1)
               || (check(cx +r, cy+210 , bx+560 +30,by -100,bx+620 +30,by+40 -100)==1) ||
                  (check(cx+r ,cy+210,bx-50,by-240,bx+70-50,by+50-240) ==1)
               || (check(cx +r, cy+210 , bx+180-50,by+30-240,bx+220-50,by+70-240)==1)
               || (check(cx+r , cy+210 , bx+300-50,by-240,bx+350-50,by+50-240)==1)
               || (check(cx +r, cy+210 , bx+410-50,by-240,bx+500-50,by+30-240)==1)
               || (check(cx+r, cy+210 , bx+560-50,by-240,bx+620-50,by+40-240)==1) ||
               (check(cx +r,cy+210,bx+30,by-360,bx+70 +30,by+50 -360) ==1)
               || (check(cx +r, cy+210 , bx+180 +30,by+30 -360,bx+220 +30,by+70 -360)==1)
               || (check(cx +r, cy+210 , bx+300 +30,by -360,bx+350 +30,by+50 -360)==1)
               || (check(cx +r, cy+210 , bx+410 +30,by -360,bx+500 +30,by+30 -360)==1)
               || (check(cx +r, cy+210 , bx+560 + 30,by -360,bx+620 +30,by+40 -360)==1)||
                   (check(cx+r ,cy+210,bx +90,by-500,bx+70 +90,by+50 -500) ==1)
                || (check(cx +r, cy+210 , bx+180+90,by+30 -500,bx+220 +90,by+70 -500)==1)
               || (check(cx +r, cy+210, bx+300 +90,by -500,bx+350 +90,by+50 -500)==1)
               || (check(cx +r, cy+210 , bx+410 +90,by -500,bx+500 +90,by+30 -500)==1)
               || (check(cx +r, cy+210 , bx+560 +90,by-500,bx+620 +90,by+40 -500)==1) ||
                  (check(cx +r,cy+210,bx-100,by -620,bx+70 -100,by+50 -620) ==1)
               || (check(cx +r, cy+210 , bx+180 -100,by+30 -620,bx+220 -100,by+70 -620)==1)
               || (check(cx +r, cy+210, bx+300 -100,by -620,bx+350 -100,by+50 -620)==1)
               || (check(cx+r, cy+210 , bx+410 -100,by -620,bx+500 -100,by+30 -620)==1)
               || (check(cx +r, cy+210, bx+560 -100,by -620,bx+620 -100,by+40 -620)==1) ||
               // cx - r
               (check(cx-r ,cy+210,bx,by,bx+70,by+50) ==1)
               || (check(cx-r , cy+210 , bx+180,by+30,bx+220,by+70)==1)
               || (check(cx -r, cy+210, bx+300,by,bx+350,by+50)==1)
               || (check(cx -r, cy+210 , bx+410,by,bx+500,by+30)==1)
               || (check(cx -r, cy+210 , bx+560,by,bx+620,by+40)==1)
               ||(check(cx -r,cy+210,bx+30,by-100,bx+70 +30,by+50 -100) ==1)
               || (check(cx-r , cy+210 , bx+180 +30,by+30 -100,bx+220 +30,by+70 -100)==1)
               || (check(cx -r, cy+210 , bx+300 +30,by -100,bx+350 +30,by+50 -100)==1)
               || (check(cx-r , cy+210 , bx+410 +30,by -100,bx+500 +30,by+30 -100)==1)
               || (check(cx -r, cy+210 , bx+560 +30,by -100,bx+620 +30,by+40 -100)==1) ||
                  (check(cx-r ,cy+210,bx-50,by-240,bx+70-50,by+50-240) ==1)
               || (check(cx -r, cy+210 , bx+180-50,by+30-240,bx+220-50,by+70-240)==1)
               || (check(cx-r , cy+210 , bx+300-50,by-240,bx+350-50,by+50-240)==1)
               || (check(cx -r, cy+210, bx+410-50,by-240,bx+500-50,by+30-240)==1)
               || (check(cx-r, cy+210, bx+560-50,by-240,bx+620-50,by+40-240)==1) ||
                  (check(cx -r,cy+210,bx+30,by-360,bx+70 +30,by+50 -360) ==1)
               || (check(cx -r, cy+210 , bx+180 +30,by+30 -360,bx+220 +30,by+70 -360)==1)
               || (check(cx -r, cy+210 , bx+300 +30,by -360,bx+350 +30,by+50 -360)==1)
               || (check(cx -r, cy+210, bx+410 +30,by -360,bx+500 +30,by+30 -360)==1)
               || (check(cx -r, cy+210, bx+560 + 30,by -360,bx+620 +30,by+40 -360)==1)
               || (check(cx-r ,cy+210,bx +90,by-500,bx+70 +90,by+50 -500) ==1)
               || (check(cx -r, cy+210 , bx+180+90,by+30 -500,bx+220 +90,by+70 -500)==1)
               || (check(cx -r, cy+210 , bx+300 +90,by -500,bx+350 +90,by+50 -500)==1)
               || (check(cx -r, cy+210 , bx+410 +90,by -500,bx+500 +90,by+30 -500)==1)
               || (check(cx -r, cy+210 , bx+560 +90,by-500,bx+620 +90,by+40 -500)==1) ||
                  (check(cx -r, cy+210,bx-100,by -620,bx+70 -100,by+50 -620) ==1)
               || (check(cx -r, cy+210, bx+180 -100,by+30 -620,bx+220 -100,by+70 -620)==1)
               || (check(cx -r, cy+210, bx+300 -100,by -620,bx+350 -100,by+50 -620)==1)
               || (check(cx-r , cy+210, bx+410 -100,by -620,bx+500 -100,by+30 -620)==1)
               || (check(cx -r, cy+210, bx+560 -100,by -620,bx+620 -100,by+40 -620)==1)||
               //cy+r
               (check(cx ,cy+210+r,bx,by,bx+70,by+50) ==1)
               || (check(cx , cy+210+r , bx+180,by+30,bx+220,by+70)==1)
               || (check(cx , cy+210+r, bx+300,by,bx+350,by+50)==1)
               || (check(cx, cy+210 +r, bx+410,by,bx+500,by+30)==1)
               || (check(cx , cy+210 +r, bx+560,by,bx+620,by+40)==1)
               ||(check(cx ,cy+210+r,bx+30,by-100,bx+70 +30,by+50 -100) ==1)
               || (check(cx , cy+210 +r, bx+180 +30,by+30 -100,bx+220 +30,by+70 -100)==1)
               || (check(cx , cy+210 +r, bx+300 +30,by -100,bx+350 +30,by+50 -100)==1)
               || (check(cx , cy+210 +r, bx+410 +30,by -100,bx+500 +30,by+30 -100)==1)
               || (check(cx , cy+210 +r, bx+560 +30,by -100,bx+620 +30,by+40 -100)==1) ||
                  (check(cx ,cy+210+r,bx-50,by-240,bx+70-50,by+50-240) ==1)
               || (check(cx , cy+210 +r, bx+180-50,by+30-240,bx+220-50,by+70-240)==1)
               || (check(cx , cy+210 +r, bx+300-50,by-240,bx+350-50,by+50-240)==1)
               || (check(cx , cy+210+r, bx+410-50,by-240,bx+500-50,by+30-240)==1)
               || (check(cx, cy+210+r, bx+560-50,by-240,bx+620-50,by+40-240)==1) ||
                  (check(cx ,cy+210+r,bx+30,by-360,bx+70 +30,by+50 -360) ==1)
               || (check(cx , cy+210+r , bx+180 +30,by+30 -360,bx+220 +30,by+70 -360)==1)
               || (check(cx , cy+210 +r, bx+300 +30,by -360,bx+350 +30,by+50 -360)==1)
               || (check(cx , cy+210+r, bx+410 +30,by -360,bx+500 +30,by+30 -360)==1)
               || (check(cx , cy+210+r, bx+560 + 30,by -360,bx+620 +30,by+40 -360)==1)
               || (check(cx ,cy+210+r,bx +90,by-500,bx+70 +90,by+50 -500) ==1)
               || (check(cx , cy+210 +r, bx+180+90,by+30 -500,bx+220 +90,by+70 -500)==1)
               || (check(cx , cy+210 +r, bx+300 +90,by -500,bx+350 +90,by+50 -500)==1)
               || (check(cx , cy+210 +r, bx+410 +90,by -500,bx+500 +90,by+30 -500)==1)
               || (check(cx , cy+210 +r, bx+560 +90,by-500,bx+620 +90,by+40 -500)==1) ||
                  (check(cx , cy+210+r,bx-100,by -620,bx+70 -100,by+50 -620) ==1)
               || (check(cx , cy+210+r, bx+180 -100,by+30 -620,bx+220 -100,by+70 -620)==1)
               || (check(cx , cy+210+r, bx+300 -100,by -620,bx+350 -100,by+50 -620)==1)
               || (check(cx , cy+210+r, bx+410 -100,by -620,bx+500 -100,by+30 -620)==1)
               || (check(cx , cy+210+r, bx+560 -100,by -620,bx+620 -100,by+40 -620)==1)

                               )
                {
                    return;
                    gameover_rr(score);}
            delay(20);

            setcolor(MAGENTA);
            setfillstyle(1,MAGENTA);for(int h = 0;h<20;h++){
            obstacle(bx-20+h ,  by1-1800+h);
            obstacle(bx-20 ,  by1-1900);
            obstacle(bx-100, by1-2000);
            obstacle(bx-100, by1-2100);
            obstacle(bx +30, by1-2200);
            obstacle(bx+80 , by1-2350);
            obstacle(bx-90 , by1-2500);
            obstacle(bx+30 , by1-2650);
            obstacle(bx+80 , by1-2800);
            obstacle(bx+80 , by1-2900);
            obstacle(bx+150, by1-3000);
            obstacle(bx+150, by1-3100);
            obstacle(bx-90 , by1-3200);
            obstacle(bx+50 , by1-3350);}
            by1= by1 +5;

                if( GetAsyncKeyState(VK_LEFT))//a
                {cx=cx-m;}

                 if( GetAsyncKeyState(VK_UP))//w
                {cy=cy-m;}

                 if( GetAsyncKeyState(VK_DOWN))//s
                {cy=cy+m;}

                if(GetAsyncKeyState(VK_RIGHT))//d
                {cx=cx+m;}

                if(
                   //cx+r
                   (check(cx+r,cy+210,bx-20,by1-1800,bx+70-20,by1+50-1800) ==1)
                   || (check(cx+r, cy+210, bx+180-20,by1+30-1800,bx+220-20,by1+70-1800)==1)
                   || (check(cx +r, cy+210, bx+300-20,by1-1800,bx+350-20,by1+50-1800)==1)
                   || (check(cx +r, cy+210, bx+410-20,by1-1800,bx+500-20,by1+30-1800)==1)
                   || (check(cx +r, cy+210 , bx+560-20,by1-1800,bx+620-20,by1+40-1800)==1)||
                       (check(cx+r , cy+210, bx-20,    by1-1900,   bx+70-20, by1+50-1900) ==1)
                    || (check(cx+r, cy+210, bx+180-20,by1+30-1900,bx+220-20,by1+70-1900)==1)
                    || (check(cx +r, cy+210, bx+300-20,by1-1900,   bx+350-20,by1+50-1900)==1)
                    || (check(cx +r, cy+210, bx+410-20,by1-1900,   bx+500-20,by1+30-1900)==1)
                    || (check(cx +r, cy+210, bx+560-20,by1-1900,   bx+620-20,by1+40-1900)==1) ||
                       (check(cx+r , cy+210,     bx-100,    by1-2000,    bx+70-100,by1+50-2000) ==1)
                   || (check( cx+r , cy+210 , bx+180-100,by1+30-2000,bx+220-100,by1+70-2000)==1)
                    || (check(cx+r, cy+210 ,bx+300-100,by1-2000,   bx+350-100,by1+50-2000)==1)
                   || (check( cx+r, cy+210 , bx+410-100,by1-2000,   bx+500-100,by1+30-2000)==1)
                    || (check(cx+r,  cy+210 , bx+560-100,by1-2000,  bx+620-100,by1+40-2000)==1)||
                        (check(cx+r ,cy+210,bx-100,by1-2100,bx+70-100,by1+50-2100) ==1)
                   || (check(cx+r , cy+210 , bx+180-100,by1+30-2100,bx+220-100,by1+70-2100)==1)
                    || (check(cx +r, cy+210, bx+300-100,by1-2100,bx+350-100,by1+50-2100)==1)
                   || (check(cx +r, cy+210, bx+410-100,by1-2100,bx+500-100,by1+30-2100)==1)
                    || (check(cx+r,  cy+210 , bx+560-100,by1-2100,  bx+620-100,by1+40-2100)==1)||
                        (check(cx+r,cy+210,bx+30,by1-2200,bx+70+30,by1+50-2200) ==1)
                   || (check(cx+r , cy+210 , bx+180+30,by1+30-2200,bx+220+30,by1+70-2200)==1)
                    || (check(cx +r, cy+210, bx+300+30,by1-2200,bx+350+30,by1+50-2200)==1)
                   || (check(cx +r, cy+210 , bx+410+30,by1-2200,bx+500+30,by1+30-2200)==1)
                    || (check(cx+r,  cy+210 , bx+560+30,by1-2200,  bx+620+30,by1+40-2200)==1)||
                        (check(cx+r,cy+210,bx+80,by1-2350,bx+70+80,by1+50-2350) ==1)
                   || (check(cx+r , cy+210, bx+180+80,by1+30-2350,bx+220+80,by1+70-2350)==1)
                    || (check(cx +r, cy+210, bx+300+80,by1-2350,bx+350+80,by1+50-2350)==1)
                   || (check(cx +r, cy+210, bx+410+80,by1-2350,bx+500+80,by1+30-2350)==1)
                    || (check(cx+r,  cy+210, bx+560+80,by1-2350,  bx+620+80,by1+40-2350)==1)||
                        (check(cx+r,cy+210,bx -90 ,by1-2500,bx+70 -90 ,by1+50-2500) ==1)
                   || (check(cx+r , cy+210 , bx+180 -90 ,by1+30-2500,bx+220 -90 ,by1+70-2500)==1)
                    || (check(cx +r, cy+210 , bx+300 -90 ,by1-2500,bx+350 -90 ,by1+50-2500)==1)
                   || (check(cx +r, cy+210, bx+410 -90 ,by1-2500,bx+500 -90 ,by1+30-2500)==1)
                    || (check(cx+r,  cy+210, bx+560-90,by1-2500,  bx+620-90,by1+40-2500)==1)||
                        (check(cx+r,cy+210,bx+30,by1-2650,bx+70+30,by1+50-2650) ==1)
                   || (check(cx+r , cy+210 , bx+180+30,by1+30-2650,bx+220+30,by1+70-2650)==1)
                    || (check(cx +r, cy+210 , bx+300+30,by1-2650,bx+350+30,by1+50-2650)==1)
                    || (check(cx +r, cy+210, bx+410+30,by1-2650,bx+500+30,by1+30-2650)==1)
                    || (check(cx+r,  cy+210 , bx+560+30,by1-2650,  bx+620+30,by1+40-2650)==1)
                    ||    (check(cx+r,cy+210,bx+80 ,by1-2800,bx+70+80 ,by1+50-2800) ==1)
                   || (check(cx+r , cy+210, bx+180+80 ,by1+30-2800,bx+220+80 ,by1+70-2800)==1)
                    || (check(cx +r, cy+210 , bx+300+80 ,by1-2800,bx+350+80 ,by1+50-2800)==1)
                   || (check(cx +r, cy+210 , bx+410+80 ,by1-2800,bx+500+80 ,by1+30-2800)==1)
                    || (check(cx+r,  cy+210 , bx+560+80 ,by1-2800,  bx+620+80 ,by1+40-2800)==1)||
                   (check(cx+r,cy+210,bx+80,by1-2900,bx+70+80,by1+50-2900) ==1)
                   || (check(cx+r , cy+210 , bx+180+80,by1+30-2900,bx+220+80,by1+70-2900)==1)
                    || (check(cx +r, cy+210  , bx+300+80,by1-2900,bx+350+80,by1+50-2900)==1)
                   || (check(cx +r, cy+210 , bx+410+80,by1-2900,bx+500+80,by1+30-2900)==1)
                    || (check(cx+r,  cy+210 , bx+560+80,by1-2900,  bx+620+80,by1+40-2900)==1)||
                      (check(cx+r,cy+210,bx+150,by1-3000,bx+70+150,by1+50-3000) ==1)
                   || (check(cx+r , cy+210 , bx+180+150,by1+30-3000,bx+220+150,by1+70-3000)==1)
                   || (check(cx +r, cy+210 , bx+300+150,by1-3000,bx+350+150,by1+50-3000)==1)
                   || (check(cx +r, cy+210, bx+410+150,by1-3000,bx+500+150,by1+30-3000)==1)
                   || (check(cx+r,  cy+210 , bx+560+150,by1-3000,  bx+620+150,by1+40-3000)==1)||
                   (check(cx+r,cy+210,bx+150,by1-3100,bx+70+150,by1+50-3100) ==1)
                   || (check(cx+r , cy+210, bx+180+150,by1+30-3100,bx+220+150,by1+70-3100)==1)
                    || (check(cx +r, cy+210 , bx+300+150,by1-3100,bx+350+150,by1+50-3100)==1)
                   || (check(cx +r, cy+210, bx+410+150,by1-3100,bx+500+150,by1+30-3100)==1)
                   || (check(cx+r,  cy+210 , bx+560+150,by1-3100,  bx+620+150,by1+40-3100)==1)||
                    (check(cx+r,cy+210,bx-90,by1-3200,bx+70-3200-90,by1+50-3200) ==1)
                   || (check(cx+r , cy+210, bx+180-90,by1+30-3200,bx+220-90,by1+70-3200)==1)
                   || (check(cx +r, cy+210 , bx+300-90,by1-3200,bx+350-90,by1+50-3200)==1)
                   || (check(cx +r, cy+210, bx+410-90,by1-3200,bx+500-90,by1+30-3200)==1)
                   || (check(cx+r,  cy+210, bx+560-90,by1-3200,  bx+620-90,by1+40-3200)==1)||
                    (check(cx+r,cy+210,bx+50,by1-3350,bx+70+50,by1+50-3350) ==1)
                   || (check(cx+r , cy+210 , bx+180+50,by1+30-3350,bx+220+50,by1+70-3350)==1)
                    || (check(cx +r, cy+210 , bx+300+50,by1-3350,bx+350+50,by1+50-3350)==1)
                   || (check(cx +r, cy+210 , bx+410+50,by1-3350,bx+500+50,by1+30-3350)==1)
                   || (check(cx+r,  cy+210, bx+560+50,by1-3350,  bx+620+50,by1+40-3350)==1)||

                    //cx-r
                   (check(cx-r,cy+210,bx-20,by1-1800,bx+70-20,by1+50-1800) ==1)
                   || (check(cx-r, cy+210, bx+180-20,by1+30-1800,bx+220-20,by1+70-1800)==1)
                   || (check(cx -r, cy+210, bx+300-20,by1-1800,bx+350-20,by1+50-1800)==1)
                   || (check(cx -r, cy+210, bx+410-20,by1-1800,bx+500-20,by1+30-1800)==1)
                   || (check(cx -r, cy+210 , bx+560-20,by1-1800,bx+620-20,by1+40-1800)==1)||
                       (check(cx-r , cy+210, bx-20,    by1-1900,   bx+70-20, by1+50-1900) ==1)
                    || (check(cx-r, cy+210, bx+180-20,by1+30-1900,bx+220-20,by1+70-1900)==1)
                    || (check(cx -r, cy+210, bx+300-20,by1-1900,   bx+350-20,by1+50-1900)==1)
                    || (check(cx -r, cy+210, bx+410-20,by1-1900,   bx+500-20,by1+30-1900)==1)
                    || (check(cx -r, cy+210, bx+560-20,by1-1900,   bx+620-20,by1+40-1900)==1) ||
                       (check(cx-r , cy+210,     bx-100,    by1-2000,    bx+70-100,by1+50-2000) ==1)
                   || (check( cx-r , cy+210 , bx+180-100,by1+30-2000,bx+220-100,by1+70-2000)==1)
                    || (check(cx-r, cy+210 ,bx+300-100,by1-2000,   bx+350-100,by1+50-2000)==1)
                   || (check( cx-r, cy+210 , bx+410-100,by1-2000,   bx+500-100,by1+30-2000)==1)
                    || (check(cx-r,  cy+210 , bx+560-100,by1-2000,  bx+620-100,by1+40-2000)==1)||
                        (check(cx-r ,cy+210,bx-100,by1-2100,bx+70-100,by1+50-2100) ==1)
                   || (check(cx-r , cy+210 , bx+180-100,by1+30-2100,bx+220-100,by1+70-2100)==1)
                    || (check(cx -r, cy+210 , bx+300-100,by1-2100,bx+350-100,by1+50-2100)==1)
                   || (check(cx -r, cy+210 , bx+410-100,by1-2100,bx+500-100,by1+30-2100)==1)
                    || (check(cx-r,  cy+210 , bx+560-100,by1-2100,  bx+620-100,by1+40-2100)==1)||
                        (check(cx-r,cy+210,bx+30,by1-2200,bx+70+30,by1+50-2200) ==1)
                   || (check(cx-r , cy+210, bx+180+30,by1+30-2200,bx+220+30,by1+70-2200)==1)
                    || (check(cx -r, cy+210 , bx+300+30,by1-2200,bx+350+30,by1+50-2200)==1)
                   || (check(cx -r, cy+210, bx+410+30,by1-2200,bx+500+30,by1+30-2200)==1)
                    || (check(cx-r,  cy+210 , bx+560+30,by1-2200,  bx+620+30,by1+40-2200)==1)||
                        (check(cx-r,cy+210,bx+80,by1-2350,bx+70+80,by1+50-2350) ==1)
                   || (check(cx-r , cy+210 , bx+180+80,by1+30-2350,bx+220+80,by1+70-2350)==1)
                    || (check(cx -r, cy+210 , bx+300+80,by1-2350,bx+350+80,by1+50-2350)==1)
                   || (check(cx -r, cy+210 , bx+410+80,by1-2350,bx+500+80,by1+30-2350)==1)
                    || (check(cx-r,  cy+210 , bx+560+80,by1-2350,  bx+620+80,by1+40-2350)==1)||
                        (check(cx-r,cy+210,bx -90 ,by1-2500,bx+70 -90 ,by1+50-2500) ==1)
                   || (check(cx-r , cy+210 , bx+180 -90 ,by1+30-2500,bx+220 -90 ,by1+70-2500)==1)
                    || (check(cx -r, cy+210 , bx+300 -90 ,by1-2500,bx+350 -90 ,by1+50-2500)==1)
                   || (check(cx -r, cy+210, bx+410 -90 ,by1-2500,bx+500 -90 ,by1+30-2500)==1)
                    || (check(cx-r,  cy+210 , bx+560-90,by1-2500,  bx+620-90,by1+40-2500)==1)||
                        (check(cx-r,cy+210,bx+30,by1-2650,bx+70+30,by1+50-2650) ==1)
                   || (check(cx-r , cy+210 , bx+180+30,by1+30-2650,bx+220+30,by1+70-2650)==1)
                    || (check(cx -r, cy+210 , bx+300+30,by1-2650,bx+350+30,by1+50-2650)==1)
                    || (check(cx -r, cy+210 , bx+410+30,by1-2650,bx+500+30,by1+30-2650)==1)
                    || (check(cx-r,  cy+210 , bx+560+30,by1-2650,  bx+620+30,by1+40-2650)==1)
                    ||    (check(cx-r,cy+210,bx+80 ,by1-2800,bx+70+80 ,by1+50-2800) ==1)
                   || (check(cx-r , cy+210 , bx+180+80 ,by1+30-2800,bx+220+80 ,by1+70-2800)==1)
                    || (check(cx -r, cy+210 , bx+300+80 ,by1-2800,bx+350+80 ,by1+50-2800)==1)
                   || (check(cx -r, cy+210 , bx+410+80 ,by1-2800,bx+500+80 ,by1+30-2800)==1)
                    || (check(cx-r,  cy+210 , bx+560+80 ,by1-2800,  bx+620+80 ,by1+40-2800)==1)||
                   (check(cx-r,cy+210,bx+80,by1-2900,bx+70+80,by1+50-2900) ==1)
                   || (check(cx-r , cy+210 , bx+180+80,by1+30-2900,bx+220+80,by1+70-2900)==1)
                    || (check(cx -r, cy+210 , bx+300+80,by1-2900,bx+350+80,by1+50-2900)==1)
                   || (check(cx -r, cy+210 , bx+410+80,by1-2900,bx+500+80,by1+30-2900)==1)
                    || (check(cx-r,  cy+210 , bx+560+80,by1-2900,  bx+620+80,by1+40-2900)==1)||
                      (check(cx-r,cy+210,bx+150,by1-3000,bx+70+150,by1+50-3000) ==1)
                   || (check(cx-r , cy+210 , bx+180+150,by1+30-3000,bx+220+150,by1+70-3000)==1)
                   || (check(cx -r, cy+210, bx+300+150,by1-3000,bx+350+150,by1+50-3000)==1)
                   || (check(cx -r, cy+210, bx+410+150,by1-3000,bx+500+150,by1+30-3000)==1)
                   || (check(cx-r,  cy+210 , bx+560+150,by1-3000,  bx+620+150,by1+40-3000)==1)||
                   (check(cx-r,cy+210,bx+150,by1-3100,bx+70+150,by1+50-3100) ==1)
                   || (check(cx-r , cy+210 , bx+180+150,by1+30-3100,bx+220+150,by1+70-3100)==1)
                    || (check(cx -r, cy+210, bx+300+150,by1-3100,bx+350+150,by1+50-3100)==1)
                   || (check(cx -r, cy+210 , bx+410+150,by1-3100,bx+500+150,by1+30-3100)==1)
                   || (check(cx-r,  cy+210 , bx+560+150,by1-3100,  bx+620+150,by1+40-3100)==1)||
                    (check(cx-r,cy+210,bx-90,by1-3200,bx+70-3200-90,by1+50-3200) ==1)
                   || (check(cx-r , cy+210 , bx+180-90,by1+30-3200,bx+220-90,by1+70-3200)==1)
                   || (check(cx -r, cy+210 , bx+300-90,by1-3200,bx+350-90,by1+50-3200)==1)
                   || (check(cx -r, cy+210 , bx+410-90,by1-3200,bx+500-90,by1+30-3200)==1)
                   || (check(cx-r,  cy+210 , bx+560-90,by1-3200,  bx+620-90,by1+40-3200)==1)||
                    (check(cx-r,cy+210,bx+50,by1-3350,bx+70+50,by1+50-3350) ==1)
                   || (check(cx-r , cy+210 , bx+180+50,by1+30-3350,bx+220+50,by1+70-3350)==1)
                    || (check(cx -r, cy+210 , bx+300+50,by1-3350,bx+350+50,by1+50-3350)==1)
                   || (check(cx -r, cy+210 , bx+410+50,by1-3350,bx+500+50,by1+30-3350)==1)
                   || (check(cx-r,  cy+210 , bx+560+50,by1-3350,  bx+620+50,by1+40-3350)==1)||

                   //cy+r
                   (check(cx,cy+210+r,bx-20,by1-1800,bx+70-20,by1+50-1800) ==1)
                   || (check(cx, cy+210+r, bx+180-20,by1+30-1800,bx+220-20,by1+70-1800)==1)
                   || (check(cx , cy+210+r, bx+300-20,by1-1800,bx+350-20,by1+50-1800)==1)
                   || (check(cx , cy+210+r, bx+410-20,by1-1800,bx+500-20,by1+30-1800)==1)
                   || (check(cx , cy+210+r , bx+560-20,by1-1800,bx+620-20,by1+40-1800)==1)||
                       (check(cx , cy+210+r, bx-20,    by1-1900,   bx+70-20, by1+50-1900) ==1)
                    || (check(cx, cy+210+r, bx+180-20,by1+30-1900,bx+220-20,by1+70-1900)==1)
                    || (check(cx , cy+210+r, bx+300-20,by1-1900,   bx+350-20,by1+50-1900)==1)
                    || (check(cx , cy+210+r, bx+410-20,by1-1900,   bx+500-20,by1+30-1900)==1)
                    || (check(cx , cy+210+r, bx+560-20,by1-1900,   bx+620-20,by1+40-1900)==1) ||
                       (check(cx , cy+210+r,     bx-100,    by1-2000,    bx+70-100,by1+50-2000) ==1)
                   || (check( cx , cy+210+r , bx+180-100,by1+30-2000,bx+220-100,by1+70-2000)==1)
                    || (check(cx, cy+210 +r,bx+300-100,by1-2000,   bx+350-100,by1+50-2000)==1)
                   || (check( cx, cy+210 +r, bx+410-100,by1-2000,   bx+500-100,by1+30-2000)==1)
                    || (check(cx,  cy+210+r , bx+560-100,by1-2000,  bx+620-100,by1+40-2000)==1)||
                        (check(cx ,cy+210+r,bx-100,by1-2100,bx+70-100,by1+50-2100) ==1)
                   || (check(cx , cy+210+r , bx+180-100,by1+30-2100,bx+220-100,by1+70-2100)==1)
                    || (check(cx , cy+210  +r, bx+300-100,by1-2100,bx+350-100,by1+50-2100)==1)
                   || (check(cx , cy+210 +r, bx+410-100,by1-2100,bx+500-100,by1+30-2100)==1)
                    || (check(cx,  cy+210+r , bx+560-100,by1-2100,  bx+620-100,by1+40-2100)==1)||
                        (check(cx,cy+210+r,bx+30,by1-2200,bx+70+30,by1+50-2200) ==1)
                   || (check(cx , cy+210+r , bx+180+30,by1+30-2200,bx+220+30,by1+70-2200)==1)
                    || (check(cx , cy+210  +r, bx+300+30,by1-2200,bx+350+30,by1+50-2200)==1)
                   || (check(cx , cy+210 +r, bx+410+30,by1-2200,bx+500+30,by1+30-2200)==1)
                    || (check(cx,  cy+210+r , bx+560+30,by1-2200,  bx+620+30,by1+40-2200)==1)||
                        (check(cx,cy+210+r,bx+80,by1-2350,bx+70+80,by1+50-2350) ==1)
                   || (check(cx , cy+210+r , bx+180+80,by1+30-2350,bx+220+80,by1+70-2350)==1)
                    || (check(cx , cy+210  +r, bx+300+80,by1-2350,bx+350+80,by1+50-2350)==1)
                   || (check(cx , cy+210 +r, bx+410+80,by1-2350,bx+500+80,by1+30-2350)==1)
                    || (check(cx,  cy+210+r , bx+560+80,by1-2350,  bx+620+80,by1+40-2350)==1)||
                        (check(cx,cy+210+r,bx -90 ,by1-2500,bx+70 -90 ,by1+50-2500) ==1)
                   || (check(cx , cy+210+r , bx+180 -90 ,by1+30-2500,bx+220 -90 ,by1+70-2500)==1)
                    || (check(cx , cy+210  +r, bx+300 -90 ,by1-2500,bx+350 -90 ,by1+50-2500)==1)
                   || (check(cx , cy+210 +r, bx+410 -90 ,by1-2500,bx+500 -90 ,by1+30-2500)==1)
                    || (check(cx,  cy+210+r , bx+560-90,by1-2500,  bx+620-90,by1+40-2500)==1)||
                        (check(cx,cy+210+r,bx+30,by1-2650,bx+70+30,by1+50-2650) ==1)
                   || (check(cx , cy+210+r , bx+180+30,by1+30-2650,bx+220+30,by1+70-2650)==1)
                    || (check(cx , cy+210  +r, bx+300+30,by1-2650,bx+350+30,by1+50-2650)==1)
                    || (check(cx , cy+210 +r, bx+410+30,by1-2650,bx+500+30,by1+30-2650)==1)
                    || (check(cx,  cy+210+r , bx+560+30,by1-2650,  bx+620+30,by1+40-2650)==1)
                    ||    (check(cx,cy+210+r,bx+80 ,by1-2800,bx+70+80 ,by1+50-2800) ==1)
                   || (check(cx, cy+210+r , bx+180+80 ,by1+30-2800,bx+220+80 ,by1+70-2800)==1)
                    || (check(cx , cy+210  +r, bx+300+80 ,by1-2800,bx+350+80 ,by1+50-2800)==1)
                   || (check(cx , cy+210 +r, bx+410+80 ,by1-2800,bx+500+80 ,by1+30-2800)==1)
                    || (check(cx,  cy+210+r , bx+560+80 ,by1-2800,  bx+620+80 ,by1+40-2800)==1)||
                   (check(cx,cy+210+r,bx+80,by1-2900,bx+70+80,by1+50-2900) ==1)
                   || (check(cx , cy+210+r , bx+180+80,by1+30-2900,bx+220+80,by1+70-2900)==1)
                    || (check(cx , cy+210  +r, bx+300+80,by1-2900,bx+350+80,by1+50-2900)==1)
                   || (check(cx , cy+210 +r, bx+410+80,by1-2900,bx+500+80,by1+30-2900)==1)
                    || (check(cx,  cy+210+r , bx+560+80,by1-2900,  bx+620+80,by1+40-2900)==1)||
                      (check(cx,cy+210+r,bx+150,by1-3000,bx+70+150,by1+50-3000) ==1)
                   || (check(cx , cy+210+r , bx+180+150,by1+30-3000,bx+220+150,by1+70-3000)==1)
                   || (check(cx , cy+210  +r, bx+300+150,by1-3000,bx+350+150,by1+50-3000)==1)
                   || (check(cx, cy+210 +r, bx+410+150,by1-3000,bx+500+150,by1+30-3000)==1)
                   || (check(cx,  cy+210+r , bx+560+150,by1-3000,  bx+620+150,by1+40-3000)==1)||
                   (check(cx,cy+210+r,bx+150,by1-3100,bx+70+150,by1+50-3100) ==1)
                   || (check(cx , cy+210+r , bx+180+150,by1+30-3100,bx+220+150,by1+70-3100)==1)
                    || (check(cx , cy+210  +r, bx+300+150,by1-3100,bx+350+150,by1+50-3100)==1)
                   || (check(cx , cy+210 +r, bx+410+150,by1-3100,bx+500+150,by1+30-3100)==1)
                   || (check(cx,  cy+210+r , bx+560+150,by1-3100,  bx+620+150,by1+40-3100)==1)||
                    (check(cx,cy+210+r,bx-90,by1-3200,bx+70-3200-90,by1+50-3200) ==1)
                   || (check(cx , cy+210+r , bx+180-90,by1+30-3200,bx+220-90,by1+70-3200)==1)
                   || (check(cx , cy+210  +r, bx+300-90,by1-3200,bx+350-90,by1+50-3200)==1)
                   || (check(cx , cy+210 +r, bx+410-90,by1-3200,bx+500-90,by1+30-3200)==1)
                   || (check(cx,  cy+210+r , bx+560-90,by1-3200,  bx+620-90,by1+40-3200)==1)||
                    (check(cx,cy+210+r,bx+50,by1-3350,bx+70+50,by1+50-3350) ==1)
                   || (check(cx , cy+210+r , bx+180+50,by1+30-3350,bx+220+50,by1+70-3350)==1)
                    || (check(cx , cy+210 +r, bx+300+50,by1-3350,bx+350+50,by1+50-3350)==1)
                   || (check(cx , cy+210 +r, bx+410+50,by1-3350,bx+500+50,by1+30-3350)==1)
                   || (check(cx,  cy+210+r , bx+560+50,by1-3350,  bx+620+50,by1+40-3350)==1)


                   )
                {
                     gameover_rr(score);
                }
                  delay(3);

            setcolor(RED);
            setfillstyle(2,RED);for(int p = 0;p<10;p++){
            obstacle(bx1 - 1800-p , by2 - 2500+p);
            obstacle(bx1 - 1850 -p, by2 - 2650+p);
            obstacle(bx1 - 1900 -p, by2 - 2800+p);
            obstacle(bx1 - 2000 -p, by2 - 2950+p);
            obstacle(bx1 - 2100 -p, by2 - 3100+p);}


                    if( GetAsyncKeyState(VK_LEFT))//a
                    {cx=cx-m;}

                     if(GetAsyncKeyState(VK_UP))//w
                    {cy=cy-m;}

                    if( GetAsyncKeyState(VK_DOWN))//s
                    {cy=cy+m;}

                    if( GetAsyncKeyState(VK_RIGHT))//d
                    {cx=cx+m;}

                   if(
                      //cx+r;
                      (check(cx+r,cy+210+r,bx1- 1800,by2- 2500,bx1+70- 1800,by2+50- 2500) ==1)
                   || (check(cx+r, cy+210+r, bx1+180- 1800,by2+30- 2500,bx1+220- 1800,by2+70- 2500)==1)
                   || (check(cx +r, cy+210+r, bx1+300- 1800,by2- 2500,bx1+350- 1800,by2+50- 2500)==1)
                   || (check(cx +r, cy+210+r, bx1+410- 1800,by2- 2500,bx1+500- 1800,by2+30- 2500)==1)
                   || (check(cx +r, cy+210+r , bx1+560- 1800,by2- 2500,bx1+620- 1800,by2+40- 2500)==1)
                   || (check(cx+r,cy+210+r,bx1- 1850 ,by2- 2650,bx1+70- 1850 ,by2+50- 2650) ==1)
                   || (check(cx+r, cy+210+r, bx1+180- 1850 ,by2+30- 2650,bx1+220- 1850 ,by2+70- 2650)==1)
                   || (check(cx +r, cy+210+r, bx1+300- 1850 ,by2- 2650,bx1+350- 1850 ,by2+50- 2650)==1)
                   || (check(cx +r, cy+210+r, bx1+410- 1850 ,by2- 2650,bx1+500- 1850 ,by2+30- 2650)==1)
                   || (check(cx +r, cy+210+r , bx1+560- 1850 ,by2- 2650,bx1+620- 1850 ,by2+40- 2650)==1)
                   || (check(cx+r,cy+210+r,bx1- 1900,by2- 2800,bx1+70- 1900,by2+50- 2800) ==1)
                   || (check(cx+r, cy+210+r, bx1+180- 1900,by2+30- 2800,bx1+220- 1900,by2+70- 2800)==1)
                   || (check(cx +r, cy+210+r, bx1+300- 1900,by2- 2800,bx1+350- 1900,by2+50- 2800)==1)
                   || (check(cx +r, cy+210+r, bx1+410- 1900,by2- 2800,bx1+500- 1900,by2+30- 2800)==1)
                   || (check(cx +r, cy+210+r , bx1+560- 1900,by2- 2800,bx1+620- 1900,by2+40- 2800)==1)
                   || (check(cx+r,cy+210+r,bx1- 2000,by2- 2950,bx1+70- 2000,by2+50- 2950) ==1)
                   || (check(cx+r, cy+210+r, bx1+180- 2000,by2+30- 2950,bx1+220- 2000,by2+70- 2950)==1)
                   || (check(cx +r, cy+210+r, bx1+300- 2000,by2- 2950,bx1+350- 2000,by2+50- 2950)==1)
                   || (check(cx +r, cy+210+r, bx1+410- 2000,by2- 2950,bx1+500- 2000,by2+30- 2950)==1)
                   || (check(cx +r, cy+210+r , bx1+560- 2000,by2- 2950,bx1+620- 2000,by2+40- 2950)==1)
                    ||  (check(cx+r,cy+210+r,bx1- 2100 ,by2- 3100,bx1+70- 2100 ,by2+50- 3100) ==1)
                   || (check(cx+r, cy+210+r, bx1+180- 2100 ,by2+30- 3100,bx1+220- 2100 ,by2+70- 3100)==1)
                   || (check(cx +r, cy+210+r, bx1+300- 2100 ,by2- 3100,bx1+350- 2100 ,by2+50- 3100)==1)
                   || (check(cx +r, cy+210+r, bx1+410- 2100 ,by2- 3100,bx1+500- 2100 ,by2+30- 3100)==1)
                   || (check(cx +r, cy+210+r , bx1+560- 2100 ,by2- 3100,bx1+620- 2100 ,by2+40- 3100)==1)||

                    //cx-r
                      (check(cx-r,cy+210,bx1- 1800,by2- 2500,bx1+70- 1800,by2+50- 2500) ==1)
                   || (check(cx-r, cy+210, bx1+180- 1800,by2+30- 2500,bx1+220- 1800,by2+70- 2500)==1)
                   || (check(cx -r, cy+210, bx1+300- 1800,by2- 2500,bx1+350- 1800,by2+50- 2500)==1)
                   || (check(cx -r, cy+210, bx1+410- 1800,by2- 2500,bx1+500- 1800,by2+30- 2500)==1)
                   || (check(cx -r, cy+210 , bx1+560- 1800,by2- 2500,bx1+620- 1800,by2+40- 2500)==1)
                   || (check(cx-r,cy+210,bx1- 1850 ,by2- 2650,bx1+70- 1850 ,by2+50- 2650) ==1)
                   || (check(cx-r, cy+210, bx1+180- 1850 ,by2+30- 2650,bx1+220- 1850 ,by2+70- 2650)==1)
                   || (check(cx -r, cy+210, bx1+300- 1850 ,by2- 2650,bx1+350- 1850 ,by2+50- 2650)==1)
                   || (check(cx -r, cy+210, bx1+410- 1850 ,by2- 2650,bx1+500- 1850 ,by2+30- 2650)==1)
                   || (check(cx -r, cy+210 , bx1+560- 1850 ,by2- 2650,bx1+620- 1850 ,by2+40- 2650)==1)
                   || (check(cx-r,cy+210,bx1- 1900,by2- 2800,bx1+70- 1900,by2+50- 2800) ==1)
                   || (check(cx-r, cy+210, bx1+180- 1900,by2+30- 2800,bx1+220- 1900,by2+70- 2800)==1)
                   || (check(cx -r, cy+210, bx1+300- 1900,by2- 2800,bx1+350- 1900,by2+50- 2800)==1)
                   || (check(cx -r, cy+210, bx1+410- 1900,by2- 2800,bx1+500- 1900,by2+30- 2800)==1)
                   || (check(cx -r, cy+210 , bx1+560- 1900,by2- 2800,bx1+620- 1900,by2+40- 2800)==1)
                   || (check(cx-r,cy+210,bx1- 2000,by2- 2950,bx1+70- 2000,by2+50- 2950) ==1)
                   || (check(cx-r, cy+210, bx1+180- 2000,by2+30- 2950,bx1+220- 2000,by2+70- 2950)==1)
                   || (check(cx -r, cy+210, bx1+300- 2000,by2- 2950,bx1+350- 2000,by2+50- 2950)==1)
                   || (check(cx -r, cy+210, bx1+410- 2000,by2- 2950,bx1+500- 2000,by2+30- 2950)==1)
                   || (check(cx -r, cy+210 , bx1+560- 2000,by2- 2950,bx1+620- 2000,by2+40- 2950)==1)
                    ||  (check(cx-r,cy+210,bx1- 2100 ,by2- 3100,bx1+70- 2100 ,by2+50- 3100) ==1)
                   || (check(cx-r, cy+210, bx1+180- 2100 ,by2+30- 3100,bx1+220- 2100 ,by2+70- 3100)==1)
                   || (check(cx -r, cy+210, bx1+300- 2100 ,by2- 3100,bx1+350- 2100 ,by2+50- 3100)==1)
                   || (check(cx -r, cy+210, bx1+410- 2100 ,by2- 3100,bx1+500- 2100 ,by2+30- 3100)==1)
                   || (check(cx -r, cy+210 , bx1+560- 2100 ,by2- 3100,bx1+620- 2100 ,by2+40- 3100)==1)||
                   //cy+r
                    (check(cx,cy+210+r,bx1- 1800,by2- 2500,bx1+70- 1800,by2+50- 2500) ==1)
                   || (check(cx, cy+210+r, bx1+180- 1800,by2+30- 2500,bx1+220- 1800,by2+70- 2500)==1)
                   || (check(cx , cy+210+r, bx1+300- 1800,by2- 2500,bx1+350- 1800,by2+50- 2500)==1)
                   || (check(cx , cy+210+r, bx1+410- 1800,by2- 2500,bx1+500- 1800,by2+30- 2500)==1)
                   || (check(cx , cy+210+r , bx1+560- 1800,by2- 2500,bx1+620- 1800,by2+40- 2500)==1)
                   || (check(cx,cy+210+r,bx1- 1850 ,by2- 2650,bx1+70- 1850 ,by2+50- 2650) ==1)
                   || (check(cx, cy+210+r, bx1+180- 1850 ,by2+30- 2650,bx1+220- 1850 ,by2+70- 2650)==1)
                   || (check(cx , cy+210+r, bx1+300- 1850 ,by2- 2650,bx1+350- 1850 ,by2+50- 2650)==1)
                   || (check(cx , cy+210+r, bx1+410- 1850 ,by2- 2650,bx1+500- 1850 ,by2+30- 2650)==1)
                   || (check(cx , cy+210+r , bx1+560- 1850 ,by2- 2650,bx1+620- 1850 ,by2+40- 2650)==1)
                   || (check(cx,cy+210+r,bx1- 1900,by2- 2800,bx1+70- 1900,by2+50- 2800) ==1)
                   || (check(cx, cy+210+r, bx1+180- 1900,by2+30- 2800,bx1+220- 1900,by2+70- 2800)==1)
                   || (check(cx , cy+210+r, bx1+300- 1900,by2- 2800,bx1+350- 1900,by2+50- 2800)==1)
                   || (check(cx , cy+210+r, bx1+410- 1900,by2- 2800,bx1+500- 1900,by2+30- 2800)==1)
                   || (check(cx , cy+210+r , bx1+560- 1900,by2- 2800,bx1+620- 1900,by2+40- 2800)==1)
                   || (check(cx,cy+210+r,bx1- 2000,by2- 2950,bx1+70- 2000,by2+50- 2950) ==1)
                   || (check(cx, cy+210+r, bx1+180- 2000,by2+30- 2950,bx1+220- 2000,by2+70- 2950)==1)
                   || (check(cx , cy+210+r, bx1+300- 2000,by2- 2950,bx1+350- 2000,by2+50- 2950)==1)
                   || (check(cx , cy+210+r, bx1+410- 2000,by2- 2950,bx1+500- 2000,by2+30- 2950)==1)
                   || (check(cx , cy+210+r , bx1+560- 2000,by2- 2950,bx1+620- 2000,by2+40- 2950)==1)
                    ||  (check(cx,cy+210+r,bx1- 2100 ,by2- 3100,bx1+70- 2100 ,by2+50- 3100) ==1)
                   || (check(cx, cy+210+r, bx1+180- 2100 ,by2+30- 3100,bx1+220- 2100 ,by2+70- 3100)==1)
                   || (check(cx , cy+210+r, bx1+300- 2100 ,by2- 3100,bx1+350- 2100 ,by2+50- 3100)==1)
                   || (check(cx , cy+210+r, bx1+410- 2100 ,by2- 3100,bx1+500- 2100 ,by2+30- 3100)==1)
                   || (check(cx , cy+210+r , bx1+560- 2100 ,by2- 3100,bx1+620- 2100 ,by2+40- 3100)==1)
                      )
                   {
                        gameover_rr(score);
                   }
               delay(10);
               bx1 = bx1+2;
               by2+=3;


                setcolor(GREEN);
                setfillstyle(3,GREEN);
                obstacle(bx2 +800 , by3 - 4000);
                obstacle(bx2 +950 , by3 - 5500);
                obstacle(bx2 +1400 , by3 - 6000);
                obstacle(bx2 +1650 , by3 - 6200);
                obstacle(bx2 +1700 , by3 - 6450);


                    if(GetAsyncKeyState(VK_LEFT))//a
                    {cx=cx-m;}

                     if(GetAsyncKeyState(VK_UP))//w
                    {cy=cy-m;}

                     if( GetAsyncKeyState(VK_DOWN))//s
                    {cy=cy+m;}

                     if( GetAsyncKeyState(VK_RIGHT))//d
                    {cx=cx+m;}

                    if(
                       //cx+r
                       (check(cx+r,cy+210,bx2+800,by3- 4000,bx2+70+800,by3+50- 4000) ==1)
                   || (check(cx+r, cy+210, bx2+180+800,by3+30- 4000,bx2+220+800,by3+70- 4000)==1)
                   || (check(cx +r, cy+210, bx2+300+800,by3- 4000,bx2+350+800,by3+50- 4000)==1)
                   || (check(cx +r, cy+210, bx2+410+800,by3- 4000,bx2+500+800,by3+30- 4000)==1)
                   || (check(cx +r, cy+210 , bx2+560+800,by3- 4000,bx2+620+800,by3+40- 4000)==1)

                     ||  (check(cx+r ,cy+210,bx2+950,by3- 5500,bx2+70+950,by3+50- 5500) ==1)
                    || (check(cx+r , cy+210 , bx2+180+950,by3+30- 5500,bx2+220+950,by3+70- 5500)==1)
                    || (check(cx +r, cy+210, bx2+300+950,by3- 5500,bx2+350+950,by3+50- 5500)==1)
                    || (check(cx +r, cy+210, bx2+410+950,by3- 5500,bx2+500+950,by3+30- 5500)==1)
                    || (check(cx +r, cy+210 , bx2+560+950,by3- 5500,bx2+620+950,by3+40- 5500)==1)

                        ||  (check(cx+r ,cy+210,bx2+1400,by3- 6000,bx2+70+1400,by3+50- 6000) ==1)
                    || (check(cx+r, cy+210 , bx2+180+1400,by3+30- 6000,bx2+220+1400,by3+70- 6000)==1)
                    || (check(cx +r, cy+210  , bx2+300+1400,by3- 6000,bx2+350+1400,by3+50- 6000)==1)
                    || (check(cx +r, cy+210, bx2+410+1400,by3- 6000,bx2+500+1400,by3+30- 6000)==1)
                    || (check(cx +r, cy+210 , bx2+560+1400,by3- 6000,bx2+620+1400,by3+40- 6000)==1)

                        ||  (check(cx+r ,cy+210,bx2+1650,by3- 6200,bx2+70+1650,by3+50- 6200) ==1)
                    || (check(cx+r , cy+210, bx2+180+1650,by3+30- 6200,bx2+220+1650,by3+70- 6200)==1)
                    || (check(cx +r, cy+210 , bx2+300+1650,by3- 6200,bx2+350+1650,by3+50- 6200)==1)
                    || (check(cx +r, cy+210 , bx2+410+1650,by3- 6200,bx2+500+1650,by3+30- 6200)==1)
                    || (check(cx +r, cy+210, bx2+560+1650,by3- 6200,bx2+620+1650,by3+40- 6200)==1)

                        ||  (check(cx+r ,cy+210,bx2+1700,by3- 6450,bx2+70+1700,by3+50- 6450) ==1)
                    || (check(cx+r , cy+210 , bx2+180+1700,by3+30- 6450,bx2+220+1700,by3+70- 6450)==1)
                    || (check(cx +r, cy+210 , bx2+300+1700,by3- 6450,bx2+350+1700,by3+50- 6450)==1)
                    || (check(cx +r, cy+210 , bx2+410+1700,by3- 6450,bx2+500+1700,by3+30- 6450)==1)
                    || (check(cx +r, cy+210, bx2+560+1700,by3- 6450,bx2+620+1700,by3+40- 6450)==1)||
                       //cx-r
                       (check(cx-r,cy+210,bx2+800,by3- 4000,bx2+70+800,by3+50- 4000) ==1)
                   || (check(cx-r, cy+210, bx2+180+800,by3+30- 4000,bx2+220+800,by3+70- 4000)==1)
                   || (check(cx -r, cy+210, bx2+300+800,by3- 4000,bx2+350+800,by3+50- 4000)==1)
                   || (check(cx -r, cy+210, bx2+410+800,by3- 4000,bx2+500+800,by3+30- 4000)==1)
                   || (check(cx -r, cy+210 , bx2+560+800,by3- 4000,bx2+620+800,by3+40- 4000)==1)

                     ||  (check(cx-r ,cy+210,bx2+950,by3- 5500,bx2+70+950,by3+50- 5500) ==1)
                    || (check(cx-r , cy+210, bx2+180+950,by3+30- 5500,bx2+220+950,by3+70- 5500)==1)
                    || (check(cx -r, cy+210 , bx2+300+950,by3- 5500,bx2+350+950,by3+50- 5500)==1)
                    || (check(cx -r, cy+210, bx2+410+950,by3- 5500,bx2+500+950,by3+30- 5500)==1)
                    || (check(cx -r, cy+210, bx2+560+950,by3- 5500,bx2+620+950,by3+40- 5500)==1)

                        ||  (check(cx-r ,cy+210,bx2+1400,by3- 6000,bx2+70+1400,by3+50- 6000) ==1)
                    || (check(cx-r, cy+210, bx2+180+1400,by3+30- 6000,bx2+220+1400,by3+70- 6000)==1)
                    || (check(cx -r, cy+210 , bx2+300+1400,by3- 6000,bx2+350+1400,by3+50- 6000)==1)
                    || (check(cx -r, cy+210 , bx2+410+1400,by3- 6000,bx2+500+1400,by3+30- 6000)==1)
                    || (check(cx -r, cy+210 , bx2+560+1400,by3- 6000,bx2+620+1400,by3+40- 6000)==1)

                        ||  (check(cx-r ,cy+210,bx2+1650,by3- 6200,bx2+70+1650,by3+50- 6200) ==1)
                    || (check(cx-r , cy+210, bx2+180+1650,by3+30- 6200,bx2+220+1650,by3+70- 6200)==1)
                    || (check(cx -r, cy+210  , bx2+300+1650,by3- 6200,bx2+350+1650,by3+50- 6200)==1)
                    || (check(cx -r, cy+210 , bx2+410+1650,by3- 6200,bx2+500+1650,by3+30- 6200)==1)
                    || (check(cx -r, cy+210 , bx2+560+1650,by3- 6200,bx2+620+1650,by3+40- 6200)==1)

                        ||  (check(cx-r ,cy+210,bx2+1700,by3- 6450,bx2+70+1700,by3+50- 6450) ==1)
                    || (check(cx-r , cy+210 , bx2+180+1700,by3+30- 6450,bx2+220+1700,by3+70- 6450)==1)
                    || (check(cx -r, cy+210 , bx2+300+1700,by3- 6450,bx2+350+1700,by3+50- 6450)==1)
                    || (check(cx -r, cy+210 , bx2+410+1700,by3- 6450,bx2+500+1700,by3+30- 6450)==1)
                    || (check(cx -r, cy+210, bx2+560+1700,by3- 6450,bx2+620+1700,by3+40- 6450)==1)||

                       //cy+r
                       (check(cx,cy+210+r,bx2+800,by3- 4000,bx2+70+800,by3+50- 4000) ==1)
                   || (check(cx, cy+210+r, bx2+180+800,by3+30- 4000,bx2+220+800,by3+70- 4000)==1)
                   || (check(cx , cy+210+r, bx2+300+800,by3- 4000,bx2+350+800,by3+50- 4000)==1)
                   || (check(cx , cy+210+r, bx2+410+800,by3- 4000,bx2+500+800,by3+30- 4000)==1)
                   || (check(cx , cy+210+r , bx2+560+800,by3- 4000,bx2+620+800,by3+40- 4000)==1)

                     ||  (check(cx ,cy+210+r,bx2+950,by3- 5500,bx2+70+950,by3+50- 5500) ==1)
                    || (check(cx , cy+210+r , bx2+180+950,by3+30- 5500,bx2+220+950,by3+70- 5500)==1)
                    || (check(cx , cy+210 +r, bx2+300+950,by3- 5500,bx2+350+950,by3+50- 5500)==1)
                    || (check(cx , cy+210+r, bx2+410+950,by3- 5500,bx2+500+950,by3+30- 5500)==1)
                    || (check(cx , cy+210+r , bx2+560+950,by3- 5500,bx2+620+950,by3+40- 5500)==1)

                        ||  (check(cx ,cy+210+r,bx2+1400,by3- 6000,bx2+70+1400,by3+50- 6000) ==1)
                    || (check(cx, cy+210+r , bx2+180+1400,by3+30- 6000,bx2+220+1400,by3+70- 6000)==1)
                    || (check(cx , cy+210 +r, bx2+300+1400,by3- 6000,bx2+350+1400,by3+50- 6000)==1)
                    || (check(cx , cy+210 +r, bx2+410+1400,by3- 6000,bx2+500+1400,by3+30- 6000)==1)
                    || (check(cx , cy+210+r , bx2+560+1400,by3- 6000,bx2+620+1400,by3+40- 6000)==1)

                        ||  (check(cx ,cy+210+r,bx2+1650,by3- 6200,bx2+70+1650,by3+50- 6200) ==1)
                    || (check(cx, cy+210+r, bx2+180+1650,by3+30- 6200,bx2+220+1650,by3+70- 6200)==1)
                    || (check(cx , cy+210  +r, bx2+300+1650,by3- 6200,bx2+350+1650,by3+50- 6200)==1)
                    || (check(cx , cy+210 +r, bx2+410+1650,by3- 6200,bx2+500+1650,by3+30- 6200)==1)
                    || (check(cx , cy+210+r , bx2+560+1650,by3- 6200,bx2+620+1650,by3+40- 6200)==1)

                        ||  (check(cx,cy+210+r,bx2+1700,by3- 6450,bx2+70+1700,by3+50- 6450) ==1)
                    || (check(cx, cy+210+r , bx2+180+1700,by3+30- 6450,bx2+220+1700,by3+70- 6450)==1)
                    || (check(cx , cy+210 +r, bx2+300+1700,by3- 6450,bx2+350+1700,by3+50- 6450)==1)
                    || (check(cx , cy+210 +r, bx2+410+1700,by3- 6450,bx2+500+1700,by3+30- 6450)==1)
                    || (check(cx , cy+210+r , bx2+560+1700,by3- 6450,bx2+620+1700,by3+40- 6450)==1)


                        )

                     {
                        gameover_rr(score);
                     }

                delay(10);
                bx2=bx2-2;
                by3+=5;
            page = 1-page;
        }

}

