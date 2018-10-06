void insert(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int cur = a[i];
        int j = i;
        while (j > 0 && cur < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = cur;
    }
}

void insert(double *a, int n) {
    for (int i = 1; i < n; i++) {
        double cur = a[i];
        int j = i;
        while (j > 0 && cur < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = cur;
    }
}
