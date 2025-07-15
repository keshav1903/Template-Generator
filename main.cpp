
#include <bits/stdc++.h>
using namespace std;

void usage() {
    cerr << "Usage: gen_template <outfile.cpp> [--platform cf|atcoder] [--debug|--no-debug] "
            "[--math|--no-math] [--graph|--no-graph]\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        usage();
        return 1;
    }
    string outfile = argv[1];
    string platform = "cf"; // default Codeforces
    bool debug = false, math = false, graph = false;

    for (int i = 2; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--platform" && i + 1 < argc) {
            platform = argv[++i];
            if (platform != "cf" && platform != "atcoder") {
                cerr << "Unknown platform: " << platform << "\n";
                return 1;
            }
        } else if (arg == "--debug") debug = true;
        else if (arg == "--no-debug") debug = false;
        else if (arg == "--math") math = true;
        else if (arg == "--no-math") math = false;
        else if (arg == "--graph") graph = true;
        else if (arg == "--no-graph") graph = false;
        else {
            cerr << "Unknown option: " << arg << "\n";
            usage();
            return 1;
        }
    }

    ofstream fout(outfile);
    if (!fout) {
        cerr << "Cannot open output file\n";
        return 1;
    }

    // Header and includes
    fout << "#include <bits/stdc++.h>\n";
    fout << "using namespace std;\n\n";

    // DEBUG toggle
    if (debug) fout << "#define DEBUG\n";

    fout << R"RAW(
// — place this after your #includes — //
#ifdef DEBUG
  #define dbg(x)  do { \
      cerr << __func__ << ":" << __LINE__ \
           << " " #x " = "; \
      _print(x); \
      cerr << "\n"; \
    } while(0)
#else
  #define dbg(x)  do {} while(0)
#endif

// — printer overloads for dbg(x) — //
inline void _print(int x)            { cerr << x; }
inline void _print(long long x)      { cerr << x; }
inline void _print(double x)         { cerr << x; }
inline void _print(const string &s)  { cerr << '"' << s << '"'; }
inline void _print(char c)           { cerr << '\'' << c << '\''; }
inline void _print(bool b)           { cerr << (b ? "true" : "false"); }

template<typename A, typename B>
inline void _print(const pair<A,B>& p) {
  cerr << "("; _print(p.first); cerr << ", "; _print(p.second); cerr << ")";
}

template<typename T>
auto _print(const T& c) -> decltype(begin(c), end(c), void()) {
  cerr << "{";
  bool first = true;
  for (const auto &e : c) {
    if (!first) cerr << ", ";
    _print(e);
    first = false;
  }
  cerr << "}";
}

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

/* UTILS */
ll gcdll(ll a,ll b){ return b?gcdll(b,a%b):a; }
ll lcmll(ll a,ll b){ return a/gcdll(a,b)*b; }
string to_upper(string a){ for(char &c:a) if('a'<=c && c<='z') c-=32; return a; }
string to_lower(string a){ for(char &c:a) if('A'<=c && c<='Z') c+=32; return a; }
)RAW";

    // Math helpers
    if (math) {
        fout << R"RAW(
// ---------------- MATH HELPERS ---------------- //
long long binpow(long long a,long long b){
    long long res=1;
    while(b){ if(b&1) res*=a; a*=a; b>>=1; }
    return res;
}

vector<ll> sieve(int n){
    vector<int> prime(n+1,1); prime[0]=prime[1]=0;
    for(int i=2;i*i<=n;++i) if(prime[i]) for(int j=i*i;j<=n;j+=i) prime[j]=0;
    vector<ll> res; for(int i=2;i<=n;++i) if(prime[i]) res.push_back(i);
    return res;
}

bool isPerfectSquare(ll n){ if(n<0) return false; ll r=sqrtl(n); return r*r==n; }

const int MOD = 1'000'000'007;
long long modpow(long long a,long long b,long long m=MOD){ long long res=1% m; while(b){ if(b&1) res=res*a% m; a=a*a% m; b>>=1;} return res; }
long long modinv(long long a,long long m=MOD){ return modpow(a,m-2,m); }
long long nCr(long long n,int r,long long m=MOD){ if(r<0||r>n) return 0; long long res=1; for(int i=1;i<=r;++i) res = res*(n-r+i)%m*modinv(i,m)%m; return res; }
)RAW";
    }

    // Graph helpers
    if (graph) {
        fout << R"RAW(
// ---------------- GRAPH (DSU) ---------------- //
struct DSU{
    vector<int> p, sz;
    DSU(int n):p(n),sz(n,1){ iota(p.begin(),p.end(),0);}    
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(sz[a]<sz[b]) swap(a,b); p[b]=a; sz[a]+=sz[b]; return true; }
};
)RAW";
    }

    fout << R"RAW(
// ---------------- SOLUTION ---------------- //
void solve(){
    // write your solution here
}
)RAW";

    // platform-specific main
    if (platform == "cf") {
        fout << R"RAW(
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; if(!(cin>>tc)) tc=1; while(tc--) solve();
    return 0;
}
)RAW";
    } else {
        fout << R"RAW(
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
)RAW";
    }

    fout.close();
    cout << "Template generated: " << outfile << "\n";
    return 0;
}
