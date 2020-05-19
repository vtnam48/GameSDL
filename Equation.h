#ifndef EQUATION_H
#define EQUATION_H

#include "Common.h"

struct Equation{
    int x = 0, y = 0, z = 0;
    typeEqua tp;

    void randomEquation(){
        x = rand()%MAX_A;
        y = rand()%MAX_B;

        int n = rand()%3;

        if(n == 0) tp = cong;
        if(n == 1) tp = tru;
        if(n == 2) tp = nhan;

        if(tp == cong)  z = (x+y) + rand()%flex;
        if(tp == tru)   z = (x-y) + rand()%flex;
        if(tp == nhan)  z = (x*y) + rand()%flex;

    }

    string getString(){
        string strReturn;
        stringstream s;
        s << x;
        strReturn = s.str();

        stringstream s2;
        s2 << y;
        if(tp == cong) strReturn = strReturn + " + " + s2.str();
        if(tp == tru)  strReturn = strReturn + " - " + s2.str();
        if(tp == nhan) strReturn = strReturn + " x " + s2.str();

        stringstream s3;
        s3 << z;
        strReturn = strReturn + " = " + s3.str();

        return strReturn;
    }

    int key(){
        if(tp == cong) if(x+y == z) return 1;
        if(tp == tru)  if(x-y == z) return 1;
        if(tp == nhan) if(x*y == z) return 1;

        return 2;
    }

};

#endif // EQUATION_H
