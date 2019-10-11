//
//  Game.hpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#ifndef Game_hpp
#define Game_hpp

#include "Scene.hpp"

class Game:public Myapp::Scene
{
public:
    Game(const InitData& init);
    void update();
    const void draw();
};

#endif /* Game_hpp */
