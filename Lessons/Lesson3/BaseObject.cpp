#include "BaseObject.h"
#include <iostream>
using namespace std;

BaseObject::BaseObject(int id, string name, pair<int, int> position = pair<int, int> (0,0)) {
	this->id = id;
	this->name = name;
	this->position = position;
}

BaseObject::~BaseObject() {
	
}

int BaseObject::getId() {
	return this->id;
}

void BaseObject::setId(int id) {
	this->id = id;
}

string BaseObject::getName() {
	return this->name;
}

void BaseObject::setName(string name) {
	this->name = name;
}

pair<int, int> BaseObject::getPosition() {
	return this->position;
}

void BaseObject::setPosition(pair<int, int> position) {
	this->position = position;
}

void BaseObject::printPosition() {
	cout << this->position.first << "," << this->position.second;
}

void BaseObject::move(pair<int,int> new_position){
	this->setPosition(new_position);
}


