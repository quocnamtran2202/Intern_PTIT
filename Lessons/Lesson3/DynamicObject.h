#pragma once
#include "BaseObject.h"
#include<iostream>
using namespace std;

class DynamicObject : public BaseObject{

public:
	DynamicObject(int id, string name, pair<int, int> position);
	string getType();
};

