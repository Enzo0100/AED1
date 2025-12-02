#include <stdio.h>
#include <stdlib.h>

int main() {
    int T, N, k;
    scanf("%d", &T);
    int num[10100], local[10100];

    while (T--) {
        int valores = 0;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &k);
            num[i] = k - 1;
            local[k - 1] = i;
        }
        for (int j = 0; j < N; j++) {
            if (num[j] != j) {
                num[local[j]] = num[j];
                local[num[j]] = local[j];
                num[j] = local[j] = j;
                valores++;
            }
        }
        printf("%d\n", valores);
    }
    return 0;
}