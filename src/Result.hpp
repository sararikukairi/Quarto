//
//  Result.hpp
//  qua
//
//  Created by ginkgo mottled on 2019/10/20.
//

#ifndef Result_hpp
#define Result_hpp

#include "Scene.hpp"

class Result:public Myapp::Scene
{
public:
    Result(const InitData& init);
    void update() override;
    void draw() const override;
};


#endif /* Result_hpp */
