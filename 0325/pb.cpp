#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    while(cin >> num) {
        vector<int> data(num);
        for(int i = 0; i < num; ++i) {
            cin >> data[i];
        }

        int count = 0;
        // bubble sort
        for(int i = 0; i < num - 1; ++i) {
            for(int j = 0; j < num -i - 1; ++j) { // num - i - 1的原因：因為完整掃過一次vector，最右邊會試最大值，因此可以忽略
                if(data[j] > data[j+1]) {
                    int temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                    count++;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
