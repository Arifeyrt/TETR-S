#ifndef TETRIS_H
#define TETRIS_H
#include "tetromino.h"

#include <iostream>
using namespace NTetrominos;
namespace NTetris{
class indexTutan{
    public:
    int i;
    int j;
    
};
class Tetris{
private:
int x;
int y;
char** board;

public:                            
indexTutan tetro_index[4];         
Tetris(int _x,int _y);

Tetris& operator +=(Tetromino &tetrominoShape);
void draw();//draw
void NoktaTespit(Tetromino &tetrominoShape);/////the function i use to locate the tetron on the map I keep the values of the 4 points in the class I created.
int tetro_col(Tetromino &tetrominoShape);//find the biggest col
int tetro_row(Tetromino &tetrominoShape);//find the biggest row
int move(Tetromino &tetrominoShape,int nekadargidicek,char); // In order to shift left and right, we need to keep only the letter-containing parts of the 4e4 tetron that we put on the map with the operator as data.
void animate(Tetromino &tetrominoShape,int nekadargidicek);
void clean(); /////////The function that deletes the indexed tetro in the map.
void cleanboard();////if row is full,clean row
int bitir(Tetromino &tetrominoShape);///////////If it is full while talking to the retro map, return 1 is returned.



};
}
#endif
