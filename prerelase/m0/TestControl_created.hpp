//  psggConverterLib.dll converted from TestControl.xlsx. 
#pragma once
#include <string>
#include "TestControl.hpp"

using namespace std;

class TestControl_created : public TestControl
{
public:
    TestControl_created() {}

    void Start() {
        Goto("S_START");
    }
    bool IsEnd() {
        return CheckState("S_END");
    }

private:

    void execute_state(string& st, bool bFirst) {


        if (st == "S_END") { S_END(bFirst); return; }
        if (st == "S_INPUT") { S_INPUT(bFirst); return; }
        if (st == "S_NO") { S_NO(bFirst); return; }
        if (st == "S_PRINT") { S_PRINT(bFirst); return; }
        if (st == "S_START") { S_START(bFirst); return; }
        if (st == "S_YES") { S_YES(bFirst); return; }


    }


    /*
        S_END
    */
    void S_END(bool bFirst)
    {
        if (bFirst)
        {
        }
        if (HasNextState())
        {
            GoNextState();
        }
    }
    /*
        S_INPUT
        Input an answer
    */
    void S_INPUT(bool bFirst)
    {
        if (bFirst)
        {
            char c;
            scanf("%c",&c);
            printf("\n");
            m_bYesNo = (c=='y' || c=='Y');
        }
        br_YES("S_YES");
        br_NO("S_NO");
        if (HasNextState())
        {
            GoNextState();
        }
    }
    /*
        S_NO
    */
    void S_NO(bool bFirst)
    {
        if (bFirst)
        {
            printf("You must not be a programmer.");
        }
        if (!HasNextState())
        {
            SetNextState("S_END");
        }
        if (HasNextState())
        {
            GoNextState();
        }
    }
    /*
        S_PRINT
        Print a question.
    */
    void S_PRINT(bool bFirst)
    {
        if (bFirst)
        {
            printf("Would you like to go to the new dimension of programming?\n");
        }
        if (!HasNextState())
        {
            SetNextState("S_INPUT");
        }
        if (HasNextState())
        {
            GoNextState();
        }
    }
    /*
        S_START
    */
    void S_START(bool bFirst)
    {
        if (bFirst)
        {
        }
        if (!HasNextState())
        {
            SetNextState("S_PRINT");
        }
        if (HasNextState())
        {
            GoNextState();
        }
    }
    /*
        S_YES
    */
    void S_YES(bool bFirst)
    {
        if (bFirst)
        {
            printf("We will bring you to SYN-G-GEN.");
        }
        if (!HasNextState())
        {
            SetNextState("S_END");
        }
        if (HasNextState())
        {
            GoNextState();
        }
    }


};

