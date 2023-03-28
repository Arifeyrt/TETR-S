#include <iostream>
#include "tetromino.h"
using namespace std;


namespace NTetrominos{
Tetromino::Tetromino(const shapes& shape){
    this->shape=shape;
    int i,j;
    boardtet=new char*[4];
for(int i=0;i<4;i++){
    boardtet[i]=new char[4];
}
//we create tetromino shapes
char type=(char)shape;
if(shape == shapes::T){
    boardtet[0][0]='T';
     boardtet[0][1]='T';
      boardtet[0][2]='T';
       boardtet[1][1]='T';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='T')
                    boardtet[i][j]=' ';
            }
        }
}
else if(shape == shapes::S){
    boardtet[0][1]='S';
     boardtet[0][2]='S';
      boardtet[1][0]='S';
       boardtet[1][1]='S';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='S')
                    boardtet[i][j]=' ';
            }
        }
}
else if(shape == shapes::Z){
    boardtet[0][0]='Z';
     boardtet[0][1]='Z';
      boardtet[1][1]='Z';
       boardtet[1][2]='Z';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='Z')
                    boardtet[i][j]=' ';
            }
        }
}
else if(shape == shapes::I){
    boardtet[0][0]='I';
     boardtet[1][0]='I';
      boardtet[2][0]='I';
       boardtet[3][0]='I';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='I')
                    boardtet[i][j]=' ';
            }
        }
}
else if(shape == shapes::O){
    boardtet[0][0]='O';
     boardtet[0][1]='O';
      boardtet[1][0]='O';
       boardtet[1][1]='O';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='O')
                    boardtet[i][j]=' ';
            }
        }
}
else if(shape == shapes::J){
    boardtet[0][1]='J';
     boardtet[1][1]='J';
      boardtet[2][1]='J';
       boardtet[2][0]='J';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='J')
                    boardtet[i][j]=' ';
            }
        }
}
else if(shape == shapes::L){
    boardtet[0][0]='L';
     boardtet[1][0]='L';
      boardtet[2][0]='L';
       boardtet[2][1]='L';
        for( i=0;i<4;i++){
            for(j=0;j<4;++j){
                if(boardtet[i][j]!='L')
                    boardtet[i][j]=' ';
            }
        }
}
}


void Tetromino::rotate(char rot){
   if(rot=='R' || rot=='r'){
        for (int j=0; j * 2 < 4; j++) {
            for (int i=j; i<3-j; i++) {
                swap(boardtet[j][i], boardtet[i][3-j]);
                swap(boardtet[3-i][j], boardtet[j][i]);
                swap(boardtet[3-j][3-i], boardtet[3-i][j]);
            }
        }
   }
   if(rot=='L' || rot=='l'){
 for (int j=0; j * 2 < 4; j++) {
            for (int i=j; i<3-j; i++) {
                swap(boardtet[i][j], boardtet[3-j][i]);
                swap(boardtet[j][3-i], boardtet[i][j]);
                swap(boardtet[3-i][3-j], boardtet[j][3-i]);
            }
        }
   }
   int a=0;
   int count1=0;
     while(a<4){          
 count1=0;
int satir=0;
           
    for (int i=0;i < 4; i++){
      
        count1=0; 
   for (int j=0; j < 4; j++){
    if(boardtet[i][j]==' '){
        count1++;
        
    }
   }
   if(count1==4){
    satir=i;
    
    for (int k=0; k < 4; k++){
        if(satir<3){
    boardtet[satir][k]=boardtet[satir+1][k];
    boardtet[satir+1][k]=' ';
        }
   }
    }


    } 
    a++;
     }
a=0;
        int col=0;
     while(a<4){
count1=0;
col=0;
           
    for (int i=0;i < 4; i++){

        count1=0; 
   for (int j=0; j < 4; j++){
    if(boardtet[j][i]==' '){
        count1++;

    }
   }
   if(count1==4){
    col=i;

    for (int k=0; k < 4; k++){
        if(col<3){
    boardtet[k][col]=boardtet[k][col+1];
    boardtet[k][col+1]=' ';
        }
   }
    }
    } 
    a++;
     }
    
}
}