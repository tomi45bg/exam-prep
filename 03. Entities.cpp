#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;

void mostCommon(vector<vector<string>>& vectors, vector<string> titles, string word, int count) {
    int index = 0;

    for (size_t i = 0; i < titles.size(); i++)
    {
        if (titles[i] == word) {
            index = i;
        }
    }

    vector<string> info;
    vector<int> infoCount;
    bool repeats = false;
    int count1 = 1;

    for (size_t i = 0; i < count; i++)
    {
        string w = vectors[i][index];
        int countRepeats = 0;
        for (size_t j = 0; j < info.size(); j++)
        {
            if (info[j] == w) {
                countRepeats = j;
                repeats = true;
                infoCount[j]++;
            }
        }

        if (!repeats) {
            info.push_back(w);
            infoCount.push_back(count1);
        }

        repeats = false;
    }

    int maxValue = INT_MIN;
    int indexMax = 0;

    for (size_t i = 0; i < infoCount.size(); i++)
    {
        if (infoCount[i] > maxValue) {
            maxValue = infoCount[i];
            indexMax = i;
        }
    }

    cout << info[indexMax] << " " << maxValue << endl;
}

int main(){

    int countColumns = 0;
    string line;
    getline(cin, line);

    istringstream istr(line);
    string word;
    vector<string> titles;

    while (istr >> word) {
        countColumns++;
        titles.push_back(word);
    }

    vector<vector<string>> vectors;

    for (size_t i = 0; i <= 200; i++)
    {
        vector<string> my_vec;
        vectors.push_back(my_vec);
    }

    string info;
    getline(cin, info);
    int count = 0;
    
    while (info != "end") {

        istringstream istr(info);
        string words;

        while (istr >> words) {
            vectors[count].push_back(words);
        }

        count++;
        getline(cin, info);
    }

    string searchColumn;
    cin >> searchColumn;

    mostCommon(vectors, titles, searchColumn, count);

    return 0;
}