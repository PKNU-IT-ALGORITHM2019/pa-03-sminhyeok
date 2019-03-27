#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
int N, *datas;										// �������� ũ��, �����Ͱ� ��� �迭

void init(int n);
void analyze();
void BubbleSort( int n);
void SelectionSort( int n);
void InsertSort( int n);
void MergeSort( int first, int last);
void Merge( int first, int middle, int last);
void QuickSort1( int first, int last);
void QuickSort2( int first, int last);
void QuickSort3( int first, int last);
void Heapify( int i);
void HeapBuild();
void HeapSort();

int main() {
	analyze();
}

void init(int n) {
	if (n == 0 || n == 1) N = 1000;	
	else if (n == 2 || n == 3) N = 10000;
	else N = 100000;

	if (n % 2 == 0) {
		for (int i = 1; i <= N; i++)
			datas[i] = 1 + rand() % N;
	}
	else {
		for (int i = 1; i <= N; i++)
			datas[i] = N + 1 - i;
	}
}

void analyze() {
	datas = new int[100001];

	clock_t begin, end;
	vector<int> library;
	cout << "               Random1000     Reverse1000     Random10000     Reverse10000     Random100000     Reverse100000\n";
	
	cout << "Bubble            ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				BubbleSort(N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			BubbleSort(N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nSelection         ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				SelectionSort(N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			SelectionSort(N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nInsertion         ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				InsertSort(N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			InsertSort(N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nMerge             ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				MergeSort(1,N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			MergeSort(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nQuick1            ";					// ������ ���� pivot���� ������ ������
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				QuickSort1(1,N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			QuickSort1(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	cout << "\nQuick2            ";					// ó�� �߰� ������ �� �� ��� ���� pivot���� ������ ������ 
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				QuickSort2(1, N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			QuickSort2(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}
	
	cout << "\nQuick3            ";					// ������ ���� pivot���� ������ ������
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				QuickSort3(1, N);
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			QuickSort3(1, N);
			end = clock();
			mean += (double)(end - begin);
		}
		
		cout << mean / 1000 << "s          ";
	}

	cout << "\nHeap              ";					// Heap ���� ����
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {							// ���� �����ʹ�	10���� �׽�Ʈ ������ ������ ��� ����
			for (int j = 0; j < 10; j++) {
				init(i);
				begin = clock();
				HeapSort();
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			init(i);
			begin = clock();
			HeapSort();
			end = clock();
			mean += (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}

	// ���̺귯�� Sort�� �ϱ����ؼ� vector�� �ʿ�. vector�� �����͸� ��� ����
	cout << "\nLibrary           ";
	library.resize(100000);
	for (int i = 0; i <= 5; i++) {
		double mean = 0; int n;
		if (i == 0 || i == 1) n = 1000;
		else if (i == 2 || i == 3) n = 10000;
		else n = 100000;

		if (i % 2 == 0) {
			for (int k = 0; k < 10; k++) {
				for (int j = 0; j < n; j++)
					library[j] = 1 + rand() % N;
				begin = clock();
				sort(library.begin(), library.end());
				end = clock();
				mean += (double)(end - begin);
			}
			mean /= 10;
		}
		else {
			for (int j = 0; j < n; j++)
				library[j] = n - j;
			begin = clock();
			sort(library.begin(), library.end());
			end = clock();
			mean = (double)(end - begin);
		}
		cout << mean / 1000 << "s          ";
	}

	
	
	
}

// �������� ����
// �¿� ���ذ��� ������ ū ���Ͻ� ��ȯ, ���������� ū ���� ä��
void BubbleSort(int n) {
	for (int i = n; i > 0; i--) {
		for (int j = 1; j < i; j++) {
			
			if (datas[j+1] < datas[j]) {
				int temp = datas[j + 1];
				datas[j + 1] = datas[j];
				datas[j] = temp;
			}
		}
	}
}
// �� �� ����� �ִ밪�� ã�Ƽ� �������� ����, ���������� ū ���� ä��
void SelectionSort(int n) {
	for (int i = n; i > 0; i--) {
		int max = datas[i], index = i;
		for (int j = 0; j < i; j++) {
			if (datas[j] > max) { max = datas[j]; index = j; }
		}
		if (max > datas[i]) {
			datas[index] = datas[i];
			datas[i] = max;
		}
	}
}
// ���ʺ��� ������ �����ذ���, �� ���� ���Ե� ��ġ�� ã�� ����
void InsertSort(int n) {
	for (int i = 1; i <= n; i++) {
		int max = datas[i];
		int j = i - 1;
		while (j >= 1 && max < datas[j]) {
			datas[j + 1] = datas[j];
			datas[j] = max;
			j--;
		}
	}
}

// �����͸� ������ ���� �������� ���� ��ġ�� ���
void MergeSort(int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		// ������ ������ ����
		MergeSort( first, middle);
		MergeSort( middle + 1, last);
		// ������ ������ �� ����
		Merge( first, middle, last);
	}
}

void Merge( int first, int middle, int last) {
	int i = first, j = middle+1, k = first;
	// ���ĵ� �����͸� ���� temp�迭 ����
	int *temp = new int[last + 1];
	// ���� �����Ͱ� ���� temp�� ���� �Ͽ� �������� ����
	while (i <= middle && j <= last) {
		if (datas[i] < datas[j]) { temp[k++] = datas[i++]; }
		else { temp[k++] = datas[j++]; }
	}
	while (i <= middle) {
		temp[k++] = datas[i++];
	}
	while (j <= last) {
		temp[k++] = datas[j++];
	}
	// temp�� ��� ���ĵ� �����͸� �ٽ� data�� ��ȯ
	for (int index = first; index <= last; index++)
		datas[index] = temp[index];
	delete temp;
}

// ������ ���� �Ǻ������ϴ� ������
void QuickSort1( int first, int last) {
	stack<int> s;								// �������� ������ ���Ľ� �����÷ο� �߻� ��ü ���� ������ �̿��� �ݺ��� �ۼ�
	s.push(last); s.push(first);

	while (!s.empty()) {
		int F = s.top(); s.pop();				// First
		int L = s.top(); s.pop();				// Last

		if (F < L) {
			int pivot = datas[L];				// ���� ������ �����͸� pivot���� ����
			int i = F - 1;
			for (int j = F; j < L; j++) {		// pivot�� �������� ���� �����ʹ� ����, ū �����ʹ� ���������� ����
				if (datas[j] <= pivot) {
					i++;
					int temp = datas[j];
					datas[j] = datas[i];
					datas[i] = temp;
				}
			}
			i++; 
			datas[last] = datas[i];
			datas[i] = pivot;
			
			s.push(L);							// pivot�� �¿� �������� ������ ����
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}
		
	}
	
}

// ù��°, ���, ������ �� �߰����� pivot���� ����
void QuickSort2( int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int middle = (F + L) / 2, max = datas[F], index = F;
			int mid[3] = { F,middle,L };		// ó��, ���, ������ ���� ��ġ�� ���� mid �迭
			for (int i = 0; i < 3; i++)
				if (max > datas[mid[i]]) {
					max = datas[mid[i]]; index = mid[i];
				}
			max = 0;
			for (int i = 0; i < 3; i++) {
				if (mid[i] == index) continue;
				if (max > datas[mid[i]]) {
					max = datas[mid[i]]; index = mid[i];
				}
			}									// index�� �߰����� pivot ��ġ

			int pivot = datas[index];			// �߰����� pivot���� ���� ��, �������� �ִ� �����Ϳ� ��ȯ �� QuickSort �ǽ�
			datas[index] = datas[L];
			datas[L] = pivot;		

			int i = F - 1;
			for (int j = F; j < L; j++) {
				if (datas[j] <= pivot) {
					i++;
					int temp = datas[j];
					datas[j] = datas[i];
					datas[i] = temp;
				}
			}
			i++;
			datas[L] = datas[i];
			datas[i] = pivot;

			s.push(L);
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}

	}
}

// pivot�� �����ϰ� ����
void QuickSort3( int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int index = (rand() % (L - F)) +F;	//	F �� L ���̿� �ִ� ���� �����͸� pivot���� ����
			int pivot = datas[index];
			datas[index] = datas[L];
			datas[L] = pivot;					// ������ �����͸� pivot���� ������, ������ �����Ϳ� ��ȯ�Ͽ� QuickSort �ǽ�

			int i = F - 1;
			for (int j = F; j < L; j++) {
				if (datas[j] <= pivot) {
					i++;
					int temp = datas[j];
					datas[j] = datas[i];
					datas[i] = temp;
				}
			}
			i++;
			datas[L] = datas[i];
			datas[i] = pivot;

			s.push(L);
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}

	}
}
// Heap ������ ������Ű�� ���� Heapify, �Է��� ��ġ���� Heap�� ����
void Heapify(int i) {
	if (2 * i > N) return;			// �ڽĳ�尡 ���� ���� ���� X
	int index = 2 * i;				// �ڽ��� ���� ū ����� ��ġ�� index�� ����
	int k2, k1 = datas[index];		// k2 ������ �ڽ� ����� ��, k1 �ڽ� �� ���� ū ���� ���� ���
	
	if (index + 1 <= N) {			// ������ �ڽ� ��尡 �ִ� ���
		k2 = datas[index + 1];		// k2�� ������ �ڽ� ����� �� �Ҵ�
		if (k2 > k1) { k1 = k2; index++; }	// ������ �ڽ� ��尡 ���� Ŭ ���, k1�� �� ���� ��� �ε����� ��ġ ����
	}

	if (datas[i] > k1) return;		// �θ� ��尡 �ڽ� ��庸�� Ŭ ��� ���� x -> max_heap�̱� ����
	datas[index] = datas[i];		// �θ� ��尡 �ڽ� ��庸�� ������, ���� ū �ڽ� ���� ��ü
	datas[i] = k1;
	Heapify(index);					// ��ü�� �ڽ� ����� ��ġ���� �ٽ� Heapify ����
}
// Heap�� ����
void HeapBuild() {
	for (int i = N / 2; i >= 1; i--)	// ������ �θ� ������ �������� Heapify �����ν� Heap ����
		Heapify(i);
}
// Heap�� ���ĵ� �����ͷ� ����
void HeapSort() {						
	HeapBuild();						
	for (int i = N; i >= 2; i--) {		// ������ ����� ���� ����⸦ ��ü�����ν� ���� ū ���� ���������� ���� �������� ����
		int max = datas[1];				// max_heap���� ���� ū ���� �׻� ����⿡ ����
		datas[1] = datas[i];
		datas[i] = max;
		N--;							// ��� ���� �������ν� ������ ��忡 ���� ū ���� ������

		Heapify(1);
	}
}
