#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N1 100
#define N2 1000
#define N3 10000
#define N4 100000
#define N5 1000000

void TaoMang(int *A, int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		A[i] = rand() % n;
}
void XuatMang(int *A, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d  ", A[i]);
	printf("\n");
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void InsertionSort(int *A, int n, __int64 &ss, __int64 &gan)
{
	int x, j;
	ss = 0; gan = 0;
	for (int i = 1; i < n; i++)
	{
		ss++;
		x = A[i];
		j = i - 1;
		gan += 3;
		if (j<0 || A[j] <= x)
			ss++;
		while (j >= 0 && A[j]>x)
		{
			ss += 2;
			A[j + 1] = A[j];
			j--;
			gan += 2;
		}
		A[j + 1] = x;
		gan++;
	}
}
void BubbleSort(int *A, int n, __int64 &ss, __int64 &gan)
{
	for (int i = 1; i < n; i++)
	{
		ss++;
		gan++;
		for (int j = n - 1; j >= i; j--)
		{
			gan++;
			ss += 2;
			if (A[j - 1]>A[j])
			{
				swap(A[j - 1], A[j]);
				gan += 3;
			}
		}
	}
}
void ShakerSort(int *A, int n, __int64 &ss, __int64 &gan)
{
	int l = 0, r = n - 1, i;
	if (l >= r)
		ss++;
	while (l < r)
	{
		ss++;
		for (i = r; i>l; i--)
		{
			ss += 2;
			gan++;
			if (A[i - 1] > A[i])
			{
				swap(A[i], A[i - 1]);
				gan += 3;
			}
		}
		for (i = l + 1; i < r; i++)
		{
			ss += 2;
			gan++;
			if (A[i + 1] < A[i])
			{
				swap(A[i], A[i + 1]);
				gan += 3;
			}
		}
		l++;
		r--;
		gan += 2;
	}
}
void ShellSort(int *A, int n, __int64 &ss, __int64 &gan)
{
	int h = n / 2, i;
	gan++;
	if (h <= 0)
		ss++;
	while (h > 0)
	{
		ss++;
		i = h;
		gan++;
		if (i >= n)
			ss++;
		while (i < n)
		{
			ss++;
			for (int j = i - h; j >= 0; j = j - h)
			{
				ss += 2;
				gan++;
				if (A[j]>A[j + h])
				{
					swap(A[j], A[j + h]);
					gan += 3;
				}
			}
			i++;
			gan++;
		}
		h = h / 2;
		gan++;
	}
}
void QuickSort(int *A, int l, int r, __int64 &ss, __int64 &gan)
{
	ss++;
	if (l >= r) return;
	int x = A[(l + r) / 2], i = l, j = r;
	gan += 3;
	if (i > j) ss++;
	while (i <= j)
	{
		ss++;
		if (A[i] >= x)
			ss++;
		while (A[i] < x)
		{
			i++;
			gan++;
			ss++;
		}
		if (A[j] <= x)
			ss++;
		while (A[j] > x)
		{
			j--;
			gan++;
			ss++;
		}
		ss++;
		if (i <= j){
			{
				swap(A[i], A[j]);
				i++; j--;
				gan += 5;
			}
		}
	}
	QuickSort(A, l, j, ss, gan);
	QuickSort(A, i, r, ss, gan);
}
void Merge(int *A, int l, int t, int r, __int64 &ss, __int64 & gan)
{
	int *C;
	C = (int*)malloc((r + 1)*sizeof(int));
	int p = l, i = l, j = t + 1;
	gan += 3;
	if (i > t || j > r)
		ss++;
	while (i <= t&&j <= r){
		ss += 3;
		if (A[i] < A[j]){
			C[p] = A[i];
			i++;
		}
		else{
			C[p] = A[j];
			j++;
		}
		p++;
		gan += 3;
	}
	if (i > t)
		ss++;
	while (i <= t){
		ss++;
		C[p] = A[i];
		i++;
		p++;
		gan += 3;
	}
	if (j > r)
		ss++;
	while (j <= r){
		ss++;
		C[p] = A[j];
		j++;
		p++;
		gan += 3;
	}
	for (i = l; i <= r; i++)
	{
		A[i] = C[i];
		gan += 2;
		ss++;
	}
	free(C);
}
void MergeSort(int *A, int l, int r, __int64 &ss, __int64 &gan)
{
	ss++;
	if (l >= r) return;
	int t = (l + r) / 2;
	gan++;
	MergeSort(A, l, t, ss, gan);
	MergeSort(A, t + 1, r, ss, gan);
	Merge(A, l, t, r, ss, gan);
}
void BuildHeap(int *A, int n, __int64 &ss, __int64 &gan)
{
	int i, x, r;
	for (i = 1; i < n; i++)
	{
		ss++;
		gan += 3;
		x = A[i];
		r = i;
		if (r <= 0)
			ss++;
		while (r>0)
		{
			ss += 2;
			if (A[r] > A[(r - 1) / 2])
			{
				A[r] = A[(r - 1) / 2];
				r = (r - 1) / 2;
				A[r] = x;
				gan += 3;
			}
			else
			{
				r = (r - 1) / 2;
				gan++;
			}
		}
	}
}
void DownHeap(int *A, int n, __int64 &ss, __int64 &gan)
{
	int i, j, r, x;
	for (i = n - 1; i >= 1; i--)
	{
		ss++;
		gan += 5;
		x = A[i];
		r = 0;
		j = r * 2 + 1;
		A[i] = A[0];
		if (j >= i)
			ss++;
		while (j < i)
		{
			ss += 4;
			if (j + 1 < i&&A[j + 1] > A[j])
			{
				j++;
				gan++;
			}
			if (x < A[j])
			{
				gan += 3;
				A[r] = A[j];
				r = j;
				j = 2 * r + 1;
			}
			else break;
		}
		A[r] = x;
		gan++;
	}
}
void HeapSort(int *A, int n, __int64 &ss, __int64 &gan)
{
	BuildHeap(A, n, ss, gan);
	DownHeap(A, n, ss, gan);
}
void RadixSort(int *A, int n, __int64 &ss, __int64 &gan)
{
	int max = A[0], i, j, h = 1;
	gan += 2;
	int *c;
	c = (int*)malloc(n*sizeof(int));
	for (i = 1; i < n; i++)
	{
		ss += 2;
		gan++;
		if (A[i]>max)
		{
			max = A[i];
			gan++;
		}
	}
	if (max / h == 0)
		ss++;
	while (max / h != 0)
	{
		ss++;
		gan++;
		int b[10] = { 0 };
		for (i = 0; i < n; i++)
		{
			b[A[i] / h % 10]++;
			ss++;
			gan += 2;
		}
		for (i = 1; i < 10; i++)
		{
			b[i] += b[i - 1];
			ss++;
			gan += 2;
		}
		for (i = n - 1; i >= 0; i--)
		{
			c[--b[A[i] / h % 10]] = A[i];
			gan += 3;
			ss++;
		}

		for (i = 0; i < n; i++)
		{
			A[i] = c[i];
			gan += 2;
			ss++;
		}
		h = h * 10;
		gan++;
	}
	free(c);
}

void main()
{
	int *A;
	// N1, N2, N3, N4, N5 là số phần tử 100, 1000, 10000, 100000, 1000000 đã được gán là hằng số
	int N=N3;
	A = new int[N];
	clock_t start, end;
	double time_use;
	__int64 ss = 0, gan = 0;
	TaoMang(A, N);
	start = clock();
	InsertionSort(A, N, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay InsertionSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	BubbleSort(A, N, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay BubbleSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	ShakerSort(A, N, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay ShakerSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	ShellSort(A, N, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay ShellSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	QuickSort(A, 0, N - 1, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay QuickSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	MergeSort(A, 0, N - 1, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay MergeSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	HeapSort(A, N, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay HeapSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	ss = 0; gan = 0;
	start = clock();
	RadixSort(A, N, ss, gan);
	end = clock();
	time_use = (double)(end - start);
	printf("tgian chay RadixSort(bao gom tgian tinh cac phep ss vs gan)= %lf(ms)\n", time_use);
	printf("so phep so sanh: %d\n", ss);
	printf("so phep gan: %d\n\n", gan);
	delete[]A;
}