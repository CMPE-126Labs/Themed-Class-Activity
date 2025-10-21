#include "taskManager.h"
#include <iostream>
#include <vector>

taskManager::taskManager(const Task &t) { this->list.push_back(t); }
taskManager::taskManager() {}

void taskManager::add(const Task &t) {
  this->list.push_back(t);
  int index = this->list.size() - 1;
  taskDetails temp(t, index, true);
  this->stack.push(temp);
}
void taskManager::remove(const Task &t) {
  for (int i = 0; i < this->list.size(); i++) {
    if (this->list.at(i) == t) {
      this->list.erase(this->list.begin() + i);
      taskDetails temp(t, i, false);
      this->stack.push(temp);
    }
  }
}
void taskManager::remove(int index) {
  if (index < 0 || index > this->list.size()) {
    taskDetails temp(this->list.at(index), index, false);
    this->list.erase(this->list.begin() + index);
    this->stack.push(temp);
  }
}

void taskManager::print() {

  if (this->list.size() == 0) {
    std::cout << "Empty List" << std::endl;
  }
  for (int i = 0; i < this->list.size(); i++) {
    std::cout << this->list.at(i).name << " ";
  }
  std::cout << std::endl;
}
