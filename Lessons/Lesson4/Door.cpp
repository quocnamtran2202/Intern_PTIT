#include "Door.h"
#include <typeinfo>
#include <iostream>
using namespace std;

Door::Door(State* state) :m_state(nullptr) {
	this->Transition(state);
}

Door::~Door() {
	delete m_state;
}

void Door::Transition(State* state) {
	//cout << "The door is " << typeid(state).name() << "\n";
	if (m_state != nullptr) {
		delete m_state;
	}
	m_state = state;
	m_state->setDoor(this);
}

void Door::open_request() {
	m_state->open();
}

void Door::close_request() {
	m_state->close();
}

void Door::lock_request() {
	m_state->lock();
}
