#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
        int i;

        i = 0;
        while(str[i])
                i++;
        return i;
}

int main(int argc, char **argv)
{
        if(argc == 3)
        {
                int i;
                int j;

                i = 1;
                write(1, &argv[1][0], 1);
                while(argv[1][i])
                {
                        j = 0;
                        while(j < i && argv[1][i] != argv[1][j])
                                j++;
                        if(j == i)
                                write(1, &argv[1][i], 1);
                        i++;
                }
                i = 0;
                while(argv[2][i])
                {
                        j = 0;
                        while(argv[1][j] != argv[2][i] && argv[1][j])
                                j++;
                        if(j == ft_strlen(argv[1]))
                        {
                                j = 0;
                                while(argv[2][i] != argv[2][j])
                                        j++;
                                if(j == i)
                                        write(1, &argv[2][i], 1);
                        }
                        write(1, "0", 1);
                        i++;
                }
        }
        return 0;
}