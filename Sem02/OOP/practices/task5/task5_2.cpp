void select(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
    }
}

void select(double *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        double temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
    }
}
