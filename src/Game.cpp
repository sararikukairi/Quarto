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
    for(i=0;i<4;i++)//ボード配置
    {
        sell<<Circle(544+(i*64),64+(i*64),40);
        sell<<Circle(480+(i*64),64*2+(i*64),40);
        sell<<Circle(416+(i*64),64*3+(i*64),40);
        sell<<Circle(352+(i*64),64*4+(i*64),40);
    }
    
    for(i=0;i<16;i++)
    {
        piece<<TextureAsset(U"LBCH");
    }
    
    for(const auto& sells : sell)
    {
        if(sells.mouseOver()&&MouseL.pressed())
        {
            //配列の要素番号
            break;
        }
    }
    
    
        
}

void Game::update()
{
    
}

void Game::draw() const
{

    ClearPrint();
    
    for(const auto& sells : sell)//ボード描画
    {
        if(sells.mouseOver())
            sells.draw(Palette::Red);
        else
            sells.draw();
    }
    
    for(const auto& pieces:piece)
    {
        pieces.draw(10,10);
    }
    
    
    
    Print<<Cursor::Pos();
    //Circle(Cursor::Pos(),30).draw();

}

