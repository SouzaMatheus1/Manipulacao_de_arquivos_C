#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 3

typedef struct{
	int matricula;
	char nome[30];
	float salario;	
}funcionario;

funcionario lerfun();

int i;
int main(){
	funcionario f[tam];
	int menu,cont;
	float sal = 1000.00;
	float soma=0, media;
	printf("Bem-vindo!\n");
	while (true){
	printf("\n1 - Cadastrar os 20 funcionarios.\n2 - Classificar os registros por numero de matricula\n3 - Pesquisar matricula.\n4 - Apresentar matriculas com salario menor que R$ 1000,00.\n5 - Apresentar matriculas com salario abaixo que R$ 1000,00.\n6 - Apresentar matriculas com salario igual a R$ 1000,00.\n0 - Sair.\n");
	scanf("%d", &menu);
	switch(menu){
		case 1:
			for(int i=0;i<tam;i++){
				f[i] = lerfun();
			}continue;
		case 2:
			for(int i=1;i<tam;i++){
					for(int j=i+1;j<tam;j++){
						if(f[i].matricula < f[j].matricula){
						f[0] = f[i];
						f[i] = f[j];
						f[j] = f[0];
						}
					}
				}printf("Cadastros organizados com sucesso!"); break;
		case 3:
			printf("oi");
		case 4:
			
				for(int i=1;i<tam;i++){
					for(int j=i+1;j<tam;j++){
						if(f[i].matricula < f[j].matricula){
						f[0] = f[i];
						f[i] = f[j];
						f[j] = f[0];
						}
					}
				}
				for(int i=1;i<tam;i++){
					if(f[i].salario > sal){
						
						printf("-=-=-=-=-=-=-=-=-=-=-=-\n");
						printf("Matricula..: %02d\n", f[i].matricula);
						printf("Nome.......: %s\n", f[i].nome);
						printf("Salario.....: %.2f\n", f[i].salario);
					}
			}
			continue;
		case 5:
			for(int i=1;i<tam;i++){
					for(int j=i+1;j<tam;j++){
						if(f[i].matricula < f[j].matricula){
						f[0] = f[i];
						f[i] = f[j];
						f[j] = f[0];
						}
					}
				}
			for(int i=1;i<tam;i++){
				if(f[i].salario < sal){
					printf("-=-=-=-=-=-=-=-=-=-=-=-\n");
					printf("Matricula..: %02d\n", f[i].matricula);
					printf("Nome.......: %s\n", f[i].nome);
					printf("Salario.....: %.2f\n", f[i].salario);
				}
			}continue;
		case 6:
			for(int i=1;i<tam;i++){
					for(int j=i+1;j<tam;j++){
						if(f[i].matricula < f[j].matricula){
						f[0] = f[i];
						f[i] = f[j];
						f[j] = f[0];
						}
					}
				}
			for(int i=0;i<tam;i++){
				if(f[i].salario == sal){
					printf("-=-=-=-=-=-=-=-=-=-=-=-\n");
					printf("Matricula..: %02d\n", f[i].matricula);
					printf("Nome.......: %s\n", f[i].nome);
					printf("Salario.....: %.2f\n", f[i].salario);
				}
			}continue;
		case 0:
			break;
		}break;
		
	}
}



funcionario lerfun(){
	char palavra[20];
	funcionario f;
	FILE *arquivo;
	arquivo = fopen("ficha.txt", "a");  
	
	if (arquivo == NULL){
		printf("Erro na abertura do arquivo!");
	}else{
		printf("\n-=-=-=- CADASTRO -=-=-=-\n");
			
			fprintf(arquivo, "\n");
			
			printf("Matricula: ");
			fflush(stdin);
			scanf("%d", &f.matricula);
			fprintf(arquivo, "Matricula..: %03d\n", f.matricula);
			
			printf("Nome: ");
			fflush(stdin);
			gets(f.nome);
			fprintf(arquivo, "Nome.......: %s\n", f.nome);
			
			printf("Salario: ");
			fflush(stdin);
			scanf("%f", &f.salario);
			fprintf(arquivo, "Salario.....: %.2f\n", f.salario);
	}
	fclose(arquivo);
	printf("\nDados gravados com sucesso!");
}


