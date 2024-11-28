#include <iostream>
#include <vector>
using namespace std;

class Remainder {
private:
    vector<string> dates;
    vector<string> times;
    vector<string> tasks;
    vector<string> events;

public:
    Remainder() {}
    ~Remainder() {}

    void getdate() {
        string date;
        cout << "Enter today's date: ";
        cin >> date;
        dates.push_back(date);
    }

    void gettime() {
        string time;
        cout << "Enter the deadline to complete this work or task or time of this event: ";
        cin >> time;
        times.push_back(time);
    }

    void gettask() {
        string task;
        cout << "Enter the task: ";
        cin >> task;
        tasks.push_back(task);
    }

    void getevent() {
        string event;
        cout << "Enter the name of the event: ";
        cin >> event;
        events.push_back(event);
    }

    void displaytasks() {
        if (tasks.empty()) {
            cout << "NO TASKS SCHEDULED!" << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << dates[i] << " : " << tasks[i] << " : " << times[i] << endl;
            }
        }
    }

    void displayevents() {
        if (events.empty()) {
            cout << "NO EVENTS SCHEDULED!" << endl;
        } else {
            for (size_t i = 0; i < events.size(); ++i) {
                cout << i + 1 << ". " << dates[i] << " : " << events[i] << " : " << times[i] << endl;
            }
        }
    }

    void deleteTask() {
        int index;
        displaytasks();
        cout << "Enter the number of the task to delete: ";
        cin >> index;
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            dates.erase(dates.begin() + index - 1);
            times.erase(times.begin() + index - 1);
            cout << "Task deleted." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void deleteEvent() {
        int index;
        displayevents();
        cout << "Enter the number of the event to delete: ";
        cin >> index;
        if (index > 0 && index <= events.size()) {
            events.erase(events.begin() + index - 1);
            dates.erase(dates.begin() + index - 1);
            times.erase(times.begin() + index - 1);
            cout << "Event deleted." << endl;
        } else {
            cout << "Invalid event number." << endl;
        }
    }

    void all() {
        displaytasks();
        displayevents();
    }
};

int main() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "**************WELCOME**********************" << endl;
    cout << "************SMART TASK MANAGER*************" << endl;
    cout << "*******************************************" << endl;

    Remainder obj;
    int a;

    do {
        cout << "1. Add task" << endl;
        cout << "2. Add event" << endl;
        cout << "3. Display tasks and events" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Delete event" << endl;
        cout << "6. Exit" << endl;
        cin >> a;

        switch (a) {
            case 1:
                obj.getdate();
                obj.gettime();
                obj.gettask();
                break;
            case 2:
                obj.getdate();
                obj.gettime();
                obj.getevent();
                break;
            case 3:
                obj.all();
                break;
            case 4:
                obj.deleteTask();
                break;
            case 5:
                obj.deleteEvent();
                break;
            case 6:
                cout << "Exiting.........." << endl;
                break;
            default:
                cout << "<<<<<<<<<<<<<<<<<THANK YOU>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
                break;
        }
    } while (a != 6);

    cout << "~~~~~~~~~SEE YOU AGAIN~~~~~~~~~~~" << endl;
    return 0;
}
