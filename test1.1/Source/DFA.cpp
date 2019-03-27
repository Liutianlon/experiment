//
// Created by dell on 2019/3/25.
//
#include "DFA.h"

char scan(){
    if(!file)
        return -1;

    if(Pos==datalen-1)
    {
        fflush(stdin);
        datalen=fread(BUFF,1,BUFLEN,file);
        if(datalen==0)
        {
            datalen=1;
            BUFF[0]=-1;

        }

        Pos=-1;
    }
    Pos++;
    char ch=BUFF[Pos];

    if(ch==-1)
    {
        fclose(file);
        file=NULL;
    }
    lastch=ch;

    return ch;
}



DFA::DFA() {

}
DFA::~DFA() {

}
string DFA::Integer(char ch) {
    int state=0;
    char n_char=ch;
    string str="";

    while(true)
    {
        switch(state)
        {
            case 0:{

                if(n_char>='1'&&n_char<='9')
                {
                    state=1;
                }else{
                    str=n_char;
                    lastch=scan();
                    return "Error:"+str;
                }
            };break;
            case 1:{

                if(n_char>='0'&&n_char<='9'){
                    state=1;
                }else{
                    return str;
                }
            };break;
        }
        str+=n_char;
        n_char=scan();
    }

}
string DFA::Identifier(char ch) {

    int state=0;
    char n_char=ch;
    string str;

    while(true)
    {

        switch(state)
        {

            case 0:{

                if(n_char=='_'||(n_char>='A'&&n_char<='Z')||(n_char>='a'&&n_char<='z'))
                {
                    state=1;

                }else{
                    str=n_char;
                    lastch=scan();
                    return "Error:"+str;
                }
            };break;
            case 1:{

                if(n_char=='_'||(n_char>='A'&&n_char<='Z')||(n_char>='a'&&n_char<='z')||(n_char>='0'&&n_char<='9'))
                {
                    state=1;
                }else{
                    return str;
                }
            };break;
        }
        str+=n_char;
        n_char=scan();

    }

}
