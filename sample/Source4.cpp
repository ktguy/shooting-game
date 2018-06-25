#include "DxLib.h"

int player, enemy, shot;
int px = 288;
int ex = 0, es = 8;
int sx, sy;
bool sf = false;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();	// DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);
	
	player = LoadGraph("player.bmp");
	enemy = LoadGraph("player.bmp");
	shot = LoadGraph("shot.bmp");
	
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
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			if (!sf) {
				sf = true;
				sx = px + 24;
				sy = 400;
			}
		}

		ex += es;
		if (ex <= 0 || ex >= 640 - 64) es = -es;
		
		if (sf) {
			sy -= 16;
			if (sy < 0) sf = false;
		}

		if (sf) DrawGraph(sx, sy, shot, FALSE);
		DrawGraph(px, 400, player, FALSE);
		DrawGraph(ex, 16, enemy, FALSE);
		ScreenFlip();
	}
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}