#pragma once
#include "BaseObject.h"
#include <iostream>
using namespace std;

class StaticObject : public BaseObject{

public:
	StaticObject(int id, string name, pair<int, int> position);	
	string getType();
};

