#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*There are some gas stations along a circular route. You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations. Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction. If there is no such starting station exists, return -1.
Note: If a solution exists, it is guaranteed to be unique.*/

int startStation(vector<int> &gas, vector<int> &cost)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance >= 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (balance + deficit >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}