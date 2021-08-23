#include "GSCredit.h"

GSCredit::GSCredit() : GameStateBase(StateType::STATE_CREDIT),
	m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_backButton(nullptr)
{
}


GSCredit::~GSCredit()
{
}



void GSCredit::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Background.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// back button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_back.tga");
	m_backButton = std::make_shared<GameButton>(model, shader, texture);
	m_backButton->Set2DPosition(Globals::screenWidth / 10, Globals::screenHeight / 15);
	m_backButton->SetSize(66, 54);
	m_backButton->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "Credits", TextColor::BLACK, 2, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 80), Globals::screenHeight / 12));
	m_listText.push_back(text);

	// game title
	text = std::make_shared< Text>(shader, font, "Developed by Tran Quoc Nam D17 PTIT", TextColor::BLACK, 1.25, TextAlign::CENTER);
	text->Set2DPosition(Vector2(5, 200));
	m_listText.push_back(text);
}

void GSCredit::Exit()
{
}


void GSCredit::Pause()
{
}

void GSCredit::Resume()
{
}


void GSCredit::HandleEvents()
{
}

void GSCredit::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSCredit::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (m_backButton->HandleTouchEvents(x, y, bIsPressed))
	{
		return;
	}
}

void GSCredit::HandleMouseMoveEvents(int x, int y)
{
}

void GSCredit::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	m_backButton->Update(deltaTime);
}

void GSCredit::Draw()
{
	m_background->Draw();
	m_backButton->Draw();
	for (auto it : m_listText)
	{
		it->Draw();
	}
}