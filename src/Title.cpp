//
//  Title.cpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#include "Title.hpp"

Title::Title(const InitData& init)
: IScene(init)
{
    
}

void Title::update()
{
    if(KeyEnter.down()){
        changeScene(State::Game);
    }
}

void Title::draw() const
{
    FontAsset(U"Title")(U"Quarto").draw(544,306);
}
