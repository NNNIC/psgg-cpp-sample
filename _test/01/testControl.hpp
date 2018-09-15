class TestControl 
{
public:
    enum STATE {
        NONE = 0,
        S_START,
        S_END,
        S_0001,
    };

    STATE m_curstate;
    STATE m_nextstate;

    TestControl() : 
        m_curstate(STATE::NONE), 
        m_nextstate(STATE::NONE)
    {}

    void Update() {
        bool bFirst = false;
        if (m_nextstate!=STATE::NONE) {
            m_curstate = m_nextstate;
            m_nextstate = STATE::NONE;
            bFirst = true;
        }
        if (m_curstate!=STATE::NONE) {
            excute_state(m_curstate,bFirst);
        }
    }
    void Goto(STATE st) { m_nextstate = st; }
    bool CheckState(STATE st) { return (m_curstate == st);}

    void Start() {
        Goto(STATE::S_START);        
    }
    bool IsEnd() {
        return CheckState(STATE::S_END);
    }

private:

    void excute_state(STATE st, bool bFirst) {
        switch(m_curstate) {
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
