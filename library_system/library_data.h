#ifndef __LIBRARY_DATA__
#define __LIBRARY_DATA__
#define LIBRARY_BOOK_NUM 200
#include "library_structure.h"

extern s_book* book_list[LIBRARY_BOOK_NUM];
void library_init();
void library_end();

#endif
