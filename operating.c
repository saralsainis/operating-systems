#include <stdio.h>

#define N 10  
#define M 20  

int n, m;           
int alloc[N][M];    
int max[N][M];     
int avail[M];      
int need[N][M];     
int safeSeq[N];     
int isSafe()
{
    int i, j, k;
    int work[M];    
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }
    int finish[N] = {0};
    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int canBeMet = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canBeMet = 0;
                        break;
                    }
                }
                if (canBeMet) {
                    for (j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    safeSeq[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if (!found) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i, j;

    printf("Enter the number of chefs: ");
    scanf("%d", &n);

    printf("Enter the number of ingredients: ");
    scanf("%d", &m);

   
    printf("Enter the allocated resources matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Chef %d:\n", i + 1);
        for     (j = 0; j < m; j++) {
        scanf("%d", &alloc[i][j]);
    }
}


printf("Enter the maximum resources matrix:\n");
for (i = 0; i < n; i++) {
    printf("Chef %d:\n", i + 1);
    for (j = 0; j < m; j++) {
        scanf("%d", &max[i][j]);
        need[i][j] = max[i][j] - alloc[i][j];
    }
}


printf("Enter the available resources array:\n");
for (i = 0; i < m; i++) {
    scanf("%d", &avail[i]);
}


if (isSafe()) {
    printf("System is safe\n");

  
    printf("Safe sequence: ");
    for (i = 0; i < n; i++) {
        printf("Chef %d", safeSeq[i] + 1);
        if (i < n - 1) {
            printf(" -> ");
        }
    }
    printf("\n");

  
    int totalIngredients = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            totalIngredients += max[j][i];
        }
    }
    printf("Total number of ingredients in the kitchen: %d\n", totalIngredients);
} else {
    printf("System is not . Deadlock may occur.\n");
}

return 0;}
