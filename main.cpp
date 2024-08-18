#include <iostream>
#include "todo.h"

int main() {
    List todoList;

    // Adding items
    std::string task1 = "Buy groceries";
    std::string task2 = "Call Alice";
    std::string task3 = "Finish homework";

    todoList.Add(task1);
    todoList.Add(task2);
    todoList.Add(task3);

    // Displaying items
    std::cout << "Initial list:" << std::endl;
    todoList.Display();
    std::cout << std::endl;

    // Editing an item
    std::string newTask2 = "Call Bob";
    todoList.Edit(1, newTask2);
    todoList.Complete(1);

    // Displaying items after edit
    std::cout << "List after editing task 2:" << std::endl;
    todoList.Display();
    std::cout << std::endl;

    // Deleting an item
    todoList.Delete(0);

    // Displaying items after delete
    std::cout << "List after deleting task 0:" << std::endl;
    todoList.Display();
    std::cout << std::endl;
    todoList.Complete(1);
    todoList.Display();
    // Saving the list to a file
    todoList.Save();

    // Clearing the list and loading from file
    todoList.Clear();
    std::cout << "List after clearing:" << std::endl;
    todoList.Display();
    std::cout << std::endl;

    todoList.Load();
    std::cout << "List after loading from file:" << std::endl;
    todoList.Display();

    return 0;
}
