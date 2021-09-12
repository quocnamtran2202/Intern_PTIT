#include "GSLeaderboard.h"
#include <fstream>;

GSLeaderboard::GSLeaderboard() : GameStateBase(StateType::STATE_LEADERBOARD),
m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_listButton(std::list<std::shared_ptr<GameButton>>{})
{
}


GSLeaderboard::~GSLeaderboard()
{
}



void GSLeaderboard::Init()
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
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButton.push_back(button);


	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "High Score", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 80), Globals::screenHeight / 12));
	m_listText.push_back(text);

	//classic
	std::ifstream file;
	file.open("Data/HighScore.txt");
	file >> highscore1;
	file.close();
	
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	text = std::make_shared< Text>(shader, font,"Classic  " + std::to_string(highscore1), TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 120), Globals::screenHeight / 4));
	m_listText.push_back(text);

	//speed
	file.open("Data/HighScore_Speed.txt");
	file >> highscore2;
	file.close();
	font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	text = std::make_shared< Text>(shader, font, "Speed     " + std::to_string(highscore2), TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 120), Globals::screenHeight / 3));
	m_listText.push_back(text);

}

void GSLeaderboard::Exit()
{
}


void GSLeaderboard::Pause()
{
}

void GSLeaderboard::Resume()
{
}


void GSLeaderboard::HandleEvents()
{
}

void GSLeaderboard::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSLeaderboard::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSLeaderboard::HandleMouseMoveEvents(int x, int y)
{
}

void GSLeaderboard::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSLeaderboard::Draw()
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
}