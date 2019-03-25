#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;
int N, *datas;

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
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
	cout << "\nIsertion          ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
	cout << "\nQucik1            ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
	cout << "\nQucik2            ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
	cout << "\nQucik3            ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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
	cout << "\nHeap              ";
	for (int i = 0; i <= 5; i++) {
		double mean = 0;
		if (i % 2 == 0) {	// 랜덤 데이터는	10개의 테스트 데이터 실행후 평균 구함
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

// 오름차순 정렬, 데이터 크기 그대로 입력하면됨
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

// last입력시 데이터 크기 - 1 이어야함
void MergeSort(int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		MergeSort( first, middle);
		MergeSort( middle + 1, last);
		Merge( first, middle, last);
	}
}

void Merge( int first, int middle, int last) {
	int i = first, j = middle+1, k = first;
	int *temp = new int[last + 1];

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
	for (int index = first; index <= last; index++)
		datas[index] = temp[index];
	delete temp;
}

// 마지막 값을 피봇으로, last는 크기 - 1
void QuickSort1( int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int pivot = datas[L];
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
			datas[last] = datas[i];
			datas[i] = pivot;
			
			s.push(L);
			s.push(i + 1);
			s.push(i - 1);
			s.push(F);
		}
		
	}
	
}

// 첫번째, 가운데, 마지막 중 중간값을 pivot으로 선택
void QuickSort2( int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int middle = (F + L) / 2, max = datas[F], index = F;
			int mid[3] = { F,middle,L };
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
			}// index는 중간값의 pivot 위치
			int pivot = datas[index];
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

// pivot을 랜덤하게 선택
void QuickSort3( int first, int last) {
	stack<int> s;
	s.push(last); s.push(first);
	while (!s.empty()) {
		int F = s.top(); s.pop();
		int L = s.top(); s.pop();

		if (F < L) {
			int index = rand() % (L + 1);
			int pivot = datas[index];
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

void Heapify(int i) {
	if (2 * i > N) return;
	int index = 2 * i;
	int k2, k1 = datas[index];
	
	if (index + 1 <= N) {
		k2 = datas[index + 1];
		if (k2 > k1) { k1 = k2; index++; }
	}

	if (datas[i] > k1) return;
	datas[index] = datas[i];
	datas[i] = k1;
	Heapify(index);
}
void HeapBuild() {
	for (int i = N / 2; i >= 1; i--)
		Heapify(i);
}
void HeapSort() {
	HeapBuild();
	for (int i = N; i >= 2; i--) {
		int max = datas[1];
		datas[1] = datas[i];
		datas[i] = max;
		N--;

		Heapify(1);
	}
}
