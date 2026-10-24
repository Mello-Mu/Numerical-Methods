/*
Input:
n - number of equations
a - augmented matrix (n x (n + 1))
    each row contains n coefficients and one right-hand side value

Output:
X - solution vector
det - determinant of the coefficient matrix
inverse matrix

Constraints:
n >= 1, non-singular coefficient matrix

Example input:
3
1 2 3 4
2 5 6 8
2 1 3 0
*/

#include <iostream>
#include <vector>
#include <utility>

int main() {

    int n;
    double K, sum;
    double det = 1;

    std::cin >> n;

    std::vector<double> x(n);

    std::vector<std::vector<double>> a(n, std::vector<double> (n + 1));
    std::vector<std::vector<double>> b(n, std::vector<double> (n + 1));

    for(int i = 0; i < n; i++){
        b[i][i] = 1;
        for(int j = 0; j <= n; j++){
            std::cin >> a[i][j];
        }
    }

    /* Forward elimination: transform matrix a into upper triangular form and apply the same row operations to matrix b */

    for(int i = 0; i < n; i++){
        if (a[i][i] == 0){
            for(int r = i + 1; r < n; r++){
                if (a[r][i] != 0){
                    std::swap(a[i], a[r]);
                    std::swap(b[i], b[r]);
                    det = -det;
                    break;
                }
            }
            if (a[i][i] == 0){
                std::cout << "The system does not have a unique solution\n";
                return 0;
            }
        }
        for(int h = i + 1; h < n; h++){
            K = a[h][i] / a[i][i];
            for(int j = 0; j <= n; j++){
                b[h][j] = b[h][j] - K * b[i][j];
            }
            for(int j = i; j <= n; j++){
                a[h][j] = a[h][j] - K * a[i][j];
            }
        }
    }

    /* Back substitution: calculate the solution vector X */

    for(int i = n - 1; i >= 0; i--){
        sum = a[i][n];
        for(int j = i + 1; j < n; j++){
            sum -= a[i][j] * x[j];
        }
        x[i] = sum / a[i][i];
        std::cout << "X"<< i + 1 << " = " << x[i] << "\n";
    }

    /* Calculate the determinant */
    for(int i = 0; i < n; i++){
        det *= a[i][i];
        }

    std::cout << "det = " << det << "\n";

    /* Normalize the diagonal elements to 1 */

    for(int i = 0; i < n; i++){
        double pivot = a[i][i];
        for(int r = 0; r < n; r++){
            b[i][r] = b[i][r] / pivot;
        } 
        for(int j = i; j < n; j++){
            a[i][j] = a[i][j] / pivot;
        } 
    }

    /* Backward elimination: eliminate elements above the main diagonal */

    for(int i = n - 1; i >= 0; i--){
        for(int h = i - 1; h >= 0; h--){
            K = a[h][i];
            for(int j = 0; j < n; j++){
                b[h][j] = b[h][j] - K * b[i][j];
            }
            for(int j = i; j < n; j++){
                a[h][j] = a[h][j] - K * a[i][j];
            }
        }
    }

    std::cout << "Inverse matrix:\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << b[i][j] << " ";
        }

        std::cout << "\n";
    }
}   