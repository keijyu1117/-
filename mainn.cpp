#include "DxLib.h"
#include "Enemy.h"
#include "Haikei.h"
#include "game.h"
#include "key.h"
#include "Player.h"




// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    

    // �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
    SetGraphMode(1600, 900, 16);
    ChangeWindowMode(true);

    if (DxLib_Init() == -1)		// �c�w���C�u������������
    {
        return -1;			// �G���[���N�����璼���ɏI��
    }

    SetDrawScreen(DX_SCREEN_BACK);

    Player player;
    Enemy enemy;
    Haikei haikei;
    InitializePlayer(player);
    InitializeHaikei(haikei);
    InitializeEnemy(enemy);
    InitializePlayer(player);


    //�ŏ��̃V�[���̓^�C�g������
    NowGameScene = TitleScene;

    KeyInit();

    TitleInit();


    GameScene lastGameScene;

   
    while (ProcessMessage() != -1)
    {
        // ���̃t���[���̊J�n�������o���Ă���
        LONGLONG start = GetNowHiPerformanceCount();

        // �`����s���O�ɉ�ʂ��N���A����
        ClearDrawScreen();

        // ��ʂ�����������
        ClearDrawScreen();

        // �^�C�g���V�[�����ǂ����ŕ`���؂�ւ���
        if (NowGameScene == TitleScene) {
            // �^�C�g���V�[���̕`��
            TitleDraw();
        }
        else if (NowGameScene == PlayScene) {
            // �Q�[���V�[���̕`��
            UpdateHaikei(haikei);
            DrawHaikei(haikei);
            CheckCollision(player, enemy);
            UpdatePlayer(player, enemy);
            UpdatePlayer(player);
            UpdateBox(enemy);
            DDrawBox(enemy);
            DDrawBox(player);
            UpdateEnemy(enemy);
            DrawEnemy(enemy);
            DrawGraph(player.PlayerX, player.PlayerY, player.PlayerGraph, TRUE);        
            // �X�R�A�\��
            if (player.ScoreVisible) {
                DrawFormatString(10, 30, GetColor(255, 255, 255), "Score: %d", player.Score);
            }
        }

        // �L�[�{�[�h�X�V
        KeyUpdate();

        // �V�[���؂�ւ�
        switch (NowGameScene)
        {
        case TitleScene:
            if (TitleCtrl()) {
                continue;
            }
            else {
                break;
            }
        case PlayScene:
            if (lastGameScene == TitleScene) {

            }
            // �^�C�}�[�̍X�V�ƕ\��
           
            PlayCtrl();

            break;
        default:
            break;
        }
        lastGameScene = NowGameScene;

        // ��ʂ��؂�ւ��̂�҂�
        ScreenFlip();

        // esc�L�[�ŃQ�[���I��
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        // FPS60�ɌŒ肷��
        while (GetNowHiPerformanceCount() - start < 16667)
        {
            // 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
        }
    }
    // �X�R�A�\��
    DrawFormatString(10, 30, GetColor(255, 255, 255), "Score: %d", player.Score);
   
    DxLib_End();				// �c�w���C�u�����g�p�̏I������

    return 0;				// �\�t�g�̏I�� 
}
