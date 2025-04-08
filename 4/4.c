#include <stdio.h>
#include <limits.h>
#include <locale.h>

// ����� �: ��������� �������
void process_array(int A[20], int k1, int k2) {
    // �������� ������������ ��������
    if (k1 < 0 || k1 >= 20 || k2 < 0 || k2 >= 20) {
        printf("������: �������� ������� k1 ��� k2\n");
        return;
    }

    int value_k1 = A[k1];
    int value_k2 = A[k2];

    for (int i = 0; i < 20; i++) {
        if (A[i] > 0) {
            A[i] -= value_k1;
        }
        else {
            A[i] -= value_k2;
        }
    }
}

// ����� �: ����� ������� � ����������� ������
int find_min_sum_column(int N[6][5]) {
    int min_sum = INT_MAX;
    int min_col = 0;

    for (int j = 0; j < 5; j++) {
        int col_sum = 0;
        for (int i = 0; i < 6; i++) {
            col_sum += N[i][j];
        }

        if (col_sum < min_sum) {
            min_sum = col_sum;
            min_col = j;
        }
    }

    return min_col;
}

int main() {
    system("chcp 1251");
    // ������ ��� ����� �
    int A[20] = { 5, -3, 10, 0, 7, -2, 15, -8, 4, -1,
                 3, -6, 9, -4, 12, -7, 6, -5, 8, -9 };
    int k1 = 2;  // ������ �������� ��� ������������� �����
    int k2 = 5;   // ������ �������� ��� ��������� �����

    printf("�������� ������ A:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    process_array(A, k1, k2);

    printf("������ ����� ���������:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");

    // ������ ��� ����� �
    int N[6][5] = {
        {3, 5, 2, 7, 1},
        {1, 4, 6, 2, 8},
        {5, 2, 9, 4, 3},
        {2, 7, 3, 5, 6},
        {4, 1, 8, 3, 2},
        {6, 3, 5, 1, 7}
    };

    int min_col = find_min_sum_column(N);
    printf("������� � ����������� ������ ���������: %d\n", min_col + 1);  // +1 ��� �������� (��������� � 1)

    return 0;
}