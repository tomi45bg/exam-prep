#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
using namespace std;

int main(){

    string line;
    cin >> line;

    vector<char> symbols;
    istringstream istr(line);
    char symbol;

    while (istr >> symbol) {
        symbols.push_back(symbol);
    }

    ostringstream ostr;

    for (size_t i = 0; i < symbols.size(); i++)
    {
        if (isdigit(symbols[i])) {
            int num1 = (symbols[i] - '0') * 10 + (symbols[i + 1] - '0') * 1;
            if (isdigit(num1)) {
                for (size_t j = 0; j < num1 - 1; j++)
                {
                    ostr << symbols[i + 1];
                }
                i++;
                continue;
            }
            int num = symbols[i] - '0';
            for (size_t j = 0; j < num - 1; j++)
            {
                ostr << symbols[i + 1];
            }
            continue;
        }
        ostr << symbols[i];
    }

    cout << ostr.str() << endl;

    return 0;
}