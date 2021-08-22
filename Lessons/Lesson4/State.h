#pragma once
#include <iostream>
using namespace std;

class Door;
class State
{
	public:
		virtual ~State();
		void setDoor(Door* door);
		virtual void open() = 0;
		virtual void close() = 0;
		virtual void lock() = 0;

	protected:
		Door* m_door;
};

