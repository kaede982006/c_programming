#include "library_system.h"
#include <stdlib.h>

void borrow_book(s_user* user, s_book* book) {
    user->book[user->book_count]=book; 
    user->overdue_period[user->book_count]=-DEFAULT_PERIOD; 
    user->book_count++;

    user->book=realloc(user->book, user->book_count*sizeof(s_book*));
    user->overdue_period=realloc(user->overdue_period, user->book_count*sizeof(int));
}
void remove_book(s_user* user, s_book* book) {
    int i=0;
    for (;i<user->book_count;i++) {
        if(book==user->book[i]) break;
    }
    
    user->book_count--;
    user->book=realloc(user->book, user->book_count*sizeof(s_book));
}
void set_salary(s_librarian* librarian);
void update_user(s_user* user);
void update_librarian(s_librarian* librarian);
