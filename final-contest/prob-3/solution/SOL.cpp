#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define MAXN (int)1e5+5
#define MAXK 10
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int n,k;
int L[MAXK], R[MAXK], a[MAXN], m[MAXK], pw3[MAXK], pre[MAXN][730], f[730], Bit[730][MAXK];
ll dp[730], g[730], cost[730];

bool check_max(ll *x, ll y) {
    if (*x < y) {
        *x = y;
        return 1;
    }
    return 0;
}

void init() {
    pw3[0] = 1;
    for (int i=1;i<MAXK;i++) {
        pw3[i] = pw3[i-1]*3;
    }
    for (int i=0;i<=pw3[k]-1;i++) {
        for (int j=0;j<k;j++) {
            int x = (i/pw3[j]);
            Bit[i][j] = x - (x/3)*3;
        }
    }
    for (int x=0;x<=pw3[k]-1;x++) {
        cost[x]=1;
        for (int j=0;j<k;j++) {
            if (Bit[x][j]==1) cost[x]*=m[j];
        }
    }
}

int main() {
    // freopen("MAXSUM.inp", "r", stdin);
    // freopen("MAXSUM.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0;i<k;i++) {
        scanf("%d", &m[i]);
        L[i]=n+1;
        R[i]=0;
    }
    init();
    ll ds = 0;
    int pos = 0, mask = -1;
    for (int i=1;i<=n;i++) {
        for (int x=0;x<=pw3[k]-1;x++) {
            dp[x] = g[x] + a[i] * cost[x];
            pre[i][x] = f[x];
            if (check_max(&ds, dp[x])) {
                pos = i;
                mask = x;
            }
        }
        for (int x=0;x<=pw3[k]-1;x++) {
            g[x] = 0;
            f[x] = -1;
            if (check_max(&g[x], dp[x])) f[x] = x;
            for (int j=0;j<k;j++) {
                int y = x;
                if (Bit[x][j]) y -= pw3[j];
                if (check_max(&g[x], g[y])) f[x] = f[y];
            }
        }
    }
    int r = pos;
    while (pos >= 1 && mask != -1) {
        for (int j=0;j<k;j++) {
            if (Bit[mask][j] == 1) {
                L[j] = min(L[j], pos);
                R[j] = max(R[j], pos);
            }
        }
        mask = pre[pos][mask];
        pos--;
    }
    int l = min(pos + 1, r);
    printf("%lld ",ds);
    for (int i=0;i<k;i++) {
        if (R[i] == 0) printf("0 0 ");
        else printf("%d %d ", L[i], R[i]);
    }
    printf("%d %d ", l, r);
}