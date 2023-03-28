#include <iostream>
#include "tetris.h"
#include "tetromino.h"
using namespace NTetris;
using namespace NTetrominos;


using namespace std;
int main(){
    int x; //Holds the size of the board
    int y; //Holds the size of the board
    char moveD;  //Holds the direction of the move
    int moveC;   //Holds the count of the move
    char rotateC;   //Holds the count of the rotate
    int rotate;     //Holds the directşon of the rotate
    int dondur;        
     

    cout<<"enter size"<<endl;
    cin >>x;
    y=x;

    Tetris tetris(x,y);
    char shapetet;//shape name

   while(1){//take shape constantly

    cout<<"Enter shape"<<endl;
    cin>>shapetet;
    if(shapetet!='I' && shapetet!='T' && shapetet!='L' && shapetet!='Z' && shapetet!='S' && shapetet!= 'O' && shapetet!='J' && shapetet!='R' && shapetet!='Q'){//true shaope
      cout<<"wrong shape.Try again"<<endl;
      cin>>shapetet;
      }
    if(shapetet=='Q' || shapetet=='q')//finish
        break;

    if(shapetet=='R'){

      while(1){

      shapetet = 'A' + rand()%26;//random shape assignment

        if(shapetet=='I' || shapetet=='T' || shapetet=='L' || shapetet=='Z' || shapetet=='S' || shapetet=='O' || shapetet=='J')
          break;
      }      
    }
    
    Tetromino tetromino(Tetromino(static_cast<shapes>(shapetet)));

    tetris+=tetromino;
    tetris.draw();
    tetris.clean();
    cout << "Enter the ROT Direct:" ;
    cin >> rotateC;

    cout << "Enter the ROT count:";
  cin >> rotate;
   for(int i=0;i<rotate;i++){
      tetromino.rotate(rotateC);
    }
  tetris+=tetromino;
  tetris.draw();
    cout << "Enter the move Direct:" ;
    cin >> moveD;

    cout << "Enter the move count:";
    cin >> moveC;
    
    moveC = tetris.move(tetromino,moveC,moveD);
    tetris.draw();

    tetris.animate(tetromino,moveC);//move the shape down
    tetris.cleanboard();  
   }
    




    return 0;
}

/*
           ....
           ....
           .T..
           TTT.
            n[0].i=2;bu hangisi
            n[0].j=1;
            n[1].i=3;
            n[1].j=0;

            OO
            OO


T de en küçük j li olan index n[1]
o da ise n[2];yani şunlar ya da n[0]


*/