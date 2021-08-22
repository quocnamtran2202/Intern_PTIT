#include "Lock_State.h"
#include <iostream>
#include"Door.h"
#include"Close_State.h"
using namespace std;

void Lock_State::close() {
	cout << "Lock			Close		The door is closed.\n\n";
	m_door->Transition(new Close_State);
}

void Lock_State::open() {
	cout << "Lock			Open		The door cant be opened when locked.\n\n";
}

void Lock_State::lock() {
	cout << "Lock			Lock		The door is already locked .\n\n";
}
