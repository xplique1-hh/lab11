#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <windows.h>
struct Roman {
    char name[50];
    char author[50];
    int pages;
    double rating;
    int year;
};
void input(struct Roman r[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nРоман %d\n", i + 1);
        printf("Название: ");
        scanf(" %49[^\n]", r[i].name);
        printf("Автор: ");
        scanf(" %49[^\n]", r[i].author);
        printf("Количество страниц: ");
        scanf("%d", &r[i].pages);
        printf("Средняя оценка (0-10): ");
        scanf("%lf", &r[i].rating);
        printf("Год издания: ");
        scanf("%d", &r[i].year);
    }
}
void show(struct Roman r[], int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (r[i].pages >= 100 && r[i].pages <= 200 && r[i].rating > 5) {
            printf("%s, %s, %d стр., оценка %.1f, %d г.\n",
                r[i].name, r[i].author, r[i].pages, r[i].rating, r[i].year);
            x = 1;
        }
    }
    if (!x) printf("Подходящих романов нет\n");
}
int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct Roman r[3];
    input(r, 3);
    printf("\nРезультат:\n");
    show(r, 3);
    return 0;
}