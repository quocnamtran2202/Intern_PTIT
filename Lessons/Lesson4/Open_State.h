#pragma once
#include"State.h"

class Open_State :public State {
	public:
		void close() override;	
		void open() override;
		void lock() override;
};


