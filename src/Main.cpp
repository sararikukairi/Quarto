
# include "Scene.hpp"
# include "Game.hpp"
# include "Title.hpp"

void Main()
{
    Scene::SetBackground(ColorF(0.2, 0.8, 0.4));
    FontAsset::Register(U"Title", 120, Typeface::Heavy);
    FontAsset::Register(U"Menu", 30, Typeface::Regular);
    FontAsset::Register(U"Score", 36, Typeface::Bold);
    
    Myapp manager;
    
    manager
        .add<Title>(State::Title)
        .add<Game>(State::Game)
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
