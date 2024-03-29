#include <stdio.h>
#include <math.h>
#include <string.h>
 
//Chamadas das fun��es
int converterBin2Dec(long long valor_binario);
long long converterDec2Bin(int valor_decimal);
int converterDec2Oct(int valor_decimal);
long long converterOct2Dec(int valor_octal);
 
int main()
{
     
    //Vari�veis usadas
    char opc = ' ';
    int valor_octal;
    long long valor_binario;
    int valor_decimal, cociente;
    int sequencial, valor_temp, tamanho_string;
    char valor_hexa[100];
     
    //Enquanto n�o for a op��o 0 (Sair)
    while (opc != '0') {
         
        //Mostra o menu principal
        printf("\n----------------------\n");
        printf("Digite a Opcao\n");
        printf("1 - Binario para Decimal\n");
        printf("2 - Binario para Octal\n");
        printf("3 - Decimal para Binario\n");
        printf("4 - Decimal para Octal\n");
        printf("5 - Decimal para Hexa\n");
        printf("6 - Octal para Decimal\n");
        printf("7 - Hexa para Decimal\n");
        printf("0 - Sair\n");
        printf("Resposta: ");
        scanf("%c", &opc);
        getchar();
         
        //Op��o 1 - Bin�rio -> Decimal
        if (opc == '1') {
            printf("Digite numero binario: ");
            scanf("%lld", &valor_binario);
            printf("[%lld] em binario = [%d] em decimal\n", valor_binario, converterBin2Dec(valor_binario));
        }
         
        //Op��o 2 - Bin�rio -> Octal
        else if (opc == '2') {
            printf("Digite numero binario: ");
            scanf("%lld", &valor_binario);
            valor_decimal = converterBin2Dec(valor_binario);
            valor_octal   = converterDec2Oct(valor_decimal);
            printf("[%lld] em binario = [%d] em octal\n", valor_binario, valor_octal);
        }
         
        //Op��o 3 - Decimal -> Bin�rio
        else if (opc == '3') {
            printf("Digite o numero decimal: ");
            scanf("%d", &valor_decimal);
            printf("[%d] em decimal = [%lld] em binario\n", valor_decimal, converterDec2Bin(valor_decimal));
        }
         
        //Op��o 4 - Decimal -> Octal
        else if (opc == '4') {
            printf("Digite o numero decimal: ");
            scanf("%d", &valor_decimal);
            printf("[%d] em decimal = [%d] em octal\n", valor_decimal, converterDec2Oct(valor_decimal));
        }
         
        //Op��o 5 - Decimal -> Hexadecimal
        else if (opc == '5') {
            printf("Digite o numero decimal: ");
            scanf("%d", &valor_decimal);
             
            //Zerando vari�veis
            sequencial = 0;
            cociente = valor_decimal;
             
            //Enquanto tiver cociente
            while (cociente != 0) {
                //Pega o resto da divis�o por 16
                valor_temp = cociente % 16;
                 
                //Se for menor que 10, soma com 48 (tabela ascii - parte de n�meros)
                if( valor_temp < 10)
                    valor_temp = valor_temp + 48;
                     
                //Sen�o, soma com 55 (tabela ascii - parte de letras)
                else
                    valor_temp = valor_temp + 55;
                 
                //Joga o caracter na sequ�ncia da string
                valor_hexa[sequencial++] = valor_temp;
                 
                //Divide o resto por 16
                cociente = cociente / 16;
            }
            //Encerra a string e mostra a mensagem
            valor_hexa[sequencial++] = '\0';
            printf("[%d] em decimal = [%s] em hexa", valor_decimal, valor_hexa);
        }
         
        //Op��o 6 - Octal -> Decimal
        else if (opc == '6') {
            printf("Digite o numero octal: ");
            scanf("%d", &valor_octal);
            printf("[%d] em octal = [%lld] em decimal\n", valor_octal, converterOct2Dec(valor_octal));
        }
         
        //Op��o 7 - Hexa -> Decimal
        else if (opc == '7') {
            //Zera a vari�vel de valor Decimal
            valor_decimal = 0;
             
            //Mostra mensagem para inserir valor hexa
            printf("Insira o valor hexa: ");
            gets(valor_hexa);
 
            //Pega o tamanho da string
            tamanho_string = strlen(valor_hexa);
            tamanho_string--;
             
            //Percorre todas as posi��es da string
            for(sequencial=0; valor_hexa[sequencial]!='\0'; sequencial++)
            {
                //Se for maior ou igual a 0 e menor ou igual a 9, ser� o valor retirando 48 (tabela ascii)
                if(valor_hexa[sequencial]>='0' && valor_hexa[sequencial]<='9')
                {
                    valor_temp = valor_hexa[sequencial] - 48;
                }
                 
                //Se for maior ou igual a a e menor ou igual a f, ser� o valor retirando 97 (tabela ascii) + 10 (0 a 9)
                else if(valor_hexa[sequencial]>='a' && valor_hexa[sequencial]<='f')
                {
                    valor_temp = valor_hexa[sequencial] - 97 + 10;
                }
                 
                //Se for maior ou igual a A e menor ou igual a F, ser� o valor retirando 65 (tabela ascii) + 10 (0 a 9)
                else if(valor_hexa[sequencial]>='A' && valor_hexa[sequencial]<='F')
                {
                    valor_temp = valor_hexa[sequencial] - 65 + 10;
                }
                 
                //Incrementa o valor decimal multiplicando o valor por 16 elevado � pot�ncia
                valor_decimal += valor_temp * pow(16, tamanho_string);
                tamanho_string--;
            }
            printf("[%s] em hexa = [%d] em decimal", valor_hexa, valor_decimal);
        }
         
        //Op��o desconhecida
        else {
            printf("Opcao desconhecida [%c]\n", opc);
        }
    }
     
    return 0;
}
 
//Fun��o para converter Bin�rio para Decimal
int converterBin2Dec(long long valor_binario)
{
    int valor_decimal = 0, sequencial = 0, resto;
     
    //Enquanto existir valor no bin�rio
    while (valor_binario != 0)
    {
        //Pega o resto da divis�o do valor bin�rio por 10
        resto = valor_binario % 10;
         
        //Divide o valor bin�rio por 10
        valor_binario /= 10;
         
        //Incrementa o valor decimal com o resto da divis�o multiplicado por 2 elevado ao sequencial
        valor_decimal += resto * pow(2, sequencial);
         
        //Incrementa a sequencial
        ++sequencial;
    }
     
    return valor_decimal;
}
 
//Fun��o para converter Decimal para Bin�rio
long long converterDec2Bin(int valor_decimal)
{
    long long valor_binario = 0;
    int resto, sequencial = 1;
 
    //Enquanto o valor decimal for diferente de zero
    while (valor_decimal != 0)
    {
        //Pega o resto da divis�o
        resto = valor_decimal % 2;
         
        //Divide o valor decimal por 2
        valor_decimal /= 2;
         
        //Incrementa o valor bin�rio, multiplicando o resto da divis�o pelo sequencial
        valor_binario += resto * sequencial;
         
        //Multiplica o sequencial por 10
        sequencial *= 10;
    }
     
    return valor_binario;
}
 
//Fun��o para converter Decimal para Octal
int converterDec2Oct(int valor_decimal)
{
    int valor_octal = 0, sequencia = 1;
     
    //Enquanto o valor decimal for diferente de zero
    while (valor_decimal != 0)
    {
        //Incrementa o valor octal com o resto da divis�o do decimal por 8 multiplicado pelo sequencial
        valor_octal += (valor_decimal % 8) * sequencia;
         
        //O valor decimal ser� dividido por 8
        valor_decimal /= 8;
         
        //O sequencial sera multiplicado por 10
        sequencia *= 10;
    }
 
    return valor_octal;
}
 
//Fun��o para converter Octal para Decimal
long long converterOct2Dec(int valor_octal)
{
    int valor_decimal = 0, sequencia = 0;
 
    //Enquanto o valor octal for diferente de zero
    while(valor_octal != 0)
    {
        //Incrementa o valor decimal com o resto da divis�o do valor octal por 10 multiplicado por 8 elevado pelo sequencial
        valor_decimal += (valor_octal % 10) * pow(8, sequencia);
         
        //Incrementa o sequencial
        ++sequencia;
         
        //Divide o valor octal por 10
        valor_octal /= 10;
    }
 
    return valor_decimal;
}
