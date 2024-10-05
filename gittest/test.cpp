#include <stdio.h>
#include <conio.h> // Windows 환경에서 getch 사용을 위한 헤더파일
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>


#define WIDTH 50 // 화면 너비
#define TITLE "게임 타이틀"

// 초기화 함수
//void Initialize() {
//    printf("게임 초기화 중...\n");
//}

void PrintTitleArt() {
    printf("\n\n\n\n\n");
    printf("                                         ⠀⠀⠀  ⠀⠀  ⠀⠀⠀  ⠀⠀⣀⣠⡤⠶⠶⠚⠛⠛⠻⠿⢷⣶⡶⢾⣿⢿⣿⣷⣶⣶⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                           \n");
    printf("    ⠀⠀⠀⠀⠀⠀                                       ⠀⠀⣀⣤⠶⠛⠉⠀⡀⠴⣏⡧⠐⠚⢛⡛⠓⠺⣿⣮⡿⠦⢤⡀⠀⠈⣭⠉⠛⠻⠷⣦⣄⡀⠀⠀⠀⠀⠀⠀                            ⠀\n");
    printf("⠀⠀                                            ⠀ ⣠⣶⠟⠉⣤⡄⠀⣠⡛⠃⢠⣦⡄⠀⠀⡛⠛⠀⠰⠿⠟⢧⡀⠀⠻⠦⠀⠀⠀⠶  ⢠⣦⡙⢿⣶⡄⠀⠀⠀⠀⠀⠀                           \n");
    printf("⠀                                            ⣠⡾⠋⠑⠀⠀⠉⠀⠐⠟⠁⢀⣤⡉⠀⠀⠸⢿⠂⠀⣶⡦⠀⠘⠇⠀⠀⠰⠆⠀⣠⣤⡀   ⠀⠉⠀⠙⣿⣆⠀⠀⠀⠀⠀                           \n");
    printf("                                          ⢀⣼⡟⠁⠀⠀⠰⠀⠀⠀⠀⠀⠀⠀⠉⢁⣤⡀⠀⣀⠀⠀⢀⣠⡀⠀⠀⢰⣶⠀⠀⠀⠈⠉⠀⠀⠀⠼⠏  ⠀  ⠈⠻⣦⠀⠀                              \n");
    printf("    ⠀                                   ⢀⣿⠏⡀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠀⠀⣀⡈⠉⠀⠀⠋⠁⠀⠈⠉⠁⠀⠀⠀⠁⠀⠰⠟⠀⠀⠀⠰⠆⠀⠀⠀      ⠀⠘⢧⠀                              \n");
    printf("                                     ⠀⠀ ⣾⡟⢠⠇⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠘⠛⠃⠀⠀⠀⢰⡆⠀⠀⠀⠀⠀⠀⠠⣤⠄⠀⢀⠀⠀⠀⠀⠀⠀     ⠈⣧⠀ ⠀                          \n");
    printf("                                     ⠀ ⠀⣿⣇⠈⣧⡟⣆⢘⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀    ⠀  ⢹⡄⠀                           \n");
    printf("                                         ⠘⣿⣦⣌⣁⠈⠚⠷⢽⣮⣦⣄⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀  ⢀⣼⠃⠀                            \n");
    printf("                                      ⠀⢀⣤⠾⢋⠈⠉⠛⠳⠦⣤⣀⡉⠉⠉⠒⠛⠷⢶⡤⠤⠤⠤⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⣀⣀⡀⠤⠴⠶⢾⣿⣅⠀⠀                            \n");
    printf("                                      ⣴⣿⠿⢿⣿⠃⡀⠀⠀⠀⣀⠈⠉⠛⠒⠲⣦⣤⡤⠤⠤⠤⠤⠤⠤⠤⠤⠴⠶⠖⠲⠶⣶⣒⠛⠛⠋⠉⠉⠀⠀⠀⢀⣀⣈⣻⣿⣦                             \n");
    printf("                                    ⠚⠛⣻⡇⠀⣴⣏⣙⣷⠦⠶⠶⣟⠉⠀⠀⠀   ⠀ ⢠⡤⠤⣤⣀⠀⠀⠀⣤⢶⣄⣠⡭⠿⢶⣄⠀⢀⣤⠶⠶⢦⡤⠼⣿⡏⠉⠙⠻                             \n");
    printf("                                  ⠀⠀⢠⣴⣿⣷⣶⣿⣤⣉⡙⠛⠒⠒⠛⠛⣿⡄  ⢀⣤⠾⠤⠤⠖⠛⢷⣤⣼⣿⠶⣭⣄⣀⣀⢀⣸⣾⣋⣀⣀⣤⡤⣶⣿⣿⣅⠀⠀⠀                             \n");
    printf("              ============================================================================================================================\n");
    printf("\n");
    printf("                        /$$$$$$                                                /$$$$$$$                                                   \n");
    printf("                       /$$__  $$                                              | $$__  $$                                                  \n");
    printf("                      | $$  $__/ /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$       | $$  $ $$ /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ \n");
    printf("                      |  $$$$$$ | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$      | $$$$$$$ | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$\n");
    printf("                       $____  $$| $$  | $$| $$  $ $$| $$$$$$$$| $$  $__/      | $$__  $$| $$  | $$| $$  $__/| $$  $ $$| $$$$$$$$| $$  $__/\n");
    printf("                       /$$  $ $$| $$  | $$| $$  | $$| $$_____/| $$            | $$  $ $$| $$  | $$| $$      | $$  | $$| $$_____/| $$      \n");
    printf("                      |  $$$$$$/|  $$$$$$/| $$$$$$$/|  $$$$$$$| $$            | $$$$$$$/|  $$$$$$/| $$      |  $$$$$$$|  $$$$$$$| $$      \n");
    printf("                       $______/  $______/ | $$____/  $_______/|__/            |_______/  $______/ |__/       $____  $$ $_______/|__/      \n");
    printf("                                          | $$                                                               /$$  $ $$                    \n");
    printf("                                          | $$                                                              |  $$$$$$/                    \n");
    printf("                                          |__/                                                               $______/                     \n");
    printf("              ============================================================================================================================\n");
    printf("                                        ⣾⡟⢿⣄⣈⣽⡿⠿⠟⠛⠿⣿⣿⣿⣿⣿⣿⣹⣯⣿⣤⣾⣚⣿⣲⣿⣚⣧⣤⣿⣾⣷⣾⣿⣾⣟⣋⡉⠉⠉⣿⠀⠙⣿⡄⠀⠀                            \n");
    printf("                                    ⠀⠀ ⣿⡆⣆⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢷⡄⠀⠉⠉⣉⡽⠛⠋⠙⠛⠿⣤⣤⠴⠟⠋⠁⠀⠀⠀⠀⠀⠈⠉⠛⠒⠛⠀⠀   ⢹⡇⠀⠀                             \n");
    printf("                                     ⠀ ⢿⣷⢻⣿⣆⢠⡀⠀⡀⠀⠀⠀⠀⠀⠙⠳⠶⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      ⣸⡇                             ⠀⠀\n");
    printf("                                 ⠀    ⠀⠘⢿⣦⣍⡛⠦⣷⣀⠳⣀⠈⠳⣄⠀⠀⣀⢀⣀⣀⣀⣀⣀⣀⣀⠀⠀⢀⣀⣀⣀⣀⡠⠤⠀⠀⠀⠀⠀⠀⠀  ⢀⣠⣴⠟⠀⠀                             ⠀\n");
    printf("                                ⠀⠀      ⠀⠉⠙⠛⠻⠷⣶⣶⣾⣽⣷⣦⣤⣀⣈⣉⣉⣁⣀⣀⣀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣶⡶⠶⠶⠶⠒⠚⠋⠉⠁⠀⠀⠀⠀⠀                              \n");
}

//커서 이동
void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int loading = 0;


// 렌더링 함수
void Render(int blink) {
    // 안내창
    const char* message = "게임을 시작하려면 p, 종료하려면 x를 누르시오.";
    size_t message_length = strlen(message); // 메세지 길이 측정
    int message_position = 55; //x좌표
    SetCursorPosition(message_position, 30); // y좌표는 20으로 설정
    
    //로딩메시지
    const char* loading_message[] = {
        "가게에 불을 키는 중...",
        "아침 잠과 싸우는중...",
        "재료를 손질하는 중...",
        "테이블을 닦는중..."
    };
    
    if (loading) {
        // 이전 메시지 지우기
        printf("%*s", (int)message_length + message_position, " "); // 메시지 지우기
        SetCursorPosition(message_position, 30); // 원래 위치로 이동
        printf("로딩 중: [");

        // 로딩 바 길이와 대기 시간을 조정
        int loading_length = 30; // 로딩 바의 길이
        int message_index = 0;
        clock_t start_time = clock();
        clock_t message_update_time = clock(); // 메시지 업데이트 시간 기록

        for (int i = 0; i < loading_length; i++) {
            printf("=");
            Sleep(100); // 대기시간
        }
        printf("]\n");

        // 로딩 완료 후 초마다 바뀌는 메시지 출력
        message_update_time = clock(); // 메시지 업데이트 시간 초기화
        while (message_index < 4) {
            if ((clock() - message_update_time) / CLOCKS_PER_SEC >= 1) {
                message_index++;//4번 반복하면 끝나게 조정
                SetCursorPosition(message_position, 30); // 메시지 위치로 이동
                printf("%*s", (int)message_length, " "); // 이전 메시지 지우기
                SetCursorPosition(message_position, 30); // 메시지 위치로 이동
                printf("%s", loading_message[message_index % 4]);
                message_update_time = clock(); // 메시지 업데이트 시간 초기화
            }
            if (_kbhit()) { // 키가 눌렸는지 확인
                char key = _getch();
                if (key == 'x') { // 's' 키를 누르면 게임이 시작되도록 수정하기
                    exit(0);
                }
            }
        }

        exit(0); // 로딩 후 게임 종료를 위해
    } 
    else {
        // 깜빡이는 안내창 효과
        if (blink) {
            printf("%s\n", message);
        }
        else {
            printf("%*s\n", (int)message_length + message_position, " ");
        }
    }
}
// 첫번째 인자인 너비가 unsigned int로 인식되면서 int의 불일치 고로 int로 변환시켜줌
// ㄴ> length = size_t형, position은 int형 둘이합쳐 un~랑 유사해지는데 %*s는 int형을 받아야함 (공부하기!)

// 업데이트 함수 (입력 처리 포함)
void Update() {
    if (_kbhit()) { // 키가 눌렸는지 확인
        char key = _getch(); // 키 입력을 받음
        //printf("입력된 키: %c\n", key);

        // 키에 따른 동작 추가 가능
        if (key == 'x') {
            printf("게임 종료...\n");
            exit(0); // 'q'를 입력하면 게임 종료
        }
        if (key == 'p') {
            loading = 1;//로딩시작
            //printf("게임 시작...\n");
            //exit(0);
        }
    }
}

// 메인 게임 루프
void GameLoop() {
    //Initialize();
    PrintTitleArt(); // 아스키 아트 출력

    int blink = 0; // 배경 위치 오프셋
    clock_t start_time = clock(); // 현재 시간을 기록

    while (1) {
        Update(); // Update는 계속 호출하여 키 입력을 처리

        // 현재 시간과 시작 시간의 차이를 확인하여 1초마다 렌더링
        if ((clock() - start_time) >= CLOCKS_PER_SEC / 2) { // 0.5초마다 업데이트
            //system("cls");

            Render(blink);
            blink = ~blink; // 오프셋 증가, 화면 너비를 넘어가면 초기화
            start_time = clock(); // 시간을 초기화하여 다음 0.1초를 기다림
        }
    }
}

int main() {
    HWND consoleWindow = GetConsoleWindow();
    MoveWindow(consoleWindow, 100, 100, 1280, 720, TRUE); // x, y, width, height
    GameLoop();
    return 0;
}