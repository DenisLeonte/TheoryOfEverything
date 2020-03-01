#include <iostream>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp)
{
	int output[20000]; // output array 
	int i, count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixSort(int arr[], int n)
{
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort  
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

// A utility function to print an array 
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver program to test above functions 
int main()
{
	int arr[20000];
	ifstream in("date.in");
	for (int i = 0; i < 20000; i++)
	{
		in >> arr[i];
	}
	in.close();
	int n = 20000;

	auto start = high_resolution_clock::now();
	bubbleSort(arr, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//print(arr, n);
	cout << "Time needed : " << duration.count() << endl;

	ifstream inn("date1.in");
	for (int i = 0; i < 20000; i++)
	{
		inn >> arr[i];
	}
	inn.close();

	auto start1 = high_resolution_clock::now();
	radixSort(arr, n);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);

	cout << "Time needed : " << duration1.count() << endl;
	double p;
	if (duration1.count() > duration.count())
		p = duration1.count() / duration.count();
	else
		p = duration.count() / duration1.count();

	cout << "Is better by : " << p << "%" << endl;
	return 0;
}
