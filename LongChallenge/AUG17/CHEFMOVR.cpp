/*
 * Deleted code is debugged code :)
 */
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define S(n) scanf("%lld", &n)
#define INF 1e18
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,n,d,sum,delta,mean,ans;
	vi a(100005);
	t = read_ll();
	while (t--) {
		n = read_ll();
		d = read_ll();
		sum = 0;
		FOR(i,0,n) {
			a[i] = read_ll();
			sum += a[i];
		}
		if (sum % n) {
			printf("-1\n");
			continue;
		}
		mean = sum / n;
		ans = 0;
		FOR(i,0,n-d) {
			delta = mean - a[i];
			a[i] = a[i] + delta;
			a[i+d] = a[i+d] - delta;
			if (a[i] >= 0 and a[i+d] >= 0) {
				ans += abs(delta);
			}
			else {
				break;
			}
		}
		if (i >= n-d) {
			FOR(i,n-d,n) {
				if (a[i] != mean) {
					break;
				}
			}
			if (i >= n) {
				printf("%lld\n", ans);
			}
			else {
				printf("-1\n");
			}
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}