# Task Manager

This project implements a simple task manager that can add, remove, and display tasks.

## What We Tried

We created a Task structure to represent tasks and a taskManager class to manage them. The class supports adding tasks, removing tasks by value or index, and printing the list. /n
Update: The class now supports removeDone, which removes the front of the list / queue.

## Why We Used a Vector

We chose std::vector because it resizes automatically, provides built-in methods for insertion, deletion, and iteration, and works efficiently for small to medium lists, which matches the project requirements.

## Reflection

Using a vector made it simple to handle tasks without manual memory management and left room for extending functionality later. Future improvements would probably include adding attributes like due dates or priorities, improving error handling for index removals, and formatting printed output for readability.
