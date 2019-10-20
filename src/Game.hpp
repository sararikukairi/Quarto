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
    Array<Array<int8>> bord;//駒の属性を格納
    Array<int8> line1;
    Array<int8> line2;
    Array<int8> line3;
    Array<int8> line4;
    
    Array<Texture> piece;//駒配列
    Array<Array<Circle>> sell;//ボードマス
    Array<Circle> sline1;
    Array<Circle> sline2;
    Array<Circle> sline3;
    Array<Circle> sline4;
    
    Array<Rect> piecebox;
    
    Rect quarto;
    
    int8 i;
    int8 p;//現在選ばれている駒の属性
    int8 x,y;//マス座標
    
    bool pturn;
    bool flag;//ターン進行
    bool emptybord[16];
    
public:
    Game(const InitData& init);
    void update() override;
    void draw() const override;
};

#endif /* Game_hpp */
