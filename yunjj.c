#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int are_zero(int *ary, int length) {
    for (size_t i = 0; i < length; i++) {
        if (ary[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int are_same(int *org, int *ary, int length) {
    for (size_t i = 0; i < length; i++) {
        if (ary[i] != org[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (size_t i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        int *tuple = (int *)malloc(n * sizeof(int));
        int **history = (int **)malloc(2000 * sizeof(int *));
        int his_amount = 0;

        for (size_t j = 0; j < n; j++) {
            scanf("%d", tuple + j);
        }

        while (1) {
            int a1 = tuple[0];
            for (size_t j = 0; j < n - 1; j++) {
                tuple[j] = abs(tuple[j] - tuple[j + 1]);
            }
            tuple[n - 1] = abs(tuple[n - 1] - a1);

            for (size_t j = 0; j < his_amount; j++) {
                if (are_same(tuple, history[j], n)) {
                    printf("LOOP\n");
                    goto double_break;
                }
            }

            history[his_amount++] = (int *)malloc(n * sizeof(int));
            for (size_t j = 0; j < n; j++) {
                history[his_amount - 1][j] = tuple[j];
            }

            if (are_zero(tuple, n)) {
                printf("ZERO\n");
                break;
            }
        }

        double_break:

        free(tuple);
        for (size_t j = 0; j < his_amount; j++) {
            free(history[j]);
        }
        free(history);
    }
}
