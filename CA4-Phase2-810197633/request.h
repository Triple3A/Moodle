#pragma once
#include "Structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int request(Teacher *t_head, std *stu, char* username);
int accept(Teacher *teach, std *s_head, char* username);
void request_list(Teacher *teach);
void teacher_list(std *stu);