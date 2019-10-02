#include <iostream>
#define INFINITY std::numeric_limits<int>::max()
using namespace std;
int MERGE_SORT(int* A, int p, int r);
int MERGE(int* A, int p, int q, int r);


int main()
{
	int n;//the length of array
	int* A=NULL;
	int temp = 0;

	cin >> n;
	
	A = new (nothrow)int[n];

	//read the array

	for (int i = 0; i < n ; i++)
	{
		cin >> temp;
		*(A + i) = temp;
	}

	//merge sort
	MERGE_SORT(A, 0, n-1);


	for (int i = 0; i < n; i++)
	{
		cout << *(A + i);
		if (i != n - 1)
			cout << " ";
	}

	

	delete[] A;

	return 0;


}

int MERGE_SORT(int* A, int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
	else
		return 0;
}

int MERGE(int* A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = NULL;
	int* R = NULL;
	int i = 0, j = 0;

	L = new (nothrow)int[n1 + 1];
	R = new (nothrow)int[n2 + 1];

	for (i = 0; i < n1; i++)
	{
		*(L + i) = *(A+p+i);
	}
	*(L + n1) = INFINITY;


	for (i = 0; i < n2; i++)
	{
		*(R + i) = *(A + q + 1 + i);
	}
	*(R + n2) = INFINITY;

	i = 0;
	j = 0;

	for (int k = p; k < r+1 ;k++)
	{
		if (*(L + i) <= *(R + j)) {
			*(A + k) = *(L + i);
			i++;
		}
		else
		{
			*(A + k) = *(R + j);
			j++;
		}

	}

	delete[] L;
	delete[] R;

	

	return 0;
}


