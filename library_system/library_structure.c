#include <stdlib.h>
#include <string.h>
#include "library_structure.h"

s_book* create_book(s_book* book,char* title, char* author, char* main_field, char* sub_field, unsigned int year, char* isbn) {
    book = (s_book*)calloc(1, sizeof(s_book));
    book->title=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));
    book->author=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));
    book->main_field=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));
    book->sub_field=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));
    book->isbn=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));
    
    strcpy(book->title, title);
    strcpy(book->author, author);
    strcpy(book->main_field, main_field);
    strcpy(book->sub_field, sub_field);
    strcpy(book->isbn, isbn);
    book->year=year;

    return book;
}

void delete_book(s_book* book) {
    free(book->title);
    free(book->author);
    free(book->main_field);
    free(book->sub_field);
    free(book);
}

s_user* create_user(s_user* user, s_account* account) {
    user = (s_user*)calloc(1, sizeof(s_user));

    user->book=(s_book**)calloc(1,sizeof(s_book*));
    user->book_count=0;
    user->overdue_period=(int*)calloc(1,sizeof(int));
    return user;
}

void delete_user(s_user* user) {
    free(user->book);
    free(user->overdue_period);
    free(user);
}

s_librarian* create_librarian(s_librarian* librarian, s_account* account) {
    librarian = (s_librarian*)calloc(1, sizeof(s_librarian));

    librarian->salary=300;
    return librarian;
}
void delete_librarian(s_librarian* librarian) {
    free(librarian);
}
s_account* create_account(s_account* account, char* name, char* passwd, s_year_info year_info) {
    account=(s_account*)calloc(1, sizeof(s_account));
    account->name=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));
    account->passwd=(char*)calloc(DEFAULT_STRING_LENGTH,sizeof(char));

    strcpy(account->name, name);
    strcpy(account->passwd, passwd);
    account->year_info=year_info;

    return account;
}
void delete_account(s_account* account) {
    free(account->name);
    free(account->passwd);
    free(account);
}
