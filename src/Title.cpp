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
    if(MouseL.down()){
        changeScene(State::Game);
    }
}

void Title::draw() const
{
    
}
