#pragma once

#define GameSceneCount 3
#define GameSceneNameMax 20
#define GameDebug TRUE
#define GameWidth 1600
#define GameHeight 900

//�񋓌^
enum GameScene
{
	TitleScene,//�^�C�g���V�[��
	PlayScene,//�v���C�V�[��
	
};

extern enum GameScene NowGameScene;//���݂̃Q�[���V�[��

//�O���̃v���g�^�C�v�錾
extern VOID TitleInit(VOID); //������
extern bool TitleCtrl(VOID); //�Ǘ�
extern bool TitleProc(VOID); //����	
extern VOID TitleDraw(VOID); //�`��


extern VOID PlayInit(VOID);//������
extern VOID PlayCtrl(VOID);//�Ǘ�
extern VOID PlayProc(VOID);//����
extern VOID PlayDraw(VOID);//�`��

extern VOID GameoverInit(VOID); //������
extern VOID GameoverCtrl(VOID); //�Ǘ�
extern VOID GameoverProc(VOID); //����	
extern VOID GameoverDraw(VOID); //�`��