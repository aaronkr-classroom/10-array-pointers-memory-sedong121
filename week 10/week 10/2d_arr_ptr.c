#include <stdio.h>
#define ROWS 3
#define COLS 5

void printArr(char arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    char data[ROWS][COLS] = { 0 };
    char (*p)[COLS];

    p = data;

    printf("시작 전:\n");
    printArr(data);
    printf("Press any key to continue . . .");
    getchar();

    // 포인터를 사용하여 값 대입
    (*p)[1] = 3;            // data[0][1] = 3
    (*(p + 1))[2] = 4;      // data[1][2] = 4
    (*(p + 2))[4] = 5;      // data[2][4] = 5

    printf("초기 배열:\n");
    printArr(data);
    getchar();

    p = data + 1;           // 두 번째 행
    (*p)[0] = 7;
    (*p)[4] = 8;
    (*p)[3] = 9;            // data[1][3] = 9

    printf("두 번째 수정 후:\n");
    printArr(data);
    getchar();

    char* ptr = &data[0][0];
    *(ptr + 6) = 10;        // data[1][1]
    *(ptr + 10) = 11;       // data[2][0]
    *(ptr + 14) = 28;       // data[2][4]

    printf("포인터 산술 후:\n");
    printArr(data);
    getchar();

    // 첫 번째 행과 세 번째 행 교환
    char temp[COLS];
    for (int i = 0; i < COLS; i++) {
        temp[i] = data[0][i];
        data[0][i] = data[2][i];
        data[2][i] = temp[i];
    }

    printf("행 교환 후:\n");
    printArr(data);
    getchar();

    return 0;
}
