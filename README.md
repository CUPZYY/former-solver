# Former Solver

## Overview

This project is a solver for NRK's game [Former](https://www.nrk.no/spill/former-1.17105310), a grid-based puzzle game where the goal is to remove connected groups of tiles strategically to maximize the score. The solver uses the **Monte Carlo Tree Search (MCTS)** algorithm to find optimal moves and solve the game efficiently.

## Features

- **Monte Carlo Tree Search (MCTS)**: Implements MCTS to simulate and evaluate possible moves.
- **Random Move Simulation**: Includes a fallback for random move generation.
- **Grid Visualization**: Displays the game grid in a structured format.
- **File Input Support**: Reads the game grid from a file for easy testing.
- **Cross-Platform Compatibility**: Works on macOS, Linux, and Windows.

## Requirements

- **C++ Compiler**: Requires a compiler supporting C++14 or later.
- **CMake**: Version 3.30 or later.
- **Libraries**: Standard C++ libraries (no external dependencies).

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/cupzyy/former-solver
   cd former_solver
   ```
2. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage
1. Prepare an input file (`input.txt`) containing the game grid. Each column should be represented as a line of numbers, with each number corresponding to a tile color.
   Example:
   ```
   3443214
   2333341
   1213333
   1334144
   1232143
   3331321
   1134334
   1324224
   2121211
   ```
2. Run the solver with the input file:
   ```
   ./former_solver input.txt
   ```
3. The solver will display the sequence of moves and the final result.


## Project Structure

- `src/`: Contains the source code for the solver.
  - `Game.cpp`: Implements the game logic.
  - `MCTS.cpp`: Implements the Monte Carlo Tree Search algorithm.
  - `util/FileParser.cpp`: Handles file input for the game grid.
  - `main.cpp`: Entry point for the application.
- `include/`: Contains header files for the project.
- `input.txt`: Example input file for testing.
- `CMakeLists.txt`: Build configuration for the project.

## How It Works

1. **Grid Parsing**: The grid is read from the input file and stored as a 2D vector.
2. **MCTS Algorithm**: The solver simulates possible moves using MCTS to find the optimal sequence of moves.
3. **Move Execution**: The solver executes the best move, updates the grid, and repeats until the game is finished.
4. **Output**: The solver outputs the sequence of moves and the time taken to solve the game.
