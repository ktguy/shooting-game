#include "DxLib.h"

int player, enemy;
int px = 288;
int ex = 0, es = 8;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();	// DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);
	
	player = LoadGraph("player.bmp");
	enemy = LoadGraph("player.bmp");
	
	while (!ProcessMessage()) {
		ClearDrawScreen();
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			px -= 8;
			if (px < 0) px = 0;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			px += 8;
			if (px > 640 - 64) px = 640 - 64;
		}
		ex += es;
		if (ex <= 0 || ex >= 640 - 64) es = -es;
		DrawGraph(px, 400, player, FALSE);
		DrawGraph(ex, 16, enemy, FALSE);
		ScreenFlip();
	}
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}