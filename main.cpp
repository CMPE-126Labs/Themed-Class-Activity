#include "taskManager.h"
#include <iostream>

int main() {
  taskManager taskList;

  taskList.print();

  Task task1("Task #1");
  taskList.add(task1);
  Task task2("Task #2");
  taskList.add(task2);
  taskList.print();
  taskList.undo();
  taskList.print();
  taskList.add(task2);
  taskList.print();
  taskList.remove(task2);
  taskList.print();
  taskList.undo();
  taskList.print();
  taskList.removeDone();
  taskList.print();
  Task task3("Task #3");
  taskList.add(task3);
  taskList.print();
  taskList.removeDone();
  taskList.print();
  taskList.removeDone();
  taskList.removeDone();
}
