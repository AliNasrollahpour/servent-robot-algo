# Project Documentation: Grid Exploration with Energy and Guests

## Overview
This project implements a pathfinding algorithm on a 2D grid. The goal is to explore the grid, collect guests, and manage energy, while avoiding briars (obstacles). Special teleport pads allow instantaneous jumps to other cells.

The program currently reads the map and performs a BFS-based search to evaluate reachable states (guests served, energy left). It is a work in progress – output (path reconstruction and printing) is not yet implemented.

## Data Structures

### `struct point`
- `x`, `y` – coordinates
- `type` – cell type:
  - `0` = briar (blocked)
  - `1` = start position
  - `2` = guest
  - `3` = teleport pad
  - `4` = empty
- `dx`, `dy` – destination coordinates for teleport pads (only valid if `type==3`)

### `struct valuePair`
- `guestsServed` – number of guests collected reaching this cell (`-1` = unassigned)
- `energyLeft` – remaining energy when reaching this cell (`-1` = unassigned)
- `direction` – last move direction (`0` = null, `1` = left, `2` = up) – currently not fully used.

### `map` – `vector<vector<point>>` – the grid.
### `valueMap` – `vector<vector<valuePair>>` – stores best known (guests, energy) states per cell.

## Input Format
1. First line: `n m initEnergy` – grid dimensions and starting energy.
2. Next `n` lines: each with `m` characters, where:
   - `X` = briar (type 0)
   - `S` = start (type 1)
   - `G` = guest (type 2)
   - `T` = teleport pad (type 3)
   - `.` (or any other) = empty (type 4)
3. Then zero or more lines of the form:  
   `Teleport: (x,y) -> (dx,dy)`  
   specifying the destination of each teleport pad.

## Key Functions

### `input(map, initEnergy)`
Parses input, builds the grid, and returns the start point.

### `BFS(map, valueMap, current)`
Recursive / iterative exploration. If energy remains at the current cell, it calls `createNextPoint` for allowed moves.

### `createNextPoint(map, valueMap, current)`
Generates new states for moving **down** and **right**. It checks if the neighbor is not a briar, and whether the new state (guests served, energy left) is better than any previously recorded state at that cell. If it’s a teleport pad, it immediately jumps to the destination and continues.

### `path()` – placeholder
Intended to reconstruct the optimal path from start to the best terminal state.

### `print()` – placeholder
Should output the final result: maximum guests served, energy left, and the path.

## Current Status
- ✅ Grid reading and initialization.
- ✅ BFS-like state exploration (only down/right moves, possibly incomplete).
- ✅ Teleport handling.
- ❌ Path reconstruction.
- ❌ Output formatting.
