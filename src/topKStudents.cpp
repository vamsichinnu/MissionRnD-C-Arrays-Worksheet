/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	int i, j, p = -1;
	struct student *result;
	char *temp;
	temp = (char *)malloc(sizeof(char)* 10);
	result = (struct student *)malloc(sizeof(struct student)*K);
	for (i = 0; i <K; i++)
	{
		p++;
		for (j = p; j < len - 1; j++)
		{
			if (students[i].score < students[j + 1].score)
			{
				students[i].score = students[i].score + students[j + 1].score;
				students[j + 1].score = students[i].score - students[j + 1].score;
				students[i].score = students[i].score - students[j + 1].score;
				temp = students[i].name;
				students[i].name = students[j + 1].name;
				students[j + 1].name = temp;
				

			}
		}
		result[p].name = (char *)malloc(sizeof(char)* 10);
		result[p].name = students[i].name;
		result[p].score = students[i].score;
	}

	return (&result);
}