#include <bits/stdc++.h>
using namespace std;
#define L(i, j, n) for (int i = j; i < (int)n; i++)
#define RI(i, j, n) for (int i = j; i >= (int)n; i--)
#define all(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define sz(x) int((x).size())
#define show(v) L(i, 0, v.size()) cout << v[i] << " "; cout << endl;
#define db(x) cout << #x << "=" << x << endl
#define ONLINE

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int MOD = (int)1e9 + 7;
const int oo = (int)1e9;

void solve() {}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    #ifdef ONLINE
    freopen("D:/src/input.txt", "r", stdin);
    freopen("D:/src/output.txt", "w", stdout);
    #endif
    int TT = 1;
    cin >> TT;
    while (TT--) solve();
    return 0;
}

// --- Formas de leer la entrada -------------------------------------------
// Sin cantidad de casos, hasta fin de archivo: borrar el "cin >> TT" y leer
// dentro de la condicion del while. La lectura fallida es la que corta.
void hastaEOF() { int n; while (cin >> n) { /* caso que arranca con n */ } }
void porPalabras() { string s; while (cin >> s) { /* toda la entrada */ } }
void porLineas() { string s; while (getline(cin, s)) { /* toda la entrada */ } }
void partirLinea() { string s, w; getline(cin, s); stringstream ss(s); while (ss >> w) {} }
// Trampa 1: tras un cin >> queda el '\n' y el primer getline sale vacio. Se
//   descarta con: cin >> n; { string t; getline(cin, t); }  Un cin.ignore() a
//   secas NO alcanza si el archivo tiene CRLF: come el '\r' y deja el '\n'.
// Trampa 2: input de Windows -> cada getline deja un '\r' al final. Sacarlo con
//   if (!s.empty() && s.back() == '\r') s.pop_back();
// Trampa 3: cortar SIEMPRE leyendo un dato. while (cin >> n) esta bien: si no
//   hay dato prende failbit y el stream da falso. while (cin >> ws) NO, porque
//   ws solo saltea espacios y al final prende eofbit, que no vuelve falso al
//   stream: da una vuelta de mas y te repite el ultimo caso.
