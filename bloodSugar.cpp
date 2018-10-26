//Ethan Deming
//Oct. 24, 2018
//Project 1
//COSC 2030 Fall 2018

#include <array>
#include <iostream>
#include <cmath>
#include <string>
#include "List.h"
#include "Node.h"

using namespace std;

linkedList week1 [7];
linkedList week2 [7];
linkedList all [14];
int day = 0;
string buff;
float input;

int dailySummary(int current) //retrieves the sum, max, min, and total inputs for a day, then prints them
{
    float sum = all[current].sum();
    float Max = all[current].getMax();
    float Min = all[current].getMin();
    int totalRead = all[current].getSize();

    cout << "***Summary for Day " << current+1 << "***" << endl;
    cout << "Sum of all readings:   " << sum << endl;
    cout << "Max reading for today: " << Max << endl;
    cout << "Min reading for today: " << Min << endl;
    cout << "Total readings today : " << totalRead << endl << endl;

    return 0;
}

int weeklySummary(int current) //increments through every day in a week and determines sum, max, min, total inputs,
                               //and the max delta, then prints each piece of data
{
    int week;
    float sum = 0;
    float Max = 0;
    float Min = 0;
    int totalRead = 0;
    int maxDelta = 0;

    if(current < 7)
    {
        week = 1;

        for(int i = 0; i < 7; i++)
        {
            sum = sum + week1[i].sum();

            if(week1[i].getMax() > Max)
            {
                Max = week1[i].getMax();
            }

            if(Min == 0)
            {
                Min = week1[i].getMin();
            }
            else if(week1[i].getMin() > 0 && week1[i].getMin() < Min)
            {
                Min = week1[i].getMin();
            }

            totalRead = totalRead + week1[i].getSize();

            for(int i = 1; i < 7; i++)
            {
                if(maxDelta == 0 || abs(week1[i].getSize() - week1[i-1].getSize()))
                {
                    maxDelta = i;
                }
            }
        }
    }
    else
    {
        week = 2;

        for(int i = 0; i < 7; i++)
        {
            sum = sum + week2[i].sum();

            if(week2[i].getMax() > Max)
            {
                Max = week2[i].getMax();
            }

            if(Min == 0)
            {
                Min = week2[i].getMin();
            }
            else if(week2[i].getMin() > 0 && week2[i].getMin() < Min)
            {
                Min = week2[i].getMin();
            }

            totalRead = totalRead + week2[i].getSize();

            for(int i = 1; i < 7; i++)
            {
                if(maxDelta == 0 || abs(week2[i].getSize() - week2[i-1].getSize()))
                {
                    maxDelta = i;
                }
            }
        }
    }

    cout << "****Summary for Week " << week << "****" << endl;
    cout << "Sum of all readings:       " << sum << endl;
    cout << "Max reading for this week: " << Max << endl;
    cout << "Min reading for this week: " << Min << endl;
    cout << "Total readings this week:  " << totalRead << endl;
    cout << "Max delta was on day:      " << maxDelta << endl << endl;

    return 0;
}

void receiveIn() //receives an input and decides how to handle the input based on predetermined criteria
{
    while(day < 14)
    {
        cout << "**Now entering data for day " << day+1 << "**" << endl;
        cout << "Please input a blood sugar value greater than 0" << endl;
        cout << "Enter D or Day to see daily summary, W or Week to see weekly summary" << endl;
        cout << "Enter N or Next to increment to next day" << endl;
        cout << "Input a value and hit enter: ";
        cin >> buff;
        cout << endl << endl;

        if(buff == "D" || buff == "Day" || buff == "day" || buff == "d")
        {
            dailySummary(day);
        }
        else if(buff == "W" || buff == "Week" || buff == "week" || buff == "w")
        {
            weeklySummary(day);
        }
        else if(buff == "N" || buff == "Next" || buff == "next" || buff == "n")
        {
            day++;
        }
        else
        {
            input = stof(buff);
            all[day].insertAsLast(input);
            if(day < 7)
            {
                week1[day].insertAsLast(input);
            }
            else
            {
                week2[day-7].insertAsLast(input);
            }
            cout << "Data registered. Thank you" << endl << endl;
        }

        cin.clear();
        cin.ignore();
    }
}

//main function runs receiveIn and records values until day 14, then the program reports a complete
//trial and prints the summaries for both weeks

int main()
{
    receiveIn();

    cout << "Trial Complete. Data for week 1 and week 2 is listed below. Thank you." << endl << endl;

    weeklySummary(0);

    weeklySummary(7);

    return 0;
}
