#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000005;
const int INF = 0x7fffffff;
int nums[MAX], mins[4*MAX];
int N, Q;

void push_up(int i) {
    mins[i] = min(mins[i*2], mins[i*2+1]);
}

void build(int i, int l, int r) {
    if (l == r) {
        mins[i] = nums[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push_up(i);
}

void update(int i, int l, int r, int p, int v) {
    if (l == r) {
        mins[i] = v;
        return;
    }
    int mid = l + (r-l)/2;
    if (p <= mid) update(i*2, l, mid, p, v);
    else update(i*2+1, mid+1, r, p, v);
    push_up(i);
}

int query(int i, int l, int r, int L, int R) {
    if (L <= l && r <= R) return mins[i];
    int res = INF;
    int mid = l + (r-l)/2;
    if (L <= mid) res = min(res, query(i*2, l, mid, L, R));
    if (R > mid) res = min(res, query(i*2+1, mid+1, r, L, R));
    return res;
}

int main() {
    for (int i = 0; i < 4*MAX; ++i) mins[i] = INF;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", &nums[i]);
    build(1, 1, N);

    scanf("%d", &Q);
    while (Q--) {
        int op, l, r; scanf("%d %d %d", &op, &l, &r);
        if (op == 0) printf("%d\n", query(1, 1, N, l, r));
        else update(1, 1, N, l, r);
    }
    return 0;
}
