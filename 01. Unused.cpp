#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void fillVector(vector<char>& allLetters) {
    for (size_t i = 97; i <= 122; i++)
    {
        char letter = i;
        allLetters.push_back(letter);
    }
}

vector<char> withoutRep(string& str) {
    vector<char> newVector;

    istringstream istr(str);
    char symbol;

    while (istr >> symbol) {
        newVector.push_back(symbol);

        for (size_t i = 0; i < newVector.size() - 1; i++)
        {
            if (newVector[i] == newVector[newVector.size() - 1]) {
                newVector.pop_back();
            }
        }
    }

    return newVector;
}

void sortVector(vector<char> & v) {
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j + 1 < v.size() - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                char temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void removeV(vector<char>& allLetters, vector<char>& newLine) {
    for (size_t i = 0; i < newLine.size(); i++)
    {
        for (size_t j = 0; j < allLetters.size(); j++)
        {
            if (newLine[i] == allLetters[j]) {
                allLetters.erase(allLetters.begin() + j);
            }
        }
    }
}

int main(){

    string line;
    cin >> line;

    vector<char> allLetters;
    fillVector(allLetters);

    vector<char> newLine = withoutRep(line);
    sortVector(newLine);
    removeV(allLetters, newLine);

    for (vector<char>::iterator it = allLetters.begin();
        it != allLetters.end();
        it++)
    {
        cout << *it;
    }
    return 0;
}