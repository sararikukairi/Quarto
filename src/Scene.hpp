//
//  Scene.hpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <Siv3D.hpp>

enum class State
{
    Title,
    Game,
    Result
};

struct GameData
{
    bool flag;  
};

using Myapp = SceneManager<State, GameData>;

class Result:public Myapp::Scene
{
public:
    Result();
    void set();
    void update();
    const void draw();
};

#endif /* Scene_hpp */
