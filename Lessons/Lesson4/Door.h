#pragma once
#include <iostream>
#include"State.h"
using namespace std;

class Door
{
	private: 
		State* m_state;

	public:
		Door(State* state);
		~Door();
		void Transition(State* state);
		void open_request();
		void close_request();
		void lock_request();
};

