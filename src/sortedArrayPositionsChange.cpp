/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{

	int i = 0, j = len - 1, k = -1;
	if (len > 0)
	{
		if (Arr)
		{
			while (i < len)
			{
				if (Arr[i]>Arr[i + 1])
				{
					break;
				}
				else if (Arr[i]<Arr[i + 1])
				{
					k = i + 1;
				}
				else if (Arr[i] == Arr[i + 1] && i == 0)
				{
					k = 0;
				}
				i++;
			}
			while (i < j)
			{

				if (Arr[j] >= Arr[j - 1])
				{
					j--;
				}
				else
				{

					if (k != -1)
					{
						i = k;
					}
					Arr[i] = Arr[i] + Arr[j];
					Arr[j] = Arr[i] - Arr[j];
					Arr[i] = Arr[i] - Arr[j];
					return Arr;
				}

			}
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