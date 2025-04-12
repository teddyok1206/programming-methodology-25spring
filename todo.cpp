#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i; i < size; i++)
    {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
    size = 0;

}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int i = 0;
        while (true)
        {
            if (str[i] == '\0')
            {
                break;
            }
            i++;
        }
    return 0;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int i = 0;
    while (true)
    {
        dest[i] = src[i];
        if (dest[i] == '\0')
        {
            break;
        }
        i++;
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size >= MAX_TASKS)
    {
        throw std::overflow_error("List is full.");
    }
    else
    {
        int task_len = string_length(task);
        tasks[size] = new char[task_len + 1];
        string_copy(tasks[size], task);
        size += 1;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (size < 1 || index < 0 || index >= size)
    {
        throw std::range_error("No task or Invaild idx");
    }
    else
    {
        delete[] tasks[index];
        if (index != (size - 1))
        {
            for (int i = index; i < size -1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
        }
        tasks[size - 1] = nullptr;
    }
    size -= 1;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    const char** result_ptr;
    result_ptr = new const char*[count];
    for (int i = 0; i < count; i++)
    {
        result_ptr[i] = tasks[i];
    }
    return result_ptr;
}