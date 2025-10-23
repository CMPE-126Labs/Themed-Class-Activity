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
      return;
    }
  }
}
void taskManager::remove(int index) {
  if (index >= 0 && index < this->list.size()) {
    taskDetails temp(this->list.at(index), index, false);
    this->list.erase(this->list.begin() + index);
    this->stack.push(temp);
  }
}

void taskManager::print() {

  if (this->list.size() == 0) {
    std::cout << "Empty List" << std::endl;
    return;
  }
  for (int i = 0; i < this->list.size(); i++) {
    std::cout << this->list.at(i).name << " ";
  }
  std::cout << std::endl;
}

void taskManager::undo() {

  if (this->stack.empty()) {
    std::cout << "Empty Stack" << std::endl;
    return;
  }

  taskDetails temp = this->stack.top();
  this->stack.pop();

  if (!temp.isAdded) {
    if (temp.index >= this->list.size()) {
      this->list.push_back(temp.task);
    } else {
      this->list.insert(this->list.begin() + temp.index, temp.task);
    }
  } else {
    if (temp.index >= 0 && temp.index < this->list.size()) {
      this->list.erase(this->list.begin() + temp.index);
    }
  }
}
