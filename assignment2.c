#include <stdio.h>

int isJumpingNumber(int num) {
    
    int digits[10];
    int count = 0;

    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

   
    for (int i = 0; i < count - 1; i++) {
        if (digits[i] != digits[i + 1] + 1 && digits[i] != digits[i + 1] - 1) {
            return 0;  
        }
    }

    return 1;  
}

int main() {
    int largest = 0;

    for (int i = 100; i <= 999; i++) {
        if (isJumpingNumber(i) && i > largest) {
            largest = i;
        }
    }

    printf("The largest jumping number from 100 to 999 is: %d\n", largest);

    return 0;
}
