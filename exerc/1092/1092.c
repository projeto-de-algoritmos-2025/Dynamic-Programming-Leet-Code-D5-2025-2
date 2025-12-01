#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

char* shortestCommonSupersequence(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    char *resultado = (char *)malloc((m + n + 1) * sizeof(char));
    int indice = 0;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            resultado[indice++] = str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            resultado[indice++] = str1[i - 1];
            i--;
        } else {
            resultado[indice++] = str2[j - 1];
            j--;
        }
    }

    while (i > 0) {
        resultado[indice++] = str1[i - 1];
        i--;
    }
    while (j > 0) {
        resultado[indice++] = str2[j - 1];
        j--;
    }
    resultado[indice] = '\0';

    int inicio = 0;
    int fim = indice - 1;
    while (inicio < fim) {
        char temp = resultado[inicio];
        resultado[inicio] = resultado[fim];
        resultado[fim] = temp;
        inicio++;
        fim--;
    }

    for (int k = 0; k <= m; k++) {
        free(dp[k]);
    }
    free(dp);

    return resultado;
}