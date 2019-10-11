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
private:
    int8 map[4][4]={0};
    struct RB{
        Rect shorthole();
        Rect longhole();
        Rect shortunhole();
        Rect longunhole();
    };
    
    struct CB{
        Circle shorthole();
        Circle longhole();
        Circle shortunhole();
        Circle longunhole();
    };
    
    struct RW{
        Rect shorthole();
        Rect longhole();
        Rect shortunhole();
        Rect longunhole();
    };
    
    struct CW{
        Circle shorthole();
        Circle longhole();
        Circle shortunhole();
        Circle longunhole();
    };
    
public:
    Game(const InitData& init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
