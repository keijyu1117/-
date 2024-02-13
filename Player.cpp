#include "DxLib.h"
#include "Enemy.h"
#include "Haikei.h"
#include "game.h"
#include "key.h"
#include "Player.h"
#define CHIP_SIZE 100

void InitializePlayer(Player& player)
{
    int SetLogFontSize(800);
    // �O���t�B�b�N�̃��[�h
    player.PlayerGraph = LoadGraph("data/Peromi.png");
    player.PlayerGraph2 = LoadGraph("data/ohaka.png");
    player.Score = 0;  // �X�R�A�̏�����
    // BGM�̍Đ�
    PlayMusic("data/Bgm.mp3",true);
}

int i = 0;


void CheckCollision(Player& player, Enemy& enemy)
{

    // �G�ƃv���C���[�̓����蔻��
    if (player.PlayerX + CHIP_SIZE >= enemy.moveX && player.PlayerX <= enemy.moveX + CHIP_SIZE) {
        if (player.PlayerY + CHIP_SIZE >= enemy.y && player.PlayerY <= enemy.y + CHIP_SIZE) {
            // �G�ɓ��������ꍇ�̏���
            enemy.y = -1600;
            enemy.y2 = -1600;
            enemy.y3 = -1600;

            player.PlayerX = 0;
            player.PlayerY = 0;

            printfDx("GAMEOVER", SetLogFontSize);
            StopMusic();
            PlaySoundMem(LoadSoundMem("data/zannense.mp3"), DX_PLAYTYPE_LOOP);
            // �G�ɓ��������̂ŃX�R�A�����Z�b�g����
            player.Score = 0;
            // �X�R�A�̕`����~����
            player.ScoreVisible = false;
            return;

        } 
        
    }

    // �G�ƃv���C���[�̓����蔻��
    if (player.PlayerX + CHIP_SIZE >= enemy.moveX2 && player.PlayerX <= enemy.moveX2 + CHIP_SIZE) {
        if (player.PlayerY + CHIP_SIZE >= enemy.y2 && player.PlayerY <= enemy.y2 + CHIP_SIZE) {
            // �G�ɓ��������ꍇ�̏���
            enemy.y = -1600;
            enemy.y2 = -1600;
            enemy.y3 = -1600;

            player.PlayerX = 0;
            player.PlayerY = 0;

            printfDx("GAMEOVER", SetLogFontSize);
            StopMusic();
            PlaySoundMem(LoadSoundMem("data/zannense.mp3"), DX_PLAYTYPE_LOOP);
            // �G�ɓ��������̂ŃX�R�A�����Z�b�g����
            player.Score = 0;
            // �X�R�A�̕`����~����
            player.ScoreVisible = false;
            return;
        }

    }

    // �G�ƃv���C���[�̓����蔻��
    if (player.PlayerX + CHIP_SIZE >= enemy.moveX3 && player.PlayerX <= enemy.moveX3 + CHIP_SIZE) {
        if (player.PlayerY + CHIP_SIZE >= enemy.y3 && player.PlayerY <= enemy.y3 + CHIP_SIZE) {
            // �G�ɓ��������ꍇ�̏���
            enemy.y = -1600;
            enemy.y2 = -1600;
            enemy.y3 = -1600;

            player.PlayerX = 0;
            player.PlayerY = 0;

            printfDx("GAMEOVER", SetLogFontSize);
            StopMusic();
            PlaySoundMem(LoadSoundMem("data/zannense.mp3"), DX_PLAYTYPE_LOOP);
            // �G�ɓ��������̂ŃX�R�A�����Z�b�g����
            player.Score = 0;
            // �X�R�A�̕`����~����
            player.ScoreVisible = false;
            return;
        }

        player.ScoreVisible = true;
    }


    // Enemy���щz�����ꍇ�̏���
    if (player.PlayerY < enemy.moveX && player.PlayerY > enemy.moveX - CHIP_SIZE)
    {
        // �X�R�A�����Z
        player.Score += 50;
    }

    if (player.PlayerY < enemy.moveX2 && player.PlayerY > enemy.moveX2 - CHIP_SIZE)
    {
        // �X�R�A�����Z
        player.Score += 50;
    }

    if (player.PlayerY < enemy.moveX3 && player.PlayerY > enemy.moveX3 - CHIP_SIZE)
    {
        // �X�R�A�����Z
        player.Score += 50;
    }

}


void UpdatePlayer(Player& player)
{
    // �L�[���͎擾
    player.Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // �W�����v���łȂ��ꍇ�̂݃W�����v�����Đ�����
    if (!player.IsJumping && (player.Key & PAD_INPUT_UP))
    {
        player.IsJumping = true;
        // �W�����v���͌��ʉ��Ƃ��čĐ�����
        PlaySoundMem(LoadSoundMem("data/Jump.mp3"), DX_PLAYTYPE_BACK);

        // BGM���~���Ȃ�
    }


    if (player.Key & PAD_INPUT_UP)
    {
        player.PlayerY -= 32;
    }
    if (player.Key & PAD_INPUT_DOWN)
    {
        player.PlayerY += 3;
    }
    if (player.Key & PAD_INPUT_RIGHT)
    {
        player.PlayerX += 9;
    }
    if (player.Key & PAD_INPUT_LEFT)
    {
        player.PlayerX -= 9;
    }

    // ��������
    player.PlayerY -= player.JumpPower;

    // ���������x��������
    player.JumpPower -= 1;

    // �����n�ʂɂ��Ă�����~�܂�
    if (player.PlayerY > 700)
    {
        player.PlayerY = 700;
        player.JumpPower = 0;
        player.IsJumping = false; // �W�����v�I�����Ƀt���O�����Z�b�g
    }

    if (player.PlayerX > 1600)
    {
        player.PlayerX = 0;
    }
    else if (player.PlayerX < -60)
    {
        player.PlayerX = 1600;
    }

    // �W�����v�{�^���������Ă��āA�n�ʂ� ���Ă�����W�����v
    if ((player.Key & PAD_INPUT_A) && player.PlayerY == 300)
    {
        player.JumpPower = 30;
        player.IsJumping = true;
    }
}

void DDrawBox(Player& player)//�v���C���[��BOX
{



}


void UpdatePlayer(Player& player, Enemy& enemy)
{
   
    CheckCollision(player, enemy);

}
    