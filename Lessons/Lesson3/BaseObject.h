#pragma once
#include <iostream>
using namespace std;

class BaseObject {

private:
	int id;
	string name;
	pair<int, int> position;

public:
	BaseObject(int id, string name, pair<int, int> position);
	~BaseObject();

	int getId();
	void setId(int id);

	string getName();
	void setName(string name);

	pair<int, int> getPosition();
	void printPosition();
	void setPosition(pair<int, int> position);
	void move(pair<int, int> new_position);

	virtual string getType()=0;
};
