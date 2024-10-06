// gittest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LAYERS 10

// 재료와 그에 따른 색상 코드 정의
const char* ingredients[] = {
    "빵",        // 4 blocks
    "패티",      // 6 blocks
    "치즈",      // 6 blocks
    "양상추",    // 6 blocks
    "토마토"     // 4 blocks
};

// 각 재료의 블록 문자열 정의
const char* ingredient_blocks[] = {
    "  ■■■■  ", // 빵
    "■■■■■■",  // 패티
    "■■■■■■",  // 치즈
    "■■■■■■",  // 양상추
    "  ■■■■ "   // 토마토
};

// 색상 코드 정의
const char* color_codes[] = {
    "\033[38;5;208m", // 빵: 주황색
    "\033[38;5;94m", // 패티: 빨간색
    "\033[93m", // 치즈: 밝은 노란색
    "\033[92m", // 양상추: 밝은 초록색
    "\033[31m"  // 토마토: 빨간색
};

int has_bread = 0;
int has_patty = 0;
int has_cheese = 0;
int has_lettuce = 0;
int has_tomato = 0;

void display_hamburger(int layers, int ingredient_indexes[]) {
    printf("현재 햄버거:\n");
    for (int i = 0; i < layers; i++) {
        // 각 레이어의 인덱스를 사용하여 재료 출력
        printf("%s%s\033[0m\n", color_codes[ingredient_indexes[i]], ingredient_blocks[ingredient_indexes[i]]);
    }
    printf("\n");
}

int is_hamburger_complete() {
    return has_bread && has_patty && has_cheese;
}

int main() {
    int layers = 0;
    char choice;
    int ingredient_indexes[MAX_LAYERS];

    printf("햄버거 쌓기 게임에 오신 것을 환영합니다!\n");
    printf("재료 선택: q(빵), w(패티), e(치즈), r(양상추), a(토마토)\n");

    while (layers < MAX_LAYERS) {
        printf("재료를 선택하세요: ");

        // 유효한 입력이 들어올 때까지 반복
        while (1) {
            if (scanf_s(" %c", &choice, sizeof(choice)) != 1) {
                printf("잘못된 입력입니다. 다시 시도하세요: ");
                while (getchar() != '\n'); // 버퍼 비우기
                continue;
            }
            break;
        }

        int ingredient_index = -1;

        // 선택한 키에 따라 재료 인덱스 결정
        switch (choice) {
        case 'q': ingredient_index = 0; has_bread = 1; break; // 빵
        case 'w': ingredient_index = 1; has_patty = 1; break; // 패티
        case 'e': ingredient_index = 2; has_cheese = 1; break; // 치즈
        case 'r': ingredient_index = 3; has_lettuce = 1; break; // 양상추
        case 'a': ingredient_index = 4; has_tomato = 1; // 토마토
        default: printf("잘못된 입력입니다. 다시 시도하세요.\n"); continue;
        }

        // 재료 인덱스 저장
        ingredient_indexes[layers] = ingredient_index;

        // 재료 추가
        printf("추가된 재료: %s\n", ingredients[ingredient_index]);
        layers++;

        display_hamburger(layers, ingredient_indexes); // 쌓인 햄버거 표시

        // 햄버거 완성도 체크
        if (is_hamburger_complete()) {
            printf("햄버거가 완성되었습니다! 더 이상 재료를 추가할 수 없습니다.\n");
            break;
        }

        // 계속 쌓을지 결정
        if (layers == 7) {
            printf("계속 하시겠습니까? (y/n): ");
            while (1) {
                if (scanf_s(" %c", &choice, sizeof(choice)) != 1) {
                    printf("잘못된 입력입니다. 다시 시도하세요: ");
                    while (getchar() != '\n'); // 버퍼 비우기
                    continue;
                }
                break;
            }
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
//┌-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------┐
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                        부가왕~                                                                                                                                     │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │   
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//│                                                                                                                                                                                   │
//└-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------┘ 