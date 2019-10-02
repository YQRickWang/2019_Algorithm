# include <iostream>
#define INFINITY 10e16
using namespace std;
int MERGE_SORT(int* A, int p, int r);
int MERGE(int* A, int p, int q, int r);
int BINARY_SEARCH(int* A, int item, int low, int high);

int main()
{
	int num_shop = 0;
	int* prices = NULL;
	int num_day = 0;
	int* spent = NULL;
	int* buy = NULL;
	int count = 0;


	//input
	cin >> num_shop;

	prices = new (nothrow)int[num_shop];
	
	for (int i=0; i < num_shop; i++)
	{
		cin >> *(prices + i);
	}



	cin >> num_day;//q consecutive days

	spent = new (nothrow)int[num_day];

	for (int i = 0; i < num_day; i++)
	{
		cin >> *(spent + i);
	}

	buy = new (nothrow)int[num_day];



	//implement a function
	MERGE_SORT(prices, 0, num_shop - 1);
	//MERGE_SORT(spent,0,num_day-1);

	//print prices
	//for (int i = 0; i < num_shop; i++)
	//{
	//	cout << prices[i] << " ";
	//}


	//binary search
	for (int i = 0; i < num_day; i++)
	{

		buy[i] = BINARY_SEARCH(prices, spent[i], 0, num_shop-1);

	}

	//output

	for (int i = 0; i < num_day; i++)
	{
		cout << *(buy + i);
		if (i != num_day - 1)
			cout << "\n";
	}

	delete[] prices, spent, buy;



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

int BINARY_SEARCH(int* A, int item, int low, int high)
{
	if (high <= low)
	{
		if (item >= A[low])
			return low + 1;
		else
			return low;
	}

	int mid = (low + high) / 2;


	if (item >= A[mid])
		return BINARY_SEARCH(A, item, mid + 1, high);

	return BINARY_SEARCH(A, item, low, mid - 1);


}