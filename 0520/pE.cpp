#include <iostream>
using namespace std;

int dime = 10;
int nickel = 5;
int penny = 1;

int main() {
    int total;
    while(cin >> total, total != 0) {
        int ways = 0;
        // i, j, k 分別代表了使用了多少個 dime, nickel 和 penny
        for(int i = 0; i <= total / dime; i++) {
            for(int j = 0; j <= (total - i * dime) / nickel; j++) {
                for(int k = 0; k <= (total - i * dime - j * nickel) / penny; k++) {
                    if(i * dime + j * nickel + k * penny == total) {
                        ways++;
                    }
                }
            }
        }

        if(ways > 1) {
            cout << "There are " << ways << " ways to produce " << total << " cents change.\n";
        } else {
            cout << "There is only 1 way to produce " << total << " cents change.\n";
        }
    }

    return 0;
}
