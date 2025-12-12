#ifndef __LIBRARY_STRUCTURE__
#define __LIBRARY_STRUCTURE__

#define DEFAULT_STRING_LENGTH 256
typedef struct {
    char* title;
    char* author;
    char* main_field;
    char* sub_field;
    unsigned int year;
    char* isbn;
} s_book;

typedef struct {
    int birth_year;
    int birth_month;
    int birth_day;
    int join_year;
    int join_month;
    int join_day;
} s_year_info;
typedef struct {
    char* name;
    char* passwd;
    s_year_info year_info;
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

s_book* create_book(s_book* book, char* title, char* author, char* main_field, char* sub_field, unsigned int year,char* isbn);
void delete_book(s_book* book);
s_user* create_user(s_user* user, s_account* account);
void delete_user(s_user* user);
s_librarian* create_librarian(s_librarian* librarian, s_account* account);
void delete_librarian(s_librarian* librarian);
s_account* create_account(s_account* account, char* name, char* passwd, s_year_info year_info);
void delete_account(s_account* account);
#endif
