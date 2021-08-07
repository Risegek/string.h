#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

char* strtok_str = NULL;

int s21_strlen(char* str) {
    int count = 0;
    if (str == NULL) {
        count = -1;
    } else {
        int i = 0;
        while (str[i++] != '\0') {
            count++;
        }
    }
    return count;
}

int s21_strcmp(char* str1, char* str2) {
    int status = 0;
    if (str1 == NULL || str2 == NULL) {
        if (str1 == NULL) status = -1;
        if (str2 == NULL) status = 1;
        if (str1 == NULL && str2 == NULL) status = 0;
    } else {
            int i = 0;
            while (str1[i] != '\0' && str2[i] != '\0') {
                if (str1[i] != str2[i]) {
                    if ((int)str1[i] < (int)str2[i]) {
                        status = 1;
                    } else {
                        status = -1;
                    }
                }
                i++;
            }
            if (str1[i] != '\0') status = 1;
            if (str2[i] != '\0') status = -1;
    }
    return status;
}


int s21_strcpy(char* str1, char* str2) {
    int status = 0;
    if (str1 == NULL || s21_strlen(str1) < s21_strlen(str2)) {
        status = 1;
    } else {
        if (str2 == NULL) {
            str1[0] = '\0';
        } else {
            int i = 0;
            while (1) {
                str1[i] = str2[i];
                if (str2[i] == '\0') {
                    break;
                }
                i++;
            }
        }
    }
    return status;
}


int s21_strcat(char* str1, char* str2) {
    int status = 0;
    if (str1 == NULL) {
        status = 1;
    } else {
        if (str2 != NULL) {
            int i = s21_strlen(str1);
            int j = 0;
            while (1) {
                str1[i] = str2[j];
                if (str2[j] == '\0') {
                    break;
                }
                i++;
                j++;
            }
        }
    }
    return status;
}


char* s21_strchr(char* str1, int sym) {
    char* result = NULL;
    if (str1 != NULL) {
        int i = 0;
        while (1) {
            if (str1[i] == (char)sym) {
                result = &str1[i];
                break;
            }
            if (str1[i] == '\0') {
                break;
            }
            i++;
        }
    }
    return result;
}

char* s21_strstr(char* str1, char* str2) {
    char* result = NULL;
    if (str1 != NULL && str2 != NULL) {
        int i = 0;
        while (1) {
            if (str1[i] == str2[0]) {
                int flag = 0;
                int j = 0, _i = i;
                for (; str2[j] != 0 && str1[_i] != 0; _i++, j++) {
                    if (str1[_i] != str2[j]) {
                        flag = 1;
                    }
                }
                if (str1[_i] == 0 && str2[j] != 0) {
                    flag = 1;
                }
                if (!flag) {
                    result = &str1[i];
                    break;
                }
            }
            if (str1[i] == '\0') {
                break;
            }
            i++;
        }
    }
    return result;
}

char* s21_strtok(char* str, char* delim) {
    if (str != NULL) {
        strtok_str = str;
    }
    char* result = strtok_str;
    int flag = 0;
    if (strtok_str != NULL) {
        int j = 0;
        while (1) {
            for (int i = 0; delim[i] != 0; i++) {
                if (strtok_str[j] == delim[i]) {
                    flag = 1;
                    strtok_str[j] = '\0';
                    result = strtok_str;
                    strtok_str = &strtok_str[j+1];
                    break;
                }
            }
            if (strtok_str[j] == '\0' || flag) {
                    break;
            }
            j++;
        }
    }
    if (!flag) {
        strtok_str = NULL;
    }
    return result;
}
