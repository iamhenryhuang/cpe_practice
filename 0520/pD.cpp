#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    // [i * i = n] == [i = sqrt(n)]
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) {
            return false;
        }
    }
        
    return true;
}

int main() {
    int n;
    while (cin >> n, n != 0) {
        bool found = false;
        for (int i = 2; i <= n / 2; ++i) {
            int j = n - i;
            if (isPrime(i) && isPrime(j)) {
                cout << n << " = " << i << " + " << j << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong." << endl;
    }
    return 0;
}
