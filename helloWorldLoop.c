#include <stdio.h>

int main() {
    int n;

// Ask the user for input
printf("Enter the number of times to print 'Hello World!': ");
scanf("%d", &n);

// Print "Hello World!" n times
for (int i = 0; i < n; i++) {
    printf("Hello World!\n");
}
return 0;
}

