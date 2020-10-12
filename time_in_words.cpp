#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
void timeInWords(int h, int m) 
{
    string ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string tens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string twenty = "twenty";

    if(m == 0)
    {
        if(h<10)
        {
            cout << ones[h-1] << " o' clock";
        }
        else
        {
            cout << tens[h - 10] << " o' clock";
        }
    }

    else if(m==30)
    {
        if(h < 10)
        {
            cout << "half past " << ones[h-1];
        }
        else
        {
            cout << "half past " << tens[h-10];
        }
    }

    else if(m > 0 && m < 30)
    {
        string hour = "";
        string min = "";
        if(h < 10)
        {
            hour = ones[h-1];
        }

        else if(h >= 10)
        {
            hour = tens[h - 10];
        }


        if(m < 10)
        {
            min = ones[m-1];
        }

        else if(m >= 10 && m < 20)
        {
            if(m == 15)
            {
                min = "quarter past ";
            }
            else
            {
                min = tens[m - 10];
            }
        }

        else if(m >= 20)
        {
            if(m==20)
            min = min + twenty;
            else
            min = min + twenty + " " + ones[m%10 - 1];
        }

        if(m==15)
        {
            cout << min << hour;
        }
        else if(m==1)
        {
            cout << min << " minute past " << hour;
        }
        else
        {
            cout << min << " minutes past " << hour;
        }
    }

    else if(m > 30)
    {
        h = (h%12) + 1;
        m = 60 - m;
        string hour = "";
        string min = "";
        if(h < 10)
        {
            hour = ones[h-1];
        }
        else if(h >= 10)
        {
            hour = tens[h - 10];
        }

        if(m < 10)
        {
            min = ones[m-1];
        }

        else if(m >= 10 && m < 20)
        {
            if(m == 15)
            {
                min = "quarter to ";
            }
            else
            {
                min = tens[m - 10];
            }
        }

        else if(m >= 20)
        {
            if(m==20)
            min = min + twenty;
            else
            min = min + twenty + " " + ones[m%10 - 1];
        }

        if(m==1)
        {
            cout << min << " minute to " << hour;
        }
        else if(m==15)
        {
            cout << min << hour;
        }
        else
        {
            cout << min << " minutes to " << hour;
        }
    }

}

int main()
{


    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    timeInWords(h, m);

    return 0;
}
