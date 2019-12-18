#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join(char **sa, char spliter, int count)
{
    char *str;
    int i = 0;
    size_t total_len = 0;
    size_t current_len = 0;
    for (i = 0; i < count; i++)
        total_len += strlen(sa[i]);
    total_len += count;
    str = (char *)malloc(total_len);
    str[0] = '\0';
    for (i = 0; i < count; i++)
    {
        strcat(str, sa[i]);
        current_len += strlen(sa[i]) + 1;
        if (i < count - 1)
        {
            str[current_len - 1] = spliter;
            str[current_len] = '\0';
        }
        else
            str[current_len - 1] = '\0';
    }
    return str;
}

int main(int argc, char *argv[])
{
    char *joined_string = NULL;
    joined_string = join(argv + 1, ' ', argc - 1);
    if (argc == 1)
        system("powershell.exe");
    else
        system(joined_string);
    return 0;
}
