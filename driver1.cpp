#include <iostream>
#include "tetris.h"
#include "tetromino.h"
#include<chrono>
#include<thread>
using namespace NTetris;
using namespace NTetrominos;
using namespace std;
int main(){

    cout<<"Draw Function...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
     Tetris tetris(10,10);
     tetris.draw();
     Tetromino tetro(static_cast<shapes>('T'));

     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
     cout<<"+= Operator is working....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
     tetris+=tetro;
     tetris.draw();
     tetris.clean();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

     cout<<"T tetris Rotate:R count:1....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
     tetro.rotate('R');
     tetris+=tetro;
     tetris.draw();
     tetris.clean();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

     cout<<"T tetris Rotate:L count:1....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
     tetro.rotate('L');
     tetris+=tetro;
     tetris.draw();


     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

     cout<<"Move function is working left count:2....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
     tetris.move(tetro,2,'L');
     tetris.draw();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

     cout<<"Animate function is working....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
     tetris.animate(tetro,2);
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));

      cout<<"Game is starting.Loading........\n";
}
