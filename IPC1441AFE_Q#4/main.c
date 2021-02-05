#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct Books
{
    char isbn_13[15];
    char title[100];
    char author[5][50];
    char publisher[20];
    int publish_year;
    char subject[50];
    int book_id;
};

void getBookInfo(struct Books *b);
void printBooksInfo(struct Books b);
void bookcopy(struct Books *dest, struct Books *source);
int sameBook(struct Books *book1, struct Books *book2);
int samePublisher(struct Books *book1, struct Books *book2);


int n;

int main()
{
    struct Books b ,book1, book2;


    getBookInfo(&b);
    printf("\n\n"),
    printBooksInfo(b);

    bookcopy(&book1,&b);
    sameBook(&book1,&b);

    if((sameBook(&book1,&b))==1)
        printf("These two books are the same\n");
    else
        printf("\nThese books are not the same\n\n");


    samePublisher(&book1,&book2);
    if ((samePublisher(&book1,&book2)==1))
        printf("Same Publisher");

    else
        printf("Different Publishers");


    return 0;
}

void getBookInfo(struct Books *b)
{

    printf("Enter the ISBN-13 of book: ");
    scanf("%s", b->isbn_13);
    // get isbn-13 from user

    printf("Enter book title: ");
    fgets(b->title, sizeof(b->title), stdin);
    getchar();
    //get book title from user

    printf("Enter name of the author(s):\n");

    for (int i=0;i<5;i++){
        fgets(b->author[i],50,stdin);
        getchar();
        b->author[i][ strcspn(b->author[i], "\n") ] = '\0'; //remove newline from input

    }

    //get authors name from user

    printf("\nEnter publisher: ");
    getchar();
    fgets(b->publisher, sizeof(b->publisher),stdin);
    //get book publisher

    printf("Enter year book was published: ");
    getchar();
    scanf(" %d", &(b->publish_year));
    // get yaer pook was published

    printf("Enter book subject: ");
    getchar();
    fgets(b->subject,sizeof(b->subject),stdin);
    //read book subject

    printf("Enter book id(unique 5 digits number): ");
    scanf(" %5d", &(b->book_id));
    //get book id from user


}

void printBooksInfo(struct Books b)
{
    printf("******* Book information gathered ********\n\n");
    printf("ISBN-13: %s\n",b.isbn_13);
    printf("\nBook Title: %s\n",b.title);
    printf("Author(s): ");
    for (int i=0;i<5;i++){
        printf("%s ", b.author[i]);
    }

    printf("\nPublisher: %s\n",b.publisher);
    printf("Publish year: %d\n",b.publish_year);
    printf("\nSubject: %s\n",b.subject);
    printf("Book Id: %05d\n\n",b.book_id);
    printf("***********************************************\n\n");
}

void bookcopy(struct Books *dest, struct Books *source)
{
//makes a copy of all member belonging to Books source to Books dest.
   strcpy(dest->isbn_13,source->isbn_13);
   strcpy(dest->title,source->title);

   for(int i=0;i<5;i++){
       strcpy(dest->author[i],source->author[i]);
   }

   strcpy(dest->publisher,source->publisher);
   dest->publish_year=source->publish_year;
   strcpy(dest->subject,source->subject);
   dest->book_id=source->book_id;

}

int sameBook(struct Books *book1, struct Books *book2)
{

    int check_isbn = strcmp(book1->isbn_13,book2->isbn_13);
    int check_title = strcmp(book1->title,book2->title);

    if(check_isbn == 0 && check_title == 0)
        return 1;

    return 0;
}

int samePublisher(struct Books *book1, struct Books *book2)
{
    strcpy(book2->publisher, "Canadian Press");

    int check_publisher = strcmp(book1->publisher,book2->publisher);

    if (check_publisher == 0)
        return 1;

    return 0;
}

