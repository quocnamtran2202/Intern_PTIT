#include "GSMode.h"

GSMode::GSMode() : GameStateBase(StateType::STATE_MODE),
m_background(nullptr), m_listText(std::list<std::shared_ptr<Text>>{}), m_listButton(std::list<std::shared_ptr<GameButton>>{})
{
}


GSMode::~GSMode()
{
}



void GSMode::Init()
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

	// classic mode
	texture = ResourceManagers::GetInstance()->GetTexture("mode_classic.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 3);
	button->SetSize(176, 64);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);

	// speed mode
	texture = ResourceManagers::GetInstance()->GetTexture("mode_speed.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	button->SetSize(176, 64);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY_SPEED);
		});
	m_listButton.push_back(button);

	// puzzle mode
	texture = ResourceManagers::GetInstance()->GetTexture("mode_puzzle.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 1.5);
	button->SetSize(176, 64);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PUZZLE);
		});
	m_listButton.push_back(button);

	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "Choose game mode", TextColor::BLACK, 1.5, TextAlign::CENTER);
	text->Set2DPosition(Vector2(GLfloat(Globals::screenWidth / 2 - 150), Globals::screenHeight / 12));
	m_listText.push_back(text);

	// game title
	/*text = std::make_shared< Text>(shader, font, "Developed by Tran Quoc Nam - D17 PTIT", TextColor::BLACK, 1.14, TextAlign::CENTER);
	text->Set2DPosition(Vector2(5, 200));
	m_listText.push_back(text);*/

	//sfx
	buffer.loadFromFile("Sound/zapsplat_multimedia_button_click_004_68776.wav");
	sound.setBuffer(buffer);
}

void GSMode::Exit()
{
}


void GSMode::Pause()
{
}

void GSMode::Resume()
{
}


void GSMode::HandleEvents()
{
}

void GSMode::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMode::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			sound.play();
			break;
		}
	}
}

void GSMode::HandleMouseMoveEvents(int x, int y)
{
}

void GSMode::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMode::Draw()
{
	m_background->Draw();
	for (auto it : m_listText)
	{
		it->Draw();
	}
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}