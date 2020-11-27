#include "read_write.h"

void load_data_std(char *file_name, std *head)
{
	FILE *student = fopen(file_name, "w");
	std *stu = head;
	stu = stu->next;
	int num = num_of_std(head);
	char* n = (char*)malloc(sizeof(char) * intlen(num));
	itoa(num, n, 10);
	fwrite(n, sizeof(char), intlen(num), student);
	fwrite("\n", sizeof(char), 1, student);
	while (stu != NULL)
	{
		T_LIST *course = stu->courses;
		fwrite(stu->username, sizeof(char), strlen(stu->username), student);
		fwrite("\n", sizeof(char), 1, student);
		fwrite(stu->password, sizeof(char), strlen(stu->password), student);
		fwrite("\n", sizeof(char), 1, student);
		int num_c = num_of_courses(stu->courses);
		char* n_c = (char*)malloc(sizeof(char) * intlen(num_c));
		itoa(num_c, n_c, 10);
		fwrite(n_c, sizeof(char), intlen(num_c), student);
		fwrite("\n", sizeof(char), 1, student);
		course = course->next;
		while (course != NULL)
		{
			fwrite(course->username, sizeof(char), strlen(course->username), student);
			fwrite("\n", sizeof(char), 1, student);
			fwrite(course->grade, sizeof(char), strlen(course->grade), student);
			fwrite("\n", sizeof(char), 1, student);
			course = course->next;
		}
		stu = stu->next;
	}
	fclose(student);
}

char* read_line_from_input_file(FILE* input) {
	int line_length = 0;
	char* line = (char*)malloc(sizeof(char));
	*(line) = '0';
	char temp_char[1] = { ' ' };
	while (1) {
		fread(temp_char, sizeof(char), 1, input);
		line_length++;
		line = (char*)realloc(line, sizeof(char) * line_length);
		line[line_length - 1] = NULL;
		switch (temp_char[0]) {
		case '\n':
			return line;
			break;
		case EOF:
			return line;
			break;
		default:
			line[line_length - 1] = temp_char[0];
			break;
		}
	}
}

char* getinput(void) 
{
	int line_length = 0;
	char* line = (char*)malloc(sizeof(char));
	*(line) = '0';
	char temp_char[1] = { ' ' };
	while (1) {
		temp_char[0] = getchar();
		line_length++;
		line = (char*)realloc(line, sizeof(char) * line_length);
		line[line_length - 1] = NULL;
		switch (temp_char[0]) 
		{
		case '\n':
			return line;
			break;
		default:
			line[line_length - 1] = temp_char[0];
			break;
		}
	}
}

char* u_p(char* user_name)
{
	int i, f = 0, j;
	char *username = (char*)malloc(sizeof(char) * (strlen(user_name) + 1));
	strcpy(username, user_name);
	char *password = (char*)malloc(sizeof(char));
	for (i = 0; i <= strlen(username); i++)
	{
		if (f == 1)
		{
			password = (char*)realloc(password, sizeof(char) * (strlen(username) - j));
			password[i - j - 1] = username[i];
		}
		if (username[i] == ' ')
		{
			f = 1;
			j = i;
		}	
	}
	username = (char*)realloc(username, sizeof(char) * (j + 1));
	username[j] = '\0';
	strcpy(user_name, username);
	return password;
}

std* read_students_credentials_from_file(char* file_name, std *head)
{
	FILE* input;
	int i, j;
	int num_stu, num_courses;
	T_LIST *course = (T_LIST*)malloc(sizeof(T_LIST));
	if (input = fopen(file_name, "r"))
	{
		std *stu = head;
		num_stu = atoi(read_line_from_input_file(input));
		for (i = 0; i < num_stu; i++)
		{
			std *student = (std*)malloc(sizeof(std));
			student->username = read_line_from_input_file(input);
			student->password = read_line_from_input_file(input);
			student->next = NULL;
			stu->next = student;
			stu = stu->next;
			stu->courses = (T_LIST*)malloc(sizeof(T_LIST));
			stu->courses->next = NULL;
			T_LIST *course1 = stu->courses;
			num_courses = atoi(read_line_from_input_file(input));
			for (j = 0; j < num_courses; j++)
			{
				T_LIST *course = (T_LIST*)malloc(sizeof(T_LIST));
				course->username = read_line_from_input_file(input);
				course->grade = read_line_from_input_file(input);
				course->next = NULL;
				course1->next = course;
				course1 = course1->next;
			}
		}
		fclose(input);
		return head;
	}
	return NULL;
}

Teacher* read_teachers_credentials_from_file(char* file_name, Teacher *head)
{
	FILE* input;
	int i, j;
	int num_teach, num_req, num_acc;
	if (input = fopen(file_name, "r"))
	{
		Teacher *teach = head;
		num_teach = atoi(read_line_from_input_file(input));
		for (i = 0; i < num_teach; i++)
		{
			Teacher *_teacher = (Teacher*)malloc(sizeof(Teacher));
			_teacher->username = read_line_from_input_file(input);
			_teacher->password = read_line_from_input_file(input);
			_teacher->next = NULL;
			teach->next = _teacher;
			teach = teach->next;
			teach->requests_list = (Req_LIST*)malloc(sizeof(Req_LIST));
			teach->accept_list = (Req_LIST*)malloc(sizeof(Req_LIST));
			teach->requests_list->next = NULL;
			teach->accept_list->next = NULL;
			Req_LIST *req1 = teach->requests_list;
			num_req = atoi(read_line_from_input_file(input));
			for (j = 0; j < num_req; j++)
			{
				Req_LIST *req = (Req_LIST*)malloc(sizeof(Req_LIST));
				req->username = read_line_from_input_file(input);
				req->next = NULL;
				req1->next = req;
				req1 = req1->next;
			}
			Req_LIST *acc1 = teach->accept_list;
			num_acc = atoi(read_line_from_input_file(input));
			for (j = 0; j < num_acc; j++)
			{
				Req_LIST *acc = (Req_LIST*)malloc(sizeof(Req_LIST));
				acc->username = read_line_from_input_file(input);
				acc->next = NULL;
				acc1->next = acc;
				acc1 = acc1->next;
			}
		}
		fclose(input);
		return head;
	}
	return NULL;
}

void load_data_teacher(char *file_name, Teacher *head)
{
	FILE *teachers = fopen(file_name, "w");
	Teacher *teach = head;
	teach = teach->next;
	int num = num_of_teach(head);
	char* n = (char*)malloc(sizeof(char) * intlen(num));
	itoa(num, n, 10);
	fwrite(n, sizeof(char), intlen(num), teachers);
	fwrite("\n", sizeof(char), 1, teachers);
	while (teach != NULL)
	{
		Req_LIST *req = teach->requests_list;
		Req_LIST *acc = teach->accept_list;
		fwrite(teach->username, sizeof(char), strlen(teach->username), teachers);
		fwrite("\n", sizeof(char), 1, teachers);
		fwrite(teach->password, sizeof(char), strlen(teach->password), teachers);
		fwrite("\n", sizeof(char), 1, teachers);
		int num_req = num_of_req_acc(teach->requests_list);
		char* n_req = (char*)malloc(sizeof(char) * intlen(num_req));
		itoa(num_req, n_req, 10);
		fwrite(n_req, sizeof(char), intlen(num_req), teachers);
		fwrite("\n", sizeof(char), 1, teachers);
		req = req->next;
		while (req != NULL)
		{
			fwrite(req->username, sizeof(char), strlen(req->username), teachers);
			fwrite("\n", sizeof(char), 1, teachers);
			req = req->next;
		}
		int num_acc = num_of_req_acc(teach->accept_list);
		char* n_acc = (char*)malloc(sizeof(char) * intlen(num_acc));
		itoa(num_acc, n_acc, 10);
		fwrite(n_acc, sizeof(char), intlen(num_acc), teachers);
		fwrite("\n", sizeof(char), 1, teachers);
		acc = acc->next;
		while (acc != NULL)
		{
			fwrite(acc->username, sizeof(char), strlen(acc->username), teachers);
			fwrite("\n", sizeof(char), 1, teachers);
			acc = acc->next;
		}
		teach = teach->next;
	}
	fclose(teachers);
}
