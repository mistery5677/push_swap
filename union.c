#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str) //Ja sabes o que isto faz
{
        int i;

        i = 0;
        while(str[i])
                i++;
        return i;
}

int main(int argc, char **argv)
{
        if(argc == 3) // Verificar se existe 3 argumentos
        {
                int i;
                int j;

                i = 1;
                write(1, &argv[1][0], 1); // Escrever sempre a primeira letra, aconteca o que acontecer
                while(argv[1][i]) // Vamos percorrer primeiro o argv[1]
                {
                        j = 0; // Fazer um counter para verificar todas as letras que estao para tras, e dar reset sempre
                        while(j < i && argv[1][i] != argv[1][j]) // Vamos andar com o 'j' ate chegarmos ao 'i', e verificar sempre se eles sao diferentes
                                j++;
                        if(j == i) // Caso que ele tenha percorrido ate ao 'i', sabemos que nao existe nenhuma letra igual, entao vamos imprir a letra
                                write(1, &argv[1][i], 1);
                        i++;
                }
                i = 0;
                while(argv[2][i]) //Agora vamos trabalhar com argv[2], mas com a mesma logica
                {
                        j = 0;
                        while(argv[1][j] != argv[2][i] && argv[1][j]) // Vamos percorrer argv[1], enquanto for diferente de argv[2]
                                j++;
                        if(j == ft_strlen(argv[1])) // Vamos verificar se 'j', chegou ao fim por ter encontrado uma letra igual, ou foi porque argv[1] terminou, para isso comparamos com o tamanho de argv[1], se j < ft_strlen(argv[1]), e porque encontrou uma letra igual, e nao queremos imprimir isso.
                        {
                                j = 0; // Resetamos o 'j' para trabalhar com argv[2]
                                while(argv[2][i] != argv[2][j]) // Vamos comparar com as letras que ja verificamos (como fizemos no inicio com argv[1])
                                        j++;
                                if(j == i) // Agora verificamos se 'j' chegar ao 'i' e porque, argv[1] nao tinha nenhuma letra repetida, e no argv[2] nao existe nenhuma letra repetida ate o 'i';
                                        write(1, &argv[2][i], 1);
                        }
                        i++;
                }
        }
        write(1, "\n", 1); // No final de tudo vai ter sempre de dar um new line
        return 0;
}