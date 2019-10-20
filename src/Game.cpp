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
bool check(const Array<Array<int8>> bord);
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
    cflag=true;
    getData().pturn=false;
    
    
}
/////////////////////////////////////////////////////////
void Game::update()
{
    if(flag&&cflag)
    {
        for(i=0;i<piecebox.size();i++)
        {
            if(piecebox[i].leftClicked()&&emptybord[i])
            {
                p=i;
                emptybord[i]=false;
                flag=false;
                getData().pturn=!getData().pturn;
                break;
            }
        }
    }
    
    else if(cflag)
    {
        
        if(setsellnumber(sell,&x,&y,bord))
        {
            bord[x][y]=p;
            flag=true;
        }
    }
    
    if(quarto.leftClicked()&&cflag)
    {
        if(check(bord))
        {
            getData().jugd=true;
            cflag=false;
        }
        else
        {   if(getData().pturn)
                penalty[0]++;
            else
                penalty[1]++;
            getData().jugd=false;
            if((getData().pturn&&penalty[0]==3)|(!getData().pturn&&penalty[1]==3))
                cflag=false;
        }
    }
    
    if(!cflag&&KeyEnter.down())
    {
        changeScene(State::Result);
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
    
    if(getData().pturn)
    {
        FontAsset(U"Score")(U"Player 1").draw();
        FontAsset(U"Score")(U"penalty:{}"_fmt(penalty[0])).draw(0,35);
    }
    else
    {
        FontAsset(U"Score")(U"Player 2").draw();
        FontAsset(U"Score")(U"penalty:{}"_fmt(penalty[1])).draw(0,35);
    }
    /*
    ClearPrint();
    for(int e=0;e<4;e++){
        for(int p=0;p<4;p++){
            Print<<bord[e][p];
        }
    }*/
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
///////////////////////////////////////////////////////////////////////////////////////////////
bool check(const Array<Array<int8>> bord)
{
    int jugd1=0,jugd2=15;
    bool flag=true;
    
    for(size_t i=0;i<bord.size();i++)
    {
        for (size_t j=0;j<bord[i].size();j++)
        {
            if(bord[i][j]==-1)
            {
                flag=false;
                break;
            }
            jugd1=jugd1|bord[i][j];
            jugd2=jugd2&bord[i][j];
        }
    
        if((((jugd1>-1)&&(jugd1<15))|(jugd2>0))&&flag)
        {
            return true;
        }
        else
        {
            jugd1=0;
            jugd2=15;
            flag=true;
        }
    }
    
    
    for(size_t i=0;i<bord.size();i++)
    {
        for (size_t j=0;j<bord[i].size();j++)
        {
            if(bord[j][i]==-1)
            {
                flag=false;
                break;
            }
            jugd1=jugd1|bord[j][i];
            jugd2=jugd2&bord[j][i];
        }
        
        if((((jugd1>-1)&&(jugd1<15))|(jugd2>0))&&flag)
        {
            return true;
        }
        else
        {
            jugd1=0;
            jugd2=15;
            flag=true;
        }
    }
    
    
    for(size_t i=0;i<bord.size();i++)
    {
        if(bord[i][i]==-1)
        {
            flag=false;
            break;
        }
        jugd1=jugd1|bord[i][i];
        jugd2=jugd2&bord[i][i];
    }
    if((((jugd1>-1)&&(jugd1<15))|(jugd2>0))&&flag)
    {
        return true;
    }
    else
    {
        jugd1=0;
        jugd2=15;
        flag=true;
    }
    
    
    for(size_t i=0;i<bord.size();i++)
    {
        if(bord[3-i][i]==-1)
        {
            flag=false;
            break;
        }
        jugd1=jugd1|bord[3-i][i];
        jugd1=jugd2&bord[3-i][i];
        
    }
    if((((jugd1>-1)&&(jugd1<15))|(jugd2>0))&&flag)
    {
        return true;
    }
    return false;
}
