#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            continue;
        }

        // 確保 a <= b
        if (a > b) {
            swap(a, b);
        }

        int count = 0;
        
        for (int i = a; i <= b/2; i++) {
            int square = i * i;
            if (square >= a && square <= b) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
