#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> CVector;

const double PI = acos(-1);

// Fast Fourier Transform
void FFT(CVector &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        Complex wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            Complex w(1);
            for (int j = 0; j < len / 2; j++) {
                Complex u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (Complex &x : a) {
            x /= n;
        }
    }
}

// Multiply large numbers using FFT
string multiplyLargeNumbers(const string &num1, const string &num2) {
    int n = num1.size(), m = num2.size();
    int size = 1;
    while (size < n + m) size <<= 1;

    CVector a(size), b(size);
    for (int i = 0; i < n; i++) {
        a[i] = num1[n - 1 - i] - '0';
    }
    for (int i = 0; i < m; i++) {
        b[i] = num2[m - 1 - i] - '0';
    }

    FFT(a, false);
    FFT(b, false);
    for (int i = 0; i < size; i++) {
        a[i] *= b[i];
    }
    FFT(a, true);

    vector<int> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = round(a[i].real());
    }

    for (int i = 0; i < size - 1; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    string product;
    for (int i = result.size() - 1; i >= 0; i--) {
        product += (result[i] + '0');
    }

    return product;
}

int main() {
    string A, B;
    cin >> A >> B;

    // Multiply the two numbers
    string result = multiplyLargeNumbers(A, B);

    // Output the result
    cout << result << endl;

    return 0;
}
