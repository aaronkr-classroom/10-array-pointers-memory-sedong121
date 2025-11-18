#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 3
#define FACES 6

char* colors[FACES] = {
	"white", "red", "blue", "green", "orange", "yellow"
};
char letters[FACES] = { 'W', 'R', 'B', 'G', 'O', 'Y' };
int hexColors[FACES] = {
	0xFFF, 0xF00, 0x00F, 0x0F0, 0xFA0, 0xFF0
};

int cube[LENGTH][LENGTH][FACES];

enum PrintMode {STRING, LETTER, HEX };

void initCube() {
	for (int i = 0; i < FACES; i++) {
		for (int j = 0; j < LENGTH; j++) {
			for (int k = 0; k < LENGTH; k++) {
				cube[i][j][k] = i;
			}
		}
	}

}

void printCube(enum PrintMode mode) {
	const char* labels[FACES] = {
		"Up", "Left", "Front", "Right", "Back", "Down"
	};
	for (int i = 0; i < FACES; i++) {
		printf("%s face:\n", labels[i]);
		for (int j = 0; j < LENGTH; j++) {
			for (int k = 0; k < LENGTH; k++) {
				switch (mode) {
				case STRING:
					printf("%-7s", colors[cube[i][j][k]]);
					break;
				case LETTER:
					printf("%c", letters[cube[i][j][k]]);
					break;
				case HEX:
					printf("%#05x", hexColors[cube[i][j][k]]);
					break;
				}
			}
		}
	}
}

void rotateFace(int face) {

}

void scrambleCube() {

}

void rotateRight() {
	int temp[LENGTH];
	// 오른쪽 면 시계 방향 회전
	for (int i = 0; i < LENGTH; i++) temp[i] = cube[3][i][2];
	for (int i = 0; i < LENGTH; i++) cube[3][i][2] = cube[0][2][2 - i];
	for (int i = 0; i < LENGTH; i++) cube[0][2][2 - i] = cube[1][2 - i][0];
	for (int i = 0; i < LENGTH; i++) cube[1][2 - i][0] = cube[5][0][i];
	for (int i = 0; i < LENGTH; i++) cube[5][0][i] = temp[i];
}

// 쉽게 섞기 함수
void easyScramble() {
	printf("Scrambling...\n");
	for (int i = 0; i < 5; i++) {
		rotateRight();
	}
}

int main(void) {
	initCube();
	printf("Initial cube:\n");
	printCube(HEX);

	printf("Press any key to rotate right:");
	getchar();

	rotateRight();
	printCube(STRING);

	printf("Press any key to scramble:");
	getchar();
 for (int i = 1; i <= 4; i++) {
		easyScramble();
		printCube(LETTER);
		
	}

	return 0;
}