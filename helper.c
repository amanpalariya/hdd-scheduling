#include "helper.h"

#include <math.h>
#include <stdlib.h>

int randint(int min, int max) {
    if (min > max) return 0;
    return min + rand() % (max - min + 1);
}

float mean(long* ar, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) sum += ar[i];
    return 1.0f * sum / n;
}

float min(long* ar, int n) {
    long ans = ar[0];
    for (int i = 0; i < n; i++) {
        if (ar[i] < ans) ans = ar[i];
    }
    return ans;
}

float max(long* ar, int n) {
    long ans = ar[0];
    for (int i = 0; i < n; i++) {
        if (ar[i] > ans) ans = ar[i];
    }
    return ans;
}

float standard_deviation(long* ar, int n) {
    float m = mean(ar, n);
    float num = 0;
    for (int i = 0; i < n; i++) {
        num += (m - ar[i]) * (m - ar[i]);
    }
    return sqrt(num / n);
}
