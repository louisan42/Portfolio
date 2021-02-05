#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENT 15
#define STR_SIZE 35



int main()
{
    char name[MAX_ENT][STR_SIZE];
    int age[MAX_ENT];
    int i,x,y,temp_age;
    char temp_name;
    int entry, *ptr;

    printf("Enter number of Entries: ");
    scanf(" %d", &entry);
    getchar();

     ptr = (int*) malloc(entry* sizeof(int));


    for (i = 0; i < entry; i++){
        printf("Enter last name, first name: ");
        fgets(name[i],sizeof(name[i]),stdin);
        name[i][ strcspn(name[i], "\n") ] = '\0'; //delete newline from copied string

        printf("Enter age: ");
        scanf("%d",&age[i]);
        getchar();
    }


    printf("\n\nOriginal list\n"
           "-------------------------------------------\n");

    for (i = 0; i < entry; i++)
        printf("%-35s%d\n",name[i], age[i]);



         for(i=0;i<entry-1;i++)
         {
             for(x=i;x<entry;x++)
             {
                 if(strcmp(name[i],name[x])>0)
                 {
                    temp_age = age[i];
                    age[i] = age[x];
                    age[x] = temp_age;
                    for(y=0;y<STR_SIZE;y++)
                    {
                        temp_name = name[i][y];
                        name[i][y] = name[x][y];
                        name[x][y] = temp_name;
                    }
                  }
              }
         }


    printf("\n\n");
    printf("\nAlphabetized list\n"
           "-------------------------------------------\n");
    for (i = 0; i < entry; i++)
        printf("%-35s%d\n",name[i], age[i]);


    free(ptr);
    return 0;
}
