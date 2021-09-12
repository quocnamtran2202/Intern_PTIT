#pragma once
#include "GameStateBase.h"
#include "GameButton.h"
#include <SFML/Audio.hpp>

class GSSetting :
	public GameStateBase
{
public:
	GSSetting();
	~GSSetting();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>				m_background;
	std::list<std::shared_ptr<Text>>		m_listText;
	std::shared_ptr<Text>					m_textSFX;
	std::shared_ptr<Text>					m_textMusic;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<GameButton>				m_incMusic;
	std::shared_ptr<GameButton>				m_decMusic;
	std::shared_ptr<GameButton>				m_incSFX;
	std::shared_ptr<GameButton>				m_decSFX;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	int music;
	int sfx;
};

