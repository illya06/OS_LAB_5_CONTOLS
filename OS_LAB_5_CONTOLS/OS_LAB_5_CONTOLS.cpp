// OS_LAB_5_CONTOLS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int interfaceCall(int num);
void loopCycle(int num);
void getCurentProcesses(int num);

//GLOBAL VARIABLES
//-----------------
DWORD threadID[16];
//-----------------

int main(int argc, char* argv[])
{
    //cout << argc - 1 << endl;
    if (argc > 1) {
        for (int i = 0; i < argc - 1; i++) {
            threadID[i] = atoi(argv[i+1]);
            cout << threadID[i] << endl;
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

int interfaceCall(int num) {
    int choice;
    system("cls");
    getCurentProcesses(num);

    cout << "\nOPTIONS : \n\t"
        << "[\033[92m1\033[0m] : SET PRIORITY | [\033[92m2\033[0m] : PROCESS CONTROL | [\033[92m3\033[0m] : EXIT \n";
    cout << "ENTER YOUR CHOISE : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
    cout << "\n ";

    return choice;
}

void loopCycle(int num) {
    int stop_ = interfaceCall(num);
    while (stop_ != 3) {

        stop_ = interfaceCall(num);
    }
}