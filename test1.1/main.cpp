#include "main.h"
char BUFF[BUFLEN];
char datalen=0;
char colnum;
char rownum;
char Pos=-1;
char lastch;
FILE*file;

int main() {

    file=fopen("..\\test.txt","rb");
    DFA dfa;
    int a=300;
    lastch=scan();
    while (lastch!=-1)
        cout<<dfa.Integer(lastch)<<endl;

    return 0;
}