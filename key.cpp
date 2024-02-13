#include "DxLib.h"
#include "Enemy.h"
#include "Haikei.h"
#include "game.h"
#include "key.h"
#include "Player.h"

//�O���[�o���ϐ�

//���݂̃L�[�������Ă���t���[����
int NowKeyPressFrame[KeyKindMax];

//1�O�̃L�[�������Ă���t���[����
int OldKeyPressFrame[KeyKindMax];

//�֐�

//�L�[�{�[�h�����̏�����
VOID KeyInit(VOID)
{
	//�z��̏�����
	for (int i = 0; i < KeyKindMax; i++)
	{
		NowKeyPressFrame[i] = 0;
		OldKeyPressFrame[i] = 0;
	}
	return;
}

//�L�[�{�[�h���̍X�V
VOID KeyUpdate(VOID)
{
	char KeyState[KeyKindMax];

	GetHitKeyStateAll(&KeyState[0]);

	//�L�[�����X�V
	for (int i = 0; i < KeyKindMax; i++)
	{
		OldKeyPressFrame[i] = NowKeyPressFrame[i];

		if (KeyState[i] != 0)
		{
			NowKeyPressFrame[i]++;
		}
		else if (KeyState[i] == 0)
		{
			NowKeyPressFrame[i] = 0;
		}
	}

	return;
}

//����̃L�[�����������H
BOOL KeyDown(int KEY_INPUT_)
{
	//���݉�����Ă���L�[�̃t���[�������O������Ȃ�
	if (NowKeyPressFrame[KEY_INPUT_] > 0)
	{

		return TRUE;
	}

	return FALSE;
}

BOOL KeyClick(int KEY_INPUT_)
{
	//���݉�����Ă���L�[�̃t���[�������O������Ȃ�
	if (NowKeyPressFrame[KEY_INPUT_] == 0
		&& OldKeyPressFrame[KEY_INPUT_] > 0)
	{
		return TRUE;
	}

	return FALSE;
}

int KeyPressFrame(int KEY_INPUT_)
{

	return NowKeyPressFrame[KEY_INPUT_];
}