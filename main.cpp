#include <bits/stdc++.h>
#include<graphics.h>
using namespace std;
typedef long long int ll;
#define fi first
#define sc second

ll i,j,x,y,end_row,end_colum,cng,l,fl,Delay_Time=20,res=-1,Gameover=0;
ll mxcx=625,mxcy=415,mncy,mncx,stx,sty,tx=1,control=2,lix=615,liy=405,obx=190,oby=30;

map<pair<ll,ll>,ll>mp;
vector<pair<ll,ll>>lt;
vector<pair<pair<ll,ll>,pair<ll,ll>>>a=
{
    {{500,600},{390,420}},{{530,570},{170,390}},{{600,600},{360,80}},{{600,630},{360,360}},{{600,550},{130,230}}
    ,{{550,630},{50,50}},{{500,550},{100,50}},{{470,470},{20,300}},{{500,530},{250,170}},{{500,500},{250,170}}
    ,{{470,540},{280,300}},{{510,510},{20,50}},{{210,570},{330,330}},{{500,500},{360,390}},{{520,470},{130,130}}
    ,{{540,470},{360,360}},{{440,440},{330,390}},{{340,440},{360,360}},{{310,410},{390,390}},{{240,310},{360,420}}
    ,{{210,210},{390,210}},{{210,280},{390,390}},{{180,240},{180,270}},{{240,370},{300,300}},{{210,240},{80,240}}
    ,{{210,210},{80,150}},{{210,270},{50,200}},{{240,340},{230,230}},{{240,370},{270,270}},{{370,370},{120,270}}
    ,{{400,400},{210,330}},{{370,440},{180,300}},{{400,470},{150,150}},{{370,440},{120,120}},{{340,470},{90,90}}
    ,{{310,440},{50,50}},{{310,310},{50,160}},{{300,340},{200,120}}
};
void Disgameover();/*DONE*/
void Character();/*DONE*/
void Getlife();/*DONE*/
void Outline();/*DONE*/
void Ball();/*DONE*/
void Display();
void Obstacle();

void Obstacle()
{
    int t1,t2,rr=8;
    if(mxcx>=obx&&obx>=mncx&&mxcy>=oby&&oby>=mncy)
    {
        control--;
        Display();
        t1=obx;
        t2=oby;
        setcolor(BLACK);
        circle(t1,t2,rr);
        circle(t1,t2,rr-2);
        circle(t1,t2,rr-4);
        circle(t1,t2,rr-6);
        while(true)
        {
            int tr=1;
            t1=rand()%(630-180)+180;
            t2=rand()%(420-20)+20;
            for(l=t1-rr; l<=t1+rr; l++)
                if(mp[ {l,t2}]>0)
                {
                    tr=0;
                    break;
                }
            for(l=t2-rr; l<=t2+rr; l++)
                if(mp[ {t1,l}]>0)
                {
                    tr=0;
                    break;
                }
            if(tr&&stx!=t1&&sty!=t2&&lix!=obx&&liy!=oby)
            {
                obx=t1;
                oby=t2;
                break;
            }
        }
        t1=obx;
        t2=oby;
        setcolor(LIGHTMAGENTA);
        circle(t1,t2,rr);
        circle(t1,t2,rr-2);
        circle(t1,t2,rr-4);
        circle(t1,t2,rr-6);
    }
}



// Main function ---------------------------------------------------------------------------------------------------------------
int main()
{
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
    for(i=20; i<=140; i+=30)
        lt.push_back({i,40});
    {
        Display();
        Outline();
        Ball();
        Getlife();
        Obstacle();
        Character();
    }

    getch();
    return 0;
}
// End main() ------------------------------------------------------------------------------------------------------------------
// Display Start ---------------------------------------------------------------------------------------------------------------
void Display()
{
    {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,BLACK);
        rectangle(5,25,170,60);
        floodfill(6,25,GREEN);
        setcolor(BLACK);
        rectangle(5,25,170,60);
        if(control==0)
            Gameover=1;
        int r=8,t1,t2;
        setcolor(RED);
        for(int l=0; l<control; l++)
        {
            t1=lt[l].fi;
            t2=lt[l].sc;
            setfillstyle(SOLID_FILL,RED);
            circle(t1,t2,r);
            floodfill(t1,t2,RED);
            circle(t1+r+2,t2,r);
            floodfill(t1+r+2,t2,RED);
            circle(t1+r/2+1,t2+r/2+1,r);
            floodfill(t1,t2+r,RED);
        }
    }
    settextstyle(4,4,3);
    setcolor(LIGHTMAGENTA);
    outtextxy(120,25,"LIFE");

    settextstyle(4,4,2);
    setcolor(MAGENTA);
    outtextxy(140,115,"SCORE");

    string temp=to_string(res);
    char s[4]="000";
    l=2;
    for(int k=0; k<temp.size(); k++)
        s[l--]=temp[k];
    settextstyle(4,4,3);
    setcolor(LIGHTCYAN);
    outtextxy(110,155,s);
}
// Display end -----------------------------------------------------------------------------------------------------------------
// Character Start -------------------------------------------------------------------------------------------------------------
void Character()
{
    i=mxcx-10;
    j=mxcy-10;
    int r=10;
    cng=5;
    setcolor(YELLOW);
    if(tx)
    {
        circle(i,j,r);
        line(i-r,j-r,i+r,j+r);//(\)
        line(i-r,j+r,i+r,j-r);//(/)
        line(i,j+r,i,j-r);
        line(i+r,j,i-r,j);
        tx=0;
        mxcx=i+10;
        mncx=i-10;
        mxcy=j+10;
        mncy=j-10;
    }
    while(true)
    {
        if(Gameover)
        {
            Disgameover();
            return;
        }
        else
        {
            //Display();
            delay(Delay_Time);
            fl=1;
            int t=1;
            cng=5;
            while(t--)
            {
                if(GetAsyncKeyState(VK_UP))
                {
                    for(l=j; l>=(j-3*cng); l--)
                        if(mp[ {i,l}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=i; l>=(i-r); l--)
                        if(mp[ {l,j}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=i; l<=(i+r); l++)
                        if(mp[ {l,j}]>0)
                        {
                            fl=0;
                            break;
                        }
                    if(fl)
                    {
                        setcolor(BLACK);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);

                        j-=cng;
                        setcolor(YELLOW);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);
                    }
                    mxcx=i+10;
                    mncx=i-10;
                    mxcy=j+10;
                    mncy=j-10;
                    Ball();
                    Obstacle();
                    Getlife();
                }
                if(GetAsyncKeyState(VK_DOWN))
                {
                    for(l=j; l<=(j+3*cng); l++)
                        if(mp[ {i,l}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=i; l>=(i-r); l--)
                        if(mp[ {l,j}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=i; l<=(i+r); l++)
                        if(mp[ {l,j}]>0)
                        {
                            fl=0;
                            break;
                        }
                    if(fl)
                    {
                        setcolor(BLACK);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);

                        j+=cng;
                        setcolor(YELLOW);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);
                    }
                    mxcx=i+10;
                    mncx=i-10;
                    mxcy=j+10;
                    mncy=j-10;
                    Ball();
                    Obstacle();
                    Getlife();
                }
                if(GetAsyncKeyState(VK_RIGHT))
                {
                    for(l=i; l<=(i+3*cng); l++)
                        if(mp[ {l,j}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=j; l>=(j-r); l--)
                        if(mp[ {i,l}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=j; l<=(j+r); l++)
                        if(mp[ {i,l}]>0)
                        {
                            fl=0;
                            break;
                        }
                    if(fl)
                    {
                        setcolor(BLACK);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);

                        i+=cng;
                        setcolor(YELLOW);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);
                    }
                    mxcx=i+10;
                    mncx=i-10;
                    mxcy=j+10;
                    mncy=j-10;
                    Ball();
                    Obstacle();
                    Getlife();
                }
                if(GetAsyncKeyState(VK_LEFT))
                {
                    for(l=i; l>=(i-3*cng); l--)
                        if(mp[ {l,j}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=j; l>=(j-r); l--)
                        if(mp[ {i,l}]>0)
                        {
                            fl=0;
                            break;
                        }
                    for(l=j; l<=(j+r); l++)
                        if(mp[ {i,l}]>0)
                        {
                            fl=0;
                            break;
                        }
                    if(fl)
                    {
                        setcolor(BLACK);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);

                        i-=cng;
                        setcolor(YELLOW);
                        circle(i,j,r);
                        line(i-r,j-r,i+r,j+r);
                        line(i-r,j+r,i+r,j-r);
                        line(i,j+r,i,j-r);
                        line(i+r,j,i-r,j);
                    }
                    mxcx=i+10;
                    mncx=i-10;
                    mxcy=j+10;
                    mncy=j-10;
                    Ball();
                    Obstacle();
                    Getlife();
                }
            }
        }
    }
}
// Character end ---------------------------------------------------------------------------------------------------------------
//Getlife start ----------------------------------------------------------------------------------------------------------------
void Getlife()
{
    int rr=8,t1,t2;
    if(mxcx>=lix&&lix>=mncx&&mxcy>=liy&&liy>=mncy)
    {
        if(control<5)
            control++;
        Display();
        t1=lix;
        t2=liy;
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,BLACK);
        circle(t1,t2,rr);
        floodfill(t1,t2,GREEN);
        circle(t1+rr+2,t2,rr);
        floodfill(t1+rr+2,t2,GREEN);
        circle(t1+rr/2+1,t2+rr/2+1,rr);
        floodfill(t1,t2+rr,GREEN);
        setcolor(BLACK);
        circle(t1,t2,rr);
        circle(t1+rr+2,t2,rr);
        circle(t1+rr/2+1,t2+rr/2+1,rr);
        while(true)
        {
            int tr=1;
            t1=rand()%(630-180)+180;
            t2=rand()%(420-20)+20;
            for(l=t1-rr-5; l<=t1+rr+5; l++)
                if(mp[ {l,t2}]>0)
                {
                    tr=0;
                    break;
                }
            for(l=t2-rr-5; l<=t2+rr+5; l++)
                if(mp[ {t1,l}]>0)
                {
                    tr=0;
                    break;
                }
            if(tr&&stx!=t1&&sty!=t2)
            {
                lix=t1;
                liy=t2;
                break;
            }
        }
        t1=lix;
        t2=liy;
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(t1,t2,rr);
        floodfill(t1,t2,RED);
        circle(t1+rr+2,t2,rr);
        floodfill(t1+rr+2,t2,RED);
        circle(t1+rr/2+1,t2+rr/2+1,rr);
        floodfill(t1,t2+rr,RED);
    }
}
//Getlife End ------------------------------------------------------------------------------------------------------------------
//start Game-over --------------------------------------------------------------------------------------------------------------
void Disgameover()
{
    settextstyle(4,4,7);
    while(true)
    {
        i=rand()%16+1;
        setcolor(i);
        outtextxy(620,230,"GAME_OVER");
        delay(300);
        if(GetAsyncKeyState(VK_RETURN))
            return;
    }
}
//End Game-over ----------------------------------------------------------------------------------------------------------------
// Start Ball ------------------------------------------------------------------------------------------------------------------
void Ball()
{
    int r=10,t1,t2;
    if(mxcx>=stx&&stx>=mncx&&mxcy>=sty&&sty>=mncy)
    {
        res++;
        Display();
        t1=stx;
        t2=sty;
        setfillstyle(SOLID_FILL,BLACK);
        setcolor(RED);
        circle(t1,t2,r);
        floodfill(t1,t2,RED);
        setcolor(BLACK);
        circle(t1,t2,r);
        while(true)
        {
            int tr=1;
            t1=rand()%(630-180)+180;
            t2=rand()%(420-20)+20;
            for(l=t1-r; l<=t1+r; l++)
                if(mp[ {l,t2}]>0)
                {
                    tr=0;
                    break;
                }
            for(l=t2-r; l<=t2+r; l++)
                if(mp[ {t1,l}]>0)
                {
                    tr=0;
                    break;
                }
            if(tr)
            {
                stx=t1;
                sty=t2;
                break;
            }
        }
        t1=stx;
        t2=sty;
        setcolor(LIGHTCYAN);
        setfillstyle(XHATCH_FILL,LIGHTCYAN);
        circle(t1,t2,r);
        floodfill(t1,t2,LIGHTCYAN);
    }
}
//End Ball ---------------------------------------------------------------------------------------------------------------------
// Start Outline ---------------------------------------------------------------------------------------------------------------
void Outline()
{
    x=i=180;
    y=j=20;
    end_colum=y+400;
    end_row=x+450;
    setcolor(GREEN);
    for(; i<=end_row; i++)
    {
        line(i,j-1,i-1,j);
        mp[ {i,j-1}]++;
        mp[ {i-1,j}]++;
        mp[ {i-1,j+1}]++;
    }
    for(; j<=end_colum; j++)
    {
        line(i,j-1,i-1,j);
        mp[ {i,j-1}]++;
        mp[ {i-1,j}]++;
        mp[ {i,j}]++;
    }
    for(; i>=x; i--)
    {
        line(i,j-1,i-1,j);
        mp[ {i,j-1}]++;
        mp[ {i-1,j}]++;
        mp[ {i,j-1}]++;
    }
    for(; j>=y; j--)
    {
        line(i,j-1,i-1,j);
        mp[ {i,j-1}]++;
        mp[ {i-1,j}]++;
        mp[ {i+1,j}]++;
    }
    for(auto it:a)
    {
        x=it.fi.fi;
        y=it.sc.fi;
        end_row=it.fi.sc;
        end_colum=it.sc.sc;
        if(end_row<x)
            swap(x,end_row);
        i=x;
        j=y;
        for(; i<=end_row; i++)
        {
            line(i,j-1,i-1,j);
            mp[ {i+1,j-1}]++;
            mp[ {i,j-1}]++;
            mp[ {i-1,j-1}]++;
            mp[ {i+1,j}]++;
            mp[ {i,j}]++;
            mp[ {i-1,j}]++;
            mp[ {i+1,j+1}]++;
            mp[ {i,j+1}]++;
            mp[ {i-1,j+1}]++;
            mp[ {i-2,j-1}]++;
            mp[ {i-1,j-1}]++;
            mp[ {i,j-1}]++;
            mp[ {i-2,j}]++;
            mp[ {i-1,j}]++;
            mp[ {i,j}]++;
            mp[ {i-2,j+1}]++;
            mp[ {i-1,j+1}]++;
            mp[ {i,j+1}]++;
            if(i==end_row)
            {
                i++;
                mp[ {i+1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i+1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i+1,j+1}]++;
                mp[ {i,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i-2,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-2,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-2,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i,j+1}]++;
                i--;
            }
            if(i==x)
            {
                i--;
                mp[ {i+1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i+1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i+1,j+1}]++;
                mp[ {i,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i-2,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-2,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-2,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i,j+1}]++;
                i++;
            }
        }
        if(j>end_colum)
            swap(j,end_colum);
        for(; j<=end_colum; j++)
        {
            line(i,j-1,i-1,j);
            mp[ {i+1,j-1}]++;
            mp[ {i,j-1}]++;
            mp[ {i-1,j-1}]++;
            mp[ {i+1,j}]++;
            mp[ {i,j}]++;
            mp[ {i-1,j}]++;
            mp[ {i+1,j+1}]++;
            mp[ {i,j+1}]++;
            mp[ {i-1,j+1}]++;
            mp[ {i-2,j-1}]++;
            mp[ {i-1,j-1}]++;
            mp[ {i,j-1}]++;
            mp[ {i-2,j}]++;
            mp[ {i-1,j}]++;
            mp[ {i,j}]++;
            mp[ {i-2,j+1}]++;
            mp[ {i-1,j+1}]++;
            mp[ {i,j+1}]++;
            if(j==end_colum)
            {
                j++;
                mp[ {i+1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i+1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i+1,j+1}]++;
                mp[ {i,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i-2,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-2,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-2,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i,j+1}]++;
                j--;
            }
            if(j==y)
            {
                j--;
                mp[ {i+1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i+1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i+1,j+1}]++;
                mp[ {i,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i-2,j-1}]++;
                mp[ {i-1,j-1}]++;
                mp[ {i,j-1}]++;
                mp[ {i-2,j}]++;
                mp[ {i-1,j}]++;
                mp[ {i,j}]++;
                mp[ {i-2,j+1}]++;
                mp[ {i-1,j+1}]++;
                mp[ {i,j+1}]++;
                j++;
            }
        }
    }
}
// end Outline -----------------------------------------------------------------------------------------------------------------
