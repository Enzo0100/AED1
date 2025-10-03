#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int queue[55];   
        int front = 0, rear = n - 1;

        for (int i = 0; i < n; i++) {
            queue[i] = i + 1;
        }

        printf("Discarded cards:");
        int first = 1;

        while (front != rear) {
            
            if (first) {
                printf(" %d", queue[front]);
                first = 0;
            } else {
                printf(", %d", queue[front]);
            }
            front = (front + 1) % 55;  

            
            rear = (rear + 1) % 55;
            queue[rear] = queue[front];
            front = (front + 1) % 55;
        }

        printf("\nRemaining card: %d\n", queue[rear]);
    }
    return 0;
}
