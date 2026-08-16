#include <stdio.h>
#include <stdlib.h>
#include "FILA.h"

int verifica_primo(int num)
{


    for(int i =2; i<num; i++)
    {
        if (num%i==0) return 0;
    }
    return 1;
}




int main()
{
    int solucao;
    int num;
    int vai,vem;
    Fila* fila = CriaFila();


    printf("Digite um numero de 2 a 100:");
    do
    {
        scanf("%d",&num);
        printf("\n");
        if(num<2||num>100) printf("O numero digitado nao esta entre 2 e 100 digite novamente:");

    }
    while(num<2||num>100);




    InsereFila(fila,num);

    do
    {
        int n =RetiraFila(fila);

        if(n!=num)
        {

            if(verifica_primo(n))
            {
                printf("\n O numero: %d e o primo mais proximo de %d",n,num);
                break;
            }
        }


        if(n == num && verifica_primo(n)){
            printf("\n %d e primo vamos para o proximo!",n);
        }else{
            printf("\n O numero %d nao e primo vamos para o proximo!",n);
        }


        if (n + 2 <= 100)
            InsereFila(fila, n + 2);

        if (n - 5 >= 2)
            InsereFila(fila, n - 5);


    }
    while(!VaziaFila(fila));

    return 0;
}
