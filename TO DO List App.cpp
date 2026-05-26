#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Global vectors:
vector<string> task;
vector<string> C_task;
vector<string> D_task;

//Functions:
void add()
{
    string ta;
    cout << "Enter Your Tasks (Type 'done' to stop) : \n\n";
    cin.ignore();

    while (true)
    {
        cout << "_ Task : ";
        getline(cin, ta);

        if (ta == "done" || ta == "DONE")
            break;

        task.push_back(ta);
    }

    cout << "\nTasks added successfully!\n";
}

void delet()
{
    int nd;

    while (true)
    {
        cout << "\nEnter the task number to delete (0 to exit):\n ";
        cin >> nd;

        if (nd == 0)
        {
            cout << "Exiting delete menu...\n";
            break;
        }

        int index = nd - 1;

        if (index >= 0 && index < task.size())
        {
            D_task.push_back(task[index]);   // Storing the deleted task
            task.erase(task.begin() + index); // Remove it from the list
            cout << "Task deleted successfully!\n";
        }
        else
        {
            cout << "Invalid task number!\n";
        }
    }
}

void completed()
{
    int com;

    while (true)
    {
        cout << "Choose The Number of The Completed Tasks (0 To Exit) :\n";
        cin >> com;

        if (com == 0)
        {
            cout << "Exiting completed menu...\n";
            break;
        }

        int o = com - 1;

        if (o >= 0 && o < task.size())
        {
            C_task.push_back(task[o]);   // Storing the completed task
            cout << "Task marked as completed!\n";
        }
        else
        {
            cout << "Invalid task number!\n";
        }
    }
}

void show()
{
    cout << "\nAll Tasks:\n";
    for (int i = 0; i < task.size(); i++)
    {
        cout << i + 1 << ") " << task[i] << "\n";
    }

    cout << "\nCompleted Tasks:\n";
    for (int t = 0; t < C_task.size(); t++)
    {
        cout << t + 1 << ") " << C_task[t] << "\n";
    }

    cout << "\nDeleted Tasks:\n";
    for (int p = 0; p < D_task.size(); p++)
    {
        cout << p + 1 << ") " << D_task[p] << "\n";
    }
}

int main()
{
    int x;

    while (true)
    {
        cout << "\n______Main Menu______\n";
        cout << "Choose The Number Next To The List You Want :\n";
        cout << "1_ Add Task\n";
        cout << "2_ Delete Task\n";
        cout << "3_ Show Tasks\n";
        cout << "4_ Mark Task As Completed\n";
        cout << "5_ Save and Exit\n";

        cin >> x;

        if (x == 1)
            add();
        else if (x == 2)
            delet();
        else if (x == 3)
            show();
        else if (x == 4)
            completed();
        else if (x == 5)
        {
            cout << "Saving...\n";
            return 0;
        }
        else
            cout << "Invalid Number!\n";
    }

    return 0;
}
