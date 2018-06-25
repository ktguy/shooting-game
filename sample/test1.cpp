#include "DxLib.h"

int player, enemy, shot;
int px = 288;
int ex = 0, es = 8;
int sx, sy;
bool sf = false;
int score = 0;
int ball = 3;

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
			if (sy < 0) {
				sf = false;
				ball--;
			}
		}

		if (sf) {
			if (sx + 16 > ex && sx < ex + 64 && sy + 16 > 16 && sy < 16 + 32) {
				sf = false;
				ex = 0;
				score += 100;
				es = 8 + score / 100;
			}
		}

		if (sf) DrawGraph(sx, sy, shot, FALSE);
		DrawGraph(px, 400, player, FALSE);
		DrawGraph(ex, 16, enemy, FALSE);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SCORE : %d ,BALL : %d", score, ball);
		ScreenFlip();
	}
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}