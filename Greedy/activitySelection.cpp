#include <bits/stdc++.h>

using namespace std;

bool compareEnd(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, start, end;
        cin >> n; //no. of activities

        vector<pair<int, int>> V(n); //vector to store the start and end times

        //enter the start and end times of the activity
        for (int i = 0; i < n; i++)
        {
            cin >> start >> end;
            V[i] = make_pair(start, end);
        }

        //sort according to end time
        sort(V.begin(), V.end(), compareEnd);

        //greedy
        //first activity needs to be done for greedy
        int activities = 1;

        //var to hold the last Ending time we stopped at
        int lastEndingTime = V[0].second;

        //iterate through the rest of the list
        for (int i = 1; i < n; i++)
        {
            //if starting Time >= last Ending time; include the activity
            if (V[i].first >= lastEndingTime)
            {
                //include that activity and the new Ending time is updated
                lastEndingTime = V[i].second;
                activities++;
            }
        }

        cout << activities << "\n";
    }
}