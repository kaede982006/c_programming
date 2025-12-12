#include <stdlib.h>
#include "library_structure.h"

create_book(s_book* book) {
    book = (s_book*)calloc(1, sizeof(s_book));
    book->title=(char*)calloc(256,sizeof(char));
    book->author=(char*)calloc(256,sizeof(char));
    book->main_field=(char*)calloc(256,sizeof(char));
    book->sub_field=(char*)calloc(256,sizeof(char));
    return book;
}

void delete_book(s_book* book) {
    free(book->title);
    free(book->author);
    free(book->main_field);
    free(book->sub_field);
    free(book);
}

void create_user(s_user* user) {
    user = (s_user*)calloc(1, sizeof(s_user));
    user->account.name=(char*)calloc(256,sizeof(char));
    user->account.passwd=(char*)calloc(256,sizeof(char));
    user->book=(s_book**)calloc(1,sizeof(s_book*));
    user->book_count=0;
    user->overdue_period=(int*)calloc(1,sizeof(int));
    return user;
}

void delete_user(s_user* user) {
    free(user->account.name);
    free(user->account.passwd);
    free(user->book);
    free(user->overdue_period);
    free(user);
}

void create_librarian(s_librarian* librarian) {
    librarian = (s_librarian*)calloc(1, sizeof(s_librarian));
    librarian->account.name=(char*)calloc(256,sizeof(char));
    librarian->account.passwd=(char*)calloc(256,sizeof(char));
    librarian->salary=300;   
    return librarian;
}
void delete_librarian(s_librarian* librarian) {
    free(librarian->account.name);
    free(librarian->account.passwd);
    free(librarian);
}
