//
//  Game.cpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#include "Game.hpp"
int8 setsellnumber(Array<Circle> sell);
void piecedraw(const Array<Texture> piece,const Array<Rect> hitbox,const bool empty[]);

Game::Game(const InitData& init)
: IScene(init)
{
    for(i=0;i<4;i++)//ボード配置
    {
        sell<<Circle(344+(i*64),64+(i*64),40);
        sell<<Circle(280+(i*64),64*2+(i*64),40);
        sell<<Circle(216+(i*64),64*3+(i*64),40);
        sell<<Circle(152+(i*64),64*4+(i*64),40);
    }
    for(i=0;i<4;i++)
    {
        hitbox<<Rect(700,50+i*100,100,100);
        hitbox<<Rect(800,50+i*100,100,100);
        hitbox<<Rect(900,50+i*100,100,100);
        hitbox<<Rect(1000,50+i*100,100,100);
    }
    //画像読み込み
    piece<<TextureAsset(U"LBCH");
    piece<<TextureAsset(U"LBCU");
    piece<<TextureAsset(U"LBRH");
    piece<<TextureAsset(U"LBRU");
    piece<<TextureAsset(U"LWCU");
    piece<<TextureAsset(U"LWCH");
    piece<<TextureAsset(U"LWRH");
    piece<<TextureAsset(U"LWRU");
    piece<<TextureAsset(U"SBCU");
    piece<<TextureAsset(U"SBRU");
    piece<<TextureAsset(U"SBRH");
    piece<<TextureAsset(U"SBCH");
    piece<<TextureAsset(U"SWCH");
    piece<<TextureAsset(U"SWCU");
    piece<<TextureAsset(U"SWRU");
    piece<<TextureAsset(U"SWRH");

    quarto=Rect(444,500,200,100);
    
    flag=true;
    
    for(int i=0;i<16;i++)
    {
        emptybord[i]=true;
    }
    
}

void Game::update()
{
    if(flag)
    {
        for(const auto& pieces:piece)
        {
            
        }
    }
    
    else
    {
        if((s=setsellnumber(sell))>=0)
        {
            bord[s]=p;
        }
    }
    
    if(quarto.mouseOver()&&MouseL.pressed())
    {
        
    }
}

void Game::draw() const
{

    ClearPrint();
    
    for(const auto& sells : sell)//ボード描画
    {
        if(sells.mouseOver())
            sells.draw(Palette::Red);
        else
            sells.draw(Palette::Cyan);
    }
    
    piecedraw(piece,hitbox,emptybord);//未使用の駒表示
    
    if(quarto.mouseOver())//クアルトボタン
    {
        quarto.draw(Palette::Red);
        FontAsset(U"Score")(U"Quarto!").draw(quarto.x+30,quarto.y+25,Palette::White);
    }
    else
    {
        quarto.draw();
        FontAsset(U"Score")(U"Quarto!").draw(quarto.x+30,quarto.y+25,Palette::Black);
    }
    
}


int8 setsellnumber(Array<Circle> sell)
{
    int i=0;
    for(const auto& sells : sell)
    {
        if(sells.mouseOver()&&MouseL.pressed())
        {
            return i;
        }
        i++;
    }
    return -1;
}

void piecedraw(const Array<Texture> piece,const Array<Rect> hitbox,const bool empty[])
{
    if(piece.size()!=hitbox.size())
        return;
    for(int i=0;i<piece.size();i++)
    {
        hitbox[i].draw(Palette::Gray);
        if(empty[i])
        {
            piece[i].draw(hitbox[i].pos);
        }
    }
    return;
}
//////////
//駒選び
//////////
//駒を置く
//////////
//勝利判定
//////////
