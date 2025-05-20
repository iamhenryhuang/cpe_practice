#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int matrix[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int row_wrong = 0, col_wrong = 0;
    int row_idx = -1, col_idx = -1;

    // check rows
    for (int i = 0; i < N; i++) {
        int row_sum = 0;
        for (int j = 0; j < N; j++) {
            row_sum += matrix[i][j];
        }
        if (row_sum % 2 != 0) {
            row_wrong++;
            row_idx = i + 1; // 1-based index
        }
    }

    // check columns
    for (int j = 0; j < N; j++) {
        int col_sum = 0;
        for (int i = 0; i < N; i++) {
            col_sum += matrix[i][j];
        }
        if (col_sum % 2 != 0) {
            col_wrong++;
            col_idx = j + 1; // 1-based index
        }
    }

    if (row_wrong == 0 && col_wrong == 0) {
        cout << "OK" << endl;
    } else if (row_wrong == 1 && col_wrong == 1) {
        cout << "Change bit (" << row_idx << "," << col_idx << ")" << endl;
    } else {
        cout << "Corrupt" << endl;
    }

    return 0;
}
