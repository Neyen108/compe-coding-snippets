#include<bits/stdc++.h>
using namespace std;


int main()
{
    string ones[] = {"", "one", "two","three","four","five", "six", "seven", "eight", "nine","ten"};
    string tens[] = {"twenty", "thirty"};
    string teens[] = {"eleven", "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    int hh, mm;
    string hour ="";
    string min = "";
    cin >> hh >> mm;

    if(hh <= 10)
    {
        hour = hour + ones[hh];
    }
    else
    {
        hour = hour + teens[hh-11];
    }


    if(mm == 0)
    {
        cout << hour + " o'clock"<< "\n";
    }
    else if(mm > 0 && mm < 30)
    {
        if(mm == 15)
        {
            min = min + "quarter past";
            cout << min + " " + hour << "\n";
        }
        else
        {
            int unit_place = mm%10;
            int tens_place = ((mm%100) - unit_place)/10;

            if(unit_place)
            {
                if(tens_place == 2)
                {
                    min = min + tens[tens_place - 2] + " " + ones[unit_place];
                }
                else if(tens_place == 1)
                {
                    min = min + teens[unit_place-1];
                }
                else
                {
                    min = min + ones[unit_place];
                }
            }
            else
            {
                if(tens_place == 2)
                {
                    min = min  + tens[tens_place - 2];
                }
                else if(tens_place == 1)
                {
                    min = min + ones[10];
                }
            }
            if(min == "one")
            cout << min << " minute past " << hour << "\n";
            else
                cout << min << " minutes past " << hour << "\n";
        }
    }
    else if(mm == 30)
    {
        min = min + "half past";
        cout << min + " " + hour << "\n";
    }
    else
    {
        mm = 60 - mm;
        hour = "";
        if(hh < 10)
        {
            hour = hour + ones[hh+1];
        }
        else if(hh == 12)
        {
            hour = hour + "one";
        }
        else
        {
            hour = hour + teens[hh-10];
        }

        if(mm == 15)
        {
            min = min + "quarter to";
            cout << min + " " + hour << "\n";
        }
        else
        {
            int unit_place = mm%10;
            int tens_place = ((mm%100) - unit_place)/10;
            if(unit_place)
            {
                if(tens_place == 2)
                {
                    min = min + tens[tens_place - 2] + " " + ones[unit_place];
                }
                else if(tens_place == 1)
                {
                    min = min + teens[unit_place-1];
                }
                else
                {
                    min = min + ones[unit_place];
                }
            }
            else
            {
                if(tens_place == 2)
                {
                    min = min  + tens[tens_place - 2];
                }
                else if(tens_place == 1)
                {
                    min = min + ones[10];
                }
            }

            if(min == "one")
            {
                cout << min << " minute to " << hour << "\n";
            }
            else
                cout << min << " minutes to " << hour << "\n";
        }
    }




}
