

/*CONTADOR DE PALAVRAS Rafael Reinaldo da Silva Nogueira RA:147704*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define entrada 1001 // é definida como 1001 por conta do caractere nulo

int contar_palavras (char *);

void remover_pontuacao(char *);

int main()
{

    char *frase = calloc (entrada, sizeof(char));

    int num;

    scanf("%[^\n]", frase);

    remover_pontuacao(frase);

    num = contar_palavras (frase);

    printf("%d\n", num);

    return 0;

}

int contar_palavras (char *frase)
{

    int i,fim, num=0;
    fim = strlen(frase);

    if (frase[0]!=' ') //num é o numero de palavras
        num++;      //se a frase começa com um caractere já deve ser somada uma palavra
    for (i=1; i<=fim; i++)
    {
        if ((frase[i+1]!='\0') && (frase[i]==' ') && (frase[i+1]!=' ')) // varre todo a frase procurando
            num++;                                           //onde existe um caractere depois de um espaço, incrementa 1 quando o acha
    }

    return num;
}


void remover_pontuacao(char *frase)
{
    int i, fim;
    fim = strlen(frase);

    for (i=0; i<=fim; i++) //varre o vetor até o fim procurando os caracteres abaixo
    {
        // quando os encontra troca por espaço.
        if ((frase[i]==':') || (frase[i]==';') || (frase[i]=='"') || (frase[i]=='\'') || (frase[i]=='!') || (frase[i]=='?') || (frase[i]=='(') || (frase[i]==')'))
            frase [i] = ' ';
	
    
	else if ((frase[i]=='.') || (frase[i]==','))
	{
		
		if ((frase[i-1]>='0') && (frase[i-1]<='9'))
		{
			if ((frase[i+1]>='0') && (frase[i+1]<='9'));
			else frase[i] = ' ';		
		}
	
		else frase[i] = ' ';
	
	}

	else if ((frase[i]=='-') && ((frase[i-1]!="%c") && (frase[i+1]!="%c")))

		frase [i] = ' ';	

    }
}



