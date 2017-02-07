#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<math.h>
#include "shoot.h"
#include "game_rr.h"
#include "bounce.h"
#include "game_rhero.h"

using namespace std;
/*struct bullet
{
 int mid,bx,bx1,index;
 struct bullet *next;
}*start=NULL,*end,*temp,*temp1,b[100],*bul[100];*/

int main()
{
       int ch,gdriver=DETECT,gmode;
        initgraph(&gdriver, &gmode, "");
        int pg=0,i=0,m=5,n=5,j,k=0,l=-5,p=0;
        char a[10];
        POINT cursposition;
        int mx,my;
        PlaySound("Game_of_Thrones.wav", NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
        while(1)
        {
            /*swapbuffers();
            pg=1-pg;*/
            cleardevice();
            settextstyle(1,HORIZ_DIR,4);
            setcolor(WHITE);
            outtextxy(70,80,"GAME OF HURDLES");
            setcolor(RED);
            for(j=0;j<20;j++)circle(600,30+k,20-j);
            k=k+n;
            if(k>440)
                {
                    l=5;
                    n=-5;
                }
            else if(k==25)
                {
                    l=-5;
                    n=5;
                }
            drawchar(560-i,440,560-i,450,560-i,430,4,1);
            i=i+m;
            if(i==560)
                m=-5 ;
            else if(i==0)
                m=5;
                setcolor(CYAN);
                setfillstyle(4,CYAN);
            for(j=0;j<10;j++)bar(20+j,460-j+p,50+j,510-j+p);
            p=p+l;
            //line(70,120,560,120);
            setcolor(YELLOW);
            rectangle(70,150,550,400);
            settextstyle(4,HORIZ_DIR,1);
            outtextxy(220,180,"NEW GAME");
            outtextxy(220,220,"LEVEL  1");
            outtextxy(220,260,"LEVEL  2");
            outtextxy(220,300,"LEVEL  3");
            outtextxy(220,340,"LEVEL  4");

            GetCursorPos(&cursposition);
            mx=cursposition.x;
            my=cursposition.y;

            if(GetAsyncKeyState(VK_LBUTTON)&&mx>180&&mx<400&&my>180&&my<220)
            {
                break;
            }

            else if(GetAsyncKeyState(VK_LBUTTON)&&mx>180&&mx<400&&my>220&&my<260)
            {
                game_rr();
                break;
            }

            else if(GetAsyncKeyState(VK_LBUTTON)&&mx>180&&mx<400&&my>260&&my<300)
             {
                 blank();
                shoot();
                break;
            }


           else if(GetAsyncKeyState(VK_LBUTTON)&&mx>180&&mx<400&&my>300&&my<340)
             {
                bounce();
                break;
            }


            else if(GetAsyncKeyState(VK_LBUTTON)&&mx>180&&mx<400&&my>340&&my<380)
             {
                game_rhero();
                break;
            }


            delay(100);
        }
        int t=10;
        game_rhero();
        game_rr();
        blank();
        shoot();
        bounce();


    return 0;
}
