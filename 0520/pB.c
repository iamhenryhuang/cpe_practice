#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int matrix[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // check row
    int row_wrong = 0;
    for (int i = 0; i < N; i++) {
        int row_sum = 0;
        for (int j = 0; j < N; j++) {
            row_sum += matrix[i][j];
        }
        if (row_sum % 2 != 0) {
            row_wrong++;
        }
    }

    // check column
    int column_wrong = 0;
    for (int j = 0; j < N; j++) {
        int column_sum = 0;
        for (int i = 0; i < N; i++) {
            column_sum += matrix[i][j];
        }
        if (column_sum % 2 != 0) {
            column_wrong++;
        }
    }

    if(row_wrong == 0 && column_wrong == 0) {
        printf("OK\n");
    } else if (row_wrong == 1 && column_wrong == 1) {
        printf("Change bit (%d,%d)\n", row_wrong, column_wrong);
    } else {
        printf("Corrupt\n");
    }

    return 0;
}
