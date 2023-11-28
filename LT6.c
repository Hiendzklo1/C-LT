#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* binaryToText(const char* binaryString) {
    int length = strlen(binaryString);
    if (length % 8 != 0) {
        fprintf(stderr, "Doan ma nhi phan khong hop le.\n");
        return NULL;
    }
    int textSize = length / 8;
    char* text = (char*)malloc(textSize + 1);
    for (int i = 0; i < textSize; i++) {
        char byte[9]; // 8 bits + null-terminator
        strncpy(byte, binaryString + i * 8, 8);
        byte[8] = '\0';

        int decimalValue = strtol(byte, NULL, 2);
        text[i] = (char)decimalValue;
    }
    text[textSize] = '\0';
    return text;
}
int main() {
    const char* binaryString = "0100100001100101011011000110110001101111";
    char* text = binaryToText(binaryString);
    if (text != NULL) {
        printf("oan ma nhi phan: %s\n", binaryString);
        printf("Ket qua: %s\n", text);
        free(text);
    }
    return 0;
}

