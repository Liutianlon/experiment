//
// Created by dell on 2019/3/25.
//

#ifndef PROJECT_DFA_H
#define PROJECT_DFA_H
#include "public.h"
extern char BUFF[];
extern char datalen;
extern char colnum;
extern char rownum;
extern char Pos;
extern char lastch;
extern FILE* file;

char scan();

class DFA{
public:
    DFA();
    ~DFA();
    string Integer(char ch);
    string Identifier(char ch);

};
#endif //PROJECT_DFA_H
