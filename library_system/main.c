#include "library_system.h"

int main() {
    s_book* book1; s_book* book2;
    s_user* user;

    book1=create_book(book1, "Extreme C", "Kamran Amini", "Computer Science", "C Programming",2019 ,"9781789343625");
    book2=create_book(book2, "Extreme C", "Kamran Amini", "Computer Science", "C Programming",2019 ,"9781789343625");

    s_account* account;
    account=create_account(account, "xisik", "2342",(s_year_info){2006, 10 , 5, 2025, 12, 13});
    user=create_user(user, account);

    borrow_book(user, book1);
    borrow_book(user, book2);
    remove_book(user, book2);

    delete_book(book1);
    delete_user(user);
    delete_account(account);

    return 0;
}
