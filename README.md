# Kruskal-MST-Finding-the-Shortest-Travel-Route-Between-Historical-Sites

## Overview
This project implements **Kruskal's Minimum Spanning Tree (MST) algorithm** using a **disjoint-set data structure** to determine the shortest total route connecting a set of historical sites. It reads input from the keyboard, constructs an **undirected weighted graph**, and applies **Kruskal’s algorithm** to find the optimal set of connections between sites.

## Features
- Reads historical site and route information from user input.
- Uses **disjoint-set (union-find)** to efficiently manage sets during MST construction.
- Implements **QuickSort** to sort routes by distance in ascending order.
- Computes the **Minimum Spanning Tree (MST)** using **Kruskal’s algorithm**.
- Outputs the MST with the total travel distance.

## Files
- `Assignment8.cpp` – Main program that handles input parsing and MST execution.
- `Map.h` – Defines the `Map` class, which represents the graph and implements Kruskal’s algorithm.
- `Route.h` – Defines the `Route` class, representing an edge in the graph.
- `Assignment #8.vcxproj` – Visual Studio project configuration file.

## Compilation & Execution
### **1. Compile the program:**
```bash
g++ Assignment8.cpp -o Assignment8
