#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
class FCFS
{
public:
    static const int MAX_PROCESSES = 100;
    void getProcess();
    void calculateTime();
    void printData();

private:
    int n;
    int arrival[MAX_PROCESSES];
    int burst[MAX_PROCESSES];
    int waitingTime[MAX_PROCESSES];
    int turnAroundTime[MAX_PROCESSES];
};
void FCFS::getProcess()
{
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the arrival time of the processes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arrival[i];
    }

    cout << "Enter the Burst time of the processes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> burst[i];
    }
}
void FCFS::calculateTime()
{
    waitingTime[0] = 0;
    for (int i = 0; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burst[i - 1] - arrival[i] + arrival[i - 1];

        if (waitingTime[i] < 0)
        {
            waitingTime[i] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = burst[i] + waitingTime[i];
    }
}

void FCFS::printData()
{
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << arrival[i] << "\t\t" << burst[i] << "\t\t"
             << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }
}

int main()
{
    FCFS F;
    F.getProcess();
    F.calculateTime();
    F.printData();

    return 0;
}