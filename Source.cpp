#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

// Serial implementation of the heat equation solver
void heat_equation_serial(vector<double>& u, double alpha, double dt, double dx, int num_steps) {
    int n = u.size();
    vector<double> u_new(n);

    for (int step = 0; step < num_steps; ++step) {
        for (int i = 1; i < n - 1; ++i) {
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
        u_new[0] = u[0];        // Handle boundary conditions
        u_new[n - 1] = u[n - 1];
        swap(u, u_new);
    }
}

// Parallel implementation of the heat equation solver using OpenMP
void heat_equation_parallel(vector<double>& u, double alpha, double dt, double dx, int num_steps) {
    int n = u.size();
    vector<double> u_new(n);

    for (int step = 0; step < num_steps; ++step) {
#pragma omp parallel for
        for (int i = 1; i < n - 1; ++i) {
            u_new[i] = u[i] + alpha * dt / (dx * dx) * (u[i + 1] - 2 * u[i] + u[i - 1]);
        }
        u_new[0] = u[0];        // Handle boundary conditions
        u_new[n - 1] = u[n - 1];
        swap(u, u_new);
    }
}

int main() {
    // Define test cases
    struct TestCase {
        int grid_size;
        int num_steps;
    };

    vector<TestCase> test_cases = {
        {100, 1000},
        {200, 1000},
        {500, 1000}
    };

    cout << "Grid Size\tTime Steps\tSerial Time (seconds)\tParallel Time (seconds)" << endl;

    for (const auto& test_case : test_cases) {
        int n = test_case.grid_size;
        int num_steps = test_case.num_steps;
        double alpha = 0.01;
        double dx = 1.0 / (n - 1);
        double dt = 0.5 * dx * dx / alpha;

        // Initialize vectors
        vector<double> u_serial(n, 0.0);
        u_serial[n / 2] = 1.0;

        vector<double> u_parallel = u_serial;

        double start_time, end_time;

        // Serial computation
        start_time = omp_get_wtime();
        heat_equation_serial(u_serial, alpha, dt, dx, num_steps);
        end_time = omp_get_wtime();
        double serial_time = end_time - start_time;

        // Parallel computation
        start_time = omp_get_wtime();
        heat_equation_parallel(u_parallel, alpha, dt, dx, num_steps);
        end_time = omp_get_wtime();
        double parallel_time = end_time - start_time;

        // Print results
        cout << n << "\t" << num_steps << "\t" << serial_time << "\t" << parallel_time << endl;
    }

    return 0;
}

