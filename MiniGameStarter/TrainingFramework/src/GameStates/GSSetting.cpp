#include "GSSetting.h"
#include <iostream>
#include <fstream>

GSSetting::GSSetting() : GameStateBase(StateType::STATE_SETTING),
m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_listButton(std::list<std::shared_ptr<GameButton>>{})
{
}


GSSetting::~GSSetting()
{
}



void GSSetting::Init()
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
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 10, Globals::screenHeight / 15);
	button->SetSize(60, 60);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// button music
	texture = ResourceManagers::GetInstance()->GetTexture("increase.tga");
	m_incMusic = std::make_shared<GameButton>(model, shader, texture);
	m_incMusic->Set2DPosition(Globals::screenWidth - 50, 150);
	m_incMusic->SetSize(72, 60);
	m_incMusic->SetOnClick([]() {
		});
	m_listButton.push_back(m_incMusic);

	texture = ResourceManagers::GetInstance()->GetTexture("decrease.tga");
	m_decMusic = std::make_shared<GameButton>(model, shader, texture);
	m_decMusic->Set2DPosition(Globals::screenWidth - 250, 150);
	m_decMusic->SetSize(72, 60);
	m_decMusic->SetOnClick([]() {
		});
	m_listButton.push_back(m_decMusic);

	// button sfx
	texture = ResourceManagers::GetInstance()->GetTexture("increase.tga");
	m_incSFX = std::make_shared<GameButton>(model, shader, texture);
	m_incSFX->Set2DPosition(Globals::screenWidth - 50, 300);
	m_incSFX->SetSize(72, 60);
	m_incSFX->SetOnClick([]() {
		});
	m_listButton.push_back(m_incSFX);

	texture = ResourceManagers::GetInstance()->GetTexture("decrease.tga");
	m_decSFX = std::make_shared<GameButton>(model, shader, texture);
	m_decSFX->Set2DPosition(Globals::screenWidth - 250, 300);
	m_decSFX->SetSize(72, 60);
	m_decSFX->SetOnClick([]() {
		});
	m_listButton.push_back(m_decSFX);

	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "Settings", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 65), Globals::screenHeight / 12));
	m_listText.push_back(text);

	// text music
	text = std::make_shared< Text>(shader, font, "Music", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(50, 160);
	m_listText.push_back(text);

	m_textMusic = std::make_shared< Text>(shader, font, "100", TextColor::BLACK, 1.5, TextAlign::CENTER);
	m_textMusic->Set2DPosition(Globals::screenWidth - 175, 160);

	// text SFX
	text = std::make_shared< Text>(shader, font, "SFX", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(50, 310 );
	m_listText.push_back(text);

	m_textSFX = std::make_shared< Text>(shader, font, "100", TextColor::BLACK, 1.5, TextAlign::CENTER);
	m_textSFX->Set2DPosition(Globals::screenWidth - 175, 310);

	std::ifstream file;
	file.open("Data/Setting.txt");
	file >> music >> sfx;
	file.close();
}

void GSSetting::Exit()
{
	std::ofstream file;
	file.open("Data/Setting.txt");
	file << music << "\t" << sfx;
	file.close();
}


void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}


void GSSetting::HandleEvents()
{
}

void GSSetting::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSSetting::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			if (button == m_incMusic) {
				if (music < 100) 
					music += 10;
				else
					music = 0;
			}
			if (button == m_decMusic) {
				if (music > 0)
					music -= 10;
				else
					music = 100;
			}
			if (button == m_incSFX) {
				if (sfx < 100)
					sfx += 10;
				else
					sfx = 0;
			}
			if (button == m_decSFX) {
				if (sfx > 0)
					sfx -= 10;
				else
					sfx = 100;
			}
			break;
		}
	}
}

void GSSetting::HandleMouseMoveEvents(int x, int y)
{
}

void GSSetting::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listText)
	{
		it->Update(deltaTime);
	}
	m_textSFX->Update(deltaTime);
	m_textMusic->Update(deltaTime);
}

void GSSetting::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}	
	for (auto it : m_listText)
	{
		it->Draw();
	}
	std::string st_music = std::to_string(music);
	m_textMusic->SetText(st_music);
	m_textMusic->Draw();

	std::string st_sfx = std::to_string(sfx);
	m_textSFX->SetText(st_sfx);
	m_textSFX->Draw();
}
