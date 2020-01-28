#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class Snake
{
private:
    int width=50,height=20,x,y,fx,fy,score=0,i,j,flag,k;
    int tailX[100],tailY[100],ct=0;;
    int prevX,prevY,prev2X,prev2Y;
    public:
        int gameOver=0;
    void Setup()
    {
        x=width/2;
        y=height/2;
        l1:
        fx=rand()%width;
        if(fx==0)
            goto l1;
            l2:
        fy=rand()%height;
        if(fy==0)
            goto l2;
            gameOver=0;
    }
    void Draw()
    {
        system("cls");
        for( i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                if(i==0||i==height-1||j==0||j==width-1)
                    cout<<"#";
                else
                {
                    if(i==y&&j==x)
                    cout<<"O";
                else if(i==fy&&j==fx)
                    cout<<"0";
                else
                {
                    int ch=0;
                    for(k=0;k<ct;k++)
                    {
                    if(i==tailY[k]&&j==tailX[k])
                    {
                    cout<<"o";
                    ch=1;
                    }
                    }

                if(ch==0)
                    cout<<" ";
                }
                }
            }
            cout<<endl;
        }
        cout<<"Your score: "<<score;
    }
    void Input()
    {
        if(kbhit())
        {
            switch(getch())
            {
            case 'a':
                flag=1;
                break;
                case 's':
                flag=2;
                break;
                case 'd':
                flag=3;
                break;
                case 'w':
                flag=4;
                break;
            }
        }
    }
    void Logic()
    {
        prevX=tailX[0];
        prevY=tailY[0];
        tailX[0]=x;
        tailY[0]=y;
        for(i=1;i<ct;i++)
        {
            prev2X=tailX[i];
            prev2Y=tailY[i];
            tailX[i]=prevX;
            tailY[i]=prevY;
            prevX=prev2X;
            prevY=prev2Y;
        }
        switch(flag)
        {
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            break;
        case 4:
            y--;
            break;
        }
        for(i=0;i<ct;i++)
        {
            if(x==tailX[i]&&y==tailY[i])
                gameOver=1;
        }
        if(x<0||x>width||y<0||y>height)
            gameOver=1;
            if(x==fx&&y==fy)
            {
                l3:
        fx=rand()%width;
        if(fx==0)
            goto l3;
            l4:
        fy=rand()%height;
        if(fy==0)
            goto l4;
            score++;
            ct++;
            }

    }
};
int main()
{
    int m,n;
    Snake s;
    s.Setup();
    while(!s.gameOver)
    {
    s.Draw();
    s.Input();
    s.Logic();
    for(m=0;m<1000;m++)
    {
        for(n=0;n<1000;n++)
        {

        }
    }
    }
    return 0;
}
