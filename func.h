float totalc(float corte, float cnum)
{
  float totalcorte;
  totalcorte = (corte - 0.5)*cnum;
  	printf("\n lucro do dia com os cortes foi de R$%.2f;\n", totalcorte);
  return(totalcorte);
}
float totals(float sobral, float sobranum)
{
  float totalsobra;
  totalsobra = (sobral - 0.5)*sobranum;
  	printf("\n lucro do dia com as sobrancelhas feitas foi de R$%.2f;\n", totalsobra);
  return(totalsobra);
}
float totalb(float barba, float barbnum)
{
  float totalbarba;
  totalbarba = (barba - 0.5)*barbnum;
  	printf("\n lucro do dia com as barbas feitas foi de R$ %.2f;\n", totalbarba);
  return(totalbarba);
}float totalcom(float combo, float combonum)
{
  float totalcom;
  totalcom = (combo - 1)*combonum;
  	printf("\n lucro do dia com as platinado feitos foi de R$%.2f;\n", totalcom);
  return(totalcom);
}
float totalpe(float pezinho, float penum)
{
  float totalpe;
  totalpe = (pezinho - 0.5)*penum;
  	printf("\n lucro do dia com os pezinhos feitos foi de R$%.2f;\n \nAperte qualquer tecla parar ver o resultado geral", totalpe);
  getch();
  return(totalpe);
}
