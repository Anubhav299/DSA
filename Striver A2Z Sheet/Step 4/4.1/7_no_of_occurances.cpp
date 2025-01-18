#include <bits/stdc++.h>
using namespace std;

int firstOccur(int arr[], int n, int x)
{
	int low, high, mid, first;
	low = 0;
	high = n - 1;
	first = -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//could be the answer
		if (arr[mid] == x)
		{
			first = mid;
			high = mid - 1; //check for smaller index on the left
		}
		else if (arr[mid] < x)
		{
			low = mid + 1; //check on the right 
		}
		else
		{
			high = mid - 1; //look on the left
		}
	}
	return first;
}

int lastOccur(int arr[], int n, int x)
{
	int low, high, mid, last;
	low = 0;
	high = n - 1;
	last = -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == x)
		{
			last = mid;
			low = mid + 1;
		}
		else if (arr[mid] > x)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return last;
}

int count(int arr[], int n, int x)
{
	int first, last;
	first = firstOccur(arr, n, x);
	last = lastOccur(arr, n, x);
	if (first == -1 && last == -1)
		return 0;
	else
		return last - first + 1;
}