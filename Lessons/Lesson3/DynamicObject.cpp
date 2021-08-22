#include "DynamicObject.h"
#include <iostream>
using namespace std;

DynamicObject::DynamicObject(int id, string name, pair<int, int> position):BaseObject(id, name, position){}
	
string DynamicObject::getType() {
	return "Dynamic";
}