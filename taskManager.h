#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <iostream>
#include <string>
#include <vector>

struct Task {
  std::string name;

  bool operator==(const Task &other) { return this->name == other.name; }

  Task() { this->name = "Default Task"; }

  Task(std::string name) { this->name = name; };
};

class taskManager {
private:
  std::vector<Task> list;

public:
  taskManager(const Task &t);
  taskManager();
  void add(const Task &t);
  void remove(const Task &t);
  void remove(int index);
  void print();
};
#endif // !TASKMANAGER_H
