#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX_N 600000

using namespace std;

char str[MAX_N];
int t, n, g[MAX_N], tg[MAX_N], RANK[MAX_N], SA[MAX_N], LCP[MAX_N];

bool cmp(int x, int y) {
    if (g[x] == g[y])
        return g[x + t] < g[y + t];
    return g[x] < g[y];
}

void getSA(const char *str) {
    t = 1;
    n = (int)strlen(str);

    for (int i = 0; i < n; i++) {
        SA[i] = i;
        g[i] = str[i] - 'a';
    }

    while (t <= n) {
        sort(SA, SA + n, cmp);
        tg[SA[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            tg[SA[i]] = tg[SA[i - 1]];
        }

        for (int i = 0; i < n; i++) {
            g[i] = tg[i];
        }

        t <<= 1;
    }
}

int main() {
    scanf("%s", &str);
    getSA(str);

    for (int i = 0; i < n; i++) {
        RANK[SA[i]] = i;
    }

    int len = 0;

    for (int i = 0; i < n; i++) {
        int k = RANK[i];
        if (k) {
            int j = SA[k - 1];

            while (str[j + len] == str[i + len])
                len++;
            LCP[k] = len;

            if (len)
                len--;
        }
    }

    printf("\n[Suffix Array]\n");

    for (int i = 0; i < n; i++) {
        printf("%s\n", str + SA[i]);
    }

    printf("\n[Suffix Array Order]\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", SA[i] + 1);
    }

    printf("\n\n[LCP]\n");
    for (int i = 0; i < n; i++) {
        if (!i)
            printf("x ");
        else
            printf("%d ", LCP[i]);
    }

    printf("\n\n");

    return 0;
}