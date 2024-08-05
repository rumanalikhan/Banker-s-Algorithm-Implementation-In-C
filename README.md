# Banker's-Algorithm-Implementation-In-C

## Overview
This project implements the Banker's Algorithm for multiple instances dynamically in the C programming language. The Banker's Algorithm is a resource allocation and deadlock avoidance algorithm that helps manage multiple processes and resources, ensuring the system remains in a safe state by preventing deadlock conditions.

## Project Structure
The project is organized into a single C file (bankers_algorithm.c) containing the main program logic. The functionalities are divided into sections for user input, calculation of resource needs, and safety checks, providing a clear and structured approach for easy understanding and maintenance.

## Input
Number of Processes: Enter the total number of processes in the system.
Number of Resources: Enter the total number of resources in the system.
Allocation Matrix: Enter the current allocation of resources for each process.
Maximum Need Matrix: Enter the maximum resources each process may need.
Available Resources Vector: Enter the currently available resources in the system.

## Output
Safe State and Sequence: If the system is in a safe state, the program will display the safe sequence of processes.
Unsafe State and Deadlock Process: If the system is in an unsafe state, the program will identify the process causing the deadlock.

## Code
The main logic of the Banker's Algorithm is implemented in a single C file. The program uses arrays to store the allocation, maximum need, and current available resources. It also maintains a safe sequence of processes.
