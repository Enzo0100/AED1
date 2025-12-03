#include <stdio.h>
#include <stdlib.h>

void solve() {
    int A;
    if (scanf("%d", &A) != 1) return;

    if (A % 6 != 0) {
        printf("N\n");
        return;
    }

    int D = A / 6;

    int possivel = 0;

    for (int m = 0; m < 720; m++) {
        
        int Pm = m % 60; 
        
        int Ph = (m / 12) % 60; 
        
        int diff_abs = abs(Pm - Ph);
        
        int D_min = diff_abs;
        if (D_min > 30) {
            D_min = 60 - diff_abs;
        }

        if (D_min == D) {
            possivel = 1;
            break;
        }
    }

    if (possivel) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
}

int main() {
    while (!feof(stdin)) {
        solve();
    }
    
    return 0;
}