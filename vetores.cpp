#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Variaveis
int i,opcao,aux,posicao = 0;
float nota[5];
float busca,resultbusca;
//Main
int main(){
setlocale(LC_ALL,"Portuguese");
//Digitação
for(i = 0;i < 5;i++){
	printf("Digite as notas[%d]: ",i);
	scanf("%f",&nota);	
}
while (opcao < 5)
{
system("cls");
//Menu
printf("\n-------------Menu-------------");
printf("\n01 - Buscar 1 valor no vetor");
printf("\n02 - Remove 1 valor no vetor");
printf("\n03 - Identificar se vetor esta cheio");
printf("\n04 - Ordenar os dados do vetor\n");
scanf("\n%d",&opcao);
//Case

	switch (opcao)
	{
	case 01:
		printf("\nDigite o valor que busca:");
		scanf("%f",&busca);
		for(i = 0;i <5;i++)
		{  
			if (nota[i] = busca) {
				printf("\n%f:", nota[i]);
			break;
			}else{
				printf("\nValor não encontrado!");
			break;
			}
		}
		printf("\n\n");
		system("pause");
	break;
	case 02:
		printf("\nDigite o valor que deseja remover:");
		busca ==0;
		scanf("\n%f",&busca);
		for (i = 0; i<5;i++){
			if(nota[i] = busca){
				printf("\nValor excluido!");
				nota[i]== 0;
				break;
			} else{
				printf("\nValor não encontrado!");
				break;
			}
		}
	printf("\n\n");
	system("pause");
	break;
	case 03:
		for(i = 0;i < 5;i++){
			if (nota[i] = 0){
				posicao++;
			}else{
				printf("Nenhuma posição está vazia!");
			}
			printf("Posições vazias: %d", &posicao);
		}
	break;
	printf("\n\n");
	system("pause");
	case 04:
		for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (nota[i] > nota[j])
            {
                aux = nota[i];
                nota[i] = nota[j];
                nota[j] = aux;
            }
        }
    }
    printf("---- Vetor Ordenado ----\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Notas:%d",nota[i]);
    }
	
	system("pause");	
	break;
	printf("\n\n");
	default:
		printf("Selecione outra opção:");
 	}
 } 

}
