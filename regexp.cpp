#include <bits/stdc++.h>
#include <regex>

using namespace std;

vector<string> split_string(string);
void printDatabase(vector<vector<string>>& database);
void printGmailAsc(vector<vector<string>>& database);


int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> databaseTable;

    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstNameEmailID_temp;
        getline(cin, firstNameEmailID_temp);

        vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

        string firstName = firstNameEmailID[0];

        string emailID = firstNameEmailID[1];

        databaseTable.push_back(firstNameEmailID);
    }

    printDatabase(databaseTable);

    printGmailAsc(databaseTable);

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

void printDatabase(vector<vector<string>>& database) {
  for (int i = 0; i < database.size(); i++) {
    cout << "row: " << i << ", name: " << database[i][0] << ", email: " << database[i][1] << endl;
  }
}

// solution
void printGmailAsc(vector<vector<string>>& database) {
  regex rx("[\\w]*@gmail.com");
  cmatch match;
  regex_match("sjulia@gmail.com", match, rx);
  if (match.size()) {
    cout << "matched: " << match[0] << endl;
  } else {
    cout << "no matches." << endl;
  }
  
}