#include<stdio.h>
#include<string.h>
#include<limits.h>

#define MAXN 7005
#define max(a, b) (a > b ? a : b)

int dp[MAXN]; 
int arr[MAXN];

int minimize(int *a, int b) {
    if (*a <= b) return *a;
    *a = b;
    return *a;
}

int main() {
    // freopen("drange.inp", "r", stdin);
    // freopen("drange.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &arr[i]);
        arr[i]++;
    }
    dp[0] = 0;
    for (int i=1;i<MAXN;i++) {
        dp[i] = INT_MAX;
    }
    int res = 0;
    for (int i=n;i>=1;i--) {
        int st = n - max(i - 1, arr[i]);
        for (int j=st;j>=0;j--) {
            if (dp[j] <= n) { 
                int val = max(dp[j], i + j + arr[i] - 1);
                minimize(&dp[j + arr[i]], val); 
            }
        }
        for (int j=i+1;j<=n;j++) {
            if (dp[j - i + 1] == j) res++;
        }
    }
    printf("%d\n", res);
}