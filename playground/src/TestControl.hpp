#pragma once
#include <cstdio>
#include <string>
using namespace std;

class TestControl 
{
    //region manager 
private:
    string m_curstate;
    string m_nextstate;
    string m_tempstate;
    bool   m_bNoWait;

    void update() {
        while(true) {
            bool bFirst;
            m_bNoWait = false;
            if (m_nextstate.size()!=0) {
                m_curstate = m_nextstate;
                m_nextstate.clear();
                bFirst = true;
            }
            if (m_curstate.size()!=0) {
                execute_state(m_curstate, bFirst);
            }
            if (!m_bNoWait) break;
        }
    }
    void Goto(const char* st)        { m_nextstate = st;                                 }
    bool CheckState(const char *st)  { return m_curstate == st;                          }
    void SetNextState(const char *st){ m_tempstate = st;                                 }
    bool HasNextState()              { return m_tempstate.size()!=0;                     }
    void GoNextState()               { m_nextstate = m_tempstate; m_tempstate.clear();   }
    void NoWait()                    { m_bNoWait = true;                                 }
    //endregion manager

    //  Embed codes                              [SYN-G-GEN OUTPUT START] indent(4) $/^E_/$
//  psggConverterLib.dll converted from TestControl.xlsx. 


    //                                           [SYN-G-GEN OUTPUT END]

    //  states                                   [SYN-G-GEN OUTPUT START] indent(4) $/^S_/$
//  psggConverterLib.dll converted from TestControl.xlsx. 
    /*
        S_0001
    */
    void S_0001(bool bFirst)
    {
        int a = 3;
        if (bFirst)
        {
            printf("Hello World!\n");
        }
        if (a == 1) { SetNextState( "S_0002" ); }
        else if (a==2) { SetNextState( "S_0004" ); }
        else { SetNextState( "S_0003" ); }
        if (HasNextState())
        {
            GoNextState();
        }
    }
    /*
        S_0002
    */
    void S_0002(bool bFirst)
    {
        if (bFirst)
        {
            printf("S_0002\n");
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
        S_0003
    */
    void S_0003(bool bFirst)
    {
        if (bFirst)
        {
            printf("S_0003\n");
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
        S_0004
    */
    void S_0004(bool bFirst)
    {
        if (bFirst)
        {
            printf("S_0004\n");
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
        S_END
    */
    void S_END(bool bFirst)
    {
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
        if (!HasNextState())
        {
            SetNextState("S_0001");
        }
        if (HasNextState())
        {
            GoNextState();
        }
    }


    //                                           [SYN-G-GEN OUTPUT END]
 
	void execute_state(string &st, bool bFirst)
    {
        //                                       [SYN-G-GEN OUTPUT START] indent(8) $/^S_/->#execute_state$
//  psggConverterLib.dll converted from TestControl.xlsx. 
        if (st == "S_0001") { S_0001(bFirst); return; }
        if (st == "S_0002") { S_0002(bFirst); return; }
        if (st == "S_0003") { S_0003(bFirst); return; }
        if (st == "S_0004") { S_0004(bFirst); return; }
        if (st == "S_END") { S_END(bFirst); return; }
        if (st == "S_START") { S_START(bFirst); return; }


        //                                       [SYN-G-GEN OUTPUT END]
    }

    // write your code here!
    bool m_bYesNo;
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
public:
    void Start()  { Goto("S_START");            }
    bool IsEnd()  { return CheckState("S_END"); }
    void Update() { update();                   }
};