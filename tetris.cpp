#include <iostream>
#include "tetris.h"
#include<chrono>
#include<thread>
using namespace std;

namespace NTetris{
Tetris::Tetris(int _x ,int _y){
this->x=_x;
this->y=_x;
board=new char*[x];
for(int i=0;i<x;i++){
    board[i]=new char[x];
}

//creat tetromino board
for(int j=0;j<x;j++){
     for(int i=0;i<y;i++){
        if(i==0 || i==x-1)
         board[i][j]='#';
        else if(j==0 || j==y-1)
         board[i][j]='#';
        else
         board[i][j]=' ';
        
    }
}
}
void Tetris::clean(){

board[tetro_index[0].i][tetro_index[0].j]=' ';
board[tetro_index[1].i][tetro_index[1].j]=' ';
board[tetro_index[2].i][tetro_index[2].j]=' ';
board[tetro_index[3].i][tetro_index[3].j]=' ';

}
void Tetris::NoktaTespit(Tetromino &tetrominoShape){
int s=0;
int yari=x/2-1;
     for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            if(tetrominoShape.boardtet[j][i]!=' ' && s<4){

                tetro_index[s].i=j+1;   
                tetro_index[s].j=i+yari;   
                s++;
            }


        }
     }

}

Tetris& Tetris::operator +=(Tetromino &tetrominoShape){
    int a=0;
    int flag=0;
    while(a<3){
    if(bitir(tetrominoShape)==1){
        tetrominoShape.rotate('L');
    }
    else{
    flag=1;
    int yari=0;
    yari=x/2;//half size of the board
    int l=0,k=0;
    for(int i=1;i<=4;i++){
        l=0;
        for(int j=yari-1;j<yari+3;j++){///add the tetromino to the middle of the board
           if(tetrominoShape.boardtet[k][l]!=' ')
              board[i][j]=tetrominoShape.boardtet[k][l];

           l++;
        }
        k++;
    }
    NoktaTespit(tetrominoShape);//find the cordinate of the tetromino
    break;
}
    a++;
}

   if(flag==0){
  cout<<"Tried 4 ways to rotate but failed to place on the map.\n";
   exit(0);
}
else return *this;



}
void Tetris::draw(){

   std::this_thread::sleep_for(std::chrono::milliseconds(150));
   cout << "\x1B[2J\x1B[H";

for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<< board[i][j];

        }
cout<<endl;
}
}

int Tetris::tetro_col(Tetromino &tetrominoShape){ 

int flag=0;
int boy=0;
for(int i=3;i>=0;i--){
    for(int j=0;j<4;j++){
        if(tetrominoShape.boardtet[i][j]!=' '){ // search the tetromino array until find a space and find the height of the tetromino 
            boy=i+1;
            flag=1;
            break;
        }

    }
    if(flag==1)break;
}
    return boy;
}
int Tetris::tetro_row(Tetromino &tetrominoShape){ 


int flag=0;
int count=0;
int en=0;
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){// search the tetromino array until find a space and find the height of the tetromino 
        if(tetrominoShape.boardtet[j][i]!=' '){ 
           count++;
           break;
        }

    }
}
    return count;
}

int Tetris::move(Tetromino &tetrominoShape,int nekadargidicek,char direction){
bool flag=false;

    if(nekadargidicek==0)
        return nekadargidicek;

   if(direction=='R')
      nekadargidicek*=-1;//sağa ve sola taşımada indexlere ekleme yada çıkarma
do{
int count=0;

if(board[tetro_index[0].i][tetro_index[0].j-nekadargidicek]==' ' || board[tetro_index[0].i][tetro_index[0].j-nekadargidicek]==(char)tetrominoShape.getShape()){
    count++;
}
if(board[tetro_index[1].i][tetro_index[1].j-nekadargidicek]==' ' || board[tetro_index[1].i][tetro_index[1].j-nekadargidicek]==(char)tetrominoShape.getShape()){
    count++;
}
if(board[tetro_index[2].i][tetro_index[2].j-nekadargidicek]==' ' || board[tetro_index[2].i][tetro_index[2].j-nekadargidicek]==(char)tetrominoShape.getShape()){
    count++;
}
if(board[tetro_index[3].i][tetro_index[3].j-nekadargidicek]==' ' ||  board[tetro_index[3].i][tetro_index[3].j-nekadargidicek]==(char)tetrominoShape.getShape()){
    count++;
}
if(count==4){
    if(direction=='R'){
        for(int r=3;r>=0;r--){
           board[tetro_index[r].i][tetro_index[r].j-nekadargidicek]=board[tetro_index[r].i][tetro_index[r].j];
           board[tetro_index[r].i][tetro_index[r].j]=' ';
           tetro_index[r].j-=nekadargidicek;
        }
   
    }
    else{
        for(int k=0;k<4;k++){
           board[tetro_index[k].i][tetro_index[k].j-nekadargidicek]=board[tetro_index[k].i][tetro_index[k].j];
           board[tetro_index[k].i][tetro_index[k].j]=' ';
           tetro_index[k].j-=nekadargidicek;

        }

    }
    flag=true;
}
else {
    if(direction=='L'){
    nekadargidicek--;
    }
    else if(direction=='R'){
        nekadargidicek++;
    }
}
}while(flag==false);

return nekadargidicek;
}


void Tetris::animate(Tetromino &tetrominoShape,int nekadargidicek){
int *flag=new int[] {0,0,0,0};
int count1=0,count2=0;

for(int i=0;i<4;++i){

        if(tetro_index[i].i+1-1==4 || tetro_index[i].j-(x/2-1)+nekadargidicek==4){
            flag[i]=1;
            count1++;
        }

        else if(tetrominoShape.boardtet[tetro_index[i].i+1-1][tetro_index[i].j-(x/2-1)+nekadargidicek]==' '){
        
            flag[i]=1;
            count1++;
        }
    
}

do{
    count2=0;

    if(flag[0]==1){
        if(board[tetro_index[0].i+1][tetro_index[0].j]==' '){
            count2++;            
        }
    }
     if(flag[1]==1){
        if(board[tetro_index[1].i+1][tetro_index[1].j]==' '){
            count2++;
        }
    }
     if(flag[2]==1){
        if(board[tetro_index[2].i+1][tetro_index[2].j]==' '){
            count2++;
        }
    }
     if(flag[3]==1){
        if(board[tetro_index[3].i+1][tetro_index[3].j]==' '){
            count2++;
        }
    }
    if(count1==count2){

        board[tetro_index[3].i+1][tetro_index[3].j]=board[tetro_index[3].i][tetro_index[3].j];
        board[tetro_index[3].i][tetro_index[3].j]=' ';
        tetro_index[3].i++;
        board[tetro_index[2].i+1][tetro_index[2].j]=board[tetro_index[2].i][tetro_index[2].j];
        board[tetro_index[2].i][tetro_index[2].j]=' ';
        tetro_index[2].i++;
        board[tetro_index[1].i+1][tetro_index[1].j]=board[tetro_index[1].i][tetro_index[1].j];
        board[tetro_index[1].i][tetro_index[1].j]=' ';
        tetro_index[1].i++;
        board[tetro_index[0].i+1][tetro_index[0].j]=board[tetro_index[0].i][tetro_index[0].j];
        board[tetro_index[0].i][tetro_index[0].j]=' ';
        tetro_index[0].i++;
        
        draw();
    }

}while(count1==count2);
}
int Tetris::bitir(Tetromino &tetrominoShape){
    NoktaTespit(tetrominoShape);
int flag=0;
if(board[tetro_index[0].i][tetro_index[0].j]==' ')flag++;
if(board[tetro_index[1].i][tetro_index[1].j]==' ')flag++;
if(board[tetro_index[2].i][tetro_index[2].j]==' ')flag++;
if(board[tetro_index[3].i][tetro_index[3].j]==' ')flag++;
if(flag==4)return 0;
else return 1;


}

void Tetris::cleanboard(){
    int count ;
for(int t=0;t<3;t++){
  for(int i=x-2;i>0;i--){
    count=0;
    for(int j=1;j<y-1;j++){
    if( board[i][j]!=' '){
        count++;
    }

    }
        if(count==x-2){
           for(int k=i;k>1;k--){
             for(int j=1;j<y-1;j++){
          board[k][j]=board[k-1][j];
          board[k-1][j]=' ';

                                  }
                           }
             draw();
                   }
   }
 }


}
}