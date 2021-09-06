#pragma once
#include "GameStateBase.h"
#include <SFML/Audio.hpp>
#include <iostream>

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSPlay_Puzzle :
	public GameStateBase
{
public:
	GSPlay_Puzzle();
	~GSPlay_Puzzle();

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

	void	addTile();
	void	reset();
	bool	canMove();
	void	moveUp();
	void	moveDown();
	void	moveLeft();
	void	moveRight();
	void	reset_tmp();
	void	sumUp();
	void	sumDown();
	void	sumLeft();
	void	sumRight();
	bool	checkFull();
	void	copyBoard();
	bool	checkMove();
	bool	checkGameOver();

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Text>		m_mode;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Sprite2D>	tile[4][4];
	//int map[4][4];
	int tmp[4][4];
	bool moved;
	int g[4][4];
	int g_copy[4][4];
	sf::Music music;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	int score;
	std::string lv;
};

