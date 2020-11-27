#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student std;
typedef struct teacher_list T_LIST;
typedef struct teacher Teacher;
typedef struct request_list Req_LIST;
struct student {
	char *username;
	char *password;
	T_LIST *courses;
	std *next;
};
struct teacher_list {
	char *username;
	char *grade;
	T_LIST *next;
};
struct teacher {
	char *username;
	char *password;
	Req_LIST *requests_list;
	Req_LIST *accept_list;
	Teacher *next;
};
struct request_list {
	char *username;
	Req_LIST *next;
};
