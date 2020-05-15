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
    print(B, "sort stl");

    C = A;
    bubblesort(C.begin(), C.end());
    print(C, "bubblesort");

    sort(ARR, ARR + 5);
    C = vector<int>(ARR, ARR + N);
    print(C, "bubblesort arreglo");

    cout << "test: " << C.end() - C.begin() << endl;

    cout << endl << final;
    return 0;
}