# Connect Four Game

Connect Four is a classic two-player game where each player chooses a color, either **'R' (Red)** or **'Y' (Yellow)**, and takes turns dropping colored discs into a 6x7 grid. The objective is to be the first to form a vertical, horizontal, or diagonal line of four discs of the same color.

## Description

Connect Four is a strategic game that challenges players to outwit their opponent by forming a line of four discs while blocking the opponent's attempts to do the same. The game ends when one player achieves this goal, or the grid is completely filled without a winner, resulting in a draw.

## How to Play

### Game Initialization

- The game starts with an empty 6x7 grid, represented by dashes (`-`).

### Turns

- Players take turns to drop one of their colored discs into any of the 7 columns.
- The disc falls to the lowest available slot in the selected column.

### Winning Condition

A player wins by connecting four of their discs in one of the following ways:

- **Vertical**: Four discs in a column.
- **Horizontal**: Four discs in a row.
- **Diagonal (Left to Right)**: Four discs in a downward slope from left to right.
- **Diagonal (Right to Left)**: Four discs in a downward slope from right to left.

### End of Game

- The game ends immediately when a player forms a line of four discs, and that player is declared the winner.
- If the grid is completely filled without any player forming a line of four discs, the game ends in a draw.

## Controls

- Players use the keyboard to select the column (0-6) where they want to drop their disc.

## Functions

- **`bool isFull(int col)`**: Checks if a specific column is full.
- **`bool dropdisk(int col, char player)`**: Drops a disc for the given player into the specified column.
- **`void gamelook()`**: Displays the current state of the grid.
- **`bool checkWin(char player)`**: Checks if the given player has won the game by forming a line of four discs.

## Example Gameplay
WELCOME TO CONNECT4 GAME!
Drop a R disk at column (0-6): 3
|---R---|
|-------|
|-------|
|-------|
|-------|
|-------|

Drop a Y disk at column (0-6): 4
|---R-Y-|
|-------|
|-------|
|-------|
|-------|
|-------|

...

Player R won the game!


