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
    // グラフィックのロード
    player.PlayerGraph = LoadGraph("data/Peromi.png");
    player.PlayerGraph2 = LoadGraph("data/ohaka.png");
    player.Score = 0;  // スコアの初期化
    // BGMの再生
    PlayMusic("data/Bgm.mp3",true);
}

int i = 0;


void CheckCollision(Player& player, Enemy& enemy)
{

    // 敵とプレイヤーの当たり判定
    if (player.PlayerX + CHIP_SIZE >= enemy.moveX && player.PlayerX <= enemy.moveX + CHIP_SIZE) {
        if (player.PlayerY + CHIP_SIZE >= enemy.y && player.PlayerY <= enemy.y + CHIP_SIZE) {
            // 敵に当たった場合の処理
            enemy.y = -1600;
            enemy.y2 = -1600;
            enemy.y3 = -1600;

            player.PlayerX = 0;
            player.PlayerY = 0;

            printfDx("GAMEOVER", SetLogFontSize);
            StopMusic();
            PlaySoundMem(LoadSoundMem("data/zannense.mp3"), DX_PLAYTYPE_LOOP);
            // 敵に当たったのでスコアをリセットする
            player.Score = 0;
            // スコアの描画を停止する
            player.ScoreVisible = false;
            return;

        } 
        
    }

    // 敵とプレイヤーの当たり判定
    if (player.PlayerX + CHIP_SIZE >= enemy.moveX2 && player.PlayerX <= enemy.moveX2 + CHIP_SIZE) {
        if (player.PlayerY + CHIP_SIZE >= enemy.y2 && player.PlayerY <= enemy.y2 + CHIP_SIZE) {
            // 敵に当たった場合の処理
            enemy.y = -1600;
            enemy.y2 = -1600;
            enemy.y3 = -1600;

            player.PlayerX = 0;
            player.PlayerY = 0;

            printfDx("GAMEOVER", SetLogFontSize);
            StopMusic();
            PlaySoundMem(LoadSoundMem("data/zannense.mp3"), DX_PLAYTYPE_LOOP);
            // 敵に当たったのでスコアをリセットする
            player.Score = 0;
            // スコアの描画を停止する
            player.ScoreVisible = false;
            return;
        }

    }

    // 敵とプレイヤーの当たり判定
    if (player.PlayerX + CHIP_SIZE >= enemy.moveX3 && player.PlayerX <= enemy.moveX3 + CHIP_SIZE) {
        if (player.PlayerY + CHIP_SIZE >= enemy.y3 && player.PlayerY <= enemy.y3 + CHIP_SIZE) {
            // 敵に当たった場合の処理
            enemy.y = -1600;
            enemy.y2 = -1600;
            enemy.y3 = -1600;

            player.PlayerX = 0;
            player.PlayerY = 0;

            printfDx("GAMEOVER", SetLogFontSize);
            StopMusic();
            PlaySoundMem(LoadSoundMem("data/zannense.mp3"), DX_PLAYTYPE_LOOP);
            // 敵に当たったのでスコアをリセットする
            player.Score = 0;
            // スコアの描画を停止する
            player.ScoreVisible = false;
            return;
        }

        player.ScoreVisible = true;
    }


    // Enemyを飛び越えた場合の処理
    if (player.PlayerY < enemy.moveX && player.PlayerY > enemy.moveX - CHIP_SIZE)
    {
        // スコアを加算
        player.Score += 50;
    }

    if (player.PlayerY < enemy.moveX2 && player.PlayerY > enemy.moveX2 - CHIP_SIZE)
    {
        // スコアを加算
        player.Score += 50;
    }

    if (player.PlayerY < enemy.moveX3 && player.PlayerY > enemy.moveX3 - CHIP_SIZE)
    {
        // スコアを加算
        player.Score += 50;
    }

}


void UpdatePlayer(Player& player)
{
    // キー入力取得
    player.Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // ジャンプ中でない場合のみジャンプ音を再生する
    if (!player.IsJumping && (player.Key & PAD_INPUT_UP))
    {
        player.IsJumping = true;
        // ジャンプ音は効果音として再生する
        PlaySoundMem(LoadSoundMem("data/Jump.mp3"), DX_PLAYTYPE_BACK);

        // BGMを停止しない
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

    // 落下処理
    player.PlayerY -= player.JumpPower;

    // 落下加速度を加える
    player.JumpPower -= 1;

    // もし地面についていたら止まる
    if (player.PlayerY > 700)
    {
        player.PlayerY = 700;
        player.JumpPower = 0;
        player.IsJumping = false; // ジャンプ終了時にフラグをリセット
    }

    if (player.PlayerX > 1600)
    {
        player.PlayerX = 0;
    }
    else if (player.PlayerX < -60)
    {
        player.PlayerX = 1600;
    }

    // ジャンプボタンを押していて、地面に ついていたらジャンプ
    if ((player.Key & PAD_INPUT_A) && player.PlayerY == 300)
    {
        player.JumpPower = 30;
        player.IsJumping = true;
    }
}

void DDrawBox(Player& player)//プレイヤーのBOX
{



}


void UpdatePlayer(Player& player, Enemy& enemy)
{
   
    CheckCollision(player, enemy);

}
    