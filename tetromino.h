#ifndef TETROMINOS_H
#define TETROMINOS_H
#include <iostream>

enum class shapes{
    T='T',
    L='L',
    Z='Z',
    S='S',
    I='I',
    O='O',
    J='J'

};

namespace NTetrominos{
class Tetromino{
    private:
    shapes shape;
    public:
    Tetromino(const shapes& shape);
    shapes getShape(){
        return shape;
    }
    void rotate(char rot);
     char **boardtet;

};
}
#endif
