
# include "Scene.hpp"
# include "Game.hpp"
# include "Title.hpp"
# include "Result.hpp"
void Main()
{
    
    Window::Resize(1088,612);
    
    Scene::SetBackground(ColorF(0.6, 0.8, 0.4));
    
    FontAsset::Register(U"Title", 120, Typeface::Heavy);
    FontAsset::Register(U"Menu", 30, Typeface::Regular);
    FontAsset::Register(U"Score", 36, Typeface::Bold);

    TextureAsset::Register(U"LBCH",U"example/texture/LBCH.png");
    TextureAsset::Register(U"LBCU",U"example/texture/LBCU.png");
    TextureAsset::Register(U"LBRH",U"example/texture/LBRH.png");
    TextureAsset::Register(U"LBRU",U"example/texture/LBRU.png");
    TextureAsset::Register(U"LWCU",U"example/texture/LWCU.png");
    TextureAsset::Register(U"LWCH",U"example/texture/LWCH.png");
    TextureAsset::Register(U"LWRH",U"example/texture/LWRH.png");
    TextureAsset::Register(U"LWRU",U"example/texture/LWRU.png");
    TextureAsset::Register(U"SBCU",U"example/texture/SBCU.png");
    TextureAsset::Register(U"SBRU",U"example/texture/SBRU.png");
    TextureAsset::Register(U"SBRH",U"example/texture/SBRH.png");
    TextureAsset::Register(U"SBCH",U"example/texture/SBCH.png");
    TextureAsset::Register(U"SWCH",U"example/texture/SWCH.png");
    TextureAsset::Register(U"SWCU",U"example/texture/SWCU.png");
    TextureAsset::Register(U"SWRU",U"example/texture/SWRU.png");
    TextureAsset::Register(U"SWRH",U"example/texture/SWRH.png");

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

//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
