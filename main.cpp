#include "taskManager.h"
#include <iostream>

int main() {
  taskManager taskList;

  taskList.print();

  Task task1("Task #1");
  taskList.add(task1);
  taskList.print();
}
