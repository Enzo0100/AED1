#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LANCES 1005
#define MAX_DADO 10 

int dp[MAX_LANCES][MAX_DADO][MAX_DADO];
const int UNCALCULATED = 1000000000;

int LancesM[MAX_LANCES];
int LancesR[MAX_LANCES];
int N_Global;

int solve_dp_marmota(int i, int last_m, int last_r);
int solve_dp_rato(int i, int last_m, int last_r);

int solve_dp_marmota(int i, int last_m, int last_r) {
    if (i == N_Global) {
        return 0;
    }

    if (dp[i][last_m][last_r] != UNCALCULATED) {
        return dp[i][last_m][last_r];
    }

    int pontos_m = LancesM[i];
    int bonus_m = 0;
    int next_last_m = LancesM[i]; 

    if (LancesM[i] == last_m && last_m != 0) {
        bonus_m = 20;
        next_last_m = 0;
    }

    int resultado = (pontos_m + bonus_m) + solve_dp_rato(i, next_last_m, last_r);

    return dp[i][last_m][last_r] = resultado;
}

int solve_dp_rato(int i, int last_m, int last_r) {
    if (i == N_Global) {
        return 0;
    }

    int pontos_r = LancesR[i];
    int bonus_r = 0;
    int next_last_r = LancesR[i]; 

    if (LancesR[i] == last_r && last_r != 0) {
        bonus_r = 20;
        next_last_r = 0;
    }

    int resultado = -(pontos_r + bonus_r) + solve_dp_marmota(i + 1, last_m, next_last_r);

    return resultado;
}

void solve() {
    while (scanf("%d", &N_Global) && N_Global != 0) {
        
        for (int i = 0; i < N_Global; ++i) {
            scanf("%d", &LancesM[i]);
        }
        for (int i = 0; i < N_Global; ++i) {
            scanf("%d", &LancesR[i]);
        }

        memset(dp, 0, sizeof(dp));
        
        // Inicializa com UNCALCULATED
        for(int i = 0; i < N_Global; ++i) {
            for(int j = 0; j < MAX_DADO; ++j) {
                for(int k = 0; k < MAX_DADO; ++k) {
                    dp[i][j][k] = UNCALCULATED;
                }
            }
        }

        int diferenca_final = solve_dp_marmota(0, 0, 0);

        if (diferenca_final > 0) {
            printf("Marmota\n");
        } else if (diferenca_final < 0) {
            printf("Rato\n");
        } else {
            printf("Empate\n");
        }
    }
}

int main() {
    solve();
    return 0;
}