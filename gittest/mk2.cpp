#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX_HEIGHT 7
#define MAX_WIDTH 5

#define BREAD "\033[33m■■■■■\033[0m"    
#define TOMATO "\033[31m■■■■■\033[0m"   
#define PATTY "\033[32m■■■■■\033[0m"    
#define LETTUCE "\033[34m■■■■■\033[0m"  
#define CHEESE "\033[35m■■■■■\033[0m"   

const char* ingredients[] = { BREAD, TOMATO, PATTY, LETTUCE, CHEESE };

typedef struct {
    const char* layers[MAX_HEIGHT];
    int height;
} Burger;

typedef struct {
    int position;
    int active;
} Bug;

Burger customerOrder;
Burger playerBurger;
const char* fallingIngredient;
Bug bug;
int score = 0;

void createCustomerOrder() {
    customerOrder.height = rand() % (MAX_HEIGHT - 2) + 3; // 3~7층
    for (int i = 0; i < customerOrder.height; i++) {
        int randomIndex = rand() % 5;
        customerOrder.layers[i] = ingredients[randomIndex];
    }
}

void generateFallingIngredient() {
    int randomIndex = rand() % 5; // 0~4
    fallingIngredient = ingredients[randomIndex];
}

void stackIngredient() {
    if (playerBurger.height < MAX_HEIGHT) {
        playerBurger.layers[playerBurger.height] = fallingIngredient;
        playerBurger.height++;
    }
}

void printBurger(Burger* burger) {
    for (int i = 0; i < burger->height; i++) {
        printf("%s\n", burger->layers[i]);
    }
}

void spawnBug() {
    bug.position = rand() % (MAX_WIDTH); // 랜덤 위치
    bug.active = 1; // 벌레 활성화
}

void printBug() {
    if (bug.active) {
        for (int i = 0; i < bug.position; i++) {
            printf(" "); // 공백으로 위치 설정
        }
        printf("★\n"); // 벌레 표시
    }
}

void catchBug() {
    if (bug.active) {
        bug.active = 0; // 벌레 잡기
        printf("벌레를 잡았습니다!\n");
    }
    else {
        playerBurger.height--; // 벌레를 못 잡으면 재료 하나 사라짐
        printf("벌레를 놓쳤습니다! 재료가 하나 사라졌습니다.\n");
    }
}

void moveFallingIngredient(int direction) {
    // 실제 이동 로직 구현
}

void dropIngredient() {
    // 현재 쌓고 있는 재료를 떨어뜨리는 로직 구현
}

void updateGameState() {
    if (bug.active) {
        if (rand() % 10 == 0) {
            spawnBug();
        }
    }
    stackIngredient(); // 재료 쌓기
}

void printGameState() {
    printf("\nCustomer Order:\n");
    printBurger(&customerOrder);

    printf("\nPlayer Burger:\n");
    printBurger(&playerBurger);

    printBug(); // 벌레 상태 출력
    printf("\n현재 떨어지는 재료: %s\n", fallingIngredient);
    printf("점수: %d\n", score);
}

void gameLoop() {
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'c') {
                // 홀드 기능 구현
            }
            else if (ch == 'v') {
                catchBug(); // 벌레 잡기
            }
            else if (ch == 'a') {
                moveFallingIngredient(-1); // 왼쪽으로 이동
            }
            else if (ch == 'd') {
                moveFallingIngredient(1); // 오른쪽으로 이동
            }
            else if (ch == 's') {
                dropIngredient(); // 재료 떨어뜨리기
            }
        }

        updateGameState(); // 게임 상태 업데이트
        printGameState(); // 게임 상태 출력

        // 게임 속도 증가 로직 추가 가능
        // sleep(시간 조정); 또는 적절한 타이머 사용
    }
}

int main() {
    srand(time(NULL));
    createCustomerOrder();
    generateFallingIngredient();
    gameLoop();
    return 0;
}