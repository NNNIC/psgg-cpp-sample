class StateManager 
{
private:
    int m_curstate;
    int m_nextstate;

public:
    StateManager() : 
        m_curstate(0),
        m_nextstate(0)
    {}

public:
    virtual ~StateManager() {}

    void Update()
    {
        bool bFirst;
        if (m_nextstate!=0) {
            m_curstate = m_nextstate;
            m_nextstate = 0;
            bFirst = true;
        }
        if (m_curstate!=0) {
            execute_state(m_curstate, bFirst);
        }
    }
    virtual void execute_state(int st, bool bFirst) = 0;

    void Goto(int st) 
    {
        m_nextstate = st;
    }

    bool CheckState(int st)
    {
        return m_curstate == st;
    }

    virtual void Start() = 0;
    virtual bool IsEnd() = 0;
};

class TestControl : public StateManager
{
    // write you code here!
    
};

class TestControl_created : public TestControl
{
public:
    enum STATE {
        NONE = 0,
        S_START,
        S_END,
        S_0001,
    };

    TestControl_created() {}

    void Start() {
        Goto((int)STATE::S_START);        
    }
    bool IsEnd() {
        return CheckState((int)STATE::S_END);
    }

private:

    void execute_state(int st, bool bFirst) {
        switch((STATE)st) {
            case STATE::S_START: Func_S_START(bFirst); return;
            case STATE::S_END:   Func_S_END(bFirst);   return;
            case STATE::S_0001:  Func_S_0001(bFirst);  return;
        }
    }
    
private:

    void Func_S_START(bool bFirst) { 
        if (bFirst) {
            printf("S_INIT\n"); 
        }
        Goto(STATE::S_0001);
    }
    void Func_S_END(bool bFirst)   { 
        if (bFirst) {
            printf("S_END\n");  
        }
    }

    void Func_S_0001(bool bFirst)  { 
        if (bFirst) {
            printf("S_0001\n"); 
        }
        Goto(STATE::S_END);
    }    
};
