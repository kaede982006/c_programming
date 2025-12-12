#ifndef __LIBRARY_SYSTEM__
#define __LIBRARY_SYSTEM__

#include "library_structure.h"
#define DEFAULT_PERIOD 7
void borrow_book(s_user* user, s_book* book);
void remove_book(s_user* user, s_book* book);
void set_salary(s_librarian* librarian);
void update_user(s_user* user);
void update_librarian(s_librarian* librarian);

#endif
