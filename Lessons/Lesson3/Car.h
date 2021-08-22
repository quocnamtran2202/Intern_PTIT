#pragma once
#include "DynamicObject.h"
#include <iostream>
using namespace std;

class Car : public DynamicObject{

public:
	Car(int id, string name, pair<int, int> position);
};

