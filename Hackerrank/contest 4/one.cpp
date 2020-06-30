#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    vector<int> ans=vector<int>(2,0);
    
    // max subarray
    vector<int> subArrayDp=arr;
    int currMax=arr[0],maxSoFar=arr[0],n=arr.size();
    for(int i=1;i<n;i++){
        currMax=max(subArrayDp[i],subArrayDp[i]+currMax);
        maxSoFar=max(maxSoFar,currMax);
    }
    ans[0]=maxSoFar;

    for(int i=1;i<n;i++){
        if(subArrayDp[i-1]+arr[i]>subArrayDp[i-1]){
            subArrayDp[i]=subArrayDp[i-1]+arr[i];
        }else{
            subArrayDp[i]=max(arr[i],subArrayDp[i-1]);
        }
    }

    ans[1]=subArrayDp[n-1];
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
