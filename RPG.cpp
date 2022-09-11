#include "DxLib.h"
#include <stdio.h>
#define WD 200

#pragma warning(disable : 4996)

/*セーブデータ*/
struct save_data
{
	int haikeiflag=0;
	int yushax=220, yushay=120;
	int goburinflag=0;
	int enemycount=4;
	int bossflag = 0;
	int majoflag = 0;
	int suraimuflag = 0;
	int flowerflag = 0;
};
struct save_data data;

/*プレイヤー*/
int yushagraph,yushagraph2,yushaw,yushah,yushahp=2,yushaflag;
/*敵*/
int goburinx, goburiny, goburingraph,goburingraph2, goburinw, goburinh, goburinhp = 2/*, goburinflag*/;
int bossx, bossy, bossgraph, bossgraph2, bossw, bossh, bosshp = 5;
int flowerx, flowery, flowergraph, flowergraph2, flowerw, flowerh, flowerhp = 2;
int suraimux, suraimuy, suraimugraph, suraimugraph2, suraimuw, suraimuh, suraimuhp = 2;
int majox, majoy, majograph, majograph2, majow, majoh, majohp = 3;
/*おじいさん*/
int ojiisanx, ojiisany, ojiisangraph, ojiisanw, ojiisanh;
/*背景*/
int haikei0x,haikei0y,haikei0graph;
int haikei1x,haikei1y,haikei1graph;
int haikei2x, haikei2y, haikei2graph;
int haikei3x, haikei3y, haikei3graph;
/*武器*/
int buki0graph;
/*戦闘*/
int sentouhaikeix, sentouhaikeiy,sentouhaikeigraph;
int sentouflag;
/*タイトル・ゲームオーバー*/
int gameoverx, gameovery, gameoverflag, gameovergraph;
/*その他*/
int Cr;
int mousex,mousey,mousetype,mouseflag;
int textboxx,textboxy,textboxgraph;
/*属性*/
int kizokuseigraph;
int hizokuseigraph;
int mizuzokuseigraph;
int hikarizokuseigraph;
int yamizokuseigraph;
int zokuseiflag;
/*サウンド*/
int hizokuseisound;
int kizokuseisound;
int mizuzokuseisound;
int hikarizokuseisound;
int yamizokuseisound;
int bgmsound;
/*セーブ*/
int savedatagraph, savedatax, savedatay,savedataw,savedatah;

int i;


/*プロトタイプ宣言*/
void draw_haikei();
void player_move();
void draw_player();
void goburin_encount();
void goburin_sentou();
void boss_encount();
void boss_sentou();
void majo_encount();
void majo_sentou();
void flower_encount();
void flower_sentou();
void suraimu_encount();
void suraimu_sentou();
void chutoriaru();
void draw_gameovergamen();
void draw_haikei0();
void draw_haikei1();
void draw_haikei2();
void draw_haikei3();
void base_sentou_gamen();
void draw_goburinhp();
void draw_bosshp();
void draw_majohp();
void draw_suraimuhp();
void draw_flowerhp();
void draw_zokusei();
void load_save();
void data_save();
void savehanntei();
void zokusei_hantei();


/*WinMain関数*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	
	/*画面モードの設定*/
	SetGraphMode(640, 480, 32);

	ChangeWindowMode(TRUE);
	
	/*ＤＸライブラリ初期化処理*/
	if (DxLib_Init() == -1) return -1;

	/*グラフィックの描画先を裏画面にセット*/
	SetDrawScreen(DX_SCREEN_BACK);

	load_save();

	/*画像読み込み*/
	yushagraph = LoadGraph("主人公　剣.png");
	
	haikei0graph = LoadGraph("城内①.png");
	haikei0x = 0; haikei0y = 0;

	haikei1graph = LoadGraph("城内②.png");
	haikei1x = 0; haikei1y = 0;

	haikei2graph = LoadGraph("草原③.png");
	haikei2x = 0; haikei2y = 0;

	haikei3graph = LoadGraph("敵城④.png");
	haikei3x = 0; haikei3y = 0;

	goburingraph = LoadGraph("ゴブリン.png");
	goburinx = 70; goburiny = 200;

	bossgraph = LoadGraph("ボス.png");
	bossx = 200; bossy = 100;

	flowergraph = LoadGraph("花.png");
	flowerx = 100; flowery = 300;

	suraimugraph = LoadGraph("スライム.png");
	suraimux = 350; suraimuy = 100;

	majograph = LoadGraph("魔女.png");
	majox = 20; majoy = 40;

	sentouhaikeigraph = LoadGraph("戦闘背景.jpg");
	sentouhaikeix = 0; sentouhaikeiy = 0;

	buki0graph = LoadGraph("剣.png");

	ojiisangraph = LoadGraph("おじいさん.png");
	ojiisanx = 290; ojiisany = 100;

	textboxgraph = LoadGraph("テキストボックス.jpg");
	textboxx = 0; textboxy = 300;

	gameovergraph = LoadGraph("ゲームオーバー.jpg");
	gameoverx = 0; gameovery = 0;

	kizokuseigraph = LoadGraph("木属性.png");

	mizuzokuseigraph = LoadGraph("水属性.png");

	hizokuseigraph = LoadGraph("火属性.png");

	yamizokuseigraph = LoadGraph("闇属性.png");

	hikarizokuseigraph = LoadGraph("光属性.png");

	yushagraph2=LoadGraph("主人公2.png");

	goburingraph2 = LoadGraph("ゴブリン2.png");

	bossgraph2 = LoadGraph("ボス2.png");

	majograph2 = LoadGraph("魔女2.png");

	suraimugraph2 = LoadGraph("スライム2.png");

	flowergraph2 = LoadGraph("花2.png");

	savedatagraph = LoadGraph("セーブアイコン.png");
	savedatax = 525, savedatay = 400;

	/*画像サイズ読み込み*/
	GetGraphSize(yushagraph, &yushaw, &yushah);

	GetGraphSize(goburingraph, &goburinw, &goburinh);

	GetGraphSize(bossgraph, &bossw, &bossh);

	GetGraphSize(flowergraph, &flowerw, &flowerh);

	GetGraphSize(suraimugraph, &suraimuw, &suraimuh);

	GetGraphSize(majograph, &majow, &majoh);

	GetGraphSize(ojiisangraph, &ojiisanw, &ojiisanh);

	GetGraphSize(savedatagraph, &savedataw, &savedatah);

	/*サウンド読み込み*/
	hizokuseisound = LoadSoundMem("炎攻撃.mp3");

	mizuzokuseisound = LoadSoundMem("水攻撃.mp3");

	kizokuseisound = LoadSoundMem("木攻撃.mp3");

	hikarizokuseisound = LoadSoundMem("光攻撃.mp3");

	yamizokuseisound = LoadSoundMem("闇攻撃.mp3");

	bgmsound = LoadSoundMem("開始時のBGM.mp3");

	
	Cr = GetColor(255, 255, 255);

	
	while (1)
	{
		/*画面を初期化(真っ黒にする)*/
		ClearDrawScreen();

		if (gameoverflag == 0)
		{
			if (sentouflag == 0)
			{
				draw_haikei();

				player_move();

				draw_player();

				chutoriaru();
			
				PlaySoundMem(bgmsound,DX_PLAYTYPE_LOOP, FALSE);
				
				goburin_encount();

				boss_encount();

				majo_encount();

				suraimu_encount();

				flower_encount();

				savehanntei();
			}
		}
		else
		{
			draw_gameovergamen();
		}
		
		/*裏画面の内容を表画面にコピーする*/
		ScreenFlip();

		/*Windows 特有の面倒な処理をＤＸライブラリにやらせる*/
		/*-1 が返ってきたらループを抜ける*/
		if (ProcessMessage() < 0) break;

		/*もしＥＳＣキーが押されていたらループから抜ける*/
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}

	DxLib_End();				/*ＤＸライブラリ使用の終了処理*/

	return 0;					/*ソフトの終了*/
}




/*背景を表示（分岐）*/
void draw_haikei()
{
	switch (data.haikeiflag)
	{
		case 0:
		{
			draw_haikei0();
			break;
		}
		case 1:
		{
			draw_haikei1();
			break;
		}
		case 2:
		{
			draw_haikei2();
			break;
		}
		case 3:
		{
			draw_haikei3();
			break;
		}
	}
}

/*プレイヤーの動きを操作する*/
void player_move()
{
	if (CheckHitKey(KEY_INPUT_UP) == 1)  data.yushay -= 3;

	if (CheckHitKey(KEY_INPUT_DOWN) == 1) data.yushay += 3;

	if (CheckHitKey(KEY_INPUT_LEFT) == 1) data.yushax -= 3;

	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) data.yushax += 3;

	if (data.haikeiflag == 0)
	{
		if (data.yushax < 0)
		{
			data.yushax = 0; 
		}
		if (data.yushax > 492-yushaw)
		{
			data.yushax = 492-yushaw;
		}
		if (data.yushay < 0)
		{
			data.yushay = 0;
		}
		if (data.yushay > 480 - yushah)
		{
			data.haikeiflag = 1;
			data.yushax = 340; data.yushay = 0; 
		}
	}

	if (data.haikeiflag == 1)
	{
		if (data.yushax < 0)
		{
			data.haikeiflag = 2;
			data.yushax = 450; data.yushay = 200;
		}
		if (data.yushax > 492-yushaw)
		{
			data.yushax = 492 - yushaw;
		}
		if (data.yushay < 0)
		{
			data.haikeiflag = 0;
			data.yushax = 220; data.yushay = 480-yushah;
		}
		if (data.yushay > 480 - yushah)
		{
			data.yushay = 480 - yushah;
		}
	}

	if (data.haikeiflag == 2)
	{
		if (data.yushax < 0)
		{
			data.yushax = 0;
		}
		if (data.yushax > 492 - yushaw)
		{
			data.haikeiflag = 1;
			data.yushax = 0; data.yushay = 200;
		}
		if (data.yushay < 0)
		{
			if (data.enemycount == 0)
			{
				data.haikeiflag = 3;
				data.yushax = 220; data.yushay = 480 - yushah;
			}
			else
			{
				data.yushay = 0;
			}
		}
		if (data.yushay > 480 - yushah)
		{
			data.yushay = 480 - yushah;
		}
	}

	if (data.haikeiflag == 3)
	{
		if (data.yushax < 0)
		{
			data.yushax = 0;
		}
		if (data.yushax > 492 - yushaw)
		{
			data.yushax = 492 - yushaw;
		}
		if (data.yushay < 0)
		{
			data.yushay = 0;
		}
		if (data.yushay > 480 - yushah)
		{
			data.haikeiflag = 2;
			data.yushax = 30; data.yushay= 0;
		}
	}

}

/*プレイヤーを表示する*/
void draw_player()
{
	DrawGraph(data.yushax, data.yushay, yushagraph, TRUE);
}

/*ゴブリンとの当たり判定*/
void goburin_encount()
{
	if (data.haikeiflag == 1)
	{
		if (data.goburinflag == 0)
		{
			if (((goburinx < data.yushax) && (data.yushax < (goburinx + goburinw))) &&
				((goburiny < data.yushay) && (data.yushay < (goburiny + goburinh))))
			{
				GetMousePoint(&mousex, &mousey);
				if (((goburinx < mousex) && (mousex < (goburinx + goburinw))) &&
					((goburiny < mousey) && (mousey < (goburiny + goburinh))))
				{
					mousetype = GetMouseInput();
					if ((mousetype & MOUSE_INPUT_LEFT) != 0)
					{
						mouseflag = 1;
					}
					if (mouseflag == 1)
					{
						sentouflag = 1;
						StopSoundMem(bgmsound);
						goburin_sentou();
					}
				}
			}
		}
	}
}

/*ゴブリンとの戦闘*/
void goburin_sentou()
{
	while ((sentouflag == 1)&&(gameoverflag==0))
	{
		ClearDrawScreen();
		base_sentou_gamen();
		DrawGraph(230, 60, goburingraph2, TRUE);
		DrawGraph(240, 280, yushagraph2, TRUE);
		DrawGraph(140, 15, kizokuseigraph, TRUE);
		draw_goburinhp();
		ScreenFlip();
		i = 0;
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			while (i == 0)
			{
				ClearDrawScreen();
				DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
				DrawGraph(230, 60, goburingraph2, TRUE);
				DrawGraph(240, 280, yushagraph2, TRUE);
				DrawGraph(140, 15, kizokuseigraph, TRUE);
				draw_goburinhp();
				draw_zokusei();
				ScreenFlip();
				if (CheckHitKey(KEY_INPUT_C) == 1)
				{
					ClearDrawScreen();
					goburinhp--;
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					PlaySoundMem(hizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_goburinhp();
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (goburinhp == 0)
					{
						if (yushaflag == 0)
						{
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(240, 280, yushagraph2, TRUE);
							DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
							DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
							sentouflag = 0;
							data.goburinflag = 1;
							yushahp = 2;
							data.enemycount--;
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_D) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					PlaySoundMem(mizuzokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_goburinhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 160, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, goburingraph2, TRUE);
						DrawGraph(140, 15, kizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * goburinhp / 2, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_E) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					PlaySoundMem(kizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_goburinhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 160, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, goburingraph2, TRUE);
						DrawGraph(140, 15, kizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * goburinhp / 2, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_F) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					PlaySoundMem(hikarizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_goburinhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 160, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, goburingraph2, TRUE);
						DrawGraph(140, 15, kizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * goburinhp / 2, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_G) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					PlaySoundMem(yamizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_goburinhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 60, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_goburinhp();
					DrawGraph(230, 160, goburingraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, kizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, goburingraph2, TRUE);
						DrawGraph(140, 15, kizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * goburinhp / 2, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_B) == 1)
		{
			ScreenFlip();
			WaitTimer(2000);
			ClearDrawScreen();
			base_sentou_gamen();
			DrawGraph(300, 100, goburingraph2, TRUE);
			DrawGraph(380, 80, kizokuseigraph, TRUE);
			sentouflag = 0;
			mouseflag = 0;
			goburinhp = 2;
			yushahp = 2;
		}
	}
}

/*ボスとの当たり判定*/
void boss_encount()
{
	if (data.haikeiflag == 3)
	{
		if (data.bossflag == 0)
		{
			if (((bossx < data.yushax) && (data.yushax < (bossx + bossw))) &&
				((bossy < data.yushay) && (data.yushay < (bossy + bossh))))
			{
				GetMousePoint(&mousex, &mousey);
				if (((bossx < mousex) && (mousex < (bossx + bossw))) &&
					((bossy < mousey) && (mousey < (bossy + bossh))))
				{
					mousetype = GetMouseInput();
					if ((mousetype & MOUSE_INPUT_LEFT) != 0)
					{
						mouseflag = 1;
					}
					if (mouseflag == 1)
					{
						sentouflag = 1;
						StopSoundMem(bgmsound);
						boss_sentou();
					}
				}
			}
		}
	}
}

/*ボスとの戦闘*/
void boss_sentou()
{
	while ((sentouflag == 1) && (gameoverflag == 0))
	{
		ClearDrawScreen();
		base_sentou_gamen();
		DrawGraph(230, 60, bossgraph2, TRUE);
		DrawGraph(240, 280, yushagraph2, TRUE);
		zokusei_hantei();
		draw_bosshp();
		ScreenFlip();
		i = 0;
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			while (i == 0)
			{
				ClearDrawScreen();
				DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
				DrawGraph(230, 60, bossgraph2, TRUE);
				DrawGraph(240, 280, yushagraph2, TRUE);
				zokusei_hantei();
				draw_bosshp();
				draw_zokusei();
				ScreenFlip();
				if (CheckHitKey(KEY_INPUT_C) == 1)
				{
					if (zokuseiflag == 2)
					{
						ClearDrawScreen();
						bosshp--;
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(hizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						zokuseiflag = GetRand(4);
						if (bosshp == 0)
						{
							if (yushaflag == 0)
							{
								ClearDrawScreen();
								base_sentou_gamen();
								DrawGraph(240, 280, yushagraph2, TRUE);
								DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
								DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
								ScreenFlip();
								WaitTimer(2000);
								sentouflag = 0;
								data.bossflag = 1;
								yushahp = 2;
							}
						}
					}
					else
					{
						ClearDrawScreen();
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(hizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						yushahp -= 2;
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 160, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						if (yushahp == 0)
						{
							gameoverflag = 1;
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(230, 60, bossgraph2, TRUE);
							zokusei_hantei();
							DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
							DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_D) == 1)
				{
					if (zokuseiflag == 0)
					{
						ClearDrawScreen();
						bosshp--;
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(mizuzokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						zokuseiflag = GetRand(4);
						if (bosshp == 0)
						{
							if (yushaflag == 0)
							{
								ClearDrawScreen();
								base_sentou_gamen();
								DrawGraph(240, 280, yushagraph2, TRUE);
								DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
								DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
								ScreenFlip();
								WaitTimer(2000);
								sentouflag = 0;
								data.bossflag = 1;
								yushahp = 2;
							}
						}
					}
					else
					{
						ClearDrawScreen();
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(mizuzokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						yushahp -= 2;
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 160, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						if (yushahp == 0)
						{
							gameoverflag = 1;
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(230, 60, bossgraph2, TRUE);
							DrawGraph(140, 15, yamizokuseigraph, TRUE);
							DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
							DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_E) == 1)
				{
					if (zokuseiflag == 1)
					{
						ClearDrawScreen();
						bosshp--;
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(kizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						zokuseiflag = GetRand(4);
						if (bosshp == 0)
						{
							if (yushaflag == 0)
							{
								ClearDrawScreen();
								base_sentou_gamen();
								DrawGraph(240, 280, yushagraph2, TRUE);
								DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
								DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
								ScreenFlip();
								WaitTimer(2000);
								sentouflag = 0;
								data.bossflag = 1;
								yushahp = 2;
							}
						}
					}
					else
					{
						ClearDrawScreen();
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(kizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						yushahp -= 2;
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 160, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						if (yushahp == 0)
						{
							gameoverflag = 1;
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(230, 60, bossgraph2, TRUE);
							zokusei_hantei();
							DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
							DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_F) == 1)
				{
					if (zokuseiflag == 4)
					{
						ClearDrawScreen();
						bosshp--;
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(hikarizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						zokuseiflag = GetRand(4);
						if (bosshp == 0)
						{
							if (yushaflag == 0)
							{
								ClearDrawScreen();
								base_sentou_gamen();
								DrawGraph(240, 280, yushagraph2, TRUE);
								DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
								DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
								ScreenFlip();
								WaitTimer(2000);
								sentouflag = 0;
								data.bossflag = 1;
								yushahp = 2;
							}
						}
					}
					else
					{
						ClearDrawScreen();
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(hikarizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						yushahp -= 2;
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 160, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						if (yushahp == 0)
						{
							gameoverflag = 1;
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(230, 60, bossgraph2, TRUE);
							zokusei_hantei();
							DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
							DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_G) == 1)
				{
					if (zokuseiflag == 3)
					{
						ClearDrawScreen();
						bosshp--;
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(yamizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						zokuseiflag = GetRand(4);
						if (bosshp == 0)
						{
							if (yushaflag == 0)
							{
								ClearDrawScreen();
								base_sentou_gamen();
								DrawGraph(240, 280, yushagraph2, TRUE);
								DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
								DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
								ScreenFlip();
								WaitTimer(2000);
								sentouflag = 0;
								data.bossflag = 1;
								yushahp = 2;
							}
						}
					}
					else
					{
						ClearDrawScreen();
						DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 180, yushagraph2, TRUE);
						zokusei_hantei();
						PlaySoundMem(yamizokuseisound, DX_PLAYTYPE_BACK, TRUE);
						draw_zokusei();
						draw_bosshp();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 60, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						ClearDrawScreen();
						yushahp -= 2;
						base_sentou_gamen();
						draw_bosshp();
						DrawGraph(230, 160, bossgraph2, TRUE);
						DrawGraph(240, 280, yushagraph2, TRUE);
						zokusei_hantei();
						ScreenFlip();
						WaitTimer(1000);
						i = 1;
						if (yushahp == 0)
						{
							gameoverflag = 1;
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(230, 60, bossgraph2, TRUE);
							zokusei_hantei();
							DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
							DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_B) == 1)
		{
			ScreenFlip();
			WaitTimer(2000);
			ClearDrawScreen();
			base_sentou_gamen();
			DrawGraph(300, 100, bossgraph2, TRUE);
			zokusei_hantei();
			sentouflag = 0;
			mouseflag = 0;
			bosshp = 5;
			yushahp = 2;
		}
	}
}

/*魔女との当たり判定*/
void majo_encount()
{
	if (data.haikeiflag == 2)
	{
		if (data.majoflag == 0)
		{
			if (((majox < data.yushax) && (data.yushax < (majox + majow))) &&
				((majoy < data.yushay) && (data.yushay < (majoy + majoh))))
			{
				GetMousePoint(&mousex, &mousey);
				if (((majox < mousex) && (mousex < (majox + majow))) &&
					((majoy < mousey) && (mousey < (majoy + majoh))))
				{
					mousetype = GetMouseInput();
					if ((mousetype & MOUSE_INPUT_LEFT) != 0)
					{
						mouseflag = 1;
					}
					if (mouseflag == 1)
					{
						sentouflag = 1;
						StopSoundMem(bgmsound);
						majo_sentou();
					}
				}
			}
		}
	}
}

/*魔女との戦闘*/
void majo_sentou()
{
	while ((sentouflag == 1) && (gameoverflag == 0))
	{
		ClearDrawScreen();
		base_sentou_gamen();
		DrawGraph(230, 60, majograph2, TRUE);
		DrawGraph(240, 280, yushagraph2, TRUE);
		DrawGraph(140, 15, mizuzokuseigraph, TRUE);
		draw_majohp();
		ScreenFlip();
		i = 0;
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			while (i == 0)
			{
				ClearDrawScreen();
				DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
				DrawGraph(230, 60, majograph2, TRUE);
				DrawGraph(240, 280, yushagraph2, TRUE);
				DrawGraph(140, 15, mizuzokuseigraph, TRUE);
				draw_majohp();
				draw_zokusei();
				ScreenFlip();
				if (CheckHitKey(KEY_INPUT_C) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					PlaySoundMem(hizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_majohp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 160, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, majograph2, TRUE);
						DrawGraph(140, 15, mizuzokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * majohp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_D) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					PlaySoundMem(mizuzokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_majohp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 160, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, majograph2, TRUE);
						DrawGraph(140, 15, mizuzokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * majohp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_E) == 1)
				{
					ClearDrawScreen();
					majohp--;
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					PlaySoundMem(kizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_majohp();
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (majohp == 0)
					{
						if (yushaflag == 0)
						{
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(240, 280, yushagraph2, TRUE);
							DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
							DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
							sentouflag = 0;
							data.majoflag = 1;
							yushahp = 2;
							data.enemycount--;
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_F) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					PlaySoundMem(hikarizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_majohp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 160, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, majograph2, TRUE);
						DrawGraph(140, 15, mizuzokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * majohp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_G) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					PlaySoundMem(yamizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_majohp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 60, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_majohp();
					DrawGraph(230, 160, majograph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, mizuzokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, majograph2, TRUE);
						DrawGraph(140, 15, mizuzokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * majohp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_B) == 1)
		{
			ScreenFlip();
			WaitTimer(2000);
			ClearDrawScreen();
			base_sentou_gamen();
			DrawGraph(300, 100, majograph2, TRUE);
			DrawGraph(380, 80, mizuzokuseigraph, TRUE);
			sentouflag = 0;
			mouseflag = 0;
			majohp = 3;
			yushahp = 2;
		}
	}
}

/*スライムとの当たり判定*/
void suraimu_encount()
{
	if (data.haikeiflag == 2)
	{
		if (data.suraimuflag == 0)
		{
			if (((suraimux < data.yushax) && (data.yushax < (suraimux + suraimuw))) &&
				((suraimuy < data.yushay) && (data.yushay < (suraimuy + suraimuh))))
			{
				GetMousePoint(&mousex, &mousey);
				if (((suraimux < mousex) && (mousex < (suraimux + suraimuw))) &&
					((suraimuy < mousey) && (mousey < (suraimuy + suraimuh))))
				{
					mousetype = GetMouseInput();
					if ((mousetype & MOUSE_INPUT_LEFT) != 0)
					{
						mouseflag = 1;
					}
					if (mouseflag == 1)
					{
						sentouflag = 1;
						StopSoundMem(bgmsound);
						suraimu_sentou();
					}
				}
			}
		}
	}
}

/*スライムとの戦闘*/
void suraimu_sentou()
{
	while ((sentouflag == 1) && (gameoverflag == 0))
	{
		ClearDrawScreen();
		base_sentou_gamen();
		DrawGraph(230, 60, suraimugraph2, TRUE);
		DrawGraph(240, 280, yushagraph2, TRUE);
		DrawGraph(140, 15, hikarizokuseigraph, TRUE);
		draw_suraimuhp();
		ScreenFlip();
		i = 0;
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			while (i == 0)
			{
				ClearDrawScreen();
				DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
				DrawGraph(230, 60, suraimugraph2, TRUE);
				DrawGraph(240, 280, yushagraph2, TRUE);
				DrawGraph(140, 15, hikarizokuseigraph, TRUE);
				draw_suraimuhp();
				draw_zokusei();
				ScreenFlip();
				if (CheckHitKey(KEY_INPUT_C) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					PlaySoundMem(hizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_suraimuhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 160, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, suraimugraph2, TRUE);
						DrawGraph(140, 15, hikarizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * suraimuhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_D) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					PlaySoundMem(mizuzokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_suraimuhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 160, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, suraimugraph2, TRUE);
						DrawGraph(140, 15, hikarizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * suraimuhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_E) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					PlaySoundMem(kizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_suraimuhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 160, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, suraimugraph2, TRUE);
						DrawGraph(140, 15, hikarizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * suraimuhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_F) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					PlaySoundMem(hikarizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_suraimuhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_suraimuhp();
					DrawGraph(230, 160, suraimugraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, suraimugraph2, TRUE);
						DrawGraph(140, 15, hikarizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * suraimuhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_G) == 1)
				{
					ClearDrawScreen();
					suraimuhp--;
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, suraimugraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hikarizokuseigraph, TRUE);
					PlaySoundMem(yamizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_suraimuhp();
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (suraimuhp == 0)
					{
						if (yushaflag == 0)
						{
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(240, 280, yushagraph2, TRUE);
							DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
							DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
							sentouflag = 0;
							data.suraimuflag = 1;
							yushahp = 2;
							data.enemycount--;
						}
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_B) == 1)
		{
			ScreenFlip();
			WaitTimer(2000);
			ClearDrawScreen();
			base_sentou_gamen();
			DrawGraph(300, 100, suraimugraph2, TRUE);
			DrawGraph(380, 80, hikarizokuseigraph, TRUE);
			sentouflag = 0;
			mouseflag = 0;
			suraimuhp = 2;
			yushahp = 2;
		}
	}
}

/*花との当たり判定*/
void flower_encount()
{
	if (data.haikeiflag == 2)
	{
		if (data.flowerflag == 0)
		{
			if (((flowerx < data.yushax) && (data.yushax < (flowerx + flowerw))) &&
				((flowery < data.yushay) && (data.yushay < (flowery + flowerh))))
			{
				GetMousePoint(&mousex, &mousey);
				if (((flowerx < mousex) && (mousex < (flowerx + flowerw))) &&
					((flowery < mousey) && (mousey < (flowery + flowerh))))
				{
					mousetype = GetMouseInput();
					if ((mousetype & MOUSE_INPUT_LEFT) != 0)
					{
						mouseflag = 1;
					}
					if (mouseflag == 1)
					{
						sentouflag = 1;
						StopSoundMem(bgmsound);
						flower_sentou();
					}
				}
			}
		}
	}
}

/*花との戦闘*/
void flower_sentou()
{
	while ((sentouflag == 1) && (gameoverflag == 0))
	{
		ClearDrawScreen();
		base_sentou_gamen();
		DrawGraph(230, 60, flowergraph2, TRUE);
		DrawGraph(240, 280, yushagraph2, TRUE);
		DrawGraph(140, 15, hizokuseigraph, TRUE);
		draw_flowerhp();
		ScreenFlip();
		i = 0;
		if (CheckHitKey(KEY_INPUT_A) == 1)
		{
			while (i == 0)
			{
				ClearDrawScreen();
				DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
				DrawGraph(230, 60, flowergraph2, TRUE);
				DrawGraph(240, 280, yushagraph2, TRUE);
				DrawGraph(140, 15, hizokuseigraph, TRUE);
				draw_flowerhp();
				draw_zokusei();
				ScreenFlip();
				if (CheckHitKey(KEY_INPUT_C) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					PlaySoundMem(hizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_flowerhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 160, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, flowergraph2, TRUE);
						DrawGraph(140, 15, hizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * flowerhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_D) == 1)
				{
					ClearDrawScreen();
					flowerhp--;
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					PlaySoundMem(mizuzokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_flowerhp();
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (flowerhp == 0)
					{
						if (yushaflag == 0)
						{
							ClearDrawScreen();
							base_sentou_gamen();
							DrawGraph(240, 280, yushagraph2, TRUE);
							DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
							DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
							ScreenFlip();
							WaitTimer(2000);
							sentouflag = 0;
							data.flowerflag = 1;
							yushahp = 2;
							data.enemycount--;
						}
					}
				}
				if (CheckHitKey(KEY_INPUT_E) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					PlaySoundMem(kizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_flowerhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 160, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, flowergraph2, TRUE);
						DrawGraph(140, 15, hizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * flowerhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_F) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					PlaySoundMem(hikarizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_flowerhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 160, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, flowergraph2, TRUE);
						DrawGraph(140, 15, hizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * flowerhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
				if (CheckHitKey(KEY_INPUT_G) == 1)
				{
					ClearDrawScreen();
					DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph, FALSE);
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 180, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					PlaySoundMem(yamizokuseisound, DX_PLAYTYPE_BACK, TRUE);
					draw_zokusei();
					draw_flowerhp();
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 60, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					ClearDrawScreen();
					yushahp--;
					base_sentou_gamen();
					draw_flowerhp();
					DrawGraph(230, 160, flowergraph2, TRUE);
					DrawGraph(240, 280, yushagraph2, TRUE);
					DrawGraph(140, 15, hizokuseigraph, TRUE);
					ScreenFlip();
					WaitTimer(1000);
					i = 1;
					if (yushahp == 0)
					{
						gameoverflag = 1;
						ClearDrawScreen();
						base_sentou_gamen();
						DrawGraph(230, 60, flowergraph2, TRUE);
						DrawGraph(140, 15, hizokuseigraph, TRUE);
						DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
						DrawBox(220, 30, 220 + WD * flowerhp / 5, 50, GetColor(255, 0, 0), TRUE);
						ScreenFlip();
						WaitTimer(2000);
					}
				}
			}
		}
		if (CheckHitKey(KEY_INPUT_B) == 1)
		{
			ScreenFlip();
			WaitTimer(2000);
			ClearDrawScreen();
			base_sentou_gamen();
			DrawGraph(300, 100, flowergraph2, TRUE);
			DrawGraph(380, 80, hizokuseigraph, TRUE);
			sentouflag = 0;
			mouseflag = 0;
			flowerhp = 2;
			yushahp = 2;
		}
	}
}

/*チュートリアル*/
void chutoriaru()
{
	if (data.haikeiflag == 0)
	{
		if (((ojiisanx < data.yushax) && (data.yushax < (ojiisanx + ojiisanw))) &&
			((ojiisany < data.yushay) && (data.yushay < (ojiisany + ojiisanh))))
		{
			GetMousePoint(&mousex, &mousey);
			if (((ojiisanx < mousex) && (mousex < (ojiisanx + ojiisanw))) &&
				((ojiisany < mousey) && (mousey < (ojiisany + ojiisanh))))
			{
				mousetype = GetMouseInput();
				if ((mousetype & MOUSE_INPUT_LEFT) != 0)
				{
					DrawGraph(textboxx, textboxy, textboxgraph, FALSE);
					DrawString(45, 335, "敵にはそれぞれ弱点があるので、それを見極める必要があります", Cr);
					ScreenFlip();
					WaitTimer(4000);
				}
			}
		}
	}
}

/*ゲームオーバー画面を表示する*/
void draw_gameovergamen()
{
	DrawGraph(gameoverx, gameovery, gameovergraph, FALSE);
	ScreenFlip();
	WaitTimer(2000);
	DxLib_End();
}

/*城内①を表示*/
void draw_haikei0()
{
	DrawGraph(haikei0x, haikei0y, haikei0graph, FALSE);
	DrawGraph(ojiisanx, ojiisany, ojiisangraph, TRUE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540,435, "セーブ",GetColor(255,255,255));
	DrawFormatString(494, 200, Cr, "残りの雑魚敵…%d体", data.enemycount);
	DrawString(494, 250, "<操作説明>", Cr);
	DrawString(494, 280, "移動…↑↓←→\n\n会話、戦闘…近づ\nいて対象を左クリ\nック", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	DrawGraph(ojiisanx, ojiisany, ojiisangraph, TRUE);
}

/*城内②を表示*/
void draw_haikei1()
{
	DrawGraph(haikei1x, haikei1y, haikei1graph, FALSE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540, 435, "セーブ", GetColor(255, 255, 255));
	DrawFormatString(494, 200, Cr, "残りの雑魚敵…%d体", data.enemycount);
	DrawString(494, 250, "<操作説明>", Cr);
	DrawString(494, 280, "移動…↑↓←→\n\n会話、戦闘…近づ\nいて対象を左クリ\nック", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	if (data.goburinflag == 0)
	{
		DrawGraph(goburinx, goburiny, goburingraph, TRUE);
	}
}

/*草原③を表示*/
void draw_haikei2()
{
	DrawGraph(haikei2x, haikei2y, haikei2graph, FALSE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540, 435, "セーブ", GetColor(255, 255, 255));
	DrawFormatString(494, 200, Cr, "残りの雑魚敵…%d体", data.enemycount);
	DrawString(494, 250, "<操作説明>", Cr);
	DrawString(494, 280, "移動…↑↓←→\n\n会話、戦闘…近づ\nいて対象を左クリ\nック", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	if (data.majoflag == 0)
	{
		DrawGraph(majox, majoy, majograph, TRUE);
	}
	if (data.suraimuflag == 0)
	{
		DrawGraph(suraimux, suraimuy, suraimugraph, TRUE);
	}
	if (data.flowerflag == 0)
	{
		DrawGraph(flowerx, flowery, flowergraph, TRUE);
	}
}

/*敵城④を表示*/
void draw_haikei3()
{
	DrawGraph(haikei3x, haikei3y, haikei3graph, FALSE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540, 435, "セーブ", GetColor(255, 255, 255));
	DrawFormatString(494, 200, Cr, "残りの雑魚敵…%d体", data.enemycount);
	DrawString(494, 250, "<操作説明>", Cr);
	DrawString(494, 280, "移動…↑↓←→\n\n会話、戦闘…近づ\nいて対象を左クリ\nック", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	if (data.bossflag == 0)
	{
		DrawGraph(bossx, bossy, bossgraph, TRUE);
	}
}



/*戦闘画面の雛形*/
void base_sentou_gamen()
{
	DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph,FALSE);
	DrawString(44, 300, "A たたかう", Cr);
	DrawString(44, 350, "B にげる", Cr);
}

/*ゴブリンHP*/
void draw_goburinhp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * goburinhp / 2, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*ボスHP*/
void draw_bosshp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*魔女HP*/
void draw_majohp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * majohp / 3, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*スライムHP*/
void draw_suraimuhp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * suraimuhp / 2, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*花HP*/
void draw_flowerhp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * flowerhp / 2, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*属性*/
void draw_zokusei()
{
	DrawString(44, 285, "C 火", GetColor(255, 0, 0));
	DrawString(44, 315, "D 水", GetColor(0, 0, 255));
	DrawString(44, 345, "E 木", GetColor(0, 255, 0));
	DrawString(44, 375, "F 光", GetColor(255, 255, 0));
	DrawString(44, 405, "G 闇", GetColor(128, 0, 128));
}

/*ロード*/
void load_save()
{
	FILE* fp;
	fp = fopen("savedata.dat", "rb");
	if (fp == NULL);
	else
	{
		fread(&data, sizeof(data), 5, fp);
		fclose(fp);
	}
}

/*セーブ*/
void data_save()
{
	FILE* fp;
	fp = fopen("savedata.dat", "wb");
	if (fp == NULL)return;
	fwrite(&data, sizeof(data), 5, fp);
	fclose(fp);
}

/*セーブ判定*/
void savehanntei()
{
	if (sentouflag == 0)
	{
		if (gameoverflag == 0)
		{
			GetMousePoint(&mousex, &mousey);
			if (((savedatax < mousex) && (mousex < (savedatax + savedataw))) &&
				((savedatay < mousey) && (mousey < (savedatay + savedatah))))
			{
				mousetype = GetMouseInput();
				if ((mousetype & MOUSE_INPUT_LEFT) != 0)
				{
					mouseflag = 1;
				}
				if (mouseflag == 1)
				{
					data_save();
				}
			}
		}
	}
}

/*ボスの属性判定*/
void zokusei_hantei()
{
	switch (zokuseiflag)
	{
		case 0:
			DrawGraph(140, 15, hizokuseigraph, TRUE);
			break;
		case 1:
			DrawGraph(140, 15, mizuzokuseigraph, TRUE);
			break;
		case 2:
			DrawGraph(140, 15, kizokuseigraph, TRUE);
			break;
		case 3:
			DrawGraph(140, 15, hikarizokuseigraph, TRUE);
			break;
		case 4:
			DrawGraph(140, 15, yamizokuseigraph, TRUE);
			break;
	}
}