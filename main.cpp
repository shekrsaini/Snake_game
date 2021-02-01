#include <iostream>
#include<conio.h>

using namespace std;
bool gameOver;
const int width=40;
const int height=20;
int x,y,fruitx,fruity,score;

enum eDirection {STOP =0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void Setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitx= rand()%width;
    fruity=rand()%height;
    score =0;
}
void Draw()
{
    system("cls");
    for(int i=0;i<width+2;i++){
        cout<<"#";
    };
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width+2;j++){
            if(j==0 || j==height+1){
                cout<<"#";
            }else if(i==y && j==x){ cout<<"0";}
            else if( i==fruity && j== fruitx){cout<<"F";}
            else{ cout<<"  ";};
        };
        cout<<endl;
    };
     for(int i=0;i<width+2;i++){
        cout<<"#";
    };
    cout<<"\n score: "<<score<<endl;
}
void Input()
{
    if( kbhit() ){
        switch(getch())
        {
            case 'a': dir=LEFT;
                         break;
             case 'd': dir = RIGHT;
                           break;
             case 'w': dir=UP;
                           break;
             case 's': dir=DOWN;
                          break;
             case 'x': gameOver=false;
                          break;
        };
    };
}
void Logic()
{
    switch(dir){
        case LEFT: x--;break;
        case RIGHT:x++; break;
        case UP: y-- ; break;
        case DOWN: y++; break;
        default : break;
    };
    if(x>width+2 || x< 1 || y>height || y<0){
        gameOver=true;
    };
    if(x==fruitx && y== fruity){
         score+=5;
         fruitx= rand() % width;
        fruity=rand() % height;
    };
}
int main()
{   
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        //sleep(10);
        //gameOver =true;
    }
    return 0;
}
