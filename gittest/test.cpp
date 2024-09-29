#include <stdio.h>
#include <conio.h> // Windows ȯ�濡�� getch ����� ���� �������
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>


#define WIDTH 50 // ȭ�� �ʺ�
#define TITLE "���� Ÿ��Ʋ"

// �ʱ�ȭ �Լ�
//void Initialize() {
//    printf("���� �ʱ�ȭ ��...\n");
//}

void PrintTitleArt() {
    printf("\n\n\n\n\n");
    printf("              ============================================================================================================================\n");
    printf("\n");
    printf("                                          /$$   /$$     /$$ /$$                         /$$                           /$$              \n");
    printf("                                         |__/  | $$    |__/| $$                        | $$                          | $$              \n");
    printf("                   /$$$$$$$ /$$$$$$/$$$$  /$$ /$$$$$$   /$$| $$$$$$$         /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$  /$$$$$$   /$$   /$$\n");
    printf("                  /$$_____/| $$_  $$_  $$| $$|_  $$_/  | $$| $$__  $$       /$$_____/|_  $$_/   /$$__  $$ /$$__  $$|_  $$_/  | $$  | $$\n");
    printf("                 |  $$$$$$ | $$ \\ $$ \\ $$| $$  | $$    | $$| $$  \\ $$      |  $$$$$$   | $$    | $$  \\ $$| $$  \\__/  | $$    | $$  | $$\n");
    printf("                  \\____  $$| $$ | $$ | $$| $$  | $$ /$$| $$| $$  | $$       \\____  $$  | $$ /$$| $$  | $$| $$        | $$ /$$| $$  | $$\n");
    printf("                  /$$$$$$$/| $$ | $$ | $$| $$  |  $$$$/| $$| $$  | $$       /$$$$$$$/  |  $$$$/|  $$$$$$/| $$        |  $$$$/|  $$$$$$$\n");
    printf("                 |_______/ |__/ |__/ |__/|__/   \\___/  |__/|__/  |__/      |_______/    \\___/   \\______/ |__/         \\___/   \\____  $$\n");
    printf("                                                                                                                              /$$  | $$\n");
    printf("                                                                                                                             |  $$$$$$/\n");
    printf("                                                                                                                              \\______/ \n");
    printf("              ============================================================================================================================\n");

}
//Ŀ�� �̵�
void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int loading = 0;


// ������ �Լ�
void Render(int blink) {
    // �ȳ�â
    const char* message = "������ �����Ϸ��� p, �����Ϸ��� x�� �����ÿ�.";
    size_t message_length = strlen(message); // �޼��� ���� ����
    int message_position = 55; //x��ǥ
    SetCursorPosition(message_position, 30); // y��ǥ�� 20���� ����
    
    //�ε��޽���
    const char* loading_message[] = {
        "���尣�� ���� ���Ǵ� ��...",
        "��ħ ��� �ο����...",
        "����� ���� ì�ܸԴ� ��...",
        "�������� ������ �����ϴ� ��..."
    };
    
    if (loading) {
        // ���� �޽��� �����
        printf("%*s", (int)message_length + message_position, " "); // �޽��� �����
        SetCursorPosition(message_position, 30); // ���� ��ġ�� �̵�
        printf("�ε� ��: [");

        // �ε� �� ���̿� ��� �ð��� ����
        int loading_length = 30; // �ε� ���� ����
        int message_index = 0;
        clock_t start_time = clock();
        clock_t message_update_time = clock(); // �޽��� ������Ʈ �ð� ���

        for (int i = 0; i < loading_length; i++) {
            printf("=");
            Sleep(100); // ���ð�
        }
        printf("]\n");

        // �ε� �Ϸ� �� �ʸ��� �ٲ�� �޽��� ���
        message_update_time = clock(); // �޽��� ������Ʈ �ð� �ʱ�ȭ
        while (message_index < 4) {
            if ((clock() - message_update_time) / CLOCKS_PER_SEC >= 1) {
                message_index++;//4�� �ݺ��ϸ� ������ ����
                SetCursorPosition(message_position, 30); // �޽��� ��ġ�� �̵�
                printf("%*s", (int)message_length, " "); // ���� �޽��� �����
                SetCursorPosition(message_position, 30); // �޽��� ��ġ�� �̵�
                printf("%s", loading_message[message_index % 4]);
                message_update_time = clock(); // �޽��� ������Ʈ �ð� �ʱ�ȭ
            }
            if (_kbhit()) { // Ű�� ���ȴ��� Ȯ��
                char key = _getch();
                if (key == 'x') { // 's' Ű�� ������ ������ ���۵ǵ��� �����ϱ�
                    exit(0);
                }
            }
        }

        exit(0); // �ε� �� ���� ���Ḧ ����
    } 
    else {
        // �����̴� �ȳ�â ȿ��
        if (blink) {
            printf("%s\n", message);
        }
        else {
            printf("%*s\n", (int)message_length + message_position, " ");
        }
    }
}
// ù��° ������ �ʺ� unsigned int�� �νĵǸ鼭 int�� ����ġ ��� int�� ��ȯ������
// ��> length = size_t��, position�� int�� �������� un~�� ���������µ� %*s�� int���� �޾ƾ��� (�����ϱ�!)

// ������Ʈ �Լ� (�Է� ó�� ����)
void Update() {
    if (_kbhit()) { // Ű�� ���ȴ��� Ȯ��
        char key = _getch(); // Ű �Է��� ����
        //printf("�Էµ� Ű: %c\n", key);

        // Ű�� ���� ���� �߰� ����
        if (key == 'x') {
            printf("���� ����...\n");
            exit(0); // 'q'�� �Է��ϸ� ���� ����
        }
        if (key == 'p') {
            loading = 1;//�ε�����
            //printf("���� ����...\n");
            //exit(0);
        }
    }
}

// ���� ���� ����
void GameLoop() {
    //Initialize();
    PrintTitleArt(); // �ƽ�Ű ��Ʈ ���

    int blink = 0; // ��� ��ġ ������
    clock_t start_time = clock(); // ���� �ð��� ���

    while (1) {
        Update(); // Update�� ��� ȣ���Ͽ� Ű �Է��� ó��

        // ���� �ð��� ���� �ð��� ���̸� Ȯ���Ͽ� 1�ʸ��� ������
        if ((clock() - start_time) >= CLOCKS_PER_SEC / 2) { // 0.5�ʸ��� ������Ʈ
            //system("cls");

            Render(blink);
            blink = ~blink; // ������ ����, ȭ�� �ʺ� �Ѿ�� �ʱ�ȭ
            start_time = clock(); // �ð��� �ʱ�ȭ�Ͽ� ���� 0.1�ʸ� ��ٸ�
        }
    }
}

int main() {
    HWND consoleWindow = GetConsoleWindow();
    MoveWindow(consoleWindow, 100, 100, 1280, 720, TRUE); // x, y, width, height
    GameLoop();
    return 0;
}