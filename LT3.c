#include <stdio.h>
int calculateSum(int start, int end) {
    int total = 0;
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }
    for (int i = start; i <= end; i++) {
        total += i;
    }
    return total;
}
int main() {
    int num1, num2;

    printf("Nhap so dau tien: ");
    scanf("%d", &num1);

    printf("Nhap so thu hai: ");
    scanf("%d", &num2);

    int result = calculateSum(num1, num2);
    printf("Tong cua cac so tu %d den %d là %d\n", num1, num2, result);
    return 0;
}

