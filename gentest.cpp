#include <bits/stdc++.h>
#include <time.h>

#include <fstream>
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

const int mod = 101;

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  srand(time(NULL));

  int N, op;
  vector<int> v;

  cout << "Ingrese el tamaño de elementos: ";
  cin >> N;
  v.resize(N);

  cout << "Ingrese una opción:\n";
  cout << "1. Ordenado no decreciente\n";
  cout << "2. Ordenado no creciente\n";
  cout << "3. Aleatorio\n";
  cout << "Opcion: ";

  cin >> op;

  for (int i = 0; i < N; i++) {
    v[i] = (rand() % mod) - (mod / 2);
  }
  switch (op) {
    case 1:
      sort(all(v));
      break;
    case 2:
      sort(all(v), greater<int>());
      break;
    default:
      break;
  }
  ofstream myfile;
  myfile.open("A.in");
  myfile << N << endl;
  for (int i = 0; i < N; i++) myfile << v[i] << ' ';
  myfile.close();

  return 0;
}