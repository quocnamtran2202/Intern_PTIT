#include<iostream>
#include"Door.h"
#include"Close_State.h"
#include"Open_State.h"
#include"Lock_State.h"
using namespace std;

int main() {
	Door* door = new Door(new Close_State);
	cout << "Current State		Action			Result\n\n";
	door->close_request();
	door->lock_request();
	door->lock_request();
	door->open_request();
	door->close_request();
	door->open_request();
	door->open_request();
	door->lock_request();
	door->close_request();
	delete door;
	return 0;
}