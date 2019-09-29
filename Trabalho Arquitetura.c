
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
 int rbin [32];
 int cnt,i;
	
 void hextodec(){
 	
    char hex[17];
    long long decimal,place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    printf("Entre com um numero hexadecimal: ");
     scanf("%s", hex);

    //tamanho do numer
    len = strlen(hex);
    len--;

    /*
     * Iterate over each hex digit
     */
    for(i=0; hex[i]!='\0'; i++)
    {
 
        
        if(hex[i]>='0' && hex[i]<='9')// conversao normal 
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')//conversao caso n caps
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')// conversao caso caps
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }

    printf("Hexadecimal : %s\n", hex);
    printf("Decimal : %lld", decimal);

}

void dectohex(){
	long int decn,rmd,q,dn=0,m,l;
	int i=1,j,tmp;
    char s;

	printf("Decimal :");
	scanf("%ld",&decn);
	q = decn;
        for(l=q;l>0;l=l/16)
               {
		tmp = l % 16;
		if( tmp < 10)
		           tmp =tmp + 48; else
		         tmp = tmp + 55;
                         dn=dn*100+tmp;
	        }
          printf("Hexadecimal : ");
         for(m=dn;m>0;m=m/100)
            {
               s=m % 100;
               printf("%c",s);
            }
    printf("\n\n");  
}

int bintodec(bin){
	int  binary_val, decimal_val = 0, base = 1, rem;
 
    binary_val = bin;
    while (bin > 0)
    {
        rem = bin % 10;
        decimal_val = decimal_val + rem * base;
        bin = bin / 10 ;
        base = base * 2;
    }
   	
	return(decimal_val);
}

void dectobin(dec){
	
    cnt=0;              
    while(dec>0)
    {
        rbin[cnt]=dec%2;
        dec=dec/2;
        cnt++;
    }
}	

void main(){
	setlocale(LC_ALL, "Portuguese");
	int escolha;
	int bin ,rdec,dec; // rdec é a volta do binario 
	
		printf("**********************\n");
		printf("'w'");
		printf("CONVERSOR EM C \n");
		printf("********************** \n");
		printf("Que tipo de conversão voce quer?\n");
		printf("1. Hexadecimal para Decimal \n");
		printf("2. Decimal para Hexadecimal \n");
		printf("3. Binario para Decimal \n");
		printf("4. Decimal para Binario");
		scanf("%d", &escolha);
		
			switch(escolha){
		 		case 1:
             		hextodec();
             		break;
          		case 2:
             		dectohex();
             		break;
          		case 3:
          			printf("Entre com um numero binario \n");
             		scanf("%d", &bin);
             		rdec = bintodec(bin);
             		printf("O numero binario é  = %d \n",bin);
    				printf("O decimal é = %d \n", rdec);
             		break;
          		case 4:
             		printf("Enter com um numero decimal: ");
    				scanf("%d",&dec);
    				dectobin(dec);
    				printf("O valor em binario é: ");
    				for(i=(cnt-1); i>=0;i--)
        				printf("%d",rbin[i]);
             		break;
          	
          		default:
             		printf("  '-' Por favor escolha uma opção valida \n");
             		break;

	}
}
