#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view the list of tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    cout << "To-Do List Manager" << endl;
    while (true) {
        cout << endl;
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option: ";

        int option;
        cin >> option;

        switch (option) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                viewTasks(tasks);
                cout << "Enter task index to mark as completed: ";
                size_t index;
                cin >> index;
                markTaskAsCompleted(tasks, index - 1); // Index is 1-based in user input
                break;
            }
            case 4: {
                viewTasks(tasks);
                cout << "Enter task index to remove: ";
                size_t index;
                cin >> index;
                removeTask(tasks, index - 1); // Index is 1-based in user input
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}
