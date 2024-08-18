//
// Created by douwe on 18-8-2024.
//
#include "todo.h"
#include <fstream>
#include <iostream>

// Item class constructor
Item::Item(int idx, std::string& data, Item* n) {
  index = idx;
  info = data;
  next = n;
}

List::List() {
  amount = 0;
  head = nullptr;
  tail = nullptr;
}

List::~List() { Clear(); }

// public class methods

void List::Display() {
  if (head != nullptr) {
    Item* current = head;
    do {
      int item = current->index + 1;
      std::string info = current->info;
      std::cout << item << ". " << info << std::endl;
      current = current->next;
    } while (current != nullptr);
  }
}

void List::Add(std::string& data) {
    Item* newitem = new Item(amount, data, nullptr);
    amount++;
    if(head==nullptr){
        head = newitem;
        tail = newitem;
    } else {
        tail->next = newitem;
        tail = newitem;
    }
}
void List::Delete(int index) {
    if (index < 0 || index >= amount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    if (index == 0) {
        Item* temp = head;
        head = head->next;
        if (head == nullptr) {  
            tail = nullptr;
        }
        delete temp;
        amount--;
        head->index = 0;
        Item* current = head;
        while (current->next != nullptr) {
            current->next->index = current->index + 1;
            current = current->next;
        }
        return;
    }

    Item* prev = head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    Item* to_delete = prev->next;
    prev->next = to_delete->next;

    if (to_delete == tail) {
        tail = prev;
    }

    delete to_delete;
    amount--;

    Item* current = prev->next;
    while (current != nullptr) {
        current->index = index;
        index++;
        current = current->next;
    }
}
void List::Edit(int index, std::string& data) {
    if (index < 0 || index >= amount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    if(index==0){
        head->info = data;
    } else {
        Item* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->info = data;
    }
}
void List::Save() {
    std::ofstream file("todo.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    Item* current = head;
    while (current != nullptr) {
        file << current->index << ";" << current->info << std::endl;
        current = current->next;
    }

    file.close();
}
void List::Load() {
    std::ifstream file("todo.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return;
    }
    Clear();
    std::string line;

    while(std::getline(file, line)){
        size_t delim = line.find(';');
        int index = std::stoi(line.substr(0, delim));
        std::string info;
        if (delim != std::string::npos) {
            info = line.substr(delim + 1);
            Add(info, index);
        }
    }
    file.close();
}

// private class methods
void List::Clear() {
    Item* current = head;  

    while (current != nullptr) {
        Item* next = current->next;  
        delete current;              
        current = next;              
    }
    head = nullptr;  
    tail = nullptr;  
    amount = 0;      
}
void List::Add(std::string& data, int index) {
    if (index < 0 || index > amount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    Item* newitem = new Item(index, data, nullptr);
    amount++;

    if (index == 0) {
        newitem->next = head;
        head = newitem;
        if (tail == nullptr) {
            tail = newitem;
        }
        return;
    }

    Item* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newitem->next = current->next;
    current->next = newitem;

    if (newitem->next == nullptr) {
        tail = newitem;
    }
}
