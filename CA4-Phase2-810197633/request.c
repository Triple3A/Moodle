#include "request.h"

int request(Teacher *t_head, std *stu, char* username)
{
	Teacher *teach = t_head;
	Req_LIST *req = (Req_LIST*)malloc(sizeof(Req_LIST));
	teach = teach->next;
	while (teach != NULL)
	{
		if (!strcmp(teach->username, username))
		{
			Req_LIST *req1 = teach->requests_list;
			if (req1->next != NULL)
			{
				while (req1->next != NULL)
				{
					if (!strcmp(req1->username, stu->username))
					{
						printf("You had requested for this course before\n");
						return 0;
					}
					req1 = req1->next;
				}
				if (!strcmp(req1->username, stu->username))
				{
					printf("You had requested for this course before\n");
					return 0;
				}
			}
			req->username = (char*)malloc(sizeof(char) * strlen(stu->username));
			strcpy(req->username, stu->username);
			req->next = NULL;
			req1->next = req;
			printf("You added to this request\n");
			return 1;
		}
		teach = teach->next;
	}
	printf("The teacher doesn\'t exist\n");
	return 0;
}

int accept(Teacher *teach, std *s_head, char* username)
{
	std *stu = s_head;
	Req_LIST *acc = (Req_LIST*)malloc(sizeof(Req_LIST));
	Req_LIST *prev = teach->requests_list;
	Req_LIST *curr = teach->requests_list;
	Req_LIST *acc1 = teach->accept_list;
	curr = curr->next;
	T_LIST *course = (T_LIST*)malloc(sizeof(T_LIST));
	while (curr != NULL)
	{
		if (!strcmp(curr->username, username))
		{
			prev->next = curr->next;
			if (acc1->next != NULL)
			{
				acc1 = acc1->next;
				while (acc1->next != NULL)
				{
					if (!strcmp(acc1->username, username))
					{
						printf("You had accepted this student before\n");
						return 0;
					}
					acc1 = acc1->next;
				}
				if (!strcmp(acc1->username, username))
				{
					printf("You had accepted this student before\n");
					return 0;
				}
			}
			acc->username = (char*)malloc(sizeof(char) * strlen(username));
			strcpy(acc->username, username);
			acc->next = NULL;
			acc1->next = acc;
			printf("Student accepted\n");
			stu = stu->next;
			while (stu != NULL)
			{
				if (!strcmp(stu->username, username))
				{
					T_LIST *course1 = stu->courses;
					while (course1->next != NULL)
					{
						course1 = course1->next;
					}
					course->username = (char*)malloc(sizeof(char) * strlen(teach->username));
					strcpy(course->username, teach->username);
					course->grade = (char*)malloc(sizeof(char));
					strcpy(course->grade, "-1");
					course->next = NULL;
					course1->next = course;
					return 1;
			
				}
				stu = stu->next;
			}
			return 0;
		}
		else
			prev = prev->next;
		curr = curr->next;
	}
	printf("The student doesn\'t exist\n");
	return 0;
}

void request_list(Teacher *teach)
{
	Req_LIST *req = teach->requests_list;
	req = req->next;
	if (req != NULL)
	{
		printf("Your request list:\n");
		printf("----------------------\n");
		while (req != NULL)
		{
			printf("Student username : %s\n", req->username);
			req = req->next;
		}
		printf("----------------------\n");
	}
	else
		printf("You don\'t have any request\n");
}

void teacher_list(std *stu)
{
	T_LIST *course = stu->courses;
	course = course->next;
	if (course != NULL)
	{
		printf("Your courses list :\n");
		printf("----------------------\n");
		while (course != NULL)
		{
			printf("Teacher username : %s\n", course->username);
			course = course->next;
		}
		printf("----------------------\n");
	}
	else
		printf("You don\'t have any courses\n");
}
