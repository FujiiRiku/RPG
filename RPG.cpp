#include "DxLib.h"
#include <stdio.h>
#define WD 200

#pragma warning(disable : 4996)

/*�Z�[�u�f�[�^*/
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

/*�v���C���[*/
int yushagraph,yushagraph2,yushaw,yushah,yushahp=2,yushaflag;
/*�G*/
int goburinx, goburiny, goburingraph,goburingraph2, goburinw, goburinh, goburinhp = 2/*, goburinflag*/;
int bossx, bossy, bossgraph, bossgraph2, bossw, bossh, bosshp = 5;
int flowerx, flowery, flowergraph, flowergraph2, flowerw, flowerh, flowerhp = 2;
int suraimux, suraimuy, suraimugraph, suraimugraph2, suraimuw, suraimuh, suraimuhp = 2;
int majox, majoy, majograph, majograph2, majow, majoh, majohp = 3;
/*����������*/
int ojiisanx, ojiisany, ojiisangraph, ojiisanw, ojiisanh;
/*�w�i*/
int haikei0x,haikei0y,haikei0graph;
int haikei1x,haikei1y,haikei1graph;
int haikei2x, haikei2y, haikei2graph;
int haikei3x, haikei3y, haikei3graph;
/*����*/
int buki0graph;
/*�퓬*/
int sentouhaikeix, sentouhaikeiy,sentouhaikeigraph;
int sentouflag;
/*�^�C�g���E�Q�[���I�[�o�[*/
int gameoverx, gameovery, gameoverflag, gameovergraph;
/*���̑�*/
int Cr;
int mousex,mousey,mousetype,mouseflag;
int textboxx,textboxy,textboxgraph;
/*����*/
int kizokuseigraph;
int hizokuseigraph;
int mizuzokuseigraph;
int hikarizokuseigraph;
int yamizokuseigraph;
int zokuseiflag;
/*�T�E���h*/
int hizokuseisound;
int kizokuseisound;
int mizuzokuseisound;
int hikarizokuseisound;
int yamizokuseisound;
int bgmsound;
/*�Z�[�u*/
int savedatagraph, savedatax, savedatay,savedataw,savedatah;

int i;


/*�v���g�^�C�v�錾*/
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


/*WinMain�֐�*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	
	/*��ʃ��[�h�̐ݒ�*/
	SetGraphMode(640, 480, 32);

	ChangeWindowMode(TRUE);
	
	/*�c�w���C�u��������������*/
	if (DxLib_Init() == -1) return -1;

	/*�O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g*/
	SetDrawScreen(DX_SCREEN_BACK);

	load_save();

	/*�摜�ǂݍ���*/
	yushagraph = LoadGraph("��l���@��.png");
	
	haikei0graph = LoadGraph("����@.png");
	haikei0x = 0; haikei0y = 0;

	haikei1graph = LoadGraph("����A.png");
	haikei1x = 0; haikei1y = 0;

	haikei2graph = LoadGraph("�����B.png");
	haikei2x = 0; haikei2y = 0;

	haikei3graph = LoadGraph("�G��C.png");
	haikei3x = 0; haikei3y = 0;

	goburingraph = LoadGraph("�S�u����.png");
	goburinx = 70; goburiny = 200;

	bossgraph = LoadGraph("�{�X.png");
	bossx = 200; bossy = 100;

	flowergraph = LoadGraph("��.png");
	flowerx = 100; flowery = 300;

	suraimugraph = LoadGraph("�X���C��.png");
	suraimux = 350; suraimuy = 100;

	majograph = LoadGraph("����.png");
	majox = 20; majoy = 40;

	sentouhaikeigraph = LoadGraph("�퓬�w�i.jpg");
	sentouhaikeix = 0; sentouhaikeiy = 0;

	buki0graph = LoadGraph("��.png");

	ojiisangraph = LoadGraph("����������.png");
	ojiisanx = 290; ojiisany = 100;

	textboxgraph = LoadGraph("�e�L�X�g�{�b�N�X.jpg");
	textboxx = 0; textboxy = 300;

	gameovergraph = LoadGraph("�Q�[���I�[�o�[.jpg");
	gameoverx = 0; gameovery = 0;

	kizokuseigraph = LoadGraph("�ؑ���.png");

	mizuzokuseigraph = LoadGraph("������.png");

	hizokuseigraph = LoadGraph("�Α���.png");

	yamizokuseigraph = LoadGraph("�ő���.png");

	hikarizokuseigraph = LoadGraph("������.png");

	yushagraph2=LoadGraph("��l��2.png");

	goburingraph2 = LoadGraph("�S�u����2.png");

	bossgraph2 = LoadGraph("�{�X2.png");

	majograph2 = LoadGraph("����2.png");

	suraimugraph2 = LoadGraph("�X���C��2.png");

	flowergraph2 = LoadGraph("��2.png");

	savedatagraph = LoadGraph("�Z�[�u�A�C�R��.png");
	savedatax = 525, savedatay = 400;

	/*�摜�T�C�Y�ǂݍ���*/
	GetGraphSize(yushagraph, &yushaw, &yushah);

	GetGraphSize(goburingraph, &goburinw, &goburinh);

	GetGraphSize(bossgraph, &bossw, &bossh);

	GetGraphSize(flowergraph, &flowerw, &flowerh);

	GetGraphSize(suraimugraph, &suraimuw, &suraimuh);

	GetGraphSize(majograph, &majow, &majoh);

	GetGraphSize(ojiisangraph, &ojiisanw, &ojiisanh);

	GetGraphSize(savedatagraph, &savedataw, &savedatah);

	/*�T�E���h�ǂݍ���*/
	hizokuseisound = LoadSoundMem("���U��.mp3");

	mizuzokuseisound = LoadSoundMem("���U��.mp3");

	kizokuseisound = LoadSoundMem("�؍U��.mp3");

	hikarizokuseisound = LoadSoundMem("���U��.mp3");

	yamizokuseisound = LoadSoundMem("�ōU��.mp3");

	bgmsound = LoadSoundMem("�J�n����BGM.mp3");

	
	Cr = GetColor(255, 255, 255);

	
	while (1)
	{
		/*��ʂ�������(�^�����ɂ���)*/
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
		
		/*����ʂ̓��e��\��ʂɃR�s�[����*/
		ScreenFlip();

		/*Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��*/
		/*-1 ���Ԃ��Ă����烋�[�v�𔲂���*/
		if (ProcessMessage() < 0) break;

		/*�����d�r�b�L�[��������Ă����烋�[�v���甲����*/
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
	}

	DxLib_End();				/*�c�w���C�u�����g�p�̏I������*/

	return 0;					/*�\�t�g�̏I��*/
}




/*�w�i��\���i����j*/
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

/*�v���C���[�̓����𑀍삷��*/
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

/*�v���C���[��\������*/
void draw_player()
{
	DrawGraph(data.yushax, data.yushay, yushagraph, TRUE);
}

/*�S�u�����Ƃ̓����蔻��*/
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

/*�S�u�����Ƃ̐퓬*/
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

/*�{�X�Ƃ̓����蔻��*/
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

/*�{�X�Ƃ̐퓬*/
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

/*�����Ƃ̓����蔻��*/
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

/*�����Ƃ̐퓬*/
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

/*�X���C���Ƃ̓����蔻��*/
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

/*�X���C���Ƃ̐퓬*/
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

/*�ԂƂ̓����蔻��*/
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

/*�ԂƂ̐퓬*/
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

/*�`���[�g���A��*/
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
					DrawString(45, 335, "�G�ɂ͂��ꂼ���_������̂ŁA��������ɂ߂�K�v������܂�", Cr);
					ScreenFlip();
					WaitTimer(4000);
				}
			}
		}
	}
}

/*�Q�[���I�[�o�[��ʂ�\������*/
void draw_gameovergamen()
{
	DrawGraph(gameoverx, gameovery, gameovergraph, FALSE);
	ScreenFlip();
	WaitTimer(2000);
	DxLib_End();
}

/*����@��\��*/
void draw_haikei0()
{
	DrawGraph(haikei0x, haikei0y, haikei0graph, FALSE);
	DrawGraph(ojiisanx, ojiisany, ojiisangraph, TRUE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540,435, "�Z�[�u",GetColor(255,255,255));
	DrawFormatString(494, 200, Cr, "�c��̎G���G�c%d��", data.enemycount);
	DrawString(494, 250, "<�������>", Cr);
	DrawString(494, 280, "�ړ��c��������\n\n��b�A�퓬�c�߂�\n���đΏۂ����N��\n�b�N", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	DrawGraph(ojiisanx, ojiisany, ojiisangraph, TRUE);
}

/*����A��\��*/
void draw_haikei1()
{
	DrawGraph(haikei1x, haikei1y, haikei1graph, FALSE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540, 435, "�Z�[�u", GetColor(255, 255, 255));
	DrawFormatString(494, 200, Cr, "�c��̎G���G�c%d��", data.enemycount);
	DrawString(494, 250, "<�������>", Cr);
	DrawString(494, 280, "�ړ��c��������\n\n��b�A�퓬�c�߂�\n���đΏۂ����N��\n�b�N", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	if (data.goburinflag == 0)
	{
		DrawGraph(goburinx, goburiny, goburingraph, TRUE);
	}
}

/*�����B��\��*/
void draw_haikei2()
{
	DrawGraph(haikei2x, haikei2y, haikei2graph, FALSE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540, 435, "�Z�[�u", GetColor(255, 255, 255));
	DrawFormatString(494, 200, Cr, "�c��̎G���G�c%d��", data.enemycount);
	DrawString(494, 250, "<�������>", Cr);
	DrawString(494, 280, "�ړ��c��������\n\n��b�A�퓬�c�߂�\n���đΏۂ����N��\n�b�N", Cr);
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

/*�G��C��\��*/
void draw_haikei3()
{
	DrawGraph(haikei3x, haikei3y, haikei3graph, FALSE);
	DrawGraph(savedatax, savedatay, savedatagraph, TRUE);
	DrawString(540, 435, "�Z�[�u", GetColor(255, 255, 255));
	DrawFormatString(494, 200, Cr, "�c��̎G���G�c%d��", data.enemycount);
	DrawString(494, 250, "<�������>", Cr);
	DrawString(494, 280, "�ړ��c��������\n\n��b�A�퓬�c�߂�\n���đΏۂ����N��\n�b�N", Cr);
	DrawGraph(520, 20, buki0graph, TRUE);
	if (data.bossflag == 0)
	{
		DrawGraph(bossx, bossy, bossgraph, TRUE);
	}
}



/*�퓬��ʂ̐��`*/
void base_sentou_gamen()
{
	DrawGraph(sentouhaikeix, sentouhaikeiy, sentouhaikeigraph,FALSE);
	DrawString(44, 300, "A ��������", Cr);
	DrawString(44, 350, "B �ɂ���", Cr);
}

/*�S�u����HP*/
void draw_goburinhp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * goburinhp / 2, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*�{�XHP*/
void draw_bosshp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * bosshp / 5, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*����HP*/
void draw_majohp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * majohp / 3, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*�X���C��HP*/
void draw_suraimuhp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * suraimuhp / 2, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*��HP*/
void draw_flowerhp()
{
	DrawBox(220, 30, 220 + WD, 50, GetColor(255, 0, 0), FALSE);
	DrawBox(220, 30, 220 + WD * flowerhp / 2, 50, GetColor(255, 0, 0), TRUE);
	DrawBox(220, 440, 220 + WD, 460, GetColor(0, 255, 0), FALSE);
	DrawBox(220, 440, 220 + WD * yushahp / 2, 460, GetColor(0, 255, 0), TRUE);
}

/*����*/
void draw_zokusei()
{
	DrawString(44, 285, "C ��", GetColor(255, 0, 0));
	DrawString(44, 315, "D ��", GetColor(0, 0, 255));
	DrawString(44, 345, "E ��", GetColor(0, 255, 0));
	DrawString(44, 375, "F ��", GetColor(255, 255, 0));
	DrawString(44, 405, "G ��", GetColor(128, 0, 128));
}

/*���[�h*/
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

/*�Z�[�u*/
void data_save()
{
	FILE* fp;
	fp = fopen("savedata.dat", "wb");
	if (fp == NULL)return;
	fwrite(&data, sizeof(data), 5, fp);
	fclose(fp);
}

/*�Z�[�u����*/
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

/*�{�X�̑�������*/
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