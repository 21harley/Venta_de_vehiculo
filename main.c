#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nom[20];
    int x,k,cantV,cantM,a=1,b=0,px=0,py=0,num;
    typedef char cadenaCaracteres [50]; //Definimos el tipo cadenaCaracteres

printf("Cuantos vendedores tiene  \n");
scanf("%i",&cantV);

printf("Cuantos modelos tiene la consecionaria \n");
scanf("%i",&cantM);

    cadenaCaracteres vendedores[cantV]; //Creamos un vector de cadenas
    cadenaCaracteres modelos[cantM];
    cadenaCaracteres nombre;
    
	float precio[cantM];
    float totalV[cantM];
    float totalVe[cantM];
    float totlVe[cantV];
    float promedio=0;
    float paga;
    float eficacia=0;
    float mayoref=0;
    int t=0;
    int vent[cantV];
    int vent2[cantV];
    int meta[cantM];
    int venta[cantV][cantM];
    
for(x=0;x<cantV;x++){
    printf("Ingrese nombre de vendedor %i : ",x+1);
    scanf("%s",vendedores[x]);
    printf("\n");
}

for(x=0;x<cantM;x++){
	printf("Ingrese nombre de modelo %i : \n",x+1);
    scanf("%s",modelos[x]);
    printf("\n");
	printf("Precio del modelo %i : \n",x+1);
    scanf("%f",&precio[x]);
    printf("\n");
    printf("meta de venta  %i: ",x+1);
    scanf("%i",&meta[x]);t+=meta[x];
    printf("\n");
}
printf("\n");
for(x=0;x<cantV;x++){
	 printf("total de venta de  %s ",  vendedores[x]);
	 printf("\n");k=0;a=1;
    do{
    	if(k!=cantM){
    	 printf("cuantos vendio de modelo  %s  \n", modelos[k]);
		 scanf("%i",&venta[k][x]);
		 vent2[x]+=venta[k][x];
		 printf("\n");k++;
		}else{
			a=0;
		}
	}while(a!=0);
}


for(x=0;x<cantM;x++){
   for(k=0;k<cantV;k++){
   	totalV[x]+=venta[x][k]*precio[x];
   }
   printf("\n"); 
   printf(" total de bolívares registrados por ventas de cada modelo de vehículo %i %f \n",x+1,totalV[x]);
}

for(x=0;x<cantV;x++){
         k=0;a=1;
    do{
    	if(k!=cantM){
         totlVe[x]+=precio[k]*venta[k][x];
		 k++;
		}else{
			a=0;
		}
	}while(a!=0);
	printf("total de bolívares de ventas es  %f del vendedor %s \n",totlVe[x],  vendedores[x]);
	promedio+=totlVe[x];
}
 promedio=promedio/cantV;
for(x=0;x<cantV;x++){
         k=0;a=1;b=0;
    do{
    	if(k!=cantM){
         totalVe[x]+=venta[k][x]*precio[k];
         vent[x]+=venta[k][x];
		 if(venta[k][x]==0){
           b++;	
		 }
		 k++;
		}else{
			a=0;
		}
	}while(a!=0);
	if(vent[x]<=25){
		paga=totalVe[x]*0.08;
		printf("el vendedor %s tiene una paga de %f \n",vendedores[x],paga);
	}else if(vent[x]>25){
		paga=totalVe[x]*0.15;
		printf("el vendedor %s tiene una paga de %f \n",vendedores[x],paga);
	}
	if(b==0){
		printf("El vendedor %s si vendio un auto de cada modelo \n",vendedores[x]);
	}if(b>=1){
		printf("El vendedor %s no vendio un auto de cada modelo \n",vendedores[x]);
	}
}

///mostrar
for(x=0;x<cantV;x++){
    printf("  %s ",  vendedores[x]);
}
 printf("\n");

for(x=0;x<cantM;x++){
    printf("   %s ",modelos[x]);
	for(k=0;k<cantV;k++){
		if(venta[x][k]>0){
			printf(" %i  ", venta[x][k]);
		}
	}
	 printf(" %f ",precio[x]);
	 printf("\n");
}

 printf("Ingrese el numero  del vendedor que desea analizar ");
for(x=0;x<cantV;x++){
	printf("\n");
	printf("%i)-%s ",x+1,vendedores[x]);
}
 scanf("%i",&num);num--;
 if(totlVe[num]>promedio){
 	printf("el vendedor %s si paso el promedio %f \n",vendedores[num],promedio);
 	px++;
 }

if(px==0){
	printf("el vendedor %s no paso el promedio %f \n",vendedores[num],promedio);
}

for(x=0;x<cantV;x++){
	eficacia=(vent2[x]/t)*100;
	printf("eficacia %f del vendedor %s \n",eficacia,vendedores[x]);
	if(mayoref<eficacia){
		mayoref=eficacia;py=x;
	}
}
printf("el vendedor con la mayor eficacia es %s \n",vendedores[py]);

  printf("\n"); 
 system("PAUSE");
  return 0;
}
