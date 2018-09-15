class StateManager 
{
private:
    string m_curstate;
    string m_nextstate;
    string m_tempstate;

public:
    StateManager() 
    {
        m_curstate.clear();
        m_nextstate.clear();
        m_tempstate.clear();
    }

public:
    virtual ~StateManager() {}

    void Update()
    {
        bool bFirst;
        if (m_nextstate.size()!=0) {
            m_curstate = m_nextstate;
            m_nextstate.clear();
            bFirst = true;
        }
        if (m_curstate.size()!=0) {
            execute_state(m_curstate, bFirst);
        }
    }
    virtual void execute_state(string& st, bool bFirst) = 0;

    void Goto(const char* st) 
    {
        m_nextstate = st; 
    }

    bool CheckState(const char *st)
    {
        return m_curstate == st;
    }

    void SetNextState(const char *st)
    {
        m_tempstate = st;
    }

    bool HasNextState()
    {
        return m_tempstate.size()!=0;
    }

    void GoNextState()
    {
        m_nextstate = m_tempstate;
        m_tempstate.clear();
    }

    virtual void Start() = 0;
    virtual bool IsEnd() = 0;
};

class TestControl : public StateManager
{
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

        if (st == "S_START") {S_START(bFirst); return;}
        if (st == "S_END")   {S_END(bFirst); return;}
        if (st == "S_0001")  {S_0001(bFirst); return;}
    }
    
private:

    void S_START(bool bFirst) { 
        if (bFirst) {
            printf("@S_START\n"); 
        }
        Goto("S_0001");
    }
    void S_END(bool bFirst)   { 
        if (bFirst) {
            printf("@S_END\n");  
        }
    }

    void S_0001(bool bFirst)  { 
        if (bFirst) {
            printf("@S_0001\n"); 
        }
        Goto("S_END");
    }    
};
