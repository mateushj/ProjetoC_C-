#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int *vetor, int inicio, int fim);
void merge(int *vetor, int inicio, int meio, int fim);
void printArray(int *vetor, int tamanho, int status);

int main(void) {
    int vetor[10] = {5, 3, 1, 9, 7, 2, 4, 5, 8, 3};
    int inicio = 0;
    int fim = (sizeof(vetor) / 4) - 1;
    int status = 0;
    
    printf("\t*** METODO MERGE SORT ***\n\n");
    
    printArray(vetor, fim, status);
    
    mergeSort(vetor, inicio, fim);
    status = 1;
    printArray(vetor, fim, status);
    
    system("PAUSE");
    return 0;    
}

void merge(int *vetor, int inicio, int meio, int fim) {
     int *temp;
     int p1, p2, tamanho;
     int i, j, k;
     int fim1, fim2;
     
     p1 = inicio;
     p2 = meio+1;
     tamanho = fim - inicio + 1;
     fim1 = 0;
     fim2 = 0;
     
     temp = (int *)malloc(tamanho*sizeof(int));
     
     if(temp != NULL) {
         for(i = 0; i < tamanho; i++) {
             // Checa se o vetor acabou
             if(!fim1 && !fim2) {
                 // Combina de forma ordenada
                 if(vetor[p1] < vetor[p2])
                     temp[i] = vetor[p1++];
                 else
                     temp[i] = vetor[p2++];
                 // Seta as variáveis fim's para informar que o vetor acabou
                 if(p1 > meio)
                     fim1 = 1;
                 if(p2 > fim)
                     fim2 = 1;         
             }
             else {
                 // Copia o que sobrar
                 if(!fim1)
                     temp[i] = vetor[p1++];
                 else
                     temp[i] = vetor[p2++];     
             }
         }
         // Copia do auxiliar para o original
         for(j = 0, k = inicio; j < tamanho; j++, k++)
             vetor[k] = temp[j];
     }
     free(temp);
}

void mergeSort(int *vetor, int inicio, int fim) {
     int meio;
     if(inicio < fim) {
         // Calcula o meio, sempre arredondando para baixo
         meio = floor((inicio + fim) / 2);
         // Chama a função para dividir o vetor...
         mergeSort(vetor, inicio, meio); // ... parte da esquerda
         mergeSort(vetor, meio+1, fim);  // ... parte da direita
         // Combina as duas metades de forma ordenada
         merge(vetor, inicio, meio, fim);
     }
}

void printArray(int *vetor, int tamanho, int status) {
     int i;
     if(!status) {
         printf("Array Desordenado: ");
         for(i = 0; i <= tamanho; i++)
             printf("%d ", vetor[i]);
     }
     else {
         printf("Array Ordenado: ");
         for(i = 0; i <= tamanho; i++)
             printf("%d ", vetor[i]);
     }
     printf("\n\n");
}
