/*求数组的最大公约数算法*/
//#include "test.h"
#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int gcdArray(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

int main() {
    int arr[] = { 24, 36, 48, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("测试数组为: { ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
    printf("最大公约数是：%d\n", gcdArray(arr, n));
    return 0;
}
