#pragma once
struct Enemy
{
	int z = 0;			//�A�j���[�V����(��)
	int moveX = 0;		//�G��x���W�̏�����
	int y = 699;		//�G��y���W�̏�����
	int z2 = 0;			//�A�j���[�V����(��)
	int moveX2 = 0;	//�G2��x���W�̏�����
	int y2 = 699;		//�G2��y���W�̏�����
	int R;	//�G�̕`��1
	int R2;	//�G�̕`��2
	int R3;
	int z3 = 0;
	int moveX3 = 0;
	int y3 = 699;
	int GBheight = 30;	
	int GBwidth = 860;
	int i;
	int j;
	int cr;
	int Bx;
	int By;
	int Graph;
	int Graph2;
	int Graph3;
	int X;
	int Y;
	int Width;
	int Height;
};
void InitializeEnemy(Enemy& enemy);
void UpdateEnemy(Enemy& enemy);
void DrawEnemy(Enemy& enemy);
void DDrawBox(Enemy& enemy);
void KillPlayer(Enemy& enemy);
void UpdateBox(Enemy& enemy);