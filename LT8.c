#include <stdio.h>
#include <string.h>
// H�m kiem tra xem chuoi thu hai c� phai l� tu ho�n vi cua chuoi thu nhat hay kh�ng
int validAnagram(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // Neu do d�i cua hai chuoi kh�ng bang nhau, ch�ng kh�ng the l� tu ho�n vi 
    if (len1 != len2) {
        return 0;
    }
    // Sap xep c�c ki tu trong chuoi thu nhat
    char sortedStr1[256]; // Gia su bang ma ASCII
    strcpy(sortedStr1, str1);
    for (int i = 0; i < len1 - 1; i++) {
        for (int j = i + 1; j < len1; j++) {
            if (sortedStr1[i] > sortedStr1[j]) {
                char temp = sortedStr1[i];
                sortedStr1[i] = sortedStr1[j];
                sortedStr1[j] = temp;
            }
        }
    }
    // Sap xep c�c ki tu trong chuoi thu hai
    char sortedStr2[256];
    strcpy(sortedStr2, str2);
    for (int i = 0; i < len2 - 1; i++) {
        for (int j = i + 1; j < len2; j++) {
            if (sortedStr2[i] > sortedStr2[j]) {
                char temp = sortedStr2[i];
                sortedStr2[i] = sortedStr2[j];
                sortedStr2[j] = temp;
            }
        }
    }
    // So s�nh hai chuoi da sap xep
    return strcmp(sortedStr1, sortedStr2) == 0;
}
int main() {
    char str1[100], str2[100];
    printf("Nhap chuoi thu nhat: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1) - 1] = '\0'; // X�a k? t? newline
    printf("Nhap chuoi thu hai: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2) - 1] = '\0'; // X�a k? t? newline
    if (validAnagram(str1, str2)) {
        printf("%s v� %s la tu hoan vi.\n", str1, str2);
    } else {
        printf("%s v� %s khong la tu hoan vi.\n", str1, str2);
    }
    return 0;
}

