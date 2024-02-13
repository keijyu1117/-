#include "DxLib.h"
#include "Enemy.h"
#include "Haikei.h"
#include "game.h"
#include "key.h"
#include "Player.h"

enum GameScene NowGameScene;

int Handle = LoadGraph("data/Title.png");
int Handle2 = LoadGraph("data/a.png");

//�Q�[���V�[���̖��O
char GameSceneName[GameSceneCount][GameSceneNameMax]
{
	
};

//�֐�
//�^�C�g��������
extern VOID TitleInit(VOID)
{
	 

	return;
}

//�^�C�g���Ǘ�
extern bool TitleCtrl(VOID)
{
	auto flg = TitleProc();
	TitleDraw();

	return flg;
}

//�^�C�g������
extern bool TitleProc(VOID)
{

	//�V�[���؂�ւ�
	if (KeyClick(KEY_INPUT_SPACE) == TRUE)
	{
		//�X�y�[�X�L�[�������ꂽ�Ƃ�

		//�V�[��������
		PlayInit();

		//�V�[���؂�ւ�
		NowGameScene = PlayScene;

		//�����ɐ؂�ւ���
		return true;


	}

	return false;
}

//�^�C�g���`��
extern VOID TitleDraw(VOID)
{
	if(GameDebug == TRUE)
	{
		Handle = LoadGraph("data/Title.png");
		DrawGraph(0,0,Handle,true);

	}

	return;
}


//�v���C������
extern VOID PlayInit(VOID)
{
	
	return;
}

//�v���C�Ǘ�
extern VOID PlayCtrl(VOID)
{
	PlayProc();
	PlayDraw();

	return;
}

//�v���C����
extern VOID PlayProc(VOID)
{
	

	return;
}

//�v���C�`��
extern VOID PlayDraw(VOID)
{
	if (GameDebug == TRUE)
	{
		//�V�[�����\��
		DrawFormatString(
			GameWidth - 1600, 0,
			GetColor(255, 0, 0),
			"%s%s", GameSceneName[NowGameScene], "�G�ɓ�����ȁI");
	}

	return;
}


