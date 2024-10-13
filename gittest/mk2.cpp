#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX_HEIGHT 7
#define MAX_WIDTH 5

#define BREAD "\033[33m������\033[0m"    
#define TOMATO "\033[31m������\033[0m"   
#define PATTY "\033[32m������\033[0m"    
#define LETTUCE "\033[34m������\033[0m"  
#define CHEESE "\033[35m������\033[0m"   

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
    customerOrder.height = rand() % (MAX_HEIGHT - 2) + 3; // 3~7��
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
    bug.position = rand() % (MAX_WIDTH); // ���� ��ġ
    bug.active = 1; // ���� Ȱ��ȭ
}

void printBug() {
    if (bug.active) {
        for (int i = 0; i < bug.position; i++) {
            printf(" "); // �������� ��ġ ����
        }
        printf("��\n"); // ���� ǥ��
    }
}

void catchBug() {
    if (bug.active) {
        bug.active = 0; // ���� ���
        printf("������ ��ҽ��ϴ�!\n");
    }
    else {
        playerBurger.height--; // ������ �� ������ ��� �ϳ� �����
        printf("������ ���ƽ��ϴ�! ��ᰡ �ϳ� ��������ϴ�.\n");
    }
}

void moveFallingIngredient(int direction) {
    // ���� �̵� ���� ����
}

void dropIngredient() {
    // ���� �װ� �ִ� ��Ḧ ����߸��� ���� ����
}

void updateGameState() {
    if (bug.active) {
        if (rand() % 10 == 0) {
            spawnBug();
        }
    }
    stackIngredient(); // ��� �ױ�
}

void printGameState() {
    printf("\nCustomer Order:\n");
    printBurger(&customerOrder);

    printf("\nPlayer Burger:\n");
    printBurger(&playerBurger);

    printBug(); // ���� ���� ���
    printf("\n���� �������� ���: %s\n", fallingIngredient);
    printf("����: %d\n", score);
}

void gameLoop() {
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'c') {
                // Ȧ�� ��� ����
            }
            else if (ch == 'v') {
                catchBug(); // ���� ���
            }
            else if (ch == 'a') {
                moveFallingIngredient(-1); // �������� �̵�
            }
            else if (ch == 'd') {
                moveFallingIngredient(1); // ���������� �̵�
            }
            else if (ch == 's') {
                dropIngredient(); // ��� ����߸���
            }
        }

        updateGameState(); // ���� ���� ������Ʈ
        printGameState(); // ���� ���� ���

        // ���� �ӵ� ���� ���� �߰� ����
        // sleep(�ð� ����); �Ǵ� ������ Ÿ�̸� ���
    }
}

int main() {
    srand(time(NULL));
    createCustomerOrder();
    generateFallingIngredient();
    gameLoop();
    return 0;
}