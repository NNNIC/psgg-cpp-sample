#include <stdio.h>
using namespace std;

#include "TestControl.hpp"

int main()
{
    printf("hello!\n");

	TestControl sm;
	sm.Start();

	while(!sm.IsEnd()) {
		sm.Update();
	}

}