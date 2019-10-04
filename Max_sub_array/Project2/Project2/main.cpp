#include <iostream>
#include <tuple>
std::tuple<int,int,int> FIND_MAX_SUBARRAY(int* A, int low, int high);

int main()
{
	int* A = NULL;
	int length = 0;//the length of the array


	//input the array
	std::cin >> length;
	//allocate the space of the array
	A = new (std::nothrow) int[length];
	for (int i = 0; i < length; i++)
	{
		std::cin >> A[i];
	}
	








	return 0;
}

std::tuple<int,int,int> FIND_MAX_SUBARRAY(int* A, int low, int high)
{
	int mid = 0;
	int left_low = 0;
	int left_high = 0;
	int left_sum = 0;
	int right_low = 0;
	int right_high = 0;
	int right_sum = 0;
	int cross_low = 0;
	int cross_high = 0;
	int cross_sum = 0;

	if (high == low)
	{
		return {low,high,A[low]};
	}
	else
	{
		mid = (low + high) / 2;
	}

}