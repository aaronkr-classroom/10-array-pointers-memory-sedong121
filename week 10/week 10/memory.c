#include <stdio.h>

// 전역 변수
int* BP;
int* SP;
int stack[1024];     // 가짜 스택(값을 저장하는 공간)
int stackIndex = 0;  // 스택 top

void Show() {
    printf("-----------------------------------\n");
    printf("현재 스택 상태 (Top -> Bottom):\n");

    for (int i = stackIndex - 1; i >= 0; i--) {
        int value = stack[i];
        printf("stack[%d] = %d\n", i, value);
    }

    printf("Base Pointer (BP): %p\n", (void*)BP);
    printf("Stack Pointer (SP): %p\n", (void*)SP);
    printf("-----------------------------------\n");
}

void push(int value) {
    stack[stackIndex++] = value;
    SP = &stack[stackIndex];
}

int pop() {
    if (stackIndex > 0) {
        SP = &stack[--stackIndex];
        return stack[stackIndex];
    }
    return -1;
}

void Test(int a, int b, int c) {
    int x = a + b;
    int y = b + c;
    int z = c + a;

    printf("Test() 함수 진입 - 스택 프레임 생성\n");

    // 이전 BP 저장
    push((int)BP);

    // 지역 변수 주소 저장(정수로 변환)
    push((int)&x);
    push((int)&y);
    push((int)&z);

    Show();

    printf("Test() 함수 반환 - 스택 프레임 해제\n");
    pop(); // z
    pop(); // y
    pop(); // x

    BP = (int*)pop();   // BP 복구

    Show();
}

int main(void) {
    int a = 10, b = 20, c = 30;

    printf("Main() 함수 시작 - 초기 스택 상태\n");

    push((int)&a);
    push((int)&b);
    push((int)&c);

    BP = &stack[0];

    Show();

    printf("Test() 함수 호출\n");
    Test(a, b, c);

    printf("Main() 함수 종료 - 스택 상태 복구\n");

    pop();
    pop();
    pop();

    Show();

    return 0;
}
