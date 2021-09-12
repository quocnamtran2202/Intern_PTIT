#include "GSPuzzle.h"
#include <iostream>
#include <fstream>
using namespace std;

GSPuzzle::GSPuzzle() : GameStateBase(StateType::STATE_PUZZLE),
m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_backButton(nullptr)
{
}


GSPuzzle::~GSPuzzle()
{
}



void GSPuzzle::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Background.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// back button
	texture = ResourceManagers::GetInstance()->GetTexture("Menu_back.tga");
	m_backButton = std::make_shared<GameButton>(model, shader, texture);
	m_backButton->Set2DPosition(Globals::screenWidth / 10, Globals::screenHeight / 15);
	m_backButton->SetSize(60, 60);
	m_backButton->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MODE);
		});

	// level 1
	texture = ResourceManagers::GetInstance()->GetTexture("level/1.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 140);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 1;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 2
	texture = ResourceManagers::GetInstance()->GetTexture("level/2.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(270, 140);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 2;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 3
	texture = ResourceManagers::GetInstance()->GetTexture("level/3.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(440, 140);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 3;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 4
	texture = ResourceManagers::GetInstance()->GetTexture("level/4.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 260);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 4;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 5
	texture = ResourceManagers::GetInstance()->GetTexture("level/5.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(270, 260);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 5;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 6
	texture = ResourceManagers::GetInstance()->GetTexture("level/6.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(440, 260);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 6;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 7
	texture = ResourceManagers::GetInstance()->GetTexture("level/7.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 380);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 7;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 8
	texture = ResourceManagers::GetInstance()->GetTexture("level/8.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(270, 380);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 8;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 9
	texture = ResourceManagers::GetInstance()->GetTexture("level/9.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(440, 380);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 9;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 10
	texture = ResourceManagers::GetInstance()->GetTexture("level/10.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 500);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 10;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 11
	texture = ResourceManagers::GetInstance()->GetTexture("level/11.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(270, 500);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 11;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 12
	texture = ResourceManagers::GetInstance()->GetTexture("level/12.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(440, 500);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 12;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 13
	texture = ResourceManagers::GetInstance()->GetTexture("level/13.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(100, 620);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 13;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 14
	texture = ResourceManagers::GetInstance()->GetTexture("level/14.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(270, 620);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 14;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// level 15
	texture = ResourceManagers::GetInstance()->GetTexture("level/15.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(440, 620);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		ofstream file;
		file.open("Data/Puzzle/Puzzle.txt");
		file << 15;
		file.close();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		});
	m_listButton.push_back(button);

	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "Choose level", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 110), Globals::screenHeight / 12));
	m_listText.push_back(text);

	// game title
	/*text = std::make_shared< Text>(shader, font, "Developed by Tran Quoc Nam - D17 PTIT", TextColor::BLACK, 1.14, TextAlign::CENTER);
	text->Set2DPosition(Vector2(5, 200));
	m_listText.push_back(text);*/

}

void GSPuzzle::Exit()
{
}


void GSPuzzle::Pause()
{
}

void GSPuzzle::Resume()
{
}


void GSPuzzle::HandleEvents()
{
}

void GSPuzzle::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSPuzzle::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (m_backButton->HandleTouchEvents(x, y, bIsPressed))
	{
		return;
	}
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			sound.play();
			break;
		}
	}
}

void GSPuzzle::HandleMouseMoveEvents(int x, int y)
{
}

void GSPuzzle::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	m_backButton->Update(deltaTime);
	for (auto button : m_listButton)
	{
		button->Update(deltaTime);
	}
}

void GSPuzzle::Draw()
{
	m_background->Draw();
	m_backButton->Draw();
	for (auto it : m_listText)
	{
		it->Draw();
	}
	for (auto button : m_listButton)
	{
		button->Draw();
	}
}