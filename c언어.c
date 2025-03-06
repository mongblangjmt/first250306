#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 5
#define N 9

// 초기 네모네모로직 판을 출력하는 함수
void printPuzzle(int puzzle[SIZE][SIZE], int problemNumber) {
    system("cls");  // 화면을 지웁니다 (Windows 환경)
    if (problemNumber == 1) {
        printf("<네모네모로직 1번째 문제>\n");
        printf("\n");
        printf("       1 1  \n");
        printf("   0 3 1 1 0 \n");
    }
    else if (problemNumber == 2) {
        printf("<네모네모로직 2번째 문제>\n");
        printf("\n");
        printf("      1 1 1 1 \n");
        printf("    1 1 3 1 1 \n");
    }
    else if (problemNumber == 3) {
        printf("<네모네모로직 3번째 문제>\n");
        printf("\n");
        printf("      1   1   \n");
        printf("    3 1 3 1 5 \n");
    }

    for (int i = 0; i < SIZE; i++) {
        if (problemNumber == 1) {
            if (i == 0) printf("2 ");
            else if (i == 1) printf("1 ");
            else if (i == 2) printf("1 ");
            else if (i == 3) printf("1 ");
            else if (i == 4) printf("2 ");
        }
        else if (problemNumber == 2) {
            if (i == 0) printf("1 1");
            else if (i == 1) printf("1 3");
            else if (i == 2) printf("1 1");
            else if (i == 3) printf("  1");
            else if (i == 4) printf("  3");
        }
        else if (problemNumber == 3) {
            if (i == 0) printf("  1");
            else if (i == 1) printf("3 1");
            else if (i == 2) printf("1 3");
            else if (i == 3) printf("3 1");
            else if (i == 4) printf("  1");
        }

        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 1)
                printf(" ■");  // ■는 네모네모로직에서 채워진 부분을 나타냅니다
            else
                printf("  ");  // .는 빈 부분을 나타냅니다
        }
        printf("\n");
    }
    printf("\n");
}

// 특정 행과 열의 칸을 토글하는 함수
void toggleCell(int puzzle[SIZE][SIZE], int row, int col) {
    puzzle[row][col] = !puzzle[row][col];
}
//퍼즐 초기화 함수
void initPuzzle(int puzzle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            puzzle[i][j] = 0;
        }
    }
}

// 초기 스도쿠 판
int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// 스도쿠 판 출력 함수
void printSudoku() {
    printf("\n     스도쿠 문제   \n");
    printf("----------------------\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                printf("  ");
            }
            else {
                printf("%d ", board[row][col]);
            }
            if ((col + 1) % 3 == 0 && col != N - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row != N - 1) {
            printf("----------------------\n");
        }
    }
    printf("----------------------\n");
}

// 유효성 검사 함수: 특정 위치에 숫자를 넣을 수 있는지 확인
bool isValid(int row, int col, int num) {
    // 같은 행에 중복 확인
    for (int c = 0; c < N; c++) {
        if (board[row][c] == num) {
            return false;
        }
    }

    // 같은 열에 중복 확인
    for (int r = 0; r < N; r++) {
        if (board[r][col] == num) {
            return false;
        }
    }

    // 3x3 서브 그리드에 중복 확인
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == num) {
                return false;
            }
        }
    }

    return true; // 유효하다면 true 반환
}

// 랜덤으로 초기 스도쿠 판에 있는 0이 아닌 숫자들을 다른 숫자로 바꾸기
void randomizeNonEmptyCells() {
    srand(time(NULL));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] != 0) { // 0이 아닌 경우에만 처리
                int original = board[row][col];
                int newNumber;

                do {
                    newNumber = rand() % 9 + 1; // 1에서 9 사이의 랜덤 숫자
                } while (!isValid(row, col, newNumber) || newNumber == original);

                board[row][col] = newNumber;
            }
        }
    }
}
//네모네모로직 게임 플레이 함수
void playPicross() {
    int puzzle[SIZE][SIZE];
    int row, col;
    int problemNumber;

    while (1) {
        printf("문제를 선택하세요 (1-3), 종료하려면 0을 누르세요: ");
        scanf("%d", &problemNumber);

        if (problemNumber == 0)
            return;

        if (problemNumber < 1 || problemNumber > 3) {
            printf("잘못된 입력입니다. 1-3 사이의 값을 입력하세요.\n");
            getchar();  // 입력을 기다립니다 (Windows 환경)
            continue;
        }

        initPuzzle(puzzle);

        while (1) {
            printPuzzle(puzzle, problemNumber);
            printf("열과 행을 입력하세요 (ex : 1 5) ");
            printf("입력을 취소하려면 다시 번호를 입력하세요.\n");
            printf("종료하려면 0 0 을 다른 문제로 넘어가려면 0 1 을 누르세요.\n");
            scanf("%d %d", &row, &col);

            if (row == 0 && col == 0)
                return;

            if (row == 0 && col == 1)
                break;

            if (row >= 1 && row <= 5 && col >= 1 && col <= 5) {
                toggleCell(puzzle, row - 1, col - 1);
            }
            else {
                printf("Invalid input. Please enter values between 1 and 5.\n");
                getchar();  // 입력을 기다립니다 (Windows 환경)
            }
        }
    }
}

void playSudoku() {
    randomizeNonEmptyCells(); // 초기 스도쿠 판에 있는 0이 아닌 숫자들을 랜덤하게 바꿈
    printSudoku(); // 초기 스도쿠 판 출력

    int row, col, num;

    while (1) {
        printf("행, 열, 숫자를 입력하세요 (예: 1 1 5), 종료하려면 0 0 0을 입력하세요: ");
        scanf("%d %d %d", &row, &col, &num);

        if (row == 0 && col == 0 && num == 0)
            return;

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
            printf("잘못된 입력입니다. 1-9 사이의 값을 입력하세요.\n");
            continue;
        }

        if (isValid(row - 1, col - 1, num)) {
            board[row - 1][col - 1] = num;
            printSudoku();
        }
        else {
            printf("해당 위치에 해당 숫자를 넣을 수 없습니다.\n");
        }
    }
}
//게임 선택 메뉴 (메인 함수)
int main() {
    int choice;

    while (1) {
        printf("게임을 선택하세요:\n");
        printf("1. 네모네모로직\n");
        printf("2. 스도쿠\n");
        printf("0. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            playPicross();
            break;
        case 2:
            playSudoku();
            break;
        case 0:
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}
