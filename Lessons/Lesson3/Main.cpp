#include"Car.h"
#include"House.h"
#include"Motorbike.h"
#include"Tree.h"
#include"BaseObject.h"
#include"DynamicObject.h"
#include"StaticObject.h"
#include <list>
#include<iostream>
using namespace std;

int main() {
	list<BaseObject*> list;
	list.push_back(new House(1, "House A", pair<int,int>(0, 0)));
	list.push_back(new House(2, "House B", pair<int, int>(0, 0)));
	list.push_back(new Tree(3, "Tree A", pair<int, int>(0, 0)));
	list.push_back(new Tree(4, "Tree B", pair<int, int>(0, 0)));
	list.push_back(new Car(5, "Car A", pair<int, int>(0, 0)));
	list.push_back(new Car(6, "Car B", pair<int, int>(0, 0)));
	list.push_back(new Motorbike(7, "Motor A", pair<int, int>(0, 0)));
	list.push_back(new Motorbike(8, "Motor B", pair<int, int>(0, 0)));

	for (auto obj : list) {
		if(obj->getType() == "Dynamic"){
			obj->move(pair<int, int>(2, 2));
		}
	}

	cout << "ID  " << "NAME" << "	        POSITION\n";
	for (auto obj : list) {
		cout << obj->getId() << "   ";
		cout << obj->getName() << "	          ";
		obj->printPosition();
		cout<< "\n";
	}

	list.clear();

	return 0;
}