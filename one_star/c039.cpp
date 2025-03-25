#include <iostream>
using namespace std;

int main() {
    int i, j, counter = 0;
    while(cin >> i >> j) {
        int max_length = 0;
        for(int k = min(i, j); k < max(i, j); ++k) {
            int temp = k, counter = 1;
            while(temp != 1) {
                if(temp%2 == 0) temp /= 2;
                else temp = 3 * temp + 1;
                counter++;
            }
            max_length = max(max_length, counter);
        }

        cout << i << " " << j << " " << max_length << "\n";
    }

    return 0;
}
