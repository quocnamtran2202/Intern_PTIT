#include "GSGameOver.h"
#include <iostream>
#include <fstream>
using namespace std;

GSGameOver::GSGameOver() : GameStateBase(StateType::STATE_GAME_OVER),
m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_backButton(nullptr)
{
}


GSGameOver::~GSGameOver()
{
}



void GSGameOver::Init()
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
		ifstream file;
		file.open("Data/GSGameOver.txt");
		int x;
		file >> x;
		if (x == 1) {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		}
		if (x == 2) {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_SPEED);
		}
		if (x == 3) {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_PUZZLE);
		}
		if (x == 0) {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		}
		});

	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "Help", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 40), Globals::screenHeight / 12));
	m_listText.push_back(text);

	// game title
	/*text = std::make_shared< Text>(shader, font, "Developed by Tran Quoc Nam - D17 PTIT", TextColor::BLACK, 1.14, TextAlign::CENTER);
	text->Set2DPosition(Vector2(5, 200));
	m_listText.push_back(text);*/

	//sfx
	buffer.loadFromFile("Sound/zapsplat_multimedia_button_click_004_68776.wav");
	sound.setBuffer(buffer);
}

void GSGameOver::Exit()
{
}


void GSGameOver::Pause()
{
}

void GSGameOver::Resume()
{
}


void GSGameOver::HandleEvents()
{
}

void GSGameOver::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSGameOver::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (m_backButton->HandleTouchEvents(x, y, bIsPressed))
	{
		sound.play();
		return;
	}
}

void GSGameOver::HandleMouseMoveEvents(int x, int y)
{
}

void GSGameOver::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	m_backButton->Update(deltaTime);
}

void GSGameOver::Draw()
{
	m_background->Draw();
	m_backButton->Draw();
	for (auto it : m_listText)
	{
		it->Draw();
	}
}