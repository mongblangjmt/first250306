네모네모로직 & 스도쿠



팀 구성원
: 20221310 이지원, 20230797 정서영, 20230800 최민영


초록
이 프로그램은 사용자에게 두 가지 게임 중 하나를 선택할 수 있는 인터페이스를 제공한다: 네모네모로직(Picross)과 스도쿠(Sudoku). 각 게임은 별도의 함수로 구현되어 있으며, 사용자 입력을 통해 게임을 진행할 수 있다. 프로그램 시작 시, 사용자에게 네모네모로직, 스도쿠, 종료 옵션이 제공된다. 사용자가 네모네모로직을 선택하면, playPicross 함수가 호출되어 게임이 시작된다. 사용자는 퍼즐 문제를 선택하고, 퍼즐을 해결한다. 사용자가 스도쿠를 선택하면, playSudoku 함수가 호출되어 게임이 시작된다. 보드의 상태가 랜덤하게 초기화되고, 사용자는 숫자를 입력하여 보드를 채운다. 사용자가 종료를 선택하면, 프로그램이 종료된다. 


<보고서 개요>
1. 문제 해석
2. 문제 해석 구현 방법
3. 플로우 차트
4. 오류 가능성
5. 챗gpt 활용 방식
6. 향후 발전 방향


SDL 검사 속성을 ‘아니요’로 바꿔야 합니다. 
[ 문제 해석 ]

네모네모로직 게임의 기본 개념

네모네모로직: 일본에서 유래된 퍼즐 게임으로, 그리드 형태의 도형을 채우는 논리 퍼즐

게임 목표: 주어진 숫자 힌트를 기반으로 그리드의 특정 칸을 채워 숨겨진 그림을 완성

게임 규칙

그리드 구조: 게임은 보통 정사각형 또는 직사각형 그리드에서 진행된다.

숫자 힌트: 각 행과 열의 앞에 숫자 힌트가 주어진다. 이 숫자는 해당 행 또는 열에 연속으로 채워져야 하는 칸의 수를 나타낸다. 예를 들어, '3 1'이라는 숫자 힌트는 해당 행이나 열에 먼저 3개의 연속된 칸이 채워지고, 최소한 한 칸 이상 떨어진 곳에 1개의 칸이 채워져야 함을 의미한다.

논리적 추론: 플레이어는 논리적 추론을 통해 어떤 칸을 채우고 어떤 칸을 비워둘지 결정해야 한다.


네모네모 로직의 특성

문제 출력
격자 구조: 퍼즐은 일정 크기의 격자(grid)로 구성된다, 각 셀은 채워진 상태 또는 비어 있는 상태일 수 있다.
숫자 힌트: 각 행과 열의 바깥쪽에 주어진 숫자 힌트는 해당 행이나 열에 있는 연속된 색칠된 셀의 그룹을 나타낸다. 연속된 그룹 사이에는 하나 이상의 빈 셀이 있어야 한다.


퍼즐 선택 및 문제 변경: 플레이어는 다양한 퍼즐 문제를 선택할 수 있으며, 다른 문제로 전환할 수 있다.


플레이어 상호작용: 플레이어는 행과 열을 선택하여 셀을 색칠하거나 비워서 퍼즐을 푼다. 셀을 토글(toggle)하여 상태를 변경할 수 있다. ( ■ or ‘ ’)


초기화 및 판 초기 상태: 퍼즐이 시작되면 모든 셀은 비어 있는 상태에서 시작한다. 플레이어는 제공된 숫자 힌트를 참고하여 셀을 색칠해 나간다.


스도쿠 게임의 기본 개념

- 스도쿠: 일본에서 유래된 숫자 퍼즐 게임으로, 9x9 그리드에 숫자를 채우는 논리 퍼즐이다. '수(數)'와 '독(独)'이라는 일본어에서 이름이 유래되었다.

- 게임 목표: 9x9 그리드에 1부터 9까지의 숫자를 채워 모든 행, 열, 3x3 서브그리드에 중복되지 않게 하는 것이다.

- 게임 규칙:

- 그리드 구조: 스도쿠는 9x9 그리드에서 진행되며, 이 그리드는 3x3 크기의 서브그리드 9개로 나뉜다.

- 숫자 배치: 각 행, 각 열, 각 3x3 서브그리드에는 1부터 9까지의 숫자가 한 번씩만 들어가야 한다.

- 초기 숫자: 게임은 일부 칸에 이미 숫자가 채워진 상태로 시작된다. 이 숫자들은 퍼즐의 난이도를 결정한다.

스도쿠의 특성

문제 출력

유효성 검사 : 특정 위치에 숫자를 넣을 때, 그 숫자가 해당 행, 열, 그리고 3x3 서브 그리드에서 유일해야 한다. 이를 통해 스도쿠 판의 유효성을 유지한다.

랜덤성 : 게임의 재미를 위해 초기 스도쿠 판을 랜덤하게 변경한다. 하지만 변경된 숫자가 여전히 스도쿠 규칙을 따르도록 해야 한다.

게임 인터페이스 : 사용자가 스도쿠를 풀 수 있도록 하는 인터페이스를 제공하며, 사용자의 입력을 받아 보드를 업데이트한다.

출력 형식 : 사용자에게 현재 보드 상태를 보기 좋게 출력하여, 진행 상황을 쉽게 파악할 수 있도록 한다.




[ 문제 해석 구현 방법-코드설명 ]



1. 게임 선택 메뉴 (메인 함수)
: 프로그램 시작 시 사용자가 두 게임 중 하나를 선택할 수 있는 메뉴를 표시한다.
입력에 따라 playPicross 함수(네모네모로직 게임) 또는 playSudoku 함수(스도쿠 게임)를 호출한다.

- 게임 선택 함수 (메인 함수)


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

2. 네모네모로직 게임

< 문제 출력 / 퍼즐 선택 및 문제 변경 >

네모네모로직 문제 출력 함수
: printPuzzle 함수는 선택된 문제 번호에 따라 네모네모로직 퍼즐의 힌트를 출력하고 현재 퍼즐 상태를 표시한다.

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

< 플레이어 상호작용 >

셀 토글 함수
: toggleCell 함수는 특정 행(row)과 열(col)의 셀을 채우거나 비우는 역할을 한다.

// 특정 행과 열의 칸을 토글하는 함수


void toggleCell(int puzzle[SIZE][SIZE], int row, int col) {
    puzzle[row][col] = !puzzle[row][col];
}

퍼즐 초기화 함수
: initPuzzle 함수는 퍼즐을 모두 비워 초기 상태로 만든다.


void initPuzzle(int puzzle[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            puzzle[i][j] = 0;
        }
    }
}


네모네모로직 게임 플레이 함수
: playPicross 함수는 네모네모로직 게임을 실행한다.
문제 번호를 입력받아 해당 퍼즐을 초기화하고, 사용자가 셀을 토글할 수 있게 한다.
0 0을 입력하면 프로그램이 종료되고, 0 1을 입력하면 다른 문제로 넘어간다.

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


3. 스도쿠 게임

초기 스도쿠 판
: 0은 빈 칸을 의미한다.

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


스도쿠 출력 함수
: printSudoku 함수는 스도쿠 보드를 출력한다. 3x3 구역을 시각적으로 구분하기 위해 '|'와 '-'를 사용한다.

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


유효성 검사 함수
: isValid 함수는 특정 위치에 숫자를 넣을 수 있는지 확인한다.
행, 열, 그리고 3x3 서브 그리드에서 중복 여부를 검사한다.

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



랜덤 숫자 변경 함수
: randomizeNonEmptyCells 함수는 스도쿠 보드의 0이 아닌 셀의 숫자들을 랜덤으로 변경한다. 변경된 숫자는 유효성 검사를 통과해야 한다.

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


스도쿠 게임 플레이 함수
: playSudoku 함수는 스도쿠 게임을 실행한다.
사용자에게 행, 열, 그리고 숫자를 입력받아 해당 위치에 숫자를 넣는다.
사용자가 0 0 0을 입력하면 게임이 종료된다.


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


[ 오류 가능성 ]

- 헤더 파일 관련 문제
conio.h는 표준 라이브러리가 아니며, Windows 환경에서 주로 사용된다. 다른 운영 체제에서는 이 라이브러리가 없을 수 있다.
system("cls");는 Windows 환경에서 화면을 지우는 명령어이다. 다른 운영 체제에서는 system("clear");를 사용해야 한다.

- 사용자 입력 문제
사용자가 숫자가 아닌 다른 문자를 입력할 경우 scanf는 입력 오류를 일으킬 수 있다. 이 경우 버퍼에 남아있는 입력을 처리해야 한다.

- 퍼즐 및 보드 초기화 문제
randomizeNonEmptyCells 함수는 초기 보드의 값들을 바꾸는 함수로, 프로그램을 재실행할 때마다 동일한 값을 가질 수 있다. 따라서 매 실행마다 동일한 보드가 생성될 수 있다.
playPicross에서 퍼즐을 다시 초기화하는 경우, 초기화 전 상태를 저장하지 않으면 이전 입력값이 사라진다.

- 무한 루프 가능성
getchar();를 사용하여 입력을 기다리는 부분이 있지만, 이는 실제로 동작하지 않을 수 있습니다. 이는 입력 버퍼를 제대로 비우지 않을 수 있다.




[ Chat GPT 활용 방식 ]

- 문제별로 스도쿠 게임과 네모네모로직 게임 개별적으로 만든 후 합칠 때 활용
: 개별적으로 개발 된 코드들을 하나의 통합된 게임으로 합치는 과정에서 Chat GPT를 활용했다. 각 게임의 독립적인 로직과 플레이 방식을 어떻게 통합할 수 있는지에 대한 아이디어와 구현 방법을 찾아내어, 사용자가 게임 선택 메뉴를 통해 네모네모로직과 스도쿠를 즐길 수 있는 기능을 구현할 수 있었다.

- 스도쿠 숫자 힌트 문제별로 랜덤돌릴 때 활용
: 코드를 작성하는 과정에서 스도쿠에서 숫자가 랜덤으로 생성되지 않는 문제가 발생했을 때, Chat GPT를 활용하여 이를 해결했다. 챗지피티의 도움으로 코드에서 난수를 생성하는 방법을 다시 검토하고 수정함으로써, 각 스도쿠 게임이 실행될 때마다 무작위로 숫자가 생성되도록 보장할 수 있었다.

- 오류 가능성 찾을 때 활용
: ChatGPT는 다양한 프로그래밍 문제와 솔루션에 대한 데이터를 학습했기 때문에, 여러 유형의 오류와 그 해결 방법에 대해 방대한 지식을 보유하고 있기에 오류 가능성을 찾을 때 효과적이다.

주석 활용
: 각 기능에 대한 주석을 상세히 작성할 때 활용했다. 이를 통해 각 부분의 역할을 명확히 이해할 수 있다.




[ 향후 발전 방향 ]

1. 기능 확장

- 난이도 설정: 다양한 난이도를 제공하여 초급, 중급, 고급 수준의 퍼즐을 구현할 수 있다. 이를 위해 퍼즐 생성 알고리즘을 개선하고, 난이도별로 다른 규칙이나 제약 조건을 추가할 수 있다.

- 힌트 시스템: 사용자가 퍼즐을 풀기 어려워할 때 힌트를 제공하는 시스템을 도입한다. 예를 들어, 특정 칸에 들어갈 수 있는 숫자를 제한하거나, 잘못된 배치를 교정하는 등의 힌트를 제공할 수 있다.


2. 사용자 경험 향상

- 그래픽 및 UI 개선: 그래픽과 사용자 인터페이스(UI)를 개선하여 더 직관적이고 시각적으로 매력적인 게임을 만든다. 반응형 디자인을 도입하여 다양한 장치(예: 스마트폰, 태블릿, PC)에서도 원활하게 작동하도록 할 수 있다.
