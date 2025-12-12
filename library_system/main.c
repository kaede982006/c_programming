#include "library_system.h"

int main() {
    s_book* book;
    s_user* user;

    create_book(book);
    create_user(user);

    borrow_book(user, book);

    delete_book(book);
    delete_user(user);

    return 0;
}
