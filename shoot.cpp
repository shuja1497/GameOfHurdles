#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<math.h>
#include<iostream>

using namespace std;

int gameover_shoot();
void drawchar();
int all_one(int []);
void drawchar(int ,int ,int ,int ,int ,int ,int ,int);
void copy(int [] , int [],int);
void draw_arrow(int,int,int,int,int,int);
void create();
int check (int ,int ,int ,int,int,int,int,int);
void blank();
void shoot();
struct bullet
{
 int mid,bx,bx1,index;
 struct bullet *next;
}*start=NULL,*end,*temp,*temp1,b[100],*bul[100];

int bt[100];


void blank()
{
       cleardevice();
       /*setcolor(BLACK);
        delay(100);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
        outtextxy(40,200,"KILL THE WHITE WALKER's");*/
}
void shoot()
{
     char scr[30];
    int t=10,i=0,x=0,y1=150,y=250,x1,e;
    int mid ,s=0, bx=20,bx1=40,j,w=0;
    int m=5,tm=0,bul_count=0;
    int score=0;
    //obstacles;
    int cpy_cx[7],cpy_lx1[7],cpy_ly1[7],cpy_ly2[7],cpy_cy[7];
    int cx[7]={640,810,1040,740,880,940,990};
    int lx1[7]={640,810,1040,740,880,940,990};
    int cy[7]={100,200,150,410,300,350,390};
    int ly1[7]={110,210,160,420,310,360,400};
    int ly2[7]={120,220,170,430,320,370,410};
    int wc[7]={0,0,0,0,0,0,0};
    int wt=0;
    int draw[100],dc[7],dc_copy[7];
    copy(cpy_cx,cx,7);
    copy(cpy_lx1,lx1,7);
    copy(cpy_ly1,ly1,7);
    copy(cpy_ly2,ly2,7);
     copy(cpy_cy,cy,7);

    //checking
     int ta,tb,tc,td,te,tf;
    int ac[100],cc[100];
    int ap=0, vp=1;
    bullet b[100];

    int xy[7][100];
    for(i=0;i<100;i++)
    {
        if(i<7)
        {
            dc[i]=1;
        }
        draw[i]=1;
        bt[i]=0;
    }
    copy(dc_copy,dc,7);
    for(i=0;i<50;i++)
    create();
    temp=start;
    while(1)
    {
        swapbuffers();
        cleardevice();
        ap=1-ap;
        setcolor(CYAN);setfillstyle(1,CYAN);
        bar(0,0,700,45);
        setcolor(GREEN);setfillstyle(1,GREEN);
        bar(0,440,700,485);
        setcolor(RED);
         settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
        sprintf(scr,"SCORE: %d",score);
        outtextxy(380,20,scr);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
        outtextxy(40,450,"KILL THE WHITE WALKER's");
        /*for(i=0;i<45;i++)line(0,0+i, 700,0+i);
        for(i=0;i<45;i++)line(0,440+i,700,440+i);*/


        for(i=0;i<20;i++)
        {
            setcolor(BLUE);
            line(x+i,y1, x+i,y);
        }
        setcolor(RED);
        for(i=0;i<10;i++)circle(10,(y+y1)/2,i);
         if(GetAsyncKeyState(VK_UP))
        {
             y=y-t;
             y1=y1-t;
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
             y=y+t;
             y1=y1+t;
        }
        else if(GetAsyncKeyState(VK_SPACE))
        {
          temp->bx=20;
          temp->bx1=40;
          temp->index=s;
          temp->mid=(y+y1)/2;
          s++;
          temp=temp->next;
          bul_count=s;
        /*  bul[s]=temp;

           bul[s]->bx=20;
           bul[s]->bx1=40;
           bul[s]->mid = (y+y1)/2;
                      s++;*/

            goto A;
        }
        else if(GetAsyncKeyState(VK_ESCAPE))
            break;
        A:
            temp1=start;
            while(temp1!=NULL)
            {
             if(temp1!=NULL)
             {
                if(temp1->bx1<700)
                {
                   setcolor(YELLOW);
                draw_arrow(temp1->bx,temp1->mid,temp1->bx1,temp1->mid,draw[i],i);
                temp1->bx=temp1->bx+10;
                temp1->bx1=temp1->bx1+10;
                setcolor(BLACK);
                }
             }
            temp1=temp1->next;


            }

             /*setcolor(GREEN);
            for(i=0;i<5;i++)circle(cx[5],cy[5],10-i);
            for(i=0;i<3;i++)line(lx1[5]+i,ly1[5],lx1[5]+i,ly2[5]);*/

            drawchar(lx1[0],ly1[0],lx1[0],ly2[0],cx[0],cy[0],1,dc[0]);
            drawchar(lx1[1],ly1[1],lx1[1],ly2[1],cx[1],cy[1],2,dc[1]);
             drawchar(lx1[2],ly1[2],lx1[2],ly2[2],cx[2],cy[2],3,dc[2]);
             drawchar(lx1[3],ly1[3],lx1[3],ly2[3],cx[3],cy[3],4,dc[3]);
             drawchar(lx1[4],ly1[4],lx1[4],ly2[4],cx[4],cy[4],5,dc[4]);
              drawchar(lx1[5],ly1[5],lx1[5],ly2[5],cx[5],cy[5],1,dc[5]);
              drawchar(lx1[6],ly1[6],lx1[6],ly2[6],cx[6],cy[6],2,dc[6]);

            for(i=0;i<7;i++)
            {
                if(dc[i]==1)
                {lx1[i]=lx1[i]-m;
                cx[i]=cx[i]-m;}
                if(lx1[i]<0)
                {
                    lx1[i]=cpy_lx1[i];
                    cx[i]=cpy_cx[i];
                }
            }
            if(start!=NULL)
            {
                if(start->bx1+18>cx[j]&&start->bx1+8<cx[j]&&start->mid>cy[j]-10&&start->mid<ly2[j]+7)
                    start=start->next;
            }
            temp1=start;
            if(start==NULL)
                goto z;
            while(temp1->next!=NULL)
            {
                for(j=0;j<7;j++)
                {
                    if(temp1->next->bx1+18>cx[j]&&temp1->next->bx1+8<cx[j]&&temp1->next->mid>cy[j]-10&&temp1->next->mid<ly2[j]+7)
                    {
                                setcolor(YELLOW);
                                outtextxy(temp1->next->bx1-10,temp1->next->mid,"+ 50 ");
                                score=score+50;
                                //arrow
                                temp1->next=temp1->next->next;
                                //char
                                lx1[j]=cpy_lx1[j];
                                ly1[j]=cpy_ly1[j];
                                ly2[j]=cpy_ly2[j];
                                cx[j]=cpy_cx[j];
                                cy[j]=cpy_cy[j];
                                /*dc[j]=0;*/

                                cout<<score<<endl<<endl;
                    }
                }
                temp1=temp1->next;
            }
            z:
            for(j=0;j<7;j++)
            {
                if(cx[j]<20&&cx[j]>0)
                {

                    if(y1<ly2[j]+7&&y1>cy[j]-10){return;
                        gameover_shoot();}
                    if(y>cy[j]-10&&y<ly2[j]+7){return;
                        gameover_shoot();}
                    if(y1<cy[j]-10&&y>ly2[j]+7){return;
                        gameover_shoot();}
                }
            }

           /* if(tm==255)
            {
                copy(cx,cpy_cx,7);
                copy(lx1,cpy_lx1,7);
                copy(dc,dc_copy,7);
                m=m+3;
                tm=0;
            }*/
        tm++;
        setcolor(MAGENTA);
        score++;
        delay(100);
          }
    C:
        return ;
}
int all_one(int a[])
{
    int i;
    for(i=0;i<7;i++)
    {
        if(a[i]==1)
            return i;
    }
        return -1;
}
int  gameover_shoot()
{
    while(1)
    {
        swapbuffers();
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
        outtextxy(180,220," GAME OVER ");
        if(GetAsyncKeyState(VK_ESCAPE))
        return 1;
    }
}
void drawchar(int x1,int y1,int x2,int y2,int cx,int cy,int c,int d)
{
    if(d==1)
    {

        int i;
        switch(c)
        {
        case 1:
            setcolor(LIGHTGRAY);
            break;
        case 2:
            setcolor(GREEN);
            break;
        case 3:
            setcolor(LIGHTBLUE);
            break;
        case 4:
            setcolor(MAGENTA);
            break;
        case 5:
            setcolor(CYAN);
            break;
        }
        for(i=0;i<2;i++)circle(cx,cy,10-i);
        for(i=0;i<2;i++)circle((cx+3),(cy-3),2-i);
        for(i=0;i<2;i++)circle((cx-3),(cy-3),2-i);
        for(i=0;i<3;i++)line(x1+i,y1,x2+i,y2);
        int x3=x1-7;
        int x4=x1+7;
        int y3=y2+7;
        rectangle(cx-2,cy+1,cx,cy+3);
        rectangle(cx,cy+1,cx+2,cy+3);
        for(i=0;i<3;i++)line(x1,y1+5,x4+i,y1+2);
        for(i=0;i<3;i++)line(x1,y1+5,x3-i,y1+2);
        for(i=0;i<3;i++)line(x1,y2-i,x3+i,y3);
        for(i=0;i<3;i++)line(x1,y2-i,x4+i,y3);
    }
}

void draw_arrow(int x1,int y1,int x2,int y2,int draw,int i)
{
    if(x1==NULL)
        return;
    int j;
    int p[8]={x2,y2-3,x2+5,y2,x2,y2+3,x2,y2-3};
    if(draw==0&&bt[i]==0)
    {
        bt[i]=1;
        outtextxy(x2,y2,"+ 50 ");
        return ;
    }   setcolor(YELLOW);
    if(bt[i]==1)
        return;
    for(j=0;j<15 ;j++)line(x1,y1,x2,y2);
    for(j=0;j<15 ;j++)line(x1,y1,x1-3,y1-3);
    for(j=0;j<15 ;j++)line(x1,y1,x1-3,y1+3);
    for(j=0;j<15 ;j++)line(x1+4,y1,x1+1,y1-3);
    for(j=0;j<15 ;j++)line(x1+4,y1,x1+1,y1+3);
    drawpoly(4,p);
    setcolor(RED);
    for(j=0;j<3;j++)circle(x2+6,y2,2-j);
    a:
       return ;
}
void create()
{
          temp=(struct bullet *)malloc(sizeof(struct bullet));
          temp->bx=0;
          temp->bx1=0;
          temp->index=0;
          temp->next=NULL;
          temp->mid=-10;

            if(start==NULL)
          {
              start=temp;
              end=temp;
          }
          else
          {
              end->next=temp;
              end=temp;
          }
}
int check(int lx1,int ly1,int rx1,int ry1,int lx2,int ly2,int rx2,int ry2 )
{
    if (lx1 > rx2 || lx2 > rx1)
        return 0;
    if (ly1 < ry2 || ly2 < ry1)
        return 0;
    return 1;
}
void copy(int a[],int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}
