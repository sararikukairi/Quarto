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
    int8 bord[16];//駒の属性を格納

    Array<Texture> piece;//駒配列
    Array<Array<Circle>> sell;//ボードマス
    Array<Rect> piecebox;
    
    Rect quarto;
    
    int8 i;
    int8 p;//現在選ばれている駒の属性
    int8 s;//選ばれたマス
    
    bool pturn;
    bool flag;//ターン進行
    bool emptybord[16];
    
public:
    Game(const InitData& init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
