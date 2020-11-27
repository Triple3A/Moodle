#pragma once
#include <stdio.h>
#include "Structures.h"
std* signup_std(char* file_name, std *head, char* username, char* password);
Teacher* signup_teacher(char* file_name, Teacher *head, char* username, char* password);
std *login_std(std *head, char *username, char *password);
Teacher *login_teacher(Teacher *head, char *username, char *password);
std *logout_stu(std *stu, std *head);
Teacher *logout_teacher(Teacher *teach, Teacher *head);