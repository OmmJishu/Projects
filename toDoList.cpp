#include <bits/stdc++.h>
using namespace std;

struct Task
{
    string description;
    string dueDate;
    int priority;
};

void displayToDoList(const vector<Task> &toDoList)
{
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < toDoList.size(); i++)
    {
        cout << i + 1 << ". "
             << "Description: " << toDoList[i].description << " | Due Date: " << toDoList[i].dueDate << " | Priority: " << toDoList[i].priority << endl;
    }
}

int main()
{
    vector<Task> toDoList;
    ifstream inFile("tasks.txt");

    if (inFile.is_open())
    {
        Task task;
        while (getline(inFile, task.description) && getline(inFile, task.dueDate))
        {
            inFile >> task.priority;
            inFile.ignore();
            toDoList.push_back(task);
        }
        inFile.close();
    }

    unordered_set<string> prevTask;

    while (true)
    {
        cout << "\nEnter Options that You want to do :" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. View to-do list" << endl;
        cout << "3. Save and exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cin.ignore();
            Task newTask;
            cout << "Enter task description: ";
            getline(cin, newTask.description);

            if (prevTask.find(newTask.description) != prevTask.end())
            {
                cout << "Task with the same description already exists. Please enter a unique description." << endl;
                continue;
            }

            cout << "Enter due date (YYYY-MM-DD): ";
            cin >> newTask.dueDate;
            cout << "Enter task priority (1 for low, 2 for medium, 3 for high): ";
            cin >> newTask.priority;

            prevTask.insert(newTask.description);

            toDoList.push_back(newTask);
            cout << "Task added." << endl;
        }

        else if (choice == 2)
        {
            sort(toDoList.begin(), toDoList.end(), [](const Task &a, const Task &b)
                 { return a.priority < b.priority; });
            displayToDoList(toDoList);
        }
        else if (choice == 3)
        {
            ofstream outFile("tasks.txt");
            if (outFile.is_open())
            {
                for (const Task &task : toDoList)
                {
                    outFile << task.description << endl;
                    outFile << task.dueDate << endl;
                    outFile << task.priority << endl;
                }
                outFile.close();
            }
            else
            {
                cout << "Error: Could not save to-do list." << endl;
            }
            cout << "To-do list saved. Exiting." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}