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
    int8 bord[4][4][4]={0};//4*4のボードとマスに置かれてる駒属性を4ビット3進数で判断

    Array<Texture> piece;
    
    Array<Circle> sell;
    
    int i;
    
public:
    Game(const InitData& init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
