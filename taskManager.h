#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

struct Task {
  std::string name;

  bool operator==(const Task &other) const { return this->name == other.name; }

  Task() { this->name = "Default Task"; }

  Task(std::string name) { this->name = name; };
};

struct taskDetails {
  Task task;
  int index;
  bool isAdded;

  taskDetails() {};

  taskDetails(Task task, int index, bool isAdded) {
    this->task = task;
    this->index = index;
    this->isAdded = isAdded;
  }
};

class taskManager {
private:
  std::vector<Task> list;
  std::stack<taskDetails> stack;
  std::queue<Task> queue;

public:
  taskManager(const Task &t);
  taskManager();
  void add(const Task &t);
  void remove(const Task &t);
  void remove(int index);
  void removeDone();
  void print();
  void undo();
  int search(const Task &t) const;
};
#endif // !TASKMANAGER_H
