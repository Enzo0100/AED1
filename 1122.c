#include <stdio.h>
#include <string.h>

#define MAX_N 41 
#define MAX_SUM_RANGE 80005 
#define OFFSET 40000 

int N, F;
int valores[MAX_N];
int dp_pref[MAX_N][MAX_SUM_RANGE];
int dp_suff[MAX_N][MAX_SUM_RANGE];

void solve() {
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &valores[i]) != 1) return;
    }

    memset(dp_pref, 0, sizeof(dp_pref));
    dp_pref[0][OFFSET] = 1; 

    memset(dp_suff, 0, sizeof(dp_suff));
    
    if (F + OFFSET >= 0 && F + OFFSET < MAX_SUM_RANGE) {
        dp_suff[N][F + OFFSET] = 1;
    } else {
        printf("*\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int s = 0; s < MAX_SUM_RANGE; s++) {
            if (dp_pref[i][s]) {
                int val = valores[i];

                int next_s_plus = s + val;
                if (next_s_plus < MAX_SUM_RANGE) {
                    dp_pref[i + 1][next_s_plus] = 1;
                }

                int next_s_minus = s - val;
                if (next_s_minus >= 0) {
                    dp_pref[i + 1][next_s_minus] = 1;
                }
            }
        }
    }

    if (!dp_pref[N][F + OFFSET]) {
        printf("*\n");
        return;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int s = 0; s < MAX_SUM_RANGE; s++) {
            if (dp_suff[i + 1][s]) {
                int val = valores[i];
                
                int prev_s_plus = s - val;
                if (prev_s_plus >= 0) {
                    dp_suff[i][prev_s_plus] = 1;
                }

                int prev_s_minus = s + val;
                if (prev_s_minus < MAX_SUM_RANGE) {
                    dp_suff[i][prev_s_minus] = 1;
                }
            }
        }
    }

    char resultado[MAX_N];
    for (int i = 0; i < N; i++) {
        int val = valores[i];
        
        int pode_ser_plus = 0;
        int pode_ser_minus = 0;

        for (int s = 0; s < MAX_SUM_RANGE; s++) {
            if (dp_pref[i][s]) {
                
                int next_s_plus = s + val;
                if (next_s_plus < MAX_SUM_RANGE && dp_suff[i + 1][next_s_plus]) {
                    pode_ser_plus = 1;
                }

                int next_s_minus = s - val;
                if (next_s_minus >= 0 && dp_suff[i + 1][next_s_minus]) {
                    pode_ser_minus = 1;
                }

                if (pode_ser_plus && pode_ser_minus) break; 
            }
        }

        if (pode_ser_plus && pode_ser_minus) {
            resultado[i] = '?'; 
        } else if (pode_ser_plus) {
            resultado[i] = '+'; 
        } else {
            resultado[i] = '-'; 
        }
    }

    resultado[N] = '\0'; 
    printf("%s\n", resultado);
}

int main() {
    while (scanf("%d %d", &N, &F) == 2 && (N != 0 || F != 0)) {
        solve();
    }

    return 0;
}