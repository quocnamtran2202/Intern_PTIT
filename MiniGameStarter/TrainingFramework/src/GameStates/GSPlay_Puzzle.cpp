#include "GSPlay_Puzzle.h"
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

GSPlay_Puzzle::GSPlay_Puzzle()
{
}


GSPlay_Puzzle::~GSPlay_Puzzle()
{
}


void GSPlay_Puzzle::Init()
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
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PUZZLE);
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
		/*file.close();
		file.open("Data/Score.txt");
		file << 0;
		file.close();*/
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->PushState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	//// score
	//shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	//std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	//m_score = std::make_shared< Text>(shader, font, "Score: 0", TextColor::RED, 1.0);
	//m_score->Set2DPosition(Vector2(5, 25));

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

	// text score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_mode = std::make_shared< Text>(shader, font, "", TextColor::RED, 1.25);
	m_mode->Set2DPosition(25, 50);

	// text move left
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_move = std::make_shared< Text>(shader, font, "", TextColor::RED, 1.1);
	m_move->Set2DPosition(25, 90);

	// text gameover
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_gameover = std::make_shared< Text>(shader, font, "", TextColor::RED, 1.25);
	m_gameover->Set2DPosition(180, 120);

	//sound
	loadSetting();
	buffer.loadFromFile("Sound/zapsplat_multimedia_button_click_004_68776.wav");
	sound.setBuffer(buffer);

	music.openFromFile("Sound/ES_Quest for the Skies - Christoffer Moe Ditlevsen.wav");
	music.play();
	music.setLoop(true);

	// board
	ifstream file;
	file.open("Data/Puzzle/Puzzle.txt");
	file >> lv;
	file.close();
	string level = "Level " + lv + ".txt";
	file.open("Data/Puzzle/"+level);
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			file >> g[i][j];
		}
	}
	file >> move;
	file.close();

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (g[i][j] != -1) {
				tmp[i][j] = 0;
			}
			else {
				tmp[i][j] = 1;
			}
		}
	}
}
void GSPlay_Puzzle::reset_tmp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (g[i][j] != -1) {
				tmp[i][j] = 0;
			}
			else {
				tmp[i][j] = 1;
			}
		}
	}
}

void GSPlay_Puzzle::Exit()
{
}

void GSPlay_Puzzle::Pause()
{
	music.pause();
}

void GSPlay_Puzzle::Resume()
{
	loadSetting();
	music.play();
}

void GSPlay_Puzzle::HandleEvents()
{
}

void GSPlay_Puzzle::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) {
		switch (key) {
		case VK_DOWN: {
			if (move > 0) {
				copyBoard();
				moveDown();
				sumDown();
				moveDown();
				if (checkMove() == true) {
					sound.play();
					move--;
				}
				if (move == 0 && countTile() > 1) {
					m_gameover->SetText("GAME OVER");
				}
				if (countTile() == 1) {
					m_gameover->SetText("    YOU WIN");
				}
				reset_tmp();
			}
			break;
		}

		case VK_UP: {
			if (move > 0) {
				copyBoard();
				moveUp();
				sumUp();
				moveUp();
				if (checkMove() == true) {
					sound.play();
					move--;
				}
				if (move == 0 && countTile() > 1) {
					m_gameover->SetText("GAME OVER");
				}
				if (countTile() == 1) {
					m_gameover->SetText("YOU WIN");
				}
				reset_tmp();
			}
			break;
		}

		case VK_LEFT: {
			if (move > 0) {
				copyBoard();
				moveLeft();
				sumLeft();
				moveLeft();
				if (checkMove() == true) {
					sound.play();
					move--;
				}
				if (move == 0 && countTile() > 1) {
					m_gameover->SetText("GAME OVER");
				}
				if (countTile() == 1) {
					m_gameover->SetText("YOU WIN");
				}
				reset_tmp();
			}
			break;
		}

		case VK_RIGHT: {
			if (move > 0) {
				copyBoard();
				moveRight();
				sumRight();
				moveRight();
				if (checkMove() == true) {
					sound.play();
					move--;
				}
				if (move == 0 && countTile() > 1) {
					m_gameover->SetText("GAME OVER");
				}
				if (countTile() == 1) {
					m_gameover->SetText("YOU WIN");
				}
				reset_tmp();
			}
			break;
		}
		}
	}
}

void GSPlay_Puzzle::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay_Puzzle::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay_Puzzle::Update(float deltaTime)
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
	//m_score->Update(deltaTime);
	m_move->Update(deltaTime);
	m_gameover->Update(deltaTime);
}

void GSPlay_Puzzle::Draw()
{
	m_background->Draw();

	string mode = "Puzzle - LV" + lv;
	m_mode->SetText(mode);
	m_mode->Draw();

	std::string smove = std::to_string(move);
	m_move->SetText("Moves left: " + smove);
	m_move->Draw();

	m_gameover->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			switch (g[i][j]) {
			case -1:
				tile[i][j]->SetTexture(ResourceManagers::GetInstance()->GetTexture("x button.tga"));
				break;
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


// move + sum

void GSPlay_Puzzle::moveUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (!g[j][i]) {
				for (int k = j + 1;k < 4;k++) {
					if (g[k][i] == -1) {
						break;
					}
					if (g[k][i] && g[k][i]!=-1) {
						g[j][i] = g[k][i];
						g[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay_Puzzle::moveDown() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j >= 0;j--) {
			if (!g[j][i] && g[j][i] != -1) {
				for (int k = j - 1;k >= 0;k--) {
					if (g[k][i] == -1) {
						break;
					}
					if (g[k][i] && g[k][i] != -1) {
						g[j][i] = g[k][i];
						g[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay_Puzzle::moveLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (!g[i][j] && g[i][j] != -1) {
				for (int k = j + 1;k < 4;k++) {
					if (g[i][k] == -1) {
						break;
					}
					if (g[i][k] && g[i][k] != -1) {
						g[i][j] = g[i][k];
						g[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay_Puzzle::moveRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j >= 0;j--) {
			if (!g[i][j] && g[i][j] != -1) {
				for (int k = j - 1;k >= 0;k--) {
					if (g[i][k] == -1) {
						break;
					}
					if (g[i][k] && g[i][k] != -1) {
						g[i][j] = g[i][k];
						g[i][k] = 0;
						break;
					}
				}
			}
		}
	}
}

void GSPlay_Puzzle::sumUp() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			if (g[j][i] && g[j][i] == g[j + 1][i] && tmp[j][i] == 0 && tmp[j + 1][i] == 0 && g[j][i]!=-1) {
				g[j][i] = g[j][i] + g[j + 1][i];
				g[j + 1][i] = 0;
				score += g[j][i];
				tmp[j][i] = 1;
				tmp[j + 1][i] = 1;
			}
		}
	}
}

void GSPlay_Puzzle::sumDown() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (g[j][i] && g[j][i] == g[j - 1][i] && tmp[j][i] == 0 && tmp[j - 1][i] == 0 && g[j][i] != -1) {
				g[j][i] = g[j][i] + g[j - 1][i];
				g[j - 1][i] = 0;
				score += g[j][i];
				tmp[j][i] = 1;
				tmp[j - 1][i] = 1;
			}
		}
	}
}

void GSPlay_Puzzle::sumLeft() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			if (g[i][j] && g[i][j] == g[i][j + 1] && tmp[i][j] == 0 && tmp[i][j + 1] == 0 && g[i][j] != -1) {
				g[i][j] = g[i][j] + g[i][j + 1];
				g[i][j + 1] = 0;
				score += g[i][j];
				tmp[i][j] = 1;
				tmp[i][j + 1] = 1;
			}
		}
	}
}

void GSPlay_Puzzle::sumRight() {
	for (int i = 0;i < 4;i++) {
		for (int j = 3;j > 0;j--) {
			if (g[i][j] && g[i][j] == g[i][j - 1] && tmp[i][j] == 0 && tmp[i][j - 1] == 0 && g[i][j] != -1) {
				g[i][j] = g[i][j] + g[i][j - 1];
				g[i][j - 1] = 0;
				score += g[i][j];
				tmp[i][j] = 1;
				tmp[i][j - 1] = 1;
			}
		}
	}
}

void GSPlay_Puzzle::addTile() {
	if (checkFull() == false) return;

	int x, y;

	do {
		x = rand() % 4;
		y = rand() % 4;
	} while (g[x][y] != 0);

	int s = rand() % 100;
	if (s > 89) g[x][y] = 4;
	else g[x][y] = 2;
}

bool GSPlay_Puzzle::checkFull() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (g[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}


void GSPlay_Puzzle::copyBoard()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			g_copy[i][j] = g[i][j];
		}
	}
}

bool GSPlay_Puzzle::checkMove()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (g_copy[i][j] != g[i][j]) return true;
		}
	}
	return false;
}

bool GSPlay_Puzzle::checkGameOver()
{
	if (checkFull() == false) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (g[i][j] == g[i][j + 1] ||
					g[i][j] == g[i + 1][j]) return false;
			}
		}
	}
	else if (checkFull() == true) return false;
	return true;
}

void GSPlay_Puzzle::loadSetting() {
	std::ifstream file;
	file.open("Data/Setting.txt");
	file >> ms >> sfx;
	file.close();
	sound.setVolume(sfx);
	music.setVolume(ms);
}

int GSPlay_Puzzle::countTile() {
	int a = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (g[i][j] != 0 && g[i][j] != -1 ){
				a++;
			}
		}
	}
	return a;
}