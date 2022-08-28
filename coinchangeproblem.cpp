## Code for hacker rank The Coin Change Problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */




//// MY CODE -----------------------------
long getWays(int n, vector<long> c) {
    long cn = c.size();
    vector<vector<long>> dp(n+1, vector<long>(cn+1,1));
    //dp[i][j] represents no. of ways to get i using (1,2,..,j) coins
    dp[0][0]=1;
    for(long i=1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(long i=1;i<=cn;i++){
        dp[0][i] = 1;
    }
    for(long i=1;i<=n;i++){
        for(long j=1;j<=cn;j++){
            if(i>=c[j-1]){    
                dp[i][j] = dp[i-c[j-1]][j] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[n][cn];
}

//// MY CODE ENDS ------------------------

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    fout << ways << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
