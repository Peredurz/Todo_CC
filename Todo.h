//
// Created by douwe on 18-8-2024.
//
#include <string>

#ifndef TODO_TODO_H
#define TODO_TODO_H

class Item {
public:
    int index;
    std::string info;
    Item* next;
    Item(int idx, std::string& data, Item* n);
};

class List {
public:
    List();
    ~List();
    void Display();
    void Add(std::string& data);
    void Delete(int index);
    void Edit(int index, std::string& data);
    void Save();
    void Load();
    void Clear();

private:
    int amount = 0;
    Item* head;
    Item* tail;

    void Add(std::string& data, int index);
};

#endif //TODO_TODO_H
