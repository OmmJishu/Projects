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
    cout << "\nTo-Do List:" << endl;
    for (size_t i = 0; i < toDoList.size(); i++)
    {
        cout << i + 1 << ". "
             << "Description: " << toDoList[i].description << " | Due Date: " << toDoList[i].dueDate << " | Priority: " << toDoList[i].priority << endl;
    }
}

int main()
{
    vector<Task> toDoList;
    ifstream inFile("tasks2.txt");

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
        cout << "1. Add a Task" << endl;
        cout << "2. Remove a Task" << endl;
        cout << "3. View to-do list" << endl;
        cout << "4. Save and exit" << endl;

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

            cout << "Enter due date (DD-MM-YYYY): ";
            cin >> newTask.dueDate;
            cout << "Enter task priority (1 for low, 2 for medium, 3 for high): ";
            cin >> newTask.priority;

            prevTask.insert(newTask.description);

            toDoList.push_back(newTask);
            cout << "Task added." << endl;
        }

        else if (choice == 2)
        {
            cin.ignore(); 

            displayToDoList(toDoList);

            cout << "\nEnter the task description to remove : ";
            string descriptionToRemove;
            getline(cin, descriptionToRemove);

            // Open the "tasks2.txt" file for both reading and writing
            ifstream file("tasks2.txt");
            
            if (file.is_open())
            {
                // Read the existing tasks into a temporary vector
                vector<Task> tempTasks;
                Task tempTask;

                while (getline(file, tempTask.description) && getline(file, tempTask.dueDate))
                {
                    file >> tempTask.priority;
                    file.ignore();
                    tempTasks.push_back(tempTask);
                }
                file.close();

                // Search for the task in the temporary vector
                auto it = find_if(tempTasks.begin(), tempTasks.end(), [&descriptionToRemove](const Task &task){ 
                    return task.description == descriptionToRemove; 
                });

                // Check if the task was found
                if (it != tempTasks.end())
                {
                    // Task found, remove it from the temporary vector
                    tempTasks.erase(it);
                    cout << "Task removed." << endl;

                    // Write the updated tasks back to the file
                    fstream file("tasks2.txt");
                    for (const Task &task : tempTasks)
                    {
                        file << task.description << '\n'
                             << task.dueDate << '\n'
                             << task.priority << '\n';
                    }

                    toDoList.swap(tempTasks);

                    file.close();
                    cout << "File updated." << endl;
                }
                else
                {
                    // Task not found
                    cout << "Task not found. Please enter a valid task description." << endl;
                    file.close();
                }
            }
            else
            {
                cout << "Error opening file." << endl;
            }
        }

        else if (choice == 3)
        {
            sort(toDoList.begin(), toDoList.end(), [](const Task &a, const Task &b)
                 { return a.priority > b.priority; });
            displayToDoList(toDoList);
        }

        else if (choice == 4)
        {
            ofstream outFile("tasks2.txt");
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
