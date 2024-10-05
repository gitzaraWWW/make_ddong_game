// gittest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LAYERS 10

const char* ingredients[] = {
    "빵",      // q
    "패티",    // w
    "치즈",    // e
    "양상추",  // r
    "토마토",  // a
    "감자튀김", // s
    "콜라"     // d
};

void display_hamburger(const char* layers[], int count) {
    printf("현재 햄버거:\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s\n", layers[i]);
    }
}

int main() {
    const char* burger[MAX_LAYERS]; // 쌓인 재료를 저장할 배열
    int layers = 0;
    char choice;

    srand(time(NULL)); // 난수 초기화

    printf("햄버거 쌓기 게임에 오신 것을 환영합니다!\n");
    printf("재료 선택: q(빵), w(패티), e(치즈), r(양상추), a(토마토), s(감자튀김), d(콜라)\n");

    while (layers < MAX_LAYERS) {
        printf("재료를 선택하세요: ");
        scanf_s(" %c", &choice, sizeof(choice)); // scanf_s 사용

        int ingredient_index = -1;

        // 선택한 키에 따라 재료 인덱스 결정
        switch (choice) {
        case 'q': ingredient_index = 0; break; // 빵
        case 'w': ingredient_index = 1; break; // 패티
        case 'e': ingredient_index = 2; break; // 치즈
        case 'r': ingredient_index = 3; break; // 양상추
        case 'a': ingredient_index = 4; break; // 토마토
        case 's': ingredient_index = 5; break; // 감자튀김
        case 'd': ingredient_index = 6; break; // 콜라
        default: printf("잘못된 입력입니다. 다시 시도하세요.\n"); continue;
        }

        // 재료 추가
        printf("추가된 재료: %s\n", ingredients[ingredient_index]);
        burger[layers] = ingredients[ingredient_index]; // 재료 저장
        layers++;

        display_hamburger(burger, layers); // 쌓인 햄버거 표시

        // 계속 쌓을지 결정
        if (layers < MAX_LAYERS) {
            printf("계속 하시겠습니까? (y/n): ");
            scanf_s(" %c", &choice, sizeof(choice)); // scanf_s 사용
            if (choice != 'y') {
                break;
            }
        }
    }

    printf("게임 종료! 쌓은 햄버거 층 수: %d\n", layers);
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