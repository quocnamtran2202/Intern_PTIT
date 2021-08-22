#include "Close_State.h"
#include <iostream>
#include"Door.h"
#include"Open_State.h"
#include"Lock_State.h"
using namespace std;

void Close_State::open() {
	cout << "Close			Open		The door is opened.\n\n";
	m_door->Transition(new Open_State);
}

void Close_State::lock() {
	cout << "Close			Lock		The door is locked.\n\n";
	m_door->Transition(new Lock_State);
}

void Close_State::close() {
	cout << "Close			Close		The door is already closed.\n\n";
}