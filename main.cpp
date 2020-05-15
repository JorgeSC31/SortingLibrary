#include "sorting_library.hpp"
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef long long INT;
typedef double db;
typedef pair<int, int> pii;

string final;
vector<int> B;

bool check(vector<int> &v1, vector<int> &v2) { return v1 == v2; }

void print(vector<int> &V, string name) {
    cout << name << " contain: ";
    for (auto u : V) {
        cout << u << ' ';
    }
    cout << endl;
    final += name + ": " + (check(V, B) ? "OK" : "Error") + "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A, C;
    int ARR[10000];
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        ARR[i] = A[i];
    }
    B = A;

    // correct sort
    sort(all(B));

    print(A, "original");
    print(B, "Sort STL");

    // bubble sort
    C = A;
    bubbleSort(C.begin(), C.end());
    print(C, "Bubble Sort");

    // insertion sort
    C = A;
    insertionSort(C.begin(), C.end());
    print(C, "Insertion Sort");

    // selection sort
    C = A;
    selectionSort(C.begin(), C.end());
    print(C, "Selection Sort");

    // merge sort
    C = A;
    mergeSort(C.begin(), C.end());
    print(C, "Merge Sort");

    cout << endl << final;
    return 0;
}