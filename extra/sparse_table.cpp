// range min query [l, r] 0 base indexed
const int MAXN = 105000;
const int MAXLOG = 20;

int n; // keep this GLOBAL n in mind
int logs[MAXN]; // logs[i] means such maximum p that 2^p <= i
int a[MAXN]; // Data
int table[MAXLOG][MAXN];

void buildSparseTable() {
    for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
    for (int i = 0; i <= logs[n]; i++) {
        int curLen = 1 << i; // 2^i
        for (int j = 0; j + curLen <= n; j++)
            if (curLen == 1) table[i][j] = a[j];
            else table[i][j] = min(table[i - 1][j], table[i - 1][j + (curLen / 2)]);
    }
}

int getMin(int l, int r) {
    int p = logs[r - l + 1];
    int pLen = 1 << p; // 2^p
    return min(table[p][l], table[p][r - pLen + 1]);
}