#include<bits/stdc++.h>
using namespace std;

int main()
{
	string test = "chillout";
	double s_length = test.length();
	int rows = floor(sqrt(s_length));
	int cols = ceil(sqrt(s_length));
	if(rows*cols < s_length)
	{
		rows++;
	}

	string result = "";
	for(int curr_col = 0; curr_col < cols; curr_col++)
	{
		for(int curr_row = 0; curr_row < rows; curr_row++)
		{
			int curr_pos = curr_col + (curr_row*cols);
			if(curr_pos < s_length)
			{
				result = result + test[curr_pos];
			}
		}
		result = result + " ";
	}

	cout << result;
}
