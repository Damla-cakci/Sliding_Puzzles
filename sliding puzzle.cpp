#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

void shuffleArray(int* arr, int size) {
    srand((unsigned)time(NULL));
    int i = 0;
    for (; i < size; i++) {
        int random_value = rand() % size;

        int temp = arr[random_value];
        arr[random_value] = arr[i];
        arr[i] = temp;
    }
}

void fillTable(int table[5][5], const int* arr) {
    int count = 0;
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            table[i][j] = arr[count + i + j];
        }
        count += 4;
    }
}

void printTable(int table[5][5]) {
    printf("********* TABLE *********\n");
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%4d", table[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void swapValues(int x1, int y1, int x2, int y2, int table[5][5]) {
    const int temp = table[x1][y1];
    table[x1][y1] = table[x2][y2];
    table[x2][y2] = temp;

    printTable(table);
}

int main() {
    int table[5][5];
    int arr[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
        arr[i] = i;

    shuffleArray(arr, SIZE);
    fillTable(table, arr);
    printTable(table);

    int x1, y1, x2, y2;

    while (1) {
    	
    	
        int correct = 1;
        for (i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (table[i][j] != i * 5 + j) {
                    correct = 0;
                    break;
                }
            }
        }

        if (correct) {
            printf("Congratulations! The numbers are in the correct order.\n");
            break;
        }

        printf("enter x1(-1 to quit): ");
        scanf("%d", &y1);

        if (y1 == -1) break;

        printf("enter y1: ");
        scanf("%d", &x1);

        printf("value selected: %d", table[x1][y1]);
        printf("\n");

        printf("enter x2: ");
        scanf("%d", &y2);

        printf("enter y2: ");
        scanf("%d", &x2);

        printf("value selected: %d", table[x2][y2]);
        printf("\n\n");

        swapValues(x1, y1, x2, y2, table);
    }

    return 0;
}


