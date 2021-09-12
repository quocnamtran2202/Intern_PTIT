#include "GSPlay.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include <iostream>
#include <fstream>
using namespace std;

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Background 2.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("Menu_exit.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(60, 60);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MODE);
		});
	m_listButton.push_back(button);

	// button help
	texture = ResourceManagers::GetInstance()->GetTexture("Menu_help.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 125, 50);
	button->SetSize(60, 60);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HELP);
		});
	m_listButton.push_back(button);

	// button setting
	texture = ResourceManagers::GetInstance()->GetTexture("Menu_setting.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 200, 50);
	button->SetSize(60, 60);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_SETTING);
		});
	m_listButton.push_back(button);

	// button restart
	texture = ResourceManagers::GetInstance()->GetTexture("Menu_restart.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 130);
	button->SetSize(60, 60);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Map.txt");
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 4;j++) {
				file << 0 << "\t";
			}
			file << "\n";
		}
		file.close();
		file.open("Data/Score.txt");
		file << 0;
		file.close();
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->PushState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);

	// text score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_score = std::make_shared< Text>(shader, font, "Score: 0", TextColor::RED, 1.25);
	m_score->Set2DPosition(25, 50);

	// text mode
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_mode = std::make_shared< Text>(shader, font, "Classic", TextColor::RED, 1.25);
	m_mode->Set2DPosition(25, 90);

	// text gameover
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_gameover = std::make_shared< Text>(shader, font, "", TextColor::RED, 1.25);
	m_gameover->Set2DPosition(180, 150);

	//tile
	texture = ResourceManagers::GetInstance()->GetTexture("Tile Background.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	tile[0][0] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[0][0]->SetSize(128, 128);
	tile[0][0]->Set2DPosition((float)Globals::screenWidth / 2 - 195, (float)Globals::screenHeight / 2 - 130);

	tile[0][1] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[0][1]->SetSize(128, 128);
	tile[0][1]->Set2DPosition((float)Globals::screenWidth / 2 - 65, (float)Globals::screenHeight / 2 - 130);

	tile[0][2] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[0][2]->SetSize(128, 128);
	tile[0][2]->Set2DPosition((float)Globals::screenWidth / 2 + 65, (float)Globals::screenHeight / 2 - 130);

	tile[0][3] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[0][3]->SetSize(128, 128);
	tile[0][3]->Set2DPosition((float)Globals::screenWidth / 2 + 195, (float)Globals::screenHeight / 2 - 130);

	tile[1][0] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[1][0]->SetSize(128, 128);
	tile[1][0]->Set2DPosition((float)Globals::screenWidth / 2 - 195, (float)Globals::screenHeight / 2);

	tile[1][1] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[1][1]->SetSize(128, 128);
	tile[1][1]->Set2DPosition((float)Globals::screenWidth / 2 - 65, (float)Globals::screenHeight / 2);

	tile[1][2] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[1][2]->SetSize(128, 128);
	tile[1][2]->Set2DPosition((float)Globals::screenWidth / 2 + 65, (float)Globals::screenHeight / 2);

	tile[1][3] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[1][3]->SetSize(128, 128);
	tile[1][3]->Set2DPosition((float)Globals::screenWidth / 2 + 195, (float)Globals::screenHeight / 2);

	tile[2][0] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[2][0]->SetSize(128, 128);
	tile[2][0]->Set2DPosition((float)Globals::screenWidth / 2 - 195, (float)Globals::screenHeight / 2 + 130);

	tile[2][1] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[2][1]->SetSize(128, 128);
	tile[2][1]->Set2DPosition((float)Globals::screenWidth / 2 - 65, (float)Globals::screenHeight / 2 + 130);

	tile[2][2] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[2][2]->SetSize(128, 128);
	tile[2][2]->Set2DPosition((float)Globals::screenWidth / 2 + 65, (float)Globals::screenHeight / 2 + 130);

	tile[2][3] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[2][3]->SetSize(128, 128);
	tile[2][3]->Set2DPosition((float)Globals::screenWidth / 2 + 195, (float)Globals::screenHeight / 2 + 130);

	tile[3][0] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[3][0]->SetSize(128, 128);
	tile[3][0]->Set2DPosition((float)Globals::screenWidth / 2 - 195, (float)Globals::screenHeight / 2 + 260);

	tile[3][1] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[3][1]->SetSize(128, 128);
	tile[3][1]->Set2DPosition((float)Globals::screenWidth / 2 - 65, (float)Globals::screenHeight / 2 + 260);

	tile[3][2] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[3][2]->SetSize(128, 128);
	tile[3][2]->Set2DPosition((float)Globals::screenWidth / 2 + 65, (float)Globals::screenHeight / 2 + 260);

	tile[3][3] = std::make_shared<Sprite2D>(model, shader, texture);;
	tile[3][3]->SetSize(128, 128);
	tile[3][3]->Set2DPosition((float)Globals::screenWidth / 2 + 195, (float)Globals::screenHeight / 2 + 260);

	//sound
	loadSetting();
	buffer.loadFromFile("Sound/zapsplat_multimedia_button_click_004_68776.wav");
	sound.setBuffer(buffer);

	music.openFromFile("Sound/ES_Quest for the Skies - Christoffer Moe Ditlevsen.wav");
	music.play();
	music.setLoop(true);

	// set up board
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			//g[i][j] = 2;
			tmp[i][j] = 0;
		}
	}

	string fileBoard = "Data/Map.txt";
	ifstream file;
	file.open(fileBoard);
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			file >> g[i][j];
		}
	}
	file.close();
	
	if (checkInit() == false) {
		initBoard();
	}

	//score
	score = 0;
	string fileScore = "Data/Score.txt";
	file.open(fileScore);
	file >> score;
	file.close();
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
	music.pause();
	exportBoard();
	exportScore();
}

void GSPlay::Resume()
{
	loadSetting();
	music.play();
}

void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) {
		switch (key) {
			case VK_DOWN: {
				copyBoard();
				moveDown();
				sumDown();
				moveDown();
				if (checkMove() == true) {
					addTile();
				}
				reset_tmp();
				toGameOver();
				break;
			}

			case VK_UP: {
				copyBoard();
				moveUp();
				sumUp();
				moveUp();
				if (checkMove() == true) {
					addTile();
				}
				reset_tmp();
				break;
			}

			case VK_LEFT: {
				copyBoard();
				moveLeft();
				sumLeft();
				moveLeft();
				if (checkMove() == true) {
					addTile();
				}
				reset_tmp();
				break;
			}

			case VK_RIGHT: {
				copyBoard();
				moveRight();
				sumRight();
				moveRight();
				if (checkMove() == true) {
					addTile();
				}
				reset_tmp();
				break;
			}

			case VK_SPACE:
				reset();
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			tile[i][j]->Update(deltaTime);
		}
	}
	m_score->Update(deltaTime);
	m_gameover->Update(deltaTime);
}

void GSPlay::Draw()
{
	m_background->Draw();

	std::string s = std::to_string(score);
	m_score->SetText("Score: "+ s);
	m_score->Draw();

	m_mode->Draw();

	if (checkGameOver() == true) {
		s1 = "GAME OVER";
	}
	m_gameover->SetText(s1);
	m_gameover->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			switch (g[i][j]) {
				case 0:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("Tile Background.tga"));
					break;
				case 2:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("2 Tile.tga"));
					break;
				case 4:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("4 Tile.tga"));
					break;
				case 8:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("8 Tile.tga"));
					break;
				case 16:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("16 Tile.tga"));
					break;
				case 32:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("32 Tile.tga"));
					break;
				case 64:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("64 Tile.tga"));
					break;
				case 128:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("128 Tile.tga"));
					break;
				case 256:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("256 Tile.tga"));
					break;
				case 512:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("512 Tile.tga"));
					break;
				case 1024:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("1024 Tile.tga"));
					break;
				case 2048:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("2048 Tile.tga"));
					break;
				case 4096:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("4096 Tile.tga"));
					break;
				case 8192:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("8192 Tile.tga"));
					break;
				case 16384:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("16384 Tile.tga"));
					break;
				case 32768:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("32768 Tile.tga"));
					break;
				case 65536:
					tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("65536 Tile.tga"));
					break;
			}
			tile[i][j]->Draw();
		}
	}
	
}

// move -> combine -> move again

//void GSPlay::moveLeft() {
//	// no tile on left side
//	for (int row = 0; row < 4; row++) {
//		for (int j = 1;j < 4;j++) {
//			for (int i = j - 1;i >= 0;i--) {
//				if (map[row][i] == 0) {
//					map[row][i] = map[row][i + 1];
//					map[row][i + 1] = 0;
//				}
//			}
//		}
//	}
//	// tile on left side has the same value => combine 2 tile
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0;j < 4;j++) {
//			if (map[i][j] == map[i][j + 1]) {
//				map[i][j] += map[i][j];
//				map[i][j + 1] = 0;
//			}
//		}
//	}
//	// move again
//	for (int row = 0; row < 4; row++) {
//		for (int j = 1;j < 4;j++) {
//			for (int i = j - 1;i >= 0;i--) {
//				if (map[row][i] == 0) {
//					map[row][i] = map[row][i + 1];
//					map[row][i + 1] = 0;
//				}
//			}
//		}
//	}
//}
//
//void GSPlay::moveRight() {
//	// no tile on right side
//	for (int row = 0; row < 4; row++) {
//		for (int j = 2;j >= 0;j--) {
//			for (int i = j + 1;i <= 3;i++) {
//				if (map[row][i] == 0) {
//					map[row][i] = map[row][i - 1];
//					map[row][i - 1] = 0;
//				}
//			}
//		}
//	}
//	// tile on right side has the same value => combine 2 tile
//	for (int i = 0; i < 4; i++) {
//		for (int j = 2;j >= 0;j--) {
//			if (map[i][j] == map[i][j + 1]) {
//				map[i][j + 1] += map[i][j + 1];
//				map[i][j] = 0;
//			}
//		}
//	}
//	// move again
//	for (int row = 0; row < 4; row++) {
//		for (int j = 2;j >= 0;j--) {
//			for (int i = j + 1;i <= 3;i++) {
//				if (map[row][i] == 0) {
//					map[row][i] = map[row][i - 1];
//					map[row][i - 1] = 0;
//				}
//			}
//		}
//	}
//}
//
//void GSPlay::moveUp() {
//	// no tile above
//
//	for (int col = 0;col < 4;col++) {
//		for (int i = 1;i < 4;i++) {
//			for (int j = i - 1;j >= 0;j--) {
//				if (map[j][col] == 0) {
//					map[j][col] = map[j + 1][col];
//					map[j + 1][col] = 0;
//				}
//			}
//		}
//	}
//
//	// tile above has the same value => combine 2 tile
//	for (int j = 0;j < 4;j++) {
//		for (int i = 1;i < 4;i++) {
//			if (map[i][j] == map[i - 1][j] && tmp[i][j]==0 && tmp[i-1][j]==0) {
//				map[i - 1][j] += map[i - 1][j];
//				map[i][j] = 0;
//				tmp[i - 1][j] = 1;
//			}
//		}
//	}
//
//	// move again
//	for (int col = 0;col < 4;col++) {
//		for (int i = 1;i < 4;i++) {
//			for (int j = i - 1;j >= 0;j--) {
//				if (map[j][col] == 0) {
//					map[j][col] = map[j + 1][col];
//					map[j + 1][col] = 0;
//				}
//			}
//		}
//	}
//}
//
//void GSPlay::moveDown() {
//	// no tile beneath
//	for (int col = 0;col < 4;col++) {
//		for (int j = 2;j >= 0;j--) {
//			for (int i = j + 1;i <= 3;i++) {
//				if (map[i][col] == 0) {
//					map[i][col] = map[i - 1][col];
//					map[i - 1][col] = 0;
//				}
//			}
//		}
//	}
//	// tile beneath has the same value => combine 2 tile
//	for (int j = 0;j < 4;j++) {
//		for (int i = 3;i >= 0;i--) {
//			if (map[i][j] == map[i - 1][j] && tmp[i][j] == 0 && tmp[i - 1][j] == 0) {
//				map[i][j] += map[i][j];
//				map[i - 1][j] = 0;
//				tmp[i][j] = 1;
//			}
//		}
//	}
//
//	//move again
//	for (int col = 0;col < 4;col++) {
//		for (int j = 2;j >= 0;j--) {
//			for (int i = j + 1;i <= 3;i++) {
//				if (map[i][col] == 0) {
//					map[i][col] = map[i - 1][col];
//					map[i - 1][col] = 0;
//				}
//			}
//		}
//	}
//}


// move -> sum -> move

void GSPlay::moveUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (!g[j][i]) {
				for (int k = j + 1;k < 4;k++) {
					if (g[k][i]) {
						g[j][i] = g[k][i];
						g[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay::moveDown() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j >= 0;j--) {
			if (!g[j][i]) {
				for (int k = j - 1;k >= 0;k--) {
					if (g[k][i]) {
						g[j][i] = g[k][i];
						g[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay::moveLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (!g[i][j]) {
				for (int k = j + 1;k < 4;k++) {
					if (g[i][k]) {
						g[i][j] = g[i][k];
						g[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay::moveRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j >= 0;j--) {
			if (!g[i][j]) {
				for (int k = j - 1;k >= 0;k--) {
					if (g[i][k]) {
						g[i][j] = g[i][k];
						g[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay::sumUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			if (g[j][i] && g[j][i] == g[j + 1][i] && tmp[j][i] == 0 && tmp[j + 1][i] == 0) {
				g[j][i] = g[j][i] + g[j + 1][i];
				g[j + 1][i] = 0;
				score += g[j][i];
				tmp[j][i] = 1;
				tmp[j + 1][i] = 1;
			}
		}
	}
}

void GSPlay::sumDown() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (g[j][i] && g[j][i] == g[j - 1][i] && tmp[j][i] == 0 && tmp[j - 1][i] == 0) {
				g[j][i] = g[j][i] + g[j - 1][i];
				g[j - 1][i] = 0;
				score += g[j][i];
				tmp[j][i] = 1;
				tmp[j - 1][i] = 1;
			}
		}
	}
}

void GSPlay::sumLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			if (g[i][j] && g[i][j] == g[i][j + 1] && tmp[i][j] == 0 && tmp[i][j + 1] == 0) {
				g[i][j] = g[i][j] + g[i][j + 1];
				g[i][j + 1] = 0;
				score += g[i][j];
				tmp[i][j] = 1;
				tmp[i][j+1] = 1;
			}
		}
	}
}

void GSPlay::sumRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (g[i][j] && g[i][j] == g[i][j - 1] && tmp[i][j]==0 && tmp[i][j-1] == 0) {
				g[i][j] = g[i][j] + g[i][j - 1];
				g[i][j - 1] = 0;
				score += g[i][j];
				tmp[i][j] = 1;
				tmp[i][j - 1] = 1;
			}
		}
	}
}

void GSPlay::addTile() {
	if (checkFull() == false) return;

	int x, y;

	do {
		x = rand() % 4;
		y = rand() % 4;
	} while (g[x][y] != 0);

	int s = rand() % 100;
	if (s > 89) g[x][y] = 4;
	else g[x][y] = 2;
	sound.play();
}

bool GSPlay::checkFull() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (g[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}


void GSPlay::copyBoard()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			g_copy[i][j] = g[i][j];
		}
	}
}

bool GSPlay::checkMove()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (g_copy[i][j] != g[i][j]) return true;
		}
	}
	return false;
}

bool GSPlay::checkGameOver()
{
	if (checkFull() == false) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (g[i][j] == g[i][j + 1] || g[i][j] == g[i + 1][j]) {
					return false;
				}
			}
		}
	}
	else if (checkFull() == true) return false;
	return true;
}

void GSPlay::reset_tmp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			tmp[i][j] = 0;
		}
	}
}

void GSPlay::initBoard()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			g[i][j] = 0;
		}
	}

	int newTile[4];

	newTile[0] = rand() % 4;
	newTile[1] = rand() % 4;

	do {
		newTile[2] = rand() % 4;
		newTile[3] = rand() % 4;
	} while (newTile[0] == newTile[2] || newTile[1] == newTile[3]);

	g[newTile[0]][newTile[1]] = 2;
	g[newTile[2]][newTile[3]] = 2;
}

void GSPlay::exportBoard() {
	string fileName = "Data/Map.txt";
	ofstream file;
	file.open(fileName);
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			file << g[i][j] << "\t";
		}
		file << "\n";
	}
	file.close();
}

bool GSPlay::checkInit() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (g[i][j] != 0) {
				return true;
			}
		}
	}
	return false;
}

void GSPlay::exportScore() {
	string fileName = "Data/Score.txt";
	ofstream file;
	file.open(fileName);
	file << score;
	file.close();
}

void GSPlay::toGameOver() {
	if (checkGameOver() == true) {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_SETTING);
	}
}

void GSPlay::reset() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			g[i][j] = 0;
		}
	}
	score = 0;
	initBoard();
}

void GSPlay::loadSetting() {
	std::ifstream file;
	file.open("Data/Setting.txt");
	file >> ms >> sfx;
	file.close();
	sound.setVolume(sfx);
	music.setVolume(ms);
}
