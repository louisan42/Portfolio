#include <stdio.h>
#define SIZE 80

int mystery(const char *s1, const char *s2); // prototype

int main(void)
{
    char string1[SIZE]; // create char array
    char string2[SIZE]; // create char array



    puts("Enter two strings: ");
    scanf("%79s %79s", string1, string2);

    mystery(string1, string2);

    printf("The result is %d\n", mystery(string1, string2));

     if(mystery(string1,string2)==1)
        printf("String1 and string2 are the same");

     else
        printf("String1 and String2 are NOT same");


     return 0;


}

int mystery(const char *s1, const char *s2)
{
    int result = 1;

    for (; *s1 != '\0' && *s2 != '\0'; ++s1, ++s2)
        {
            if (*s1 != *s2)
            {
                result = 0;
            }
        }


    return result;
}
