#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
#include "read_write.h"
#include "request.h"
#include "grade.h"
int main()
{
	std *s_head = (std*)malloc(sizeof(std));
	std *stu;
	s_head->next = NULL;
	s_head->courses = (T_LIST*)malloc(sizeof(T_LIST));
	s_head->courses->next = NULL;
	s_head = read_students_credentials_from_file("student.txt", s_head);
	Teacher *t_head = (Teacher*)malloc(sizeof(Teacher));
	Teacher *teach;
	t_head->next = NULL;
	t_head->requests_list = (Req_LIST*)malloc(sizeof(Req_LIST));
	t_head->requests_list->next = NULL;
	t_head->accept_list = (Req_LIST*)malloc(sizeof(Req_LIST));
	t_head->accept_list->next = NULL;
	t_head = read_teachers_credentials_from_file("teacher.txt", t_head);
	int f = 0;
	char in[50];
	char *input;
	char *username;
	char *password;
	char *_grade;
	while (1)
	{
		scanf("%s", in);
		input = (char*)malloc(sizeof(char) * strlen(in));
		strcpy(input, in);
		if(!strcmp(input, "signup_student"))
		{
			scanf("\n");
			username = getinput();
			password = u_p(username);
			if (f == 0)
			{
				stu = signup_std("student.txt", s_head, username, password);
				if (stu != NULL)
					f = 1;
			}
			else
				printf("You don\'t logout\n");
		}
		else if (!strcmp(input, "signup_teacher"))
		{
			scanf("\n");
			username = getinput();
			password = u_p(username);
			if (f == 0)
			{
				teach = signup_teacher("teacher.txt", t_head, username, password);
				if (teach != NULL)
					f = 2;
			}
			else
				printf("You don\'t logout\n");
		}
		else if (!strcmp(input, "login_student"))
		{
			scanf("\n");
			username = getinput();
			password = u_p(username);
			if (f == 0)
			{
				stu = login_std(s_head, username, password);
				if (stu != NULL)
					f = 1;
			}
			else
				printf("You don\'t logout\n");
		}
		else if (!strcmp(input, "login_teacher"))
		{
			scanf("\n");
			username = getinput();
			password = u_p(username);
			if (f == 0)
			{
				teach = login_teacher(t_head, username, password);
				if (teach != NULL)
					f = 2;
			}
			else
				printf("You don\'t logout\n");
		}
		else if (!strcmp(input, "logout"))
		{
			if (f == 1)
				stu = logout_stu(stu, s_head);
			else if (f == 2)
				teach = logout_teacher(teach, t_head);
			else
				printf("nobody login\n");
			f = 0;
		}
		else if (!strcmp(input, "request_course"))
		{
			scanf("\n");
			username = getinput();
			if (f == 1)
			{
				request(t_head, stu, username);
			}
			else
				printf("You can\'t request\n");
		}
		else if (!strcmp(input, "accept"))
		{
			scanf("\n");
			username = getinput();
			if (f == 2)
			{
				accept(teach, s_head, username);
			}
			else
				printf("You can\'t accept\n");
		}
		else if (!strcmp(input, "requests_list"))
		{
			if (f == 2)
			{
				request_list(teach);
			}
			else
				printf("You are not a teacher\n");
		}
		else if (!strcmp(input, "grade"))
		{
			scanf("\n");
			username = getinput();
			_grade = u_p(username);
			if(f == 2)
				grade(teach, s_head, username, _grade);
			else
				printf("You are not a teacher\n");
		}
		else if (!strcmp(input, "show_grade"))
		{
			scanf("\n");
			username = getinput();
			if (f == 1)
				show_grade(stu, username);
			else
				printf("You are not a student\n");
		}
		else if (!strcmp(input, "teachers_list"))
		{
			if (f == 1)
				teacher_list(stu);
			else
				printf("You are not a student\n");
		}
		else if (!strcmp(input, "show_grades"))
		{
			if (f == 1)
				show_grades(stu);
			else
				printf("You are not a student\n");
		}
		else if(!strcmp(input, "exit"))
		{
			load_data_std("student.txt", s_head);
			load_data_teacher("teacher.txt", t_head);
			return 0;
		}
		else
			printf("!!\n");
		/*load_data_std("student.txt", s_head);
		load_data_teacher("teacher.txt", t_head);*/
	}
}