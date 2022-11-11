#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "func.h"
#define Tamanho 1
 struct ficha{
 int telefone;
 char nome [45];
 char email [35];
 }f[Tamanho];
 int ValidacaoDeEmail (char email[35]){
  int tam = strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if (c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break;           // se @ vier antes de 3 caracteres, erro
    } else if (arroba) { // se já encontrou @
      if (ponto) {       // se já encontrou . depois de @
        depoisPonto++;
      } else if (c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      } else {
        antesPonto++;
      }
    }
  } // for

  if (i == tam && depoisPonto > 1)
    return 1;

  return 0;
}

 int main(void){
      int i;
     int opcao;
     char emailcons[45];
 float corte=30;
 float barba=30;
 float sobra1=10;
 float pezinho=10;
 float combo=50,x;
 float geral;
 int cnum,barbnum,sobranum,combonum,penum;

     setlocale(LC_ALL,"");
 puts("\n====================================================================================\n");
 printf("Bem vindos a Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
 {
 char login[15] = "ADM1";
     char login1[15];
     char senha[15] = "1234";
     char senha1[15];
     int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

     while(!login_efetuado){
         printf("Digite o Login: ");
         scanf("%s", login1);

         printf("Digite a Senha: ");
         scanf("%s", senha1);

         if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
                 //strcmp compara strings
             printf("\n\nLOGIN REALIZADO COM SUCESSO!!!!\n\n");
             login_efetuado = 1;
         }
         else
             printf("\n\nDADOS INVALIDOS!\n\n");
    }

}
 system("cls");
 puts("\n====================================================================================\n");
 printf("Bem vindos a Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
 do{
 printf("Digite o numero da opção que deseja utilizar \n");
 printf("(1) Criar perfil do cliente\n(2) Calcular o lucro do dia\n(3) Tabela de preços\n\n");
 scanf("%d",&opcao);
 system("cls");
 switch(opcao)
 {
 fflush(stdin);
 case 1:
  for(i=0; i<Tamanho; i++)
    {
 puts("\n====================================================================================\n");
 printf("Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
    printf("\nEntre com o nome: ");
    fflush(stdin);
    gets(f[i].nome);
    printf("\nEntre com o email: ");
     fflush(stdin);
    gets(f[i].email);
    if (ValidacaoDeEmail(f[i].email) == 0) {//chamando a funçao de autentificação
    do {
      printf("\nPor favor, digite email válido: \n");
      scanf("%s", f[i].email);

    } while (ValidacaoDeEmail(f[i].email) == 0);
  }

    printf("\nEntre com o telefone: ");
     fflush(stdin);
    scanf("%d",&f[i].telefone);
    for(i=0;i <Tamanho; i++)
     {
         puts("\n====================================================================================\n");

     printf(" nome do clientte:\t%s \n",f[i].nome);
     printf(" email do cliente: \t%s \n",f[i].email );
    printf(" telefone do cliente: \t%d \n",f[i].telefone );
   puts("\n====================================================================================\n");

    }
 }
 break;
 case 2:
  //Fechamento do dia
 puts("\n====================================================================================\n");
 printf("Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
 printf("====================Fechamento do dia====================\n");
     printf("quantos cortes foram realizados hoje?\n");
  scanf("%d",&cnum);
     printf("quantas sobrancelhas foram feitas ?\n");
     scanf("%d",&sobranum);
     printf("quantos combos foram realizados? (COMBO = Barba + corte)\n");
     scanf("%d",&combonum);
     printf("quantas barbas foram realizadas?\n");
     scanf("%d",&barbnum);
     printf("quantos pezinhos foram realizados?\n");
     scanf("%d",&penum);
     geral = totalc(corte, cnum)+ totals(sobra1,sobranum)+ totalb(barba,barbnum)+ totalcom(combo,combonum)+ totalpe(pezinho,penum);
     getch();
     printf("\n O total lucrado foi de R$%.2f;\n aperte qualquer tecla para prosseguir",geral);
     puts("\n====================================================================================\n");
     getch();
     system("cls");
    break;
 case 3:
 puts("\n====================================================================================\n");
 printf("Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
     puts("\n====================================================================================\n");
     printf("==================================Tabela de preços==================================");
         printf("\nBarba:  R$%.2f\n",barba);
         printf("\nSobrancelha:  R$%.2f\n",sobra1);
         printf("\nCombo:  R$%.2f\n",combo);
         printf("\nPezinho:  R$%.2f\n",pezinho);
         puts("\n====================================================================================\n");
         puts("\n====================================================================================\n");
         printf("\n\n Pressione qualquer tecla para continuar");
 getch();
     break;
 default:
   			puts("Opção incorreta");
 }
 fflush(stdin);
 	printf("\n Deseja continuar utilizando o sistema? Digite: (S) Sim (N) Não\n");
 	 fflush(stdin);
 	scanf(" %c",&opcao);
}
 /* Continuar ou nao no sistema*/
 while (opcao=='S' || opcao=='s');
   puts("\Obrigado por utilizar o Software");
 getch();
 system("pause");
 }

