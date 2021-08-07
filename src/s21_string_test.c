#include "s21_string.h"
#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
    int status = 0;
    #ifdef strlen_tests
        s21_strlen_test();
    #else
        #ifdef strcmp_tests
            s21_strcmp_test();
        #else
            #ifdef strcpy_tests
                s21_strcpy_test();
            #else
                #ifdef strcat_tests
                    s21_strcat_test();
                #else
                    #ifdef strchr_tests
                        s21_strchr_test();
                    #else
                        #ifdef strstr_tests
                            s21_strstr_test();
                        #else
                            #ifdef strtok_tests
                                s21_strtok_test();
                            #endif
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
    return status;
}


void s21_strtok_test() {
    char test_str1[] = "Hello qwe asd";
    char test_str2[] = " ";
    char *p, *p1, *p2, *p3;
    printf("Test 1:\ntest string 1- %s\ttest char 2- %s.\n\t", test_str1, test_str2);
    printf("Expected - Hello\n\tqwe\n\tasd\n\tNULL.\n\tStart...\n");
    p = s21_strtok(test_str1, test_str2);
    printf("\tOutput: %s\n", p);
    p1 = s21_strtok(NULL, test_str2);
    printf("\tOutput: %s\n", p1);
    p2 = s21_strtok(NULL, test_str2);
    printf("\tOutput: %s\n", p2);
    p3 = s21_strtok(NULL, test_str2);
    if (!s21_strcmp(p, "Hello") && !s21_strcmp(p1, "qwe") && !s21_strcmp(p2, "asd") && !p3) {
        printf("\tOutput: (null)\n");
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str3 = 0;
    char test_str4[] = " ";
    printf("Test 2:\ntest string 1- (null)\ttest char 2- %s.\n\t", test_str4);
    printf("Expected - NULL.\n\tStart...\n");
    p = s21_strtok(test_str3, test_str4);
    printf("\tOutput: (null))\n");
    if (!p) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str5[] = "RABOTAI POJALUSTA RABOTAI";
    char test_str6[] = " ";
    printf("Test 3:\ntest string 1- %s\ttest char 2- %s.\n\t", test_str5, test_str6);
    printf("Expected - RABOTAI\n\tPOJALUSTA\n\tRABOTAI\n\tNULL.\n\tStart...\n");
    p = s21_strtok(test_str5, test_str6);
    printf("\tOutput: %s\n", p);
    p1 = s21_strtok(NULL, test_str6);
    printf("\tOutput: %s\n", p1);
    p2 = s21_strtok(NULL, test_str6);
    printf("\tOutput: %s\n", p2);
    p3 = s21_strtok(NULL, test_str6);
    printf("\tOutput: (null)\n");
if (!s21_strcmp(p, "RABOTAI") && !s21_strcmp(p1, "POJALUSTA") && !s21_strcmp(p2, "RABOTAI") && !p3) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strstr_test() {
    char test_str1[] = "Hello qwe asd qwe";
    char test_str2[] = "qwe";
    char* p;
    printf("Test 1:\ntest string 1- %s\ttest char 2- %s.\n\t", test_str1, test_str2);
    printf("Expected - qwe asd qwe.\n\tStart...\n");
    p = s21_strstr(test_str1, test_str2);
    printf("\tOutput: %s\n", p);
    if (!s21_strcmp(p, "qwe asd qwe")) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str3 = 0;
    char test_str4[] = "qwe";
    printf("Test 2:\ntest string 1- (null))\ttest char 2- %s.\n\t", test_str4);
    printf("Expected - NULL.\n\tStart...\n");
    p = s21_strstr(test_str3, test_str4);
    printf("\tOutput: (null)\n");
    if (!p) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str5[] = "Hello qwe asd qwe";
    char test_str6[] = "\0";
    printf("Test 3:\ntest string 1- %s\ttest char 2- %s.\n\t", test_str5, test_str6);
    printf("Expected - \\0.\n\tStart...\n");
    p = s21_strstr(test_str5, test_str6);
    printf("\tOutput: %s\n", p);
    if (!s21_strcmp(p, "\0")) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strchr_test() {
    char test_str1[] = "hello";
    char test_str2 = 'e';
    char* p;
    printf("Test 1:\ntest string 1- %s\ttest char 2- %c.\n\t", test_str1, test_str2);
    printf("Expected - e.\n\tStart...\n");
    p = s21_strchr(test_str1, test_str2);
    printf("\tOutput: %c\n", *p);
    if (*p == 'e') {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str3 = 0;
    char test_str4 = 'e';
    printf("Test 2:\ntest string 1- (null)\ttest char 2- %c.\n\t", test_str4);
    printf("Expected - NULL.\n\tStart...\n");
    p = s21_strchr(test_str3, test_str4);
    printf("\tOutput: (null)\n");
    if (!p) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str5[] = "hello";
    char test_str6 = 'z';
    printf("Test 3:\ntest string 1- %s\ttest char 2- %c.\n\t", test_str5, test_str6);
    printf("Expected - NULL.\n\tStart...\n");
    p = s21_strchr(test_str5, test_str6);
    printf("\tOutput: (null))\n");
    if (!p) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str7[] = "hello";
    char test_str8 = '\0';
    printf("Test 4:\ntest string 1- %s\ttest char 2- %c.\n\t", test_str7, test_str8);
    printf("Expected - \\0.\n\tStart...\n");
    p = s21_strchr(test_str7, test_str8);
    printf("\tOutput: %c\n", *p);
    if (*p == '\0') {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcat_test() {
    char test_str1[11] = "hello";
    char test_str2[] = "AAAAA";
    int val;
    printf("Test 1:\ntest string 1- %s\ttest string 2- %s.\n\t", test_str1, test_str2);
    printf("Expected - \"helloAAAAA\".\n\tStart...\n");
    s21_strcat(test_str1, test_str2);
    printf("\tOutput: %s\n", test_str1);
    if (s21_strcmp(test_str1, "helloAAAAA") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str3 = 0;
    char test_str4[] = "AAAAA";
    printf("Test 2:\ntest string 1- (null)\ttest string 2- %s.\n\t", test_str4);
    printf("Expected - 1.\n\tStart...\n");
    val = s21_strcat(test_str3, test_str4);
    printf("\tOutput: %d\n", val);
    if (val == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str5[11] = "qwe";
    char test_str6[] = "QWE";
    printf("Test 1:\ntest string 1- %s\ttest string 2- %s.\n\t", test_str5, test_str6);
    printf("Expected - \"qweQWE\".\n\tStart...\n");
    s21_strcat(test_str5, test_str6);
    printf("\tOutput: %s\n", test_str5);
    if (s21_strcmp(test_str5, "qweQWE") == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}


void s21_strcpy_test() {
    char test_str1[] = "hello";
    char test_str2[] = "AAAAA";
    int val;
    printf("Test 1:\ntest string 1- %s\ttest string 2- %s.\n\t", test_str1, test_str2);
    printf("Expected - \"AAAAA\".\n\tStart...\n");
    s21_strcpy(test_str1, test_str2);
    printf("\tOutput: %s\n", test_str1);
    if (s21_strcmp(test_str1, test_str2) == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str3 = 0;
    char test_str4[] = "AAAAA";
    printf("Test 2:\ntest string 1- (null)\ttest string 2- %s.\n\t", test_str4);
    printf("Expected - 1.\n\tStart...\n");
    val = s21_strcpy(test_str3, test_str4);
    printf("\tOutput: %d\n", val);
    if (val == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str5[] = "a";
    char test_str6[] = "AAAAA";
    printf("Test 3:\ntest string 1- %s\ttest string 2- %s.\n\t", test_str5, test_str6);
    printf("Expected - 1.\n\tStart...\n");
    val = s21_strcpy(test_str5, test_str6);
    printf("\tOutput: %d\n", val);
    if (val == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str7[] = "AAAAAAAAAAA";
    char test_str8[] = "BBBBB";
    printf("Test 4:\ntest string 1- %s\ttest string 2- %s.\n\t", test_str7, test_str8);
    printf("Expected - BBBBB.\n\tStart...\n");
    s21_strcpy(test_str7, test_str8);
    printf("\tOutput: %s\n", test_str7);
    if (s21_strcmp(test_str7, test_str8) == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strlen_test() {
    char test_str[] = "hello";
    printf("Test 1: test string - %s.\n\t", test_str);
    printf("Expected - 5.\n\tStart...\n");
    int len = s21_strlen(test_str);
    printf("\tOutput: %d\n", len);
    if (len == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str2 = 0;
    printf("Test 2: test string - NULL.\n\tExpected - -1.\n\tStart...\n");
    len = s21_strlen(test_str2);
    printf("\tOutput: %d\n", len);
    if (len == -1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str3[] = "";
    printf("Test 3: test string - {empty}.\n\tExpected - 0.\n\tStart...\n");
    len = s21_strlen(test_str3);
    printf("\tOutput: %d\n", len);
    if (len == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test(char* str1, char* str2) {
    char test_str1[] = "hello";
    char test_str2[] = "hello";
    printf("Test 1:\ntest string 1- %s\ttest string 2- %s.\n\t", test_str1, test_str2);
    printf("Expected - 0.\n\tStart...\n");
    int val = s21_strcmp(test_str1, test_str2);
    printf("\tOutput: %d\n", val);
    if (val == 0) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str3[] = "AAAAA";
    char test_str4[] = "BBBBB";
    printf("Test 2:\ntest string 1 - %s\ttest string 2 - %s.\n\t", test_str3, test_str4);
    printf("Expected - 1.\n\tStart...\n");
     val = s21_strcmp(test_str3, test_str4);
    printf("\tOutput: %d\n", val);
    if (val == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str5[] = "BBBBB";
    char test_str6[] = "AAAAA";
    printf("Test 3:\ntest string 1 - %s\ttest string 2 - %s.\n\t", test_str5, test_str6);
    printf("Expected - -1.\n\tStart...\n");
     val = s21_strcmp(test_str5, test_str6);
    printf("\tOutput: %d\n", val);
    if (val == -1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str7[] = "AAAAA";
    char test_str8[] = "AA";
    printf("Test 4:\ntest string 1 - %s\ttest string 2 - %s.\n\t", test_str7, test_str8);
    printf("Expected - 1.\n\tStart...\n");
    val = s21_strcmp(test_str7, test_str8);
    printf("\tOutput: %d\n", val);
    if (val == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str9[] = "";
    char test_str10[] = "AA";
    printf("Test 5:\ntest string 1 - {empty}\ttest string 2 - %s.\n\t", test_str10);
    printf("Expected - -1.\n\tStart...\n");
    val = s21_strcmp(test_str9, test_str10);
    printf("\tOutput: %d\n", val);
    if (val == -1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char test_str11[] = "AA";
    char test_str12[] = "";
    printf("Test 6:\ntest string 1 - %s\ttest string 2 - {empty}.\n\t", test_str11);
    printf("Expected - 1.\n\tStart...\n");
    val = s21_strcmp(test_str11, test_str12);
    printf("\tOutput: %d\n", val);
    if (val == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    char *test_str13 = 0;
    char test_str14[] = "qwe";
    printf("Test 7:\ntest string 1 - NULL\ttest string 2 - %s.\n\t", test_str14);
    printf("Expected - -1.\n\tStart...\n");
    val = s21_strcmp(test_str13, test_str14);
    printf("\tOutput: %d\n", val);
    if (val == -1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
