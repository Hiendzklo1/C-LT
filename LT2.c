#include <stdio.h>
void flattenArr(char arr[][10], int rows, int cols, char result[], int *resultSize) {
    *resultSize = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[*resultSize] = arr[i][j];
            (*resultSize)++;
        }
    }
}
int main() {
    char twoDArray[][10] = {{'a', 'b'}, {'c', 'b'}};
    int rows = sizeof(twoDArray) / sizeof(twoDArray[0]);
    int cols = sizeof(twoDArray[0]) / sizeof(twoDArray[0][0]);
    // Khai báo mang mot chieu voi kích thuoc toi da có the là rows * cols
    char flattenedArray[rows * cols];
    int flattenedSize;
    flattenArr(twoDArray, rows, cols, flattenedArray, &flattenedSize);
    printf("Mang mot chieu sau khi flatten:\n");
    for (int i = 0; i < flattenedSize; i++) {
        printf("'%c' ", flattenedArray[i]);
    }
    return 0;
}
