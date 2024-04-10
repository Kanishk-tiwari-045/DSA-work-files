#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct Point {
    int x, y;
} Point;

int compareX(const void* a, const void* b) {
    return ((Point*)a)->x - ((Point*)b)->x;
}

int compareY(const void* a, const void* b) {
    return ((Point*)a)->y - ((Point*)b)->y;
}

float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n, Point* p1, Point* p2) {
    float min_dist = FLT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float d = dist(P[i], P[j]);
            if (d < min_dist) {
                min_dist = d;
                *p1 = P[i];
                *p2 = P[j];
            }
        }
    }
    return min_dist;
}

float min(float x, float y) {
    return (x < y) ? x : y;
}

float closestPairUtil(Point Px[], Point Py[], int n, Point* p1, Point* p2) {
    if (n <= 3)
        return bruteForce(Px, n, p1, p2);

    int mid = n / 2;
    Point midPoint = Px[mid];

    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++) {
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    float dl = closestPairUtil(Px, Pyl, mid, p1, p2);
    Point p1r, p2r;
    float dr = closestPairUtil(Px + mid, Pyr, n - mid, &p1r, &p2r);

    float d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j++] = Py[i];
    }

    return min(d, bruteForce(strip, j, p1, p2));
}

float closestPair(Point P[], int n, Point* p1, Point* p2) {
    Point Px[n], Py[n];
    for (int i = 0; i < n; i++) {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);

    return closestPairUtil(Px, Py, n, p1, p2);
}

int main() {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    Point p1, p2;

    float min_distance = closestPair(P, n, &p1, &p2);
    printf("Closest pair is (%d, %d) and (%d, %d) with distance %.2f\n", p1.x, p1.y, p2.x, p2.y, min_distance);

    return 0;
}
