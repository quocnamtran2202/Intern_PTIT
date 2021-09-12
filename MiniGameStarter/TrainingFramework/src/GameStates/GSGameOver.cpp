#include "GSGameOver.h"
#include <iostream>
#include <fstream>
using namespace std;

GSGameOver::GSGameOver() : GameStateBase(StateType::STATE_GAME_OVER),
m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_listButton(std::list<std::shared_ptr<GameButton>>{})
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

	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "GAME OVER", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 100), Globals::screenHeight / 10));
	m_listText.push_back(text);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	text = std::make_shared< Text>(shader, font, "Score", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 100), Globals::screenHeight / 5));
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
}

void GSGameOver::HandleMouseMoveEvents(int x, int y)
{
}

void GSGameOver::Update(float deltaTime)
{
	m_background->Update(deltaTime);
}

void GSGameOver::Draw()
{
	m_background->Draw();
	for (auto it : m_listText)
	{
		it->Draw();
	}
}