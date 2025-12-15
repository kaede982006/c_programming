#include <stdlib.h>
#include "library_tools.h"

char* random_string(char* buffer, int n) {
    if(buffer==NULL) return NULL;
    for (int i=0;i<n;i++) {
        int temp=rand()%3;
        switch(temp) {
            case 0: buffer[i]=rand()%9+48; break;
            case 1: buffer[i]=rand()%25+65; break;
            case 2: buffer[i]=rand()%25+97; break;
        }
    }
    buffer[n]=='\0';
    return buffer;
}

void random_year_info(s_year_info* year_info) {
    year_info->birth_year=rand()%55+1970;
    year_info->birth_month=rand()%12+1;
    if((year_info->birth_year%4==0) && \
            (year_info->birth_year%100!=0 || year_info->birth_year%400==0) && \
            year_info->birth_month==2) {
        year_info->birth_day=rand()%29+1;
    } else {
        if(year_info->birth_month==1 || year_info->birth_month==3 || year_info->birth_month==5 || \
                year_info->birth_month==7 || year_info->birth_month==8 || year_info->birth_month==10 || \
                year_info->birth_month==12) {
            year_info->birth_day=rand()%31+1;
        } else if(year_info->birth_month==4 || year_info->birth_month==6 || \
                year_info->birth_month==9 || year_info->birth_month==11) {
            year_info->birth_day=rand()%30+1;
        } else {
            year_info->birth_day=rand()%28+1;
        }
    }

    year_info->join_year=rand()%(2025-year_info->birth_year)+year_info->birth_year;
    year_info->join_month=rand()%12+1;
    if((year_info->join_year%4==0) && \
            (year_info->join_year%100!=0 || year_info->join_year%400==0) && \
            year_info->join_month==2) {
        year_info->join_day=rand()%29+1;
    } else {
        if(year_info->join_month==1 || year_info->join_month==3 || year_info->join_month==5 || \
                year_info->join_month==7 || year_info->join_month==8 || year_info->join_month==10 || \
                year_info->join_month==12) {
            year_info->join_day=rand()%31+1;
        } else if(year_info->join_month==4 || year_info->join_month==6 || \
                year_info->join_month==9 || year_info->join_month==11) {
            year_info->join_day=rand()%30+1;
        } else {
            year_info->join_day=rand()%28+1;
        }
    }
}
