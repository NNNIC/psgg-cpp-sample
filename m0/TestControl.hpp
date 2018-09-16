#pragma once
#include <cstdio>
#include <string>
using namespace std;

#include "StateManager.hpp"

class TestControl : public StateManager
{
public:
    bool m_bYesNo;

    // write your code here!
    void br_YES(const char *st)
    {
        if (!HasNextState())
        {
            if (m_bYesNo)
            {
                SetNextState(st);
            }
        }
    }
    void br_NO(const char *st)
    {
        if (!HasNextState())
        {
            if (!m_bYesNo)
            {
                SetNextState(st);
            }
        }
    }
};