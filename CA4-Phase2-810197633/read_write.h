#pragma once
#include <stdio.h>
#include "Num.h"

void load_data_std(char *file_name, std *head);
char* read_line_from_input_file(FILE* input);
char* getinput(void);
char* u_p(char* username);
std* read_students_credentials_from_file(char* file_name, std *head);
Teacher* read_teachers_credentials_from_file(char* file_name, Teacher *head);
void load_data_teacher(char *file_name, Teacher *head);