#include "Open_State.h"
#include <iostream>
#include"Door.h"
#include"Close_State.h"
using namespace std;

void Open_State::close() {
	cout << "Open			Close		The door is closed.\n\n";
	m_door->Transition(new Close_State);
}

void Open_State::open() {
	cout << "Open			Open		The door is already opened.\n\n";
}

void Open_State::lock() {
	cout << "Open			Lock		The door cant be locked when opened.\n\n";
}

