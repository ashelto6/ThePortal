#ifndef GLOBALS_H
#define GLOBALS_H

class GLOBALS
{
    private:

        GLOBALS(const GLOBALS&) = delete;
        GLOBALS* operator=(const GLOBALS&) = delete;
        GLOBALS(){}



    protected:
        static GLOBALS* instance();
                int x = 20;
        int getNum() {return x;}
        void setNum(int num) {x = num;}
        ~GLOBALS(){ }


};



#endif // GLOBALS_H
