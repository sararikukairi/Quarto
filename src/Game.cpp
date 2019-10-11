//
//  Game.cpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#include "Game.hpp"

Game::Game(const InitData& init)
: IScene(init)
{
    for(int i=0;i<4;i++){
        sell<<Circle(544+(i*64),64+(i*64),40);
        sell<<Circle(480+(i*64),64*2+(i*64),40);
        sell<<Circle(416+(i*64),64*3+(i*64),40);
        sell<<Circle(352+(i*64),64*4+(i*64),40);
    }
}

void Game::update()
{
    
}

void Game::draw() const
{
    ClearPrint();
    for (const auto& block : sell)
    {
        block.draw();
    }
    for(int i=0;i<4;i++){
    }
    Print<<Cursor::Pos();
    //Circle(Cursor::Pos(),30).draw();
}

