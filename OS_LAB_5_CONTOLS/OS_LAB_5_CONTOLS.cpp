// OS_LAB_5_CONTOLS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int interfaceCall(int num);
void loopCycle(int num);
void getCurentProcesses(int num);
void setThreadPriorityAt();

//GLOBAL VARIABLES
//-----------------
DWORD threadID[16];
HANDLE threads[16];
DWORD priority_classes[] = { THREAD_PRIORITY_HIGHEST , THREAD_PRIORITY_NORMAL , THREAD_PRIORITY_TIME_CRITICAL };
//-----------------

int main(int argc, char* argv[])
{
    if (argc > 1) {
        for (int i = 0; i < argc - 1; i++) {
            threadID[i] = atoi(argv[i + 1]);
            threads[i] = OpenThread(THREAD_ALL_ACCESS, FALSE, threadID[i]);
            if (threads[i] == NULL) {
                cout << "\n\tERROR!!! Code : "<<GetLastError();
                Sleep(1000);
            }
        }
        loopCycle(argc - 1);
    }
    else
    {
        std::cout << "NO THREADS";
        int val;
        std::cin >> val;
    }

    return 0;
}

void getCurentProcesses(int num) {
    cout << "\THREADS : ";
    for (int i = 0; i < num; i++) {
        cout << "[\033[92m" << i << "\033[0m] - \033[34m" << threadID[i] << "\033[0m | ";
    }
    cout << endl;
}

void processControl() {
    int num, option;

    cout << "\nCONTROLING THREADS : \n\tSELECT THREAD : ";
    cin >> num;
    cout << "\t> WORKING WITH TID : \033[34m" << threadID[num] << "\033[0m \n";
    cout << "\n\tOPTIONS : \n"
        << "\t[\033[92m0\033[0m] - SUSPEND\t[\033[92m1\033[0m] - UNSUSPEND\n";
    cout << "\tSELECT PRIORITY : ";
    cin >> option;

    switch (option)
    {
    case 0:
        SuspendThread(threads[num]);
        break;
    case 1:
        ResumeThread(threads[num]);
        break;
    default:
        break;
    }
    Sleep(700);
}

int interfaceCall(int num) {
    int choice;
    system("cls");
    getCurentProcesses(num);

    cout << "\nOPTIONS : \n\t"
        << "[\033[92m1\033[0m] : SET PRIORITY | [\033[92m2\033[0m] : THREAD CONTROL | [\033[92m3\033[0m] :  RUN ALL | [\033[92m4\033[0m] : EXIT \n";
    cout << "ENTER YOUR CHOISE : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        setThreadPriorityAt();
        break;
    case 2:
        processControl();
        break;
    case 3:
        for (HANDLE thread : threads) {
            ResumeThread(thread);
        }
        break;
    default:
        break;
    }
    cout << "\n ";

    return choice;
}

void loopCycle(int num) {
    int stop_ = interfaceCall(num);
    while (stop_ != 4) {
        stop_ = interfaceCall(num);
    }
}



void setThreadPriorityAt() {
    int num, priority;

    cout << "\nSETTING PRIORITY : \n\tSELECT THREAD : ";
    cin >> num;
    cout << "\t> WORKING WITH TID : \033[34m" << threadID[num] << "\033[0m \n";
    cout << "\n\tPRIORITIES : \n"
        << "\t[\033[92m0\033[0m] - HIGH\t[\033[92m1\033[0m] - NORMAL\t[\033[92m2\033[0m] - REALTIME\n";
    cout << "\tSELECT PRIORITY : ";
    cin >> priority;

    if (!SetThreadPriority(threads[num], priority_classes[priority])) {
        cout << "ERROR ACCURED | CODE : " << GetLastError();
        Sleep(5000);
    }
    else {

    }
    Sleep(300);
}