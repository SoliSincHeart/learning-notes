#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



void quick_sort(vector<int>& nums, int l, int r)
{
	if (l + 1 >= r)
		return;
	int first = l,last = r-1,key = nums[first];
	while (first < last)
	{
		while (first < last && nums[last] >= key)
		{
			--last;
		}
		nums[first] = nums[last];
		while (first < last && nums[first] <= key)
		{
			++first;
		}
		nums[last] = nums[first];

		nums[first] = key;
		quick_sort(nums, l, first);
		quick_sort(nums, first+1, r);
	}
}


void bubble_sort(vector<int>& nums, int n)
{
	bool swapped;
	for (int i = 1; i < n; ++i)
	{
		swapped = false;
		for (int j = 1; j < n - i + 1; ++j)
		{
			if (nums[j] < nums[j - 1])
			{
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void selection_sort(vector<int>& nums, int n)
{
	int min;
	for (int i = 0; i < n; ++i)
	{
		min = i;
		for (int j = i+1; j < n; ++j)
		{
			if (nums[j] < nums[min])
			{
				min = j;
			}
		}
		swap(nums[i], nums[min]);
	}
}

void insertion_sort(vector<int>& nums, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
		{
			swap(nums[j], nums[j - 1]);
		}
	}
}

void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp) 
{
	if (l + 1 >= r) {
		return;
	}
	int m = l + (r - l) / 2;
	merge_sort(nums, l, m, temp);
	merge_sort(nums, m, r, temp);

	int p = l, q = m, i = l;
	while (p < m || q < r)
	{
		if (q >= r || (p < m && nums[p] <= nums[q]))
		{
			temp[i++] = nums[p++];
		}
		else
		{
			temp[i++] = nums[q++];
		}
	}
	for (int i = l; i < r; i++)
	{
		nums[i] = temp[i];
	}
}


int main()
{
	vector<int> nums = { 4,6,3,2,1,5 };
	vector<int> temp(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	return 0;
}
