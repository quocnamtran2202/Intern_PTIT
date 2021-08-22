#pragma once
#include "StaticObject.h"
#include <iostream>
using namespace std;

class House : public StaticObject{

public:
	House(int id, string name, pair<int, int> position);
};

