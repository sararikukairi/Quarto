
# include <Siv3D.hpp> // OpenSiv3D v0.4.1
# include "Scene.hpp"
# include "Game.hpp"
# include "Title.hpp"
# include <HamFramework.hpp>

void Main()
{
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
