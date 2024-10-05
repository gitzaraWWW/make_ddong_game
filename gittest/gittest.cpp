﻿// gittest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <conio.h> // Windows 환경에서 getch 사용을 위한 헤더파일
#include <stdlib.h>
#include <time.h>

// 초기화 함수
void Initialize() {
    printf("게임 초기화 중...\n");
}

// 렌더링 함수
void Render() {
    printf("화면을 렌더링 중...\n");

}

// 업데이트 함수 (입력 처리 포함)
void Update() {
    if (_kbhit()) { // 키가 눌렸는지 확인
        char key = _getch(); // 키 입력을 받음
        printf("입력된 키: %c\n", key);

        // 키에 따른 동작 추가 가능
        if (key == 'q') {
            printf("게임 종료...\n");
            exit(0); // 'q'를 입력하면 게임 종료
        }
    }
}

// 메인 게임 루프
void GameLoop() {
    Initialize();

    clock_t start_time = clock(); // 현재 시간을 기록
    while (1) {
        Update(); // Update는 계속 호출하여 키 입력을 처리
        // 현재 시간과 시작 시간의 차이를 확인하여 1초마다 렌더링
        if ((clock() - start_time) >= CLOCKS_PER_SEC) { // CLOCKS_PER_SEC는 1초
            Render();
            start_time = clock(); // 시간을 초기화하여 다음 1초를 기다림
        }



    }
}

int main() {
    GameLoop();
    return 0;
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.