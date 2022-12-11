#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "func.h"
#define Tamanho 1
#define MAX_SENHA 4
 struct ficha{
 char telefone[12];
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
char Validatelefone(char tel[12]){
    if(strlen(tel) != 11){
        return 1;}
    else if((strcmp(tel,"00000000000") == 0) || (strcmp(tel,"11111111111") == 0) || (strcmp(tel,"22222222222") == 0) ||
            (strcmp(tel,"33333333333") == 0) || (strcmp(tel,"44444444444") == 0) || (strcmp(tel,"55555555555") == 0) ||
            (strcmp(tel,"66666666666") == 0) || (strcmp(tel,"77777777777") == 0) || (strcmp(tel,"88888888888") == 0) ||
            (strcmp(tel,"99999999999") == 0)){
        return 1; //se o CPF tiver todos os números iguais ele é inválido.
}
    return 0;
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
int abrirArquivo(){
    FILE *a;
    int c;
    if ((a = fopen("cadastro_usuario.txt", "r")) == NULL) {
printf("\n\nNão foi possivel abrir o arquivo.\n");

exit(1);
}
printf("\nUsuários cadastrados:\n");
c = fgetc(a);
while (!feof(a)) {
putchar(c);
c = fgetc(a);
}
fclose(a);

    return 0;
}
int abrirArquivo2(){
    FILE *a;
    int c;
    if ((a = fopen("cadastro_lucro.txt", "r")) == NULL) {
printf("\n\nNão foi possível abrir o arquivo.\n");
exit(1);
}
printf("\nFaturamentos diários:\n");
c = fgetc(a);
while (!feof(a)) {
putchar(c);
c = fgetc(a);
}
fclose(a);

    return 0;
}
char Validadia(char dia[3]){
    if(strlen(dia) != 2){
        return 1;}

    return 0;
}
char Validames(char mes[3]){
    if(strlen(mes) != 2){
        return 1;}
    return 0;
}
char Validaano(char ano[5]){
    if(strlen(ano) != 4){
        return 1;}
    return 0;
}
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
 char ddia[3],dmes[3],dano[5];

     setlocale(LC_ALL,"");
     do{
 system("cls");
 puts("\n====================================================================================\n");
 printf("Bem vindos a Barbearia Brook's\n\n");
 puts("\n====================================================================================\n");
 printf("Digite o número da opção que deseja utilizar \n");
 printf("(1)Login\n(2)Tabela de preços\n(3)Sair\n\n");//menu
 scanf("%d",&opcao);
 system("cls");
switch(opcao)
 {
 fflush(stdin);
 case 2:
  puts("\n====================================================================================\n");
 printf("Barbearia Brook's\n\n");
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

 case 1:
 {
 char login[15] = "ADM1";
     char login1[15];
     char *senha= "1234";
     char *senha1;
     int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro

     while(!login_efetuado){
            puts("\n====================================================================================\n");
 printf("Bem vindos a Barbearia Brook's\n\n");
 puts("\n====================================================================================\n");
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
             printf("\n\nDADOS INVÁLIDOS!\n\n");
    }
}
 system("cls");
 puts("\n====================================================================================\n");
 printf("Bem vindos a Barbearia Brook's\n\n");
 puts("\n====================================================================================\n");
 do{
 printf("Digite o número da opção que deseja utilizar \n");
 printf("(1) Criar perfil do cliente\n(2) Calcular o faturamento do dia\n(3) Consultar clientes \n(4) Consultar faturamentos diários\n\n");//menu
 opcao=0;
 scanf("%d",&opcao);
 system("cls");
switch(opcao)
 {
 fflush(stdin);
 case 1:
  for(i=0; i<Tamanho; i++)
    {
 puts("\n====================================================================================\n");
 printf("Barbearia Brook's\n\n");
 puts("\n====================================================================================\n");
    printf("\nEntre com o nome: ");
    fflush(stdin);
    gets(f[i].nome);
    printf("\nEntre com o email: ");
     fflush(stdin);
    gets(f[i].email);
    if (ValidacaoDeEmail(f[i].email) == 0) {//chamando a funçao de autentificação
    do {
      printf("\nPor favor, digite um email válido: \n");
      scanf("%s", f[i].email);

    } while (ValidacaoDeEmail(f[i].email) == 0);
  }

    printf("\nEntre com o telefone com o DDD: ex:xxxxxxxxxxx\n ");
     fflush(stdin);
    scanf("%s",&f[i].telefone);
    if (Validatelefone(f[i].telefone) == 1) {//chamando a funçao de autentificação
    do {
      printf("\nPor favor, digite um telefone válido: \n");
      scanf("%s", f[i].telefone);

    } while (Validatelefone(f[i].telefone) == 1);
  }

    a=fopen("cadastro_usuario.txt","a");
    if(!a){
    printf("Erro na abertura");
    exit(0);
    }
    fprintf(a,"Nome:%s\nEmail:%s\nTelefone:%s\n\n",f[i].nome,f[i].email, f[i].telefone);
    fclose(a);
        for(i=0;i <Tamanho; i++)
     {
         puts("\n====================================================================================\n");

     printf(" Nome do cliente:\t%s \n",f[i].nome);
     printf(" Email do cliente: \t%s \n",f[i].email );
    printf(" Telefone do cliente: \t%s \n",f[i].telefone );
   puts("\n====================================================================================\n");
    }
 }
 break;
 case 2:
  //Fechamento do dia
 puts("\n====================================================================================\n");
 printf("Barbearia Brook's\n\n");
 puts("\n====================================================================================\n");
 printf("====================Fechamento do dia====================\n");
     printf("Que dia é hoje?ex:01\n");
     fflush(stdin);
     scanf("%s",&ddia);
     if (Validadia(ddia) == 1) {//chamando a funçao de autentificação
    do {
      printf("\nPor favor, digite um dia válido: ex:aa\n");
      scanf("%s", ddia);

    } while (Validadia(ddia) == 1);
  }
     printf("Qual mês?ex:01\n");
     fflush(stdin);
     scanf("%s",&dmes);
      if (Validames(dmes) == 1) {//chamando a funçao de autentificação
    do {
      printf("\nPor favor, digite um mês válido: ex:aa\n");
      scanf("%s", dmes);

    } while (Validames(dmes) == 1);
  }
     printf("Qual ano? ex:1900\n");
     fflush(stdin);
     scanf("%s",&dano);
      if (Validaano(dano) == 1) {//chamando a funçao de autentificação
    do {
      printf("\nPor favor, digite um ano válido: ex:aaaa\n");
      scanf("%s", dano);

    } while (Validaano(dano) == 1);
  }
     printf("Quantos cortes foram realizados hoje?\n");
     scanf("%d",&cnum);
     fflush(stdin);
     printf("Quantas sobrancelhas foram feitas ?\n");
     fflush(stdin);
     scanf("%d",&sobranum);
     printf("Quantos combos foram realizados? (COMBO = Barba + corte)\n");
     fflush(stdin);
     scanf("%d",&combonum);
     printf("Quantas barbas foram realizadas?\n");
     fflush(stdin);
     scanf("%d",&barbnum);
     printf("Quantos pezinhos foram realizados?\n");
     fflush(stdin);
     scanf("%d",&penum);
     geral = totalc(corte, cnum)+ totals(sobra1,sobranum)+ totalcom(combo,combonum)+ totalb(barba,barbnum)+ totalpe(pezinho,penum);
     getch();
     printf("\n O faturamento total do dia %s/%s/%s foi de R$%.2f;\n Aperte qualquer tecla para prosseguir",ddia,dmes,dano,geral);
     puts("\n====================================================================================\n");
     p=fopen("cadastro_lucro.txt","a");
    if(!p){
    printf("Erro na abertura");
    exit(0);
    }
    fprintf(p,"No dia %s/%s/%s\nObteve:%.2f reais de faturamento total\n\n",ddia,dmes,dano,geral);
    fclose(p);
     getch();
     system("cls");
    break;
     case 3:
        puts("\n====================================================================================\n");
        printf("Barbearia Brook's\n\n");
        puts("\n====================================================================================\n");
    abrirArquivo();
    getch();
         break;
         case 4:
        puts("\n====================================================================================\n");
        printf("Barbearia Brook's\n\n");
        puts("\n====================================================================================\n");
    abrirArquivo2();
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
   puts("\nObrigado por utilizar o Software\n");
 getch();
 system("pause");
 exit(0);
 break;

case 3:
    printf("\nObrigado por utilizar o Software\n");
    system("pause");
exit(0);
    break;
    default:
     printf("Opção incorreta");
		}
fflush(stdin);
 	printf("\n Deseja continuar utilizando o sistema? Digite: (S) Sim (N) Não\n");
 	 fflush(stdin);
 	scanf(" %c",&opcao);
 }
  /* Continuar ou nao no sistema*/
 while (opcao=='S' || opcao=='s');
   printf("\nObrigado por utilizar o Software\n");
 system("pause");
 }
