#include "grade.h"

void grade(Teacher *teach, std *s_head, char* s_username, char* _grade)
{
	std *stu = s_head;
	T_LIST *course = (T_LIST*)malloc(sizeof(T_LIST));
	stu = stu->next;
	while (stu != NULL)
	{
		if (!strcmp(stu->username, s_username))
		{
			course = stu->courses;
			course = course->next;
			while (course != NULL)
			{
				if (!strcmp(course->username, teach->username))
				{
					course->grade = (char*)malloc(sizeof(char) * strlen(_grade));
					strcpy(course->grade, _grade);
					printf("%s graded\n", s_username);
					return 1;
				}
				course = course->next;
			}
			printf("This student is not in your course\n");
			return 0;
		}
		stu = stu->next;
	}
	printf("The student does'\nt exist\n");
	return 0;
}

int show_grade(std *stu, char* t_username)
{
	T_LIST *course = stu->courses;
	course = course->next;
	while (course != NULL)
	{
		if (!strcmp(course->username, t_username))
		{
			if (!strcmp(course->grade, "-1"))
				printf("You are not graded\n");
			else
				printf("Your grade is %s\n", course->grade);
			return 1;
		}
		course = course->next;
	}
	printf("This course is not available for you\n");
	return 0;
}

void show_grades(std *stu)
{
	T_LIST *course = stu->courses;
	float avg = 0.0;
	int num = 0;
	course = course->next;
	if (course != NULL)
	{
		while (course != NULL)
		{
			if (!strcmp(course->grade, "-1"))
				course = course->next;
			else
			{
				printf("%s :\t%s\n", course->username, course->grade);
				avg += atof(course->grade);
				course = course->next;
				num++;
			}
		}
		if (num == 0)
			printf("You dont have any grade\n");
		else
		{
			avg /= num;
			printf("Your average is %f\n", avg);
		}
	}
	else
		printf("You don'\t have any courses\n");
}
