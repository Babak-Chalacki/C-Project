# Tic-Tac-Toe Game in C++

## Overview
This is a simple console-based Tic-Tac-Toe game implemented in C++. It supports both single-player mode (against a computer) and two-player mode. Players take turns placing their markers (X or O) on a 3x3 grid, aiming to get three in a row.

## Features
- **Game Modes**: 
  - Single Player: Play against a computer.
  - Two Players: Play against another human.
- **Interactive Console Interface**: Displays the board after each move.
- **Win/Draw Detection**: Checks for wins or draws after each turn.

## Requirements
- C++ compiler (e.g., g++, clang++)
- Basic knowledge of compiling and running C++ programs

## Installation
1. **Clone the Repository** (if applicable):
   ```bash
   git clone https://github.com/Babak-Chalacki/Cpp-Projects/edit/main/tic_toc_toe.git
   cd tictactoe
   ```
2. **Save the Code**: Copy the code into `tictactoe.cpp`.
3. **Compile**:
   ```bash
   g++ tictactoe.cpp -o tictactoe
   ```

## Usage
1. **Run the Game**:
   ```bash
   ./tictactoe
   ```
2. **Select Mode**: Choose between single-player or two-player by entering `1` or `2`.
3. **Make Moves**: Enter your move as row and column (1-indexed).
4. **Winning and Drawing**: The game announces when a player wins or if there’s a draw.

## Example Gameplay
```
Welcome to Tic-Tac-Toe!
Select mode:
1. Single Player
2. Two Players
1
Current Board:
 | | 
-----
 | | 
-----
 | | 
Enter your move (row and column): 1 1
Current Board:
X| | 
-----
 | | 
-----
 | | 
Computer (O) wins!
```

## Future Improvements
- Smarter AI for single-player mode.
- Better input validation.
- Enhanced user interface with graphics.
