#include <stdio.h>
#include "s21_string.h"
#define LEN 100

int input(char* str, int* w);
void start(char* str, int w);
void new_line(int* now_w, int w, char* pch);

int main(int argc, char** argv) {
    int status = 0;
    if (argc != 2 || s21_strcmp(argv[1], "-w") != 0) {
        status = 1;
    } else {
        int w = 0;
        char str[LEN];
        if (!input(str, &w)) {
            start(str, w);
        } else {
            status = 1;
        }
    }
    if (status) {
        printf("n/a");
    }
    return status;
}

int input(char* str, int* w) {
    int status = 0;
    char c = ' ';
    if (!scanf("%d%c", w, &c) || *w <= 1) {
        status = 1;
    } else {
        int i = 0;
        c = ' ';
        for (; c != '\n'; i++) {
            c = getchar();
            str[i] = c;
        }
        str[i-1] = '\0';
    }
    return status;
}

void start(char* str, int w) {
    char* pch = s21_strtok(str, " ");
    int now_w = 0;
    while (pch != NULL) {
        int len = s21_strlen(pch);
        if (now_w + len <= w) {
            if (now_w == 0) {
                printf("%s", pch);
                now_w = len;
            } else {
                if (now_w + len == w) {
                    printf("\n%s", pch);
                    now_w = len;
                } else {
                    printf(" %s", pch);
                    now_w = now_w + len + 1;
                }
            }
        } else {
            if (len <= w) {
                printf("\n%s", pch);
                now_w = len;
            } else {
               new_line(&now_w, w, pch);
            }
        }
        pch = s21_strtok(NULL, " ");
    }
}

void new_line(int* now_w, int w, char* pch) {
    if (*now_w + 3 > w) {
        printf("\n");
        *now_w = 0;
    } else {
        if (*now_w != 0) {
            (*now_w)++;
            printf(" ");
        }
    }
    for (int i = 0; pch[i] != '\0'; i++, (*now_w)++) {
        if (*now_w + 2 == w) {
            if (pch[i + 1] != 0) {
                printf("%c-\n", pch[i]);
                *now_w = -1;
            } else {
                printf("%c", pch[i]);
                (*now_w)++;
            }
        } else {
            printf("%c", pch[i]);
        }
    }
}
