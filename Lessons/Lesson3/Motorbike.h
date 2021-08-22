#pragma once
#include "DynamicObject.h"
#include <iostream>
using namespace std;

class Motorbike : public DynamicObject{

public:
	Motorbike(int id, string name, pair<int, int> position);
};

