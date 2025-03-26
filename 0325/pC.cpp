#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string removeComma(string word) {
    string result;
    for(char c : word) {
        if(c != ',' && c != '.') {
            result += c;
        }
    }
    return result;
}

int main() {
    string article;
    getline(cin, article); //讀取整行輸入

    // 用stringstream將文章中的單字讀取出來
    stringstream ss(article); //將整行輸入轉換成串流
    vector<string> words; //存放文章中的單字
    string word;

    while(ss >> word) { //每次從ss讀取一個單字
        word = removeComma(word); //去除逗號或是句號
        words.push_back(word); //存進vector
    }

    sort(words.begin(), words.end());

    for(string w : words) {
        cout << w << "\n";
    }

    return 0;
}
