/* Suppose you are working on a program that manages a library's book collection. Each book is represented by information such as the book's title, author, ISNB.
Write a C function to  take an array of book details as a pointer, along with the number of books in the array, and returns the book title with the highest number or pages. 
Use approproiate functions to implement the functionality described above*/

#include <stdio.h>
struct Book{
    char* title; //Allocating memomary dynamically
    char* author;
    char* ISBN;
    int num_pages;
};
void getinput(struct Book* book){ //*book refers to array being recieved
    char buffer[100];
    printf("Enter the book title: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")]='\0'; //strcspn function calulates the length before the first occurance of \n. WE set the \n in the string as \0.
    book->title=malloc(strlen(buffer)+1);
    strcpy(book->title, buffer);

    printf("Enter author name: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer,'\n')]='\0';
    book->author=malloc(strlen(buffer)+1);
    strcpy(book->author, buffer);

    printf("Enter the iSBN number: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, '\n')]='\0';
    book->ISBN=malloc(strlen(buffer)+1);
    strcpy(book->ISBN, buffer);

    printf("Enter the number of pages");
    scanf("%d", &book->num_pages);
    getchar(); //consumes the newline character left in the input buffer

}

char *findingbook(struct Book* books, int num_books){ //*books refers to array being recieved
    int max=-1;
    char *titleofbookwithmostpages=NULL;
    for (int i=0; i<num_books;i++){
        if (books[i].num_pages>max){
            max=books[i].num_pages;
            titleofbookwithmostpages=books[i].title;
        }
    }
    return titleofbookwithmostpages;
}

int main(){
    int num;
    printf("ENter the number of books");
    scanf("%d", &num);
    getchar(); //consumes newline character left in the input buffer

    //Allocating memorhy for an array of BOok objects
    struct Book *books=malloc(num*sizeof(struct Book));  //here * referess to the array of objetcts

    //inputting details 
    for (int i=0; i<num; i++){
        printf("Enter the details for the book %d", i+1);
        getinput(&books[i]);
    }
    //finding book with most pages
    char *bookname=findingbook(books, num);
    printf("Title of the book with most pages %s\n", bookname);

    //freeing memory
    for(int i=0; i<num;i++){
        free(books[i].title);
        free(books[i].author);
        free(books[i].ISBN);
    }
    //freeing memory allocated for array of book objects
    free(books);
    return 0;
    
}
//Above code shows segmentation error after author name is included. THe below code is error free

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char* title;
    char* author;
    char* ISBN;
    int num_pages;
};

void get_input(struct Book* book) {
    char buffer[100];
    printf("Enter the book title: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    book->title = malloc(strlen(buffer) + 1);
    strcpy(book->title, buffer);

    printf("Enter author name: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    book->author = malloc(strlen(buffer) + 1);
    strcpy(book->author, buffer);

    printf("Enter the ISBN number: ");
    fgets(buffer, 100, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    book->ISBN = malloc(strlen(buffer) + 1);
    strcpy(book->ISBN, buffer);

    printf("Enter the number of pages: ");
    scanf("%d", &book->num_pages);
    getchar();
}

char* find_book_with_most_pages(struct Book* books, int num_books) {
    int max = -1;
    char* title_of_book_with_most_pages = NULL;
    for (int i = 0; i < num_books; i++) {
        if (books[i].num_pages > max) {
            max = books[i].num_pages;
            title_of_book_with_most_pages = books[i].title;
        }
    }
    return title_of_book_with_most_pages;
}

int main() {
    int num_books;
    printf("Enter the number of books: ");
    scanf("%d", &num_books);
    getchar();

    struct Book* books = malloc(num_books * sizeof(struct Book));

    for (int i = 0; i < num_books; i++) {
        printf("Enter the details for the book %d:\n", i + 1);
        get_input(&books[i]);
    }

    char* title_of_book_with_most_pages = find_book_with_most_pages(books, num_books);
    printf("The title of the book with the most pages is: %s\n", title_of_book_with_most_pages);

    for (int i = 0; i < num_books; i++) {
        free(books[i].title);
        free(books[i].author);
        free(books[i].ISBN);
    }
    free(books);

    return 0;
}
*/
