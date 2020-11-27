#include "Num.h"

int intlen(int n)
{
	int len = 0;
	if (n == 0)
		return 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return len;
}

int num_of_std(std* head)
{
	std *stu = head;
	int i = 0;
	while (stu != NULL)
	{
		i++;
		stu = stu->next;
	}
	return i - 1;
}

int num_of_courses(T_LIST* head)
{
	T_LIST *course = head;
	int i = 0;
	while (course != NULL)
	{
		i++;
		course = course->next;
	}
	return i - 1;
}

int num_of_teach(Teacher *head)
{
	Teacher *teach = head;
	int i = 0;
	while (teach != NULL)
	{
		i++;
		teach = teach->next;
	}
	return i - 1;
}

int num_of_req_acc(Req_LIST *head)
{
	Req_LIST *req = head;
	int i = 0;
	while (req != NULL)
	{
		i++;
		req = req->next;
	}
	return i - 1;
}