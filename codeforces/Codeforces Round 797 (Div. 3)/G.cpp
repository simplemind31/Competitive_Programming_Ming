#include <bits/stdc++.h>
using namespace std;
struct segment {
    int n;
    vector<int> st, lazy;
    int NO=1e9+7;
    segment() {}
    segment(const vector<int>& a){init(a);}
    void init(const vector<int>& a) {
        n = (int)a.size();
        st.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, NO);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(node << 1, l, m, a);
        build(node << 1 | 1, m + 1, r, a);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    void apply(int node, int val) {
        st[node] = val;
        lazy[node] = val;
    }
    void push(int node) {
        if(lazy[node]==NO)return;
        
        apply(node << 1, lazy[node]);
        apply(node << 1 | 1, lazy[node]);
        lazy[node] = NO;
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, val);
            return;
        }
        push(node);
        int m = (l + r) >> 1;
        update(node << 1, l, m, ql, qr, val);
        update(node << 1 | 1, m + 1, r, ql, qr, val);
        st[node] = min(st[node << 1], st[node << 1 | 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return NO;
        if (ql <= l && r <= qr) return st[node];
        push(node);
        int m = (l + r) >> 1;
        return min(query(node << 1, l, m, ql, qr),
                   query(node << 1 | 1, m + 1, r, ql, qr));
    }

    // first position >= ql with value < x, or -1 if none
    int first_less(int node, int l, int r, int ql, int x) {
        if (r < ql || st[node] >= x) return -1;
        if (l == r) return l;
        push(node);
        int m = (l + r) >> 1;
        int left = first_less(node << 1, l, m, ql, x);
        if (left != -1) return left;
        return first_less(node << 1 | 1, m + 1, r, ql, x);
    }
};

struct SumSeg {
    int n;
    vector<int> st, lazy; // lazy: -1 none, 0 set zero, 1 set one

    SumSeg() {}
    SumSeg(const vector<int>& a) { init(a); }

    void init(const vector<int>& a) {
        n = (int)a.size();
        st.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, -1);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<int>& a) {
        if (l == r) {
            st[node] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(node << 1, l, m, a);
        build(node << 1 | 1, m + 1, r, a);
        st[node] = st[node << 1] + st[node << 1 | 1];
    }

    void apply(int node, int l, int r, int val) {
        st[node] = (r - l + 1) * val;
        lazy[node] = val;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == -1 || l == r) return;
        int m = (l + r) >> 1;
        apply(node << 1, l, m, lazy[node]);
        apply(node << 1 | 1, m + 1, r, lazy[node]);
        lazy[node] = -1;
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int m = (l + r) >> 1;
        update(node << 1, l, m, ql, qr, val);
        update(node << 1 | 1, m + 1, r, ql, qr, val);
        st[node] = st[node << 1] + st[node << 1 | 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return st[node];
        push(node, l, r);
        int m = (l + r) >> 1;
        return query(node << 1, l, m, ql, qr) +
               query(node << 1 | 1, m + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nuintptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> pref(n);
        vector<int> start(n, 0);

        int mn = (1int << 60);
        int trains = 0;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, a[i]);
            pref[i] = mn;
            if (i == 0 || pref[i] < pref[i - 1]) {
                start[i] = 1;
                ++trains;
            }
        }

        segment segMin(pref);
        SumSeg segStart(start);

        while (m--) {
            int k;
            int d;
            cin >> k >> d;
            --k;

            int nw = a[k] - d;
            a[k] = nw;

            int cur = segMin.query(1, 0, n - 1, k, k);

            if (nw < cur) {
                int p = -1;
                if (k + 1 < n) p = segMin.first_less(1, 0, n - 1, k + 1, nw);
                if (p == -1) p = n;

                int removed = segStart.query(1, 0, n - 1, k, p - 1);
                trains += 1 - removed;

                segMin.update(1, 0, n - 1, k, p - 1, nw);
                if (k + 1 <= p - 1) segStart.update(1, 0, n - 1, k + 1, p - 1, 0);
                segStart.update(1, 0, n - 1, k, k, 1);
            }

            cout << trains << ' ';
        }
        cout << '\n';
    }
    return 0;
}