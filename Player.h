#pragma once
struct Player
{
	int PlayerX = 699;
	int PlayerY = 699;
	int JumpPower = 0;
	int PlayerGraph;
	int PlayerGraph2;
	int Key;
	int GBheight = 30;
	int GBwidth = 160;
	int cr;
	int Bx;
	int By;
	int Score;  // ÉXÉRÉAÇí«â¡
	int IsJumping;
	int BGMHandle;
	int ScoreVisible;
};

void InitializePlayer(Player& player);
void UpdatePlayer(Player& player, Enemy& enemy);
void UpdatePlayer(Player& player);
void DDrawBox(Player& player);
void CheckCollision(Player& player, Enemy& enemy);

