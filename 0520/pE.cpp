#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> coins = {1, 5, 10}; // 硬幣面值
    vector<long long> dp(30001, 0); // dp[x] 表示湊出 x cent的方法數
    dp[0] = 1; // 初始化，湊出 0 cent的方法只有 1 種

    // dp
    for (int coin : coins) {
        for (int i = coin; i <= 30000; i++) {
            dp[i] += dp[i - coin];
        }
    }

    int total;
    while (cin >> total, total != 0) {
        if (dp[total] == 1) {
            cout << "There is only 1 way to produce " << total << " cents change.\n";
        } else {
            cout << "There are " << dp[total] << " ways to produce " << total << " cents change.\n";
        }
    }

    return 0;
}

/*#include <iostream>
using namespace std;

int dime = 10;
int nickel = 5;
int penny = 1;

int main() {
    int total;
    while(cin >> total, total != 0, total <= 30000) {
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
}*/
