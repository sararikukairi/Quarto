# include "Scene.hpp"
# include "Game.hpp"
# include "Title.hpp"
# include "Result.hpp"
void Main()
{
    
    Window::Resize(1088,612);
    
    Scene::SetBackground(ColorF(0.6, 0.8, 0.4));
    
    FontAsset::Register(U"Title", 120, Typeface::Heavy);
    FontAsset::Register(U"Score", 50, Typeface::Bold);

    TextureAsset::Register(U"LBCH",U"example/texture/long_cylinder_black_α.png");
    TextureAsset::Register(U"LBCU",U"example/texture/long_cylinder_black.png");
    TextureAsset::Register(U"LBRH",U"example/texture/long_prism_black_α.png");
    TextureAsset::Register(U"LBRU",U"example/texture/long_prism_black.png");
    TextureAsset::Register(U"LWCU",U"example/texture/long_cylinder_white.png");
    TextureAsset::Register(U"LWCH",U"example/texture/long_cylinder_white_α.png");
    TextureAsset::Register(U"LWRH",U"example/texture/long_prism_white_α.png");
    TextureAsset::Register(U"LWRU",U"example/texture/long_prism_white.png");
    TextureAsset::Register(U"SBCU",U"example/texture/short_cylinder_black.png");
    TextureAsset::Register(U"SBRU",U"example/texture/short_prism_black.png");
    TextureAsset::Register(U"SBRH",U"example/texture/short_prism_black_α.png");
    TextureAsset::Register(U"SBCH",U"example/texture/short_cylinder_black_α.png");
    TextureAsset::Register(U"SWCH",U"example/texture/short_cylinder_white_α.png");
    TextureAsset::Register(U"SWCU",U"example/texture/short_cylinder_white.png");
    TextureAsset::Register(U"SWRU",U"example/texture/short_prism_white.png");
    TextureAsset::Register(U"SWRH",U"example/texture/short_prism_white_α.png");

    Myapp manager;
    
    manager
        .add<Title>(State::Title)
        .add<Game>(State::Game)
        .add<Result>(State::Result)
        .setFadeColor(ColorF(1.0));
    
	while (System::Update())
	{
        if(!manager.update())
        {
            break;
        }
	}
}
