#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;    // 存放每組輸入的數字
vector<int> tempsave;    // 暫存目前選中的 6 個數

// 用 DFS，從位置 index 開始找組合
void dfs(int index, int depth) {
    // 如果已經選到 6 個數了，就輸出
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            if (i < 5) {
                cout << tempsave[i] << " ";
            } else {
                cout << tempsave[i] << "\n";
            }
        }
                    
        return;
    }

    // 從 index(遞迴的起始位置) 開始往後挑選數字
    for (int i = index; i < nums.size(); i++) {
        tempsave.push_back(nums[i]);       // 選這個數字
        dfs(i + 1, depth + 1);         // 遞迴找下一個數字
        tempsave.pop_back();               // 遞迴結束回到上一層，取消這個選擇
    }
}

int main() {
    while (true) {
        int k;
        cin >> k;              // 讀取這組有幾個數字
        if (k == 0) break;     // 如果是 0 就結束

        nums.clear();
        tempsave.clear();

        // 讀入 k 個數字
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        dfs(0, 0);   // 從第 0 個數開始，選第 0 層
        cout << endl;
    }

    return 0;
}
