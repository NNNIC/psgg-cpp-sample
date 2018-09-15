#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#include "TestControl.hpp"

int main()
{
    printf("hello!\n");

	StateManager *sm = static_cast<StateManager*>(new TestControl_created());
	sm->Start();

	while(!sm->IsEnd()) {
		sm->Update();
	}

	delete sm;
}