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
    int8 bord[4][4]={0};
    
    const Texture LBCH(U"example/texture/LBCH.png");
    const Texture LBCU(U"example/texture/LBCU.png");
    const Texture LBRH(U"example/texture/LBRH.png");
    const Texture LBRU(U"example/texture/LBRU.png");
    const Texture SBRH(U"example/texture/SBRH.png");
    const Texture SBRU(U"example/texture/SBRU.png");
    const Texture SBCH(U"example/texture/SBCH.png");
    const Texture SBCU(U"example/texture/SBCU.png");
    const Texture LWCH(U"example/texture/LWCH.png");
    const Texture LWCU(U"example/texture/LWCU.png");
    const Texture LWRH(U"example/texture/LWRH.png");
    const Texture LWRU(U"example/texture/LWRU.png");
    const Texture SWRH(U"example/texture/SWRH.png");
    const Texture SWRU(U"example/texture/SWRU.png");
    const Texture SWCH(U"example/texture/SWCH.png");
    const Texture SWCU(U"example/texture/SWCU.png");
    
    Array<Circle> sell;
    
public:
    Game(const InitData& init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
