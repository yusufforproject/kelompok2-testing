#include <iostream>
#include <cmath>
#include <vector>
#include <complex>

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
    std::vector<std::vector<long long>> result(2, std::vector<long long>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<long long>> matrixPower(std::vector<std::vector<long long>> base, int exp) {
    std::vector<std::vector<long long>> result = {{1, 0}, {0, 1}}; 
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

long long fibonacci(int n) {
    if (n == 0) return 0;
    std::vector<std::vector<long long>> F = {{1, 1}, {1, 0}};
    std::vector<std::vector<long long>> result = matrixPower(F, n - 1);
    return result[0][0];
}

std::pair<std::complex<double>, std::complex<double>> quadraticRoots(double a, double b, double c) {
    std::complex<double> discriminant = std::sqrt(std::complex<double>(b * b - 4 * a * c));
    std::complex<double> root1 = (-b + discriminant) / (2.0 * a);
    std::complex<double> root2 = (-b - discriminant) / (2.0 * a);
    return {root1, root2};
}

int main() {
    int num = 5;
    std::cout << "Factorial of " << num << " is: " << factorial(num) << "\n";

    int fibIndex = 10;
    std::cout << "The " << fibIndex << "th Fibonacci number is: " << fibonacci(fibIndex) << "\n";

    double a = 1, b = -3, c = 2;
    auto roots = quadraticRoots(a, b, c);
    std::cout << "Roots of the equation " << a << "x^2 + " << b << "x + " << c << " are: " << roots.first << " and " << roots.second << "\n";

    return 0;
}
