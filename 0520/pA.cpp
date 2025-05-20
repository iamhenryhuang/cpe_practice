#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N , case_num = 0, detect = 0;
    while(cin >> N) {
        vector<int> num;
        for(int i = 0; i < N ; i++) {
            int temp1;
            cin >> temp1;
            num.push_back(temp1);
        }

        // check repeat
        vector<int> check;
        for(int i = 0; i < num.size() - 1; i++) {
            for(int j = i + 1; j < num.size(); j++) {
                int temp2 = num[i] + num[j];
                check.push_back(temp2);
            }
        }
        sort(check.begin(), check.end());
        for(int i = 0; i < check.size()-1; i++) {
            if(check[i] == check[i+1]) {
                detect++;
            }
        }

        // check other limits
        for(int i = 0; i < num.size()-1; i++) {
            if(num[i+1]-num[i] < 0 || num[0] < 1 || num[i] > 0) {
                detect++;
            }
        }
        case_num++;

        if(detect == 0) {
            cout << "Case #" << case_num << ": " << "It is a B2-Sequence." << endl;
        } else {
            cout << "Case #" << case_num << ": " << "It is not a B2-Sequence." << endl;
        }
    }
    
    return 0;
}
