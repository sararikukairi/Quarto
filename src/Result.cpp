//
//  Result.cpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/20.
//

#include "Result.hpp"

Result::Result(const InitData& init)
: IScene(init)
{
    
}

void Result::update()
{
    if(KeyEnter.down())
    {
        changeScene(State::Title);
    }
}

void Result::draw() const
{
    if((getData().pturn&&getData().jugd)|(!getData().pturn&&!getData().jugd))
    {
        FontAsset(U"Title")(U"1P WIN").draw();
    }
    else
    {
        FontAsset(U"Title")(U"2P WIN").draw();
    }
}
