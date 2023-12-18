#include <iostream>
#include <vector>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

class TodoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &description)
    {
        Task newTask{description, false};
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks available. Add some tasks first." << endl;
            return;
        }

        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i)
        {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
            {
                cout << "[Done] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void deleteTask(size_t index)
    {
        if (index < 1 || index > tasks.size())
        {
            cout << "Invalid task index. Please enter a valid index.\n";
            return;
        }

        cout << "Task deleted: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main()
{
    TodoList todoList;
    int choice;

    do
    {
        cout << "\n===== To-Do List Manager =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case 2:
            todoList.viewTasks();
            break;
        case 3:
        {
            size_t index;
            cout << "Enter the task index to delete: ";
            cin >> index;
            todoList.deleteTask(index);
            break;
        }
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
