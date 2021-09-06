
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSCredit.h"
#include "GSSetting.h"
#include "GSLeaderboard.h"
#include "GSHelp.h"
#include "GSMenu.h"
#include "GameStatebase.h"
#include "GSMode.h"
#include "GSPlay_Puzzle.h"
#include "GSPlay_Speed.h"
#include "GSGameOver.h"
#include "GSPuzzle.h"

GameStateBase::GameStateBase(StateType stateType) : m_stateType(stateType)
{}

std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateType stt)
{
	std::shared_ptr<GameStateBase> gs = nullptr;
	switch (stt)
	{
	case StateType::STATE_INVALID:
		break;
	case StateType::STATE_INTRO:
		gs = std::make_shared<GSIntro>();
		break;
	case StateType::STATE_MENU:
		gs = std::make_shared<GSMenu>();
		break;
	case StateType::STATE_PLAY:
		gs = std::make_shared<GSPlay>();
		break;
	case StateType::STATE_CREDIT:
		gs = std::make_shared<GSCredit>();
		break;
	case StateType::STATE_SETTING:
		gs = std::make_shared<GSSetting>();
		break;
	case StateType::STATE_HELP:
		gs = std::make_shared<GSHelp>();
		break;
	case StateType::STATE_LEADERBOARD:
		gs = std::make_shared<GSLeaderboard>();
		break;
	case StateType::STATE_MODE:
		gs = std::make_shared<GSMode>();
		break;
	case StateType::STATE_PLAY_SPEED:
		gs = std::make_shared<GSPlay_Speed>();
		break;
	case StateType::STATE_PLAY_PUZZLE:
		gs = std::make_shared<GSPlay_Puzzle>();
		break;
	case StateType::STATE_GAME_OVER:
		gs = std::make_shared<GSGameOver>();
		break;
	case StateType::STATE_PUZZLE:
		gs = std::make_shared<GSPuzzle>();
		break;
	default:
		break;
	}
	return gs;
}

StateType GameStateBase::GetGameStateType()
{
	return m_stateType;
}