#include <stdio.h>
 
void countOccurrences(char arr[], int size) {
    int visited[256] = {0};
    printf("Ki tu và so lan xuat hien:\n");
    for (int i = 0; i < size; i++) {
        if (!visited[arr[i]]) {
            int count = 0;
            for (int j = i; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            visited[arr[i]] = 1;
            printf("'%c' - %d lan\n", arr[i], count);
        }
    }
}

int main() {
    char array[] = {'a', 'b', 'c', 'b', 'a'};
    int size = sizeof(array) / sizeof(array[0]);
    countOccurrences(array, size);
    return 0;
}
