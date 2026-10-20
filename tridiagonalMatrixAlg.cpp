/*
Input:
n - number of equations
a - lower diagonal
b - main diagonal
c - upper diagonal
z - right-hand side values

Output:
A(alpha), B(beta), X

Constraints:
n >= 2, non-zero denominators

Example input:
3
0 4 1 6
1 4 1 12
1 4 0 14
*/

#include <iostream>
#include <vector>

int main() {

    int n;

    std::cin >> n;

    std::vector<double> a(n), b(n), c(n), z(n), A(n - 1), B(n - 1), X(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> c[i] >> z[i];
    }

    A[0] = -(c[0] / b[0]);
    std::cout << "A2 = " << A[0] << "\n";
    B[0] = (z[0] / b[0]);
    std::cout << "B2 = " << B[0] << "\n";

    for (int i = 1; i < n - 1; i++) {
        A[i] = -(c[i] / (b[i] + a[i] * A[i - 1]));
        std::cout << "A" << i + 2 << " = " << A[i] << "\n";
        B[i] = (z[i] - a[i] * B[i - 1]) / (b[i] + a[i] * A[i - 1]);
        std::cout << "B" << i + 2 << " = " << B[i] << "\n";
    }

    X[n - 1] = (z[n - 1] - a[n - 1] * B[n - 2]) / (b[n - 1] + a[n - 1] * A[n - 2]);
    std::cout << "X" << n << " = " << X[n - 1] << "\n";

    for (int i = n - 2; i >= 0; i--) {
        X[i] = A[i] * X[i + 1] + B[i];
        std::cout << "X" << i + 1 << " = " << X[i] << "\n";
    }

    return 0;
}   