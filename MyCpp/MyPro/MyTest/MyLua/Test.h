#include <string>

class CTest
{
public:
    CTest(void);
    ~CTest(void);
    
    void SetA(int _a);
    int GetA(){return a;}

    void SetB(std::string _b);
    std::string GetB(){return b;}
private:
    int a;
    std::string b;
};