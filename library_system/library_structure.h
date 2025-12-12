#ifndef __LIBRARY_STRUCTURE__
#define __LIBRARY_STRUCTURE__

typedef struct {
    char* title;
    char* author;
    char* main_field;
    char* sub_field;
    unsigned int year;
    unsigned short isbn;
} s_book;

typedef struct {
    char* name;
    char* passwd;
    int birth_year;
    int birth_month;
    int birth_day;
    int join_year;
    int join_month;
    int join_day;
} s_account;

typedef struct {
    s_account account;
    s_book** book;
    int book_count;
    int* overdue_period;
} s_user;

typedef struct {
    s_account account;
    int salary;
} s_librarian;

void create_book(s_book* book);
void delete_book(s_book* book);
void create_user(s_user* user);
void delete_user(s_user* user);
void create_librarian(s_librarian* librarian);
void delete_librarian(s_librarian* librarian);
#endif
