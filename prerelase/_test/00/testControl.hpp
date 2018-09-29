class TestControl 
{

public:

    void Update() {
         S_START();
         S_0001();
         S_END();
    }

private:

    void S_START() { printf("S_INIT\n"); }
    void S_END()   { printf("S_END\n");  }

    void S_0001()  { printf("S_0001\n"); }    
};
