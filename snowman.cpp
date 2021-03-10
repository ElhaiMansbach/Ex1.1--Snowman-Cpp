# include <iostream>
# include <array>
# include "snowman.hpp"

using namespace std;

    const int LETTERS = 8;
    const int OPTIONS = 4;
    const int MOD = 10;
    const int B=0;
    const int T=1;
    const int Y=2;
    const int X=3;
    const int R=4;
    const int L=5;
    const int N=6;
    const int H=7;

    const array<array<string, OPTIONS>, LETTERS>  signs = 
    {{
        {" ( : )", " (\" \")", " (___)", " (   )"}, //B
        {"( : )", "(] [)", "(> <)", "(   )"}, //T
        {" >", "/ ", " \\", "  "}, //Y
        {" <", "\\ ", " /", "  "}, //X
        {".)", "o)", "O)", "-)"}, //R
        {"(.", "(o", "(O", "(-"}, //L
        {",", ".", "_", " "}, //N
        {"      \n _===_\n",  "  ___\n .....\n", "   _ \n  /_\\\n", "  ___ \n (_*_)\n" } //H
    }};

    namespace ariel{
        string snowman(int num){
            int counter = 0;
            array<string, LETTERS> choises;
            int choise = 0;
            while(counter < LETTERS){
                choise = num%MOD-1;
               if(choise < 0 || choise > 3){
                    throw runtime_error {"Exception - Invalid code"};
               }
                 num /=MOD;
                 choises.at(counter) = signs.at(counter)[choise];
                 counter++;
             }
            if(num != 0){
                throw runtime_error {"Exception - Invalid code"};
            }
                string sm = choises.at(H)+choises.at(X).at(0)+choises.at(L)+choises.at(N)+choises.at(R)+choises.at(Y).at(0)+"\n"
                +choises.at(X).at(1)+choises.at(T)+choises.at(Y).at(1)+"\n"+choises.at(B);

          return sm;
        return "";

        } 
    }


