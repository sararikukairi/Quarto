//
//  Game.cpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#include "Game.hpp"
int8 setsellnumber(Array<Circle> sell,int8 bord[]);
void piecedraw(const Array<Texture> piece,const Array<Rect> piecebox,const bool empty[]);
void usepiecedraw(const Array<Texture> piece,const Array<Circle> sell,const int8 bord[]);
///////////////////////////////////////////////////////////////////////////////////////////////
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
    for(i=0;i<4;i++)//駒盤配置
    {
        piecebox<<Rect(700,50+i*100,100,100);
        piecebox<<Rect(800,50+i*100,100,100);
        piecebox<<Rect(900,50+i*100,100,100);
        piecebox<<Rect(1000,50+i*100,100,100);
    }
    //画像読み込み
    piece<<TextureAsset(U"LWCU");
    piece<<TextureAsset(U"LWCH");
    piece<<TextureAsset(U"LWRU");
    piece<<TextureAsset(U"LWRH");
    piece<<TextureAsset(U"LBCU");
    piece<<TextureAsset(U"LBCH");
    piece<<TextureAsset(U"LBRU");
    piece<<TextureAsset(U"LBRH");
    piece<<TextureAsset(U"SWCU");
    piece<<TextureAsset(U"SWCH");
    piece<<TextureAsset(U"SWRU");
    piece<<TextureAsset(U"SWRH");
    piece<<TextureAsset(U"SBCU");
    piece<<TextureAsset(U"SBCH");
    piece<<TextureAsset(U"SBRU");
    piece<<TextureAsset(U"SBRH");

    quarto=Rect(444,500,200,100);
    
    flag=true;
    pturn=false;
    
    for(i=0;i<16;i++)
    {
        emptybord[i]=true;
        bord[i]=-1;
    }
    
    
}
/////////////////////////////////////////////////////////
void Game::update()
{
    ClearPrint();
    if(flag)
    {
        for(i=0;i<piecebox.size();i++)
        {
            if(piecebox[i].leftClicked()&&emptybord[i])
            {
                p=i;
                emptybord[i]=false;
                flag=false;
                pturn=!pturn;
                break;
            }
        }
    }
    
    else
    {
        if((s=setsellnumber(sell,bord))>=0)
        {
            bord[s]=p;
            flag=true;
        }
    }
    
    if(quarto.leftClicked())
    {
        
    }
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::draw() const
{

    for(const auto& sells : sell)//ボード描画
    {
        if(sells.mouseOver())
            sells.draw(Palette::Red);
        else
            sells.draw(Palette::Cyan);
    }

    piecedraw(piece,piecebox,emptybord);//未使用の駒表示
    usepiecedraw(piece,sell,bord);
    
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
    
    if(pturn)
    {
        FontAsset(U"Score")(U"Player 1").draw();
    }
    else
    {
        FontAsset(U"Score")(U"Player 2").draw();
    }
    
}
////////////////////////////////////////////////////////////////////////////

int8 setsellnumber(Array<Circle> sell,int8 bord[])
{
    for(size_t i=0;i<sell.size();i++)
    {
        if(sell[i].leftClicked())
        {
            return int(i);
        }
    }
    return -1;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void piecedraw(const Array<Texture> piece,const Array<Rect> piecebox,const bool empty[])
{
    if(piece.size()!=piecebox.size())
    {
        return;
    }
    
    for(size_t i=0;i<piece.size();i++)
    {
        piecebox[i].draw(Palette::Gray);
        if(empty[i])
        {
            piece[i].draw(piecebox[i].pos);
        }
    }
    return;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void usepiecedraw(const Array<Texture> piece,const Array<Circle> sell,const int8 bord[])
{
    for(size_t i=0;i<16;i++)
    {
        if(bord[i]>=0)
        {
            piece[bord[i]].draw(sell[i].x-45,sell[i].y-55);
        }
    }
    return;
}
