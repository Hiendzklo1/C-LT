#include <stdio.h>
void uniqueElements(int arr1[], int size1, int arr2[], int size2, int result[], int *resultSize) {
    *resultSize = 0;
    for (int i = 0; i < size1; i++) {
        int isUnique = 1;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            result[*resultSize] = arr1[i];
            (*resultSize)++;
        }
    }
    for (int i = 0; i < size2; i++) {
        int isUnique = 1;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            result[*resultSize] = arr2[i];
            (*resultSize)++;
        }
    }
}
int main() { 
    int size1, size2;
    printf("Nhap kich thuoc cua mang thu nhat: ");
    scanf("%d", &size1);
    int array1[size1];
    printf("Nhap cac phan tu cua mang thu nhat:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Nhap kich thuoc cua mang thu hai: ");
    scanf("%d", &size2);
    int array2[size2];
    printf("Nhap cac phan tu cua mang thu hai:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &array2[i]);
    }
    // Kích thuoc toi da cua mang ket qua có the là size1 + size2
    int resultArray[size1 + size2];
    int resultSize;
    uniqueElements(array1, size1, array2, size2, resultArray, &resultSize);
    printf("Cac phan tu doc nhat giua hai mang la: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", resultArray[i]);
    }
    return 0;
}

