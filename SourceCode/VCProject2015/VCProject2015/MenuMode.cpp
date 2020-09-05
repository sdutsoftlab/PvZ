#include "MenuMode.h"

CStaticSprite Menu::adventure("AdventureGame");		// 冒险模式
CStaticSprite Menu::mini("MiniGame");				// 迷你游戏
CStaticSprite Menu::edu("EduGame");					// 益智模式
CStaticSprite Menu::help_btn("helpBtn");			// 帮助按钮
CStaticSprite Menu::help_msg("helpMsg");			// 帮助消息面板
CStaticSprite Menu::help_close("helpClose");		// 关闭帮助消息
CStaticSprite Menu::exit_("exit");					// 退出游戏

CStaticSprite Menu::achievement("achievement");		// 成就按钮
CStaticSprite Menu::score_board("scoreBoard");		// 成就面板
CStaticSprite Menu::score_close("scoreBoardClose");	// 成就面板

CStaticSprite Menu::level_1("level_1");
CStaticSprite Menu::level_2("level_2");
CStaticSprite Menu::level_3("level_3");
CStaticSprite Menu::level_4("level_4");
CStaticSprite Menu::level_5("level_5");

void Menu::OnMouseMove(const float fMouseX, const float fMouseY) {
	// 根据鼠标位置 显示不同图片
	adventure.SetStaticSpriteImage("AdventureModeImageMap", adventure.IsPointInSprite(fMouseX, fMouseY));
	mini.SetStaticSpriteImage("MiniModeImageMap", mini.IsPointInSprite(fMouseX, fMouseY));
	edu.SetStaticSpriteImage("EduModeImageMap", edu.IsPointInSprite(fMouseX, fMouseY));
	achievement.SetStaticSpriteImage("AchievementImageMap1", achievement.IsPointInSprite(fMouseX, fMouseY));
}

void Menu::OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY) {
	// 点击不同按钮 加载不同地图
	if (!score_board.IsSpriteVisible()) {
		if (adventure.IsPointInSprite(fMouseX, fMouseY)) {
			SuperSound::closeAndPlay("open-click2", "play-click2", "close-click2");
			CSystem::LoadMap("levelChooser.t2d");
			g_GameMain.map_id = CGameMain::MapType::LevelChooserType;
		}
		else if (mini.IsPointInSprite(fMouseX, fMouseY)) {
			SuperSound::closeAndPlay("open-click2", "play-click2", "close-click2");
			// ...
		}
		else if (edu.IsPointInSprite(fMouseX, fMouseY)) {
			SuperSound::closeAndPlay("open-click2", "play-click2", "close-click2");
			CSystem::LoadMap("bowling.t2d");
			g_GameMain.map_id = CGameMain::MapType::BowlingType;
		}

		if (help_btn.IsPointInSprite(fMouseX, fMouseY)) {
			help_msg.SpriteMoveTo(1.094, -5.124, 50, true);
		}
		if (help_close.IsPointInSprite(fMouseX, fMouseY)) {
			help_msg.SpriteMoveTo(-0.198, -64.815, 80, true);
		}
		if (exit_.IsPointInSprite(fMouseX, fMouseY)) {
			exit(0);
		}
	}

	// 成就面板
	if (achievement.IsPointInSprite(fMouseX, fMouseY)) {
		score_board.SetSpriteVisible(true);
		score_close.SetSpriteVisible(true);
		int level1 = GetPrivateProfileInt("level_score", "level_1", 0, "./score.ini");
		int level2 = GetPrivateProfileInt("level_score", "level_2", 0, "./score.ini");
		int level3 = GetPrivateProfileInt("level_score", "level_3", 0, "./score.ini");
		int level4 = GetPrivateProfileInt("level_score", "level_4", 0, "./score.ini");
		int level5 = GetPrivateProfileInt("level_score", "level_5", 0, "./score.ini");
		level_1.SetSpriteVisible(level1 == 1);
		level_2.SetSpriteVisible(level2 == 1);
		level_3.SetSpriteVisible(level3 == 1);
		level_4.SetSpriteVisible(level4 == 1);
		level_5.SetSpriteVisible(level5 == 1);
	}
	if (score_close.IsPointInSprite(fMouseX, fMouseY)) {
		score_board.SetSpriteVisible(false);
		score_close.SetSpriteVisible(false);
		level_1.SetSpriteVisible(false);
		level_2.SetSpriteVisible(false);
		level_3.SetSpriteVisible(false);
		level_4.SetSpriteVisible(false);
		level_5.SetSpriteVisible(false);
	}

}

void Menu::OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY) {}
void Menu::OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress) {}
void Menu::OnKeyUp(const int iKey) {}
void Menu::OnSpriteColSprite(const char* szSrcName, const char* szTarName) {}
void Menu::OnSpriteColWorldLimit(const char* szName, const int iColSide) {}