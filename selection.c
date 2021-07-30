#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define TAM 10

int selection(int *v, int tam);

int main(){
    int valor;
    FILE *fp = fopen("vetor10.txt","r");

    clock_t tempo;
    int i, j = TAM, //contadores 
        vetor[TAM],
        trocas; //numero de trocas


//CASOS DE TESTE SEM ARQUIVO
//-------------------------------------------------------------------------
    /*for(i = 0; i < TAM; i++){//PIOR CASO: oredem decrescente
        vetor[i] = j;
        j--;
    }*/

    /*for(i = 0; i < TAM; i++){//MELHOR CASO: ordem crescente
        vetor[i] = i;
    }*/
//-------------------------------------------------------------------------



//CASOS COM ARQUIVO
    i = 0;
    while((fscanf(fp,"%d\n",&valor)) != EOF){ //colocar os numeros do arquivo dentro de um vetor
        vetor[i] = valor;
        i++;
    }

    tempo = clock();
    trocas = selection(vetor, TAM);
    tempo = clock() - tempo;

    /*printf("Ordenado: ");
    for(i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }*/
    printf("\nTempo de processamento: %f s", ((float)tempo)/CLOCKS_PER_SEC);
    printf("\nNumero de trocas = %d", trocas);
}

int selection(int *v, int tam){
    int i, j;                       //contadores 
    int aux, menor, posicao,        //auxiliares
                    nTrocas = 0;    //numero de trocas

    bool troca,                 //verificacao de necessidade de troca
         trocou;                //verifica se houve troca

    for(i = 0; i < tam - 1; i++){   //percorre da posicao inicial ate a penultima
        menor = v[i];               //menor recebe o valor que será testado e possivelmente trocado
        posicao = i;                //guarda a posicao do testado e/ou trocado
        troca = false;
        trocou = false;
        for(j = i + 1; j < tam; j++){   //percorre da posicao a frente do testado ate o ultimo
            if(v[j] < menor){           //se for verdade, a troca precisa ser feita
                menor = v[j];           //novo menor
                posicao = j;            //nova posicao do menor
                troca = true;           //troca faz-se necessária
            }
        }
        if(troca){
            aux = v[i];                 //auxiliar recebe o testado
            v[i] = menor;               //testado recebe o novo menor
            v[posicao] = aux;           //o que era menor recebe o testado
            trocou = true;
        }
        if(trocou)
            nTrocas++;
    }
    return nTrocas;
}
