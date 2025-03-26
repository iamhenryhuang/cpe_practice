#include <iostream>
#include <map>
using namespace std;

int dx[] = {1, 0, -1, 0}; //E, S, W, N
int dy[] = {0, -1, 0, 1}; //E, S, W, N

int main() {
    int row, col;
    cin >> col >> row;

    bool scent[51][51] = {false}; //移動網格最大尺寸是 50×50，true 表示該座標已經有一個機器人丟失
    map<char, int> dir_map = {{'E', 0}, {'S', 1}, {'W', 2}, {'N', 3}}; //將東西南北轉成數字
    map<int, char> rev_dir = {{0, 'E'}, {1, 'S'}, {2, 'W'}, {3, 'N'}}; //整數映射回方向

    int x, y; //機器人的座標
    char d;
    string commands;

    while (cin >> x >> y >> d){
        cin >> commands;
        int curr_dir = dir_map[d]; //將方向轉成數字
        bool lost = false; //機器人是否丟失

        for(char cmd : commands) {
            if(lost == true) break; //如果機器人丟失，則不再執行後續指令

            if(cmd == 'R') {
                curr_dir = (curr_dir + 1) % 4; //右轉
            } else if(cmd == 'L') {
                curr_dir = (curr_dir + 3) % 4; //左轉
            } else {
                int nx = x + dx[curr_dir]; //下一步的 x 座標
                int ny = y + dy[curr_dir]; //下一步的 y 座標

                if(nx < 0 || nx > col || ny < 0 || ny > row) { //如果下一步超出邊界
                    if(scent[x][y] == false) { //如果機器人之前沒有丟失
                        scent[x][y] = true; //標記機器人丟失
                        lost = true; //機器人丟失
                    }
                } else {
                    x = nx;
                    y = ny;
                }
            }
        }

        if (lost) {
            cout << x << " " << y << " " << rev_dir[curr_dir] << " LOST\n";
        } else {
            cout << x << " " << y << " " << rev_dir[curr_dir] << "\n";
        }
    }
    return 0;
}
