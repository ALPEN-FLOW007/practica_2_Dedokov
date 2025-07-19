#include <iostream>
#include <cmath>
using namespace std;

double Pi(double epsilon) {
    double term = 1.0;
    double piOver2 = 1.0;
    int n = 1;

    while (fabs(term - 1.0) > epsilon) {
        double numerator = (2.0 * n) * (2.0 * n + 2);
        double denominator = (2.0 * n + 1) * (2.0 * n + 1);
        term = numerator / denominator;
        piOver2 *= term;
        ++n;
    }

    return 2 * piOver2;
}

int main() {
    double epsilons[] = {0.01, 0.001, 0.0001};

    for (double eps : epsilons) {
        double pi = Pi(eps);
        cout << "Pi при ? = " << eps << " ? " << pi << endl;
    }

    return 0;
}

