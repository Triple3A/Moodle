#include "signin.h"

std* signup_std(char* file_name, std *head, char* username, char* password)
{
	FILE *student = fopen(file_name, "a");
	int i;
	std *stu = head, *add = (std*)malloc(sizeof(std));
	if (stu->next != NULL)
	{
		stu = stu->next;
		while (stu->next != NULL)
		{
			if (!strcmp(stu->username, username))
			{
				printf("Your username have used before.\n");
				return NULL;
			}
			stu = stu->next;
		}
		if (!strcmp(stu->username, username))
		{
			printf("Your username have used before.\n");
			return NULL;
		}
	}
	add->username = (char*)malloc((strlen(username)) * sizeof(char));
	add->username = username;
	add->password = (char*)malloc((strlen(password)) * sizeof(char));
	add->password = password;
	fwrite(username, sizeof(char), strlen(username), student);
	fwrite("\n", sizeof(char), 1, student);
	fwrite(password, sizeof(char), strlen(password), student);
	fwrite("\n", sizeof(char), 1, student);
	fwrite("0", sizeof(char), 1, student);
	fwrite("\n", sizeof(char), 1, student);
	add->courses = (T_LIST*)malloc(sizeof(T_LIST));
	add->courses->next = NULL;
	add->next = NULL;
	stu->next = add;
	stu = stu->next;
	printf("User %s added to students.\n", username);
	fclose(student);
	return stu;
}

Teacher* signup_teacher(char* file_name, Teacher *head, char* username, char* password)
{
	FILE *teacher = fopen(file_name, "a");
	int i;
	Teacher *teach = head, *add = (std*)malloc(sizeof(std));
	if (teach->next != NULL)
	{
		teach = teach->next;
		while (teach->next != NULL)
		{
			if (!strcmp(teach->username, username))
			{
				printf("Your username have used before.\n");
				return NULL;
			}
			teach = teach->next;
		}
		if (!strcmp(teach->username, username))
		{
			printf("Your username have used before.\n");
			return NULL;
		}
	}
	add->username = (char*)malloc((strlen(username)) * sizeof(char));
	add->username = username;
	add->password = (char*)malloc((strlen(password)) * sizeof(char));
	add->password = password;
	fwrite(username, sizeof(char), strlen(username), teacher);
	fwrite("\n", sizeof(char), 1, teacher);
	fwrite(password, sizeof(char), strlen(password), teacher);
	fwrite("\n", sizeof(char), 1, teacher);
	fwrite("0", sizeof(char), 1, teacher);
	fwrite("\n", sizeof(char), 1, teacher);
	add->requests_list = (Req_LIST*)malloc(sizeof(Req_LIST));
	add->requests_list->next = NULL;
	add->accept_list = (Req_LIST*)malloc(sizeof(Req_LIST));
	add->accept_list->next = NULL;
	add->next = NULL;
	teach->next = add;
	teach = teach->next;
	printf("User %s added to teachers.\n", username);
	fclose(teacher);
	return teach;
}

std *login_std(std *head, char *username, char *password)
{
	std *stu = head;
	stu = stu->next;
	while (stu != NULL)
	{
		if (!strcmp(stu->username, username) && !strcmp(stu->password, password))
		{
			printf("welcome back %s\n", username);
			return stu;
		}
		stu = stu->next;
	}
	printf("your username is not founded\n");
	return NULL;
}

Teacher *login_teacher(Teacher *head, char *username, char *password)
{
	Teacher *teach = head;
	teach = teach->next;
	while (teach != NULL)
	{
		if (!strcmp(teach->username, username) && !strcmp(teach->password, password))
		{
			printf("welcome back %s\n", username);
			return teach;
		}
		teach = teach->next;
	}
	printf("your username is not founded\n");
	return NULL;
}

std *logout_stu(std *stu, std *head)
{
	stu = head;
	printf("You loged out successfully\n");
	return head;
}

Teacher *logout_teacher(Teacher *teach, Teacher *head)
{
	teach = head;
	printf("You loged out successfully\n");
	return head;
}
