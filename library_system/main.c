#include "library_system.h"
#include "library_tools.h"
#include "library_data.h"

#include <stdlib.h>

int main() {
    library_init();

    s_user* user[10];
    s_account* account[10];
    char* name_buffer[10];
    int name_buffer_length[10];
    char* passwd_buffer[10];
    int passwd_buffer_length[10];

    for(int i=0;i<10;i++) {
        name_buffer_length[i]=rand()%8+5;
        name_buffer[i]=(char*)calloc(name_buffer_length[i], sizeof(char));
        passwd_buffer_length[i]=rand()%4+9;
        passwd_buffer[i]=(char*)calloc(passwd_buffer_length[i], sizeof(char));
        s_year_info year_info;
        random_year_info(&year_info);

        account[i]=create_account(account[i], random_string(name_buffer[i], name_buffer_length[i]-1), \
                random_string(passwd_buffer[i], passwd_buffer_length[i]-1),year_info);
        user[i]=create_user(user[i], account[i]);
    }
    for(int i=0;i<10;i++) {
        delete_user(user[i]);
        delete_account(account[i]);
        free(name_buffer[i]);
        free(passwd_buffer[i]);
    }

    library_end();
    return 0;
}
