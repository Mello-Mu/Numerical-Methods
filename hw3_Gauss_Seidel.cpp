/*
Input:
n - number of equations
a - augmented matrix (n x (n + 1))
    each row contains n coefficients and one right-hand side value

Output:
X - solution vector
iteration errors - maximum absolute difference between consecutive approximations

Constraints:
n >= 1
non-zero diagonal elements
convergence of the iterative method

Accuracy:
epsilon = 0.01

Example input:
3
10 1 1 12
2 10 1 16
2 2 10 16
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n, z = 0;
    double el, sum, max_dif;

    std::cin >> n;

    std::vector<std::vector<double>> a(n, std::vector<double> (n + 1));
    std::vector<double> x_new(n);
    std::vector<double> x_old(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++){
            std::cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        el = a[i][i];
        a[i][n] = a[i][n] / el;
        for(int j = 0; j < n; j++) {
            a[i][j] = -1 * (a[i][j] / el);
        }
        a[i][i] = 0;
    }

    for(int i = 0; i < n; i++) {
        x_old[i] = a[i][n];
    }

    do {
        z++;
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                if(j < i) {
                    sum += a[i][j] * x_new[j];
                }
                else if(j > i) {
                    sum += a[i][j] * x_old[j];
                }
            }
            x_new[i] = sum + a[i][n];
        }

        max_dif = 0;

        for(int i = 0; i < n; i++) {
            max_dif = std::max(max_dif, std::abs(x_new[i] - x_old[i]));
        }

        std::cout << "||X(" << z - 1 << ") - X(" << z << ")|| = " << max_dif << "\n\n"; 

        for(int i = 0; i < n; i++) {
        x_old[i] = x_new[i];
        }

    } while(max_dif > 0.01);

    std::cout << "X = (";
        for(int i = 0; i < n - 1; i++) {
            std::cout << x_new[i] << "; ";
        }
        std::cout << x_new[n - 1] << ")\n";
    
    return 0;
}