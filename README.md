# Heat Equation Solver

## Overview

This project implements a heat equation solver using finite difference methods and parallelization with OpenMP. The project includes both serial and parallel versions of the heat equation solver to compare their performance.

### Project Components

- **`heat_equation.cpp`**: Contains the implementations of both the serial and parallel heat equation solvers.
- **`main.cpp`**: Contains the driver code for testing and comparing the performance of the solvers.

## Prerequisites

- **Visual Studio**: Ensure that you have Visual Studio installed with C++ development tools.
- **OpenMP**: The project uses OpenMP for parallelization. Visual Studio should support OpenMP by default, but ensure it is enabled in the project settings.

## Building the Project

1. **Open the Project in Visual Studio**
   - Open `HeatEquationSolver.sln` in Visual Studio.

2. **Configure OpenMP Support**
   - Right-click on the project in the **Solution Explorer**.
   - Select **Properties**.
   - Navigate to **Configuration Properties** > **C/C++** > **Language**.
   - Set **OpenMP Support** to **Yes (/openmp)**.

3. **Build the Project**
   - Press **Ctrl+Shift+B** or go to **Build** > **Build Solution**.

## Running the Project

1. **Execute the Program**
   - Press **F5** or go to **Debug** > **Start Debugging** to run the project.

2. **View Output**
   - The console will display the execution times for both the serial and parallel implementations, along with the performance comparison.

## Performance Results

The project includes test cases with varying grid sizes and time steps. Example output might look like this:


## Error Analysis

- The results from the serial and parallel implementations should be compared to ensure consistency. Significant discrepancies might indicate issues in the parallelization or boundary condition handling.

## Conclusion

This project demonstrates solving the heat equation using both serial and parallel finite difference methods. The parallel implementation shows significant performance improvement, especially with larger grid sizes.







