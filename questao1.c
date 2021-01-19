#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define m_type float

// Function declaration
bool equal_status(int len1, int len2);
m_type **matrix_init(int row, int column);
m_type **matrix_mult(m_type **mt1, m_type **mt2);
void matrix_print(m_type **M);

int main(void){
    srand(time(NULL));
    int row1, row2, column1, column2;
    bool status;
    char rand_init[1];

    init: printf("Deseja iniciar as matrizes aleatoriamente? [S/N] ");
    scanf("%s", &rand_init);
            if(strcmpi(rand_init, "S") == 0){
            printf("SIM \n");
        } else if(strcmpi(rand_init, "N") == 0){
            printf("NAO \n");
        } else{
            printf("Resposta invalida. \n");
            goto init;
        }

    printf("%s %d \n", rand_init, strcmp(rand_init, "N"));
    printf("Digite o numero de linhas da primeira matriz (matriz A em A*B): ");
    scanf("%d", &row1);
    printf("Digite o numero de colunas da primeira matriz (matriz A em A*B): ");
    scanf("%d", &column1);
    printf("Digite o numero de linhas da segunda matriz (matriz B em A*B): ");
    scanf("%d", &row2);
    printf("Digite o numero de colunas da segunda matriz (matriz B em A*B): ");
    scanf("%d", &column2);
    
    status = equal_status(column1, row2);
    if (status == true){
        printf("INICIO\n");
        m_type **M1 = matrix_init(row1, column1);
        m_type **M2 = matrix_init(row2, column2);
        m_type **M = matrix_mult(M1, M2);
        matrix_print(M1);
        matrix_print(M2);
        matrix_print(M);
        free(M1);
        free(M2);
        free(M);
        printf("FIM\n");
    } else printf("Multiplicacao impossivel. \n");
    return 0;
}

bool equal_status(int len1, int len2){
    if (len1 == len2)
    {
        return true;
    } else return false;
}

m_type **matrix_init(int row, int column){
    m_type aux = 0;
    row += 1;
    m_type **M = (float **)malloc(row * sizeof(m_type*));
    
    for (int i = 0; i < row; i++)
    {
        M[i] = (float *)malloc((column) * sizeof(m_type));
    }

    M[0][0] = row;
    M[0][1] = column;

    // Random initialization
    for (int i = 1; i < row; i++){
        for (int j = 0; j < column; j++){
            aux = log(rand());
            // printf("%f \n", aux);
            M[i][j] = aux;
            // M[i][j] = j + 1;
        }
    }
    return M;
}

m_type **matrix_mult(m_type **mt1, m_type **mt2){
    int row1 = mt1[0][0];
    int column1 = mt1[0][1];
    int row2 = mt2[0][0];
    int column2 = mt2[0][1];
    int i, j, k;
    m_type **M = matrix_init(row1 - 1, column2);
    float aux = 0;

    for(i = 1; i < row1; i++){
        for(j = 0; j < column2; j++){
            for(k = 0; k < column1; k++){
                aux += mt1[i][k] * mt2[(k + 1)][j];
            }
            M[i][j] = aux;
            aux = 0;
        }
    }
    return M;
}

void matrix_print(m_type **M){
    int row = M[0][0];
    int column = M[0][1];
    printf("row: %d \ncolumn: %d \n",row - 1, column);
    for(int i = 1; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("M[%d][%d] = %f \n", (i - 1), j, M[i][j]);
        }
    }
}