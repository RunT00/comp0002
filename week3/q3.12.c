#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_length(char *buffer, int is_ipv4)
{
    int upper, lower;
    if (is_ipv4 == 1)
    {
        upper = 15;
        lower = 7;
    }
    else
    {
        upper = 39;
        lower = 2;
    }

    if (strlen(buffer)>upper || strlen(buffer)<lower)
    {
        return 1;
    }
    return 0;
}

int check_colon(char *buffer) // check if the :: appears more than once
{   
    int prev = -1;
    int count = 0;
    int is_colon = 0;
    if (strstr(buffer, ":::")!=NULL) // if found ::: in buffer
    {
        return 1;
    }
    for (size_t i=0; i<strlen(buffer); i++)
    {   
        if (buffer[i] == ':')
        {
            is_colon = 1;
            if (prev == -1 )
            {
                prev = i;
            }
            else if(i-prev == 1)
            {
                count += 1;
                if (count > 1)
                {
                    return 1;
                }
            }
            prev = i;
        }
    }
    if (is_colon == 0)
    {
        return 1;
    }
    return 0;
}

int check_char(char *buffer, int is_ipv4)
{
    size_t idx = 0;
    if (is_ipv4 == 1)
    {
        while (buffer[idx] != '\0')
        {
            if ((buffer[idx]<'0' || buffer[idx]>'9')&&(buffer[idx]!='.'))
            {
                return 1;
            }
            idx += 1;
        }
    }
    else
    {
        while (buffer[idx] != '\0')
        {
            if (!(buffer[idx]>='0'&&buffer[idx]<='9') && !(buffer[idx]>='a'&&buffer[idx]<='f') && !(buffer[idx]>='A'&&buffer[idx]<='F') && (buffer[idx]!=':'))
            {
                return 1;
            }
            idx += 1;
        }
    }
    
    return 0;
}

int check_range(char *buffer)
{
    size_t idx = 0;
    size_t temp = 0;
    char text[256] = {'\0'};

    while (buffer[idx] != '\0')
    {   
        if (buffer[idx] == '.')
        {   
            if (strlen(text)>3)
            {
                return 1;
            }
            else
            {
                for(size_t i=0; i<strlen(text); i++)
                {
                    temp = temp * 10 + (text[i]-'0');

                }
                if (temp > 255)
                {   
                    return 1;
                }
                else 
                {
                    size_t counter = 0;
                    do
                    {
                        temp = temp / 10;
                        counter += 1;
                    }
                    while(temp != 0);
                    
                    if (counter != strlen(text))
                    {   
                        return 1;
                    }
                    
                }
            }
            temp = 0;
            text[0] = '\0';
        }
        else
        {
            size_t len_text = strlen(text);
            text[len_text] = buffer[idx];
            text[len_text+1] = '\0';
        }

        idx += 1;
    }
    return 0;
}

int check_interval(char *buffer) // check if number of digits between two colons does not exceed four
{
    size_t idx = 0;
    size_t count = 0;

    while (buffer[idx] != '\0')
    {
        if (buffer[idx] != ':')
        {
            if (buffer[idx] == ':')
            {
                if (count > 4)
                {
                    return 1;
                }
                count = 0;
            }
            else
            {
                count += 1;
            }
        }
        idx += 1;
    }
    return 0;
}

int check_ipv4(char *buffer)
{
    if(check_length(buffer, 1) == 1)
    {
        return 1;
    }
    else if (check_char(buffer, 1) == 1)
    {
        return 1;
    }
    else if (check_range(buffer) == 1)
    {
        return 1;
    }
    else
    {
        printf("It's an IPv4 address\n");
        return 0;
    }
}

int check_ipv6(char *buffer)
{
    if (check_length(buffer, 0) == 1)
    {
        return 1;
    }
    else if (check_colon(buffer) == 1)
    {
        return 1;
    }
    else if (check_char(buffer, 0) == 1)
    {
        return 1;
    }
    else if (check_interval(buffer) == 1)
    {
        return 1;
    }
    else
    {
        printf("It's an IPv6 address\n");
        return 0;
    }
}

int main()
{   
    char buffer[100] = {'\0'};
    FILE *fptr;

    printf("Input a string: ");
    scanf("%99s", buffer);

    if (check_ipv4(buffer) == 1)
    {
        if (check_ipv6(buffer) == 1)
        {
            printf("It's neither an Ipv4 nor an IPv6 address\n");
            return 1;
        }
    }

    char command[256] = "ping -c 4 ";
    strcat(command, buffer);

    fptr = popen(command, "r");
    if (fptr == NULL)
    {
        perror("popen failed\n");
        return 1;
    }
    
    const int n = 256;
    char line[n];
    while (fgets(line, n, fptr) != NULL)
    {
        printf("%s", line);
    }

    return 0;
}