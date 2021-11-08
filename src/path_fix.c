#include "../inc/pathfinder.h"

void path_fix(const char *file){
    char *str = mx_file_to_str(file);
    char *message_error;
    int iteration = 2;
    while(*str != '\n'){
        if(!mx_isdigit(*str)){
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        str++;
        }
        str++;
    while(*str != '\0'){
        while(*str!= '-'){
            if(!mx_isalpha(*str)){
                message_error = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(message_error);
                exit(0);
            }
            str++;
        }
        str++;
        while(*str != ','){ 
            if(!mx_isalpha(*str)){
                message_error = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(message_error);
                exit(0);
            }
            str++;
        }
        str++;
        while(*str != '\n'){
            if(*str == '\0')
                break;
            if(!mx_isdigit(*str)){
                message_error = mx_strjoin(mx_strjoin("error: line ", mx_itoa(iteration)), " is not valid\n");
                mx_printerr(message_error);
                exit(0);
            }
            str++;
        }
        str++;
        iteration++;
    }
}
