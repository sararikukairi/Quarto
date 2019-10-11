//
//  Title.hpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/10.
//

#ifndef Title_hpp
#define Title_hpp

#include "Scene.hpp"

class Title:public Myapp::Scene
{
public:
    Title(const InitData& init);
    void update();
    const void draw();
};


#endif /* Title_hpp */
