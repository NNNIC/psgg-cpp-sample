#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#include "TestControl.hpp"

int main()
{
    printf("hello!\n");

	TestControl *sm = new TestControl;
	sm->Start();

	while(!sm->IsEnd()) {
		sm->Update();
	}

	delete sm;
}