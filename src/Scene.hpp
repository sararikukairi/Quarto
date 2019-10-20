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
    bool pturn;
    bool jugd;
};

using Myapp = SceneManager<State, GameData>;

#endif /* Scene_hpp */
