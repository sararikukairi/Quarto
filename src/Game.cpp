//
//  Game.cpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#include "Game.hpp"
bool setsellnumber(Array<Array<Circle>> sell,int8 *x,int8 *y,const Array<Array<int8>> bord);
void piecedraw(const Array<Texture> piece,const Array<Rect> piecebox,const bool empty[]);
void usepiecedraw(const Array<Texture> piece,const Array<Array<Circle>> sell,const Array<Array<int8>> bord);
///////////////////////////////////////////////////////////////////////////////////////////////
Game::Game(const InitData& init)
: IScene(init)
{
    
    for(int i=0;i<4;i++)
    {
        sline1<<Circle(344+(i*64),64+(i*64),40);
        sline2<<Circle(280+(i*64),64*2+(i*64),40);
        sline3<<Circle(216+(i*64),64*3+(i*64),40);
        sline4<<Circle(152+(i*64),64*4+(i*64),40);
        
        piecebox<<Rect(700,50+i*100,100,100);
        piecebox<<Rect(800,50+i*100,100,100);
        piecebox<<Rect(900,50+i*100,100,100);
        piecebox<<Rect(1000,50+i*100,100,100);
        
        line1<<-1;
        line2<<-1;
        line3<<-1;
        line4<<-1;
    }
    
    bord<<line1<<line2<<line3<<line4;
    sell<<sline1<<sline2<<sline3<<sline4;
    
    for(i=0;i<16;i++)
    {
        emptybord[i]=true;
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
        
        if(setsellnumber(sell,&x,&y,bord))
        {
            bord[x][y]=p;
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
        for(auto s:sells){
        if(s.mouseOver())
            s.draw(Palette::Red);
        else
            s.draw(Palette::Cyan);
        }
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
    for(int l=0;l<4;l++){
        for(int p=0;p<4;p++){
        Print<<bord[l][p];}}
}
////////////////////////////////////////////////////////////////////////////

bool setsellnumber(Array<Array<Circle>> sell,int8 *x,int8 *y,const Array<Array<int8>> bord)
{
    for(size_t i=0;i<bord.size();i++)
    {
        for(size_t j=0;j<bord[i].size();j++)
        {
            if((sell[i][j].leftClicked())&&(bord[i][j]==-1))
            {
                *x=i;
                *y=j;
                return true;
            }
        }
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////
void piecedraw(const Array<Texture> piece,const Array<Rect> piecebox,const bool empty[])
{
    
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
void usepiecedraw(const Array<Texture> piece,const Array<Array<Circle>> sell,const Array<Array<int8>> bord)
{
    
    for(size_t i=0;i<bord.size();i++)
    {
        for(size_t j=0;j<bord[i].size();j++)
            if(bord[i][j]>=0)
            {
                piece[bord[i][j]].draw(sell[i][j].x-45,sell[i][j].y-55);
            }
    }
    return;
}
