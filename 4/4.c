#include <stdio.h>
#include <limits.h>
#include <locale.h>

// Часть а: обработка массива
void process_array(int A[20], int k1, int k2) {
    // Проверка корректности индексов
    if (k1 < 0 || k1 >= 20 || k2 < 0 || k2 >= 20) {
        printf("Ошибка: неверные индексы k1 или k2\n");
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

// Часть б: поиск столбца с минимальной суммой
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
    // Пример для части а
    int A[20] = { 5, -3, 10, 0, 7, -2, 15, -8, 4, -1,
                 3, -6, 9, -4, 12, -7, 6, -5, 8, -9 };
    int k1 = 2;  // индекс элемента для положительных чисел
    int k2 = 5;   // индекс элемента для остальных чисел

    printf("Исходный массив A:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    process_array(A, k1, k2);

    printf("Массив после обработки:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");

    // Пример для части б
    int N[6][5] = {
        {3, 5, 2, 7, 1},
        {1, 4, 6, 2, 8},
        {5, 2, 9, 4, 3},
        {2, 7, 3, 5, 6},
        {4, 1, 8, 3, 2},
        {6, 3, 5, 1, 7}
    };

    int min_col = find_min_sum_column(N);
    printf("Столбец с минимальной суммой элементов: %d\n", min_col + 1);  // +1 для удобства (нумерация с 1)

    return 0;
}