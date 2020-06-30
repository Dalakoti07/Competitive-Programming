#include <bits/stdc++.h>

using namespace std;

// wa
vector<string> split_string(string);


// https://www.hackerrank.com/challenges/sherlock-and-gcd/editorial

// Complete the solve function below.
string solve(vector<int> a) {
    // if we are not able to find two elems such that a!=b and gcd(a,b)!=1 then its not possible means ans = NO

    // if we can find at least , its greedy find atleast one two elements non 1
    //, which can be equal and if their gcd is not 1, then it means they have some multiple and possible, else false
    int gc=0,j,n=a.size(),i;
    for(i=0; i<n; i++){
        j=a[i];
        gc=__gcd(gc,j);
    }
    if(gc==1) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int a_count;
        cin >> a_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(a_count);

        for (int a_itr = 0; a_itr < a_count; a_itr++) {
            int a_item = stoi(a_temp[a_itr]);

            a[a_itr] = a_item;
        }

        string result = solve(a);

        fout << result << "\n";
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
