/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct student {
	char name[10];
	int score;
};
void mergesort(struct student *students, int min, int mid, int max)
{
	struct student *temp;
	int i, j, k, m;
	j = min;
	m = mid + 1;
	temp = (struct student *)malloc(sizeof(struct student)*max);
	for (i = min; j <= mid && m <= max; i++)
	{
		if (students[j].score >= students[m].score)
		{
			temp[i] = students[j];
			j++;
		}
		else
		{
			temp[i] = students[m];
			m++;
		}
	}
	if (j<mid)
	{
		for (k = m; k <= max; k++)
		{
			temp[i] = students[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			temp[i] = students[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
		students[k] = temp[k];
}
void divide(struct student *students, int min, int max)
{
	int mid;
	if (min<max)
	{
		mid = (min + max) / 2;
		divide(students, min, mid);
		divide(students, mid + 1, max);
		mergesort(students, min, mid, max);
	}
}


void * scoresDescendingSort(struct student *students, int len) {
	if (len > 0)
	{
		if (students)
		{

			divide(students, 0, len - 1);
			return students;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}