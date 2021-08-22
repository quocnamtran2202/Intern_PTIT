#include "StaticObject.h"
#include <iostream>
using namespace std;

StaticObject::StaticObject(int id, string name, pair<int,int> position):BaseObject(id, name, position){}

string StaticObject::getType() {
	return "Static";
}