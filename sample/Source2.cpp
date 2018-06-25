#include "DxLib.h"

int player;
int px = 288;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();	// DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);
	player = LoadGraph("player.bmp");
	while (!ProcessMessage()) {
		ClearDrawScreen();
		if (CheckHitKey(KEY_INPUT_LEFT)) px -= 8;
		if (CheckHitKey(KEY_INPUT_RIGHT)) px += 8;
		DrawGraph(px, 400, player, FALSE);
		ScreenFlip();
	}
	DxLib_End();	// DXライブラリ終了処理
	return 0;
}