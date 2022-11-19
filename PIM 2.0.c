#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "func.h"
#define Tamanho 1
#define MAX_SENHA 4
 struct ficha{
 int telefone;
 char nome [45];
 char email [35];
 }f[Tamanho];
 char* CriaSenha()
{

    register int i;

    char* senha1 = (char*)malloc(sizeof *senha1 * MAX_SENHA);

    for(i = 0; i < MAX_SENHA; i++)
    {
        do{

        senha1[i] = getch();
         if(senha1[i] == 0x08 && i > 0)  //Backspace
         {
            printf("\b \b");
            senha1[i] = 0x00;
            i--;
         }
         else if (senha1[i] == 13) // Enter
         {
            senha1[i] = 0x00;
            break;
        }
      else if (senha1[i] != 0x08)
        {
            putchar('*');
            i++;
         }
    }while(i < 15) ;
    }
    senha1[i] = '\0';

    return senha1;
}

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
void Listaclientes();
 int main(void){
     FILE *a;//criando ponteiro
     FILE *p;
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
 int ddia,dmes,dano;

     setlocale(LC_ALL,"");
 puts("\n====================================================================================\n");
 printf("Bem vindos a Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
 {
 char login[15] = "ADM1";
     char login1[15];
     char *senha= "1234";
     char *senha1;
     int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

     while(!login_efetuado){
         printf("Digite o Login: ");
         scanf("%s", login1);
         printf("\nDigite sua senha: ");
         fflush(stdin);
         senha1 = CriaSenha();
         fflush(stdin);
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
 printf("(1) Criar perfil do cliente\n(2) Calcular o lucro do dia\n(3) Tabela de preços \n(4) Consultar Clientes \n(5) Consultar lucros diarios\n\n");//menu
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
    a=fopen("cadastro_usuario.txt","a");
    if(!a){
    printf("Erro na abertura");
    exit(0);
    }
    fprintf(a,"%Nome:s Email:%s Telefone:%d\n",f[i].nome,f[i].email, f[i].telefone);
    fclose(a);
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
     printf("que dia é hoje?\n");
     scanf("%d",&ddia);
     printf("qual mês?\n");
     scanf("%d",&dmes);
     printf("qual ano? ex:aaaa\n");
     scanf("%d",&dano);
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
     printf("\n O lucro total do dia %d/%d/%d foi de R$%.2f;\n aperte qualquer tecla para prosseguir",ddia,dmes,dano,geral);
     puts("\n====================================================================================\n");
     p=fopen("cadastro_lucro.txt","a");
    if(!p){
    printf("Erro na abertura");
    exit(0);
    }
    fprintf(p,"No dia %d/%d/%d\nObteve:%.2f reais de lucro total\n",ddia,dmes,dano,geral);
    fclose(p);
     getch();
     system("cls");
    break;
 case 3:
 puts("\n====================================================================================\n");
 printf("Barbearia Brocks\n\n");
 puts("\n====================================================================================\n");
     puts("\n====================================================================================\n");
     printf("==================================Tabela de preços==================================");
         printf("\nCorte:  R$%.2f\n",corte);
         printf("\nBarba:  R$%.2f\n",barba);
         printf("\nSobrancelha:  R$%.2f\n",sobra1);
         printf("\nCombo:  R$%.2f\n",combo);
         printf("\nPezinho:  R$%.2f\n",pezinho);
         puts("\n====================================================================================\n");
         puts("\n====================================================================================\n");
         printf("\n\n Pressione qualquer tecla para continuar");
 getch();
     break;
     case 4:
         break;

         Listaclientes();
         case 5:

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
