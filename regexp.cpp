#include <bits/stdc++.h>
#include <regex>

using namespace std;

vector<string> split_string(string);
void printDatabase(vector<vector<string>>& database);
void printGmailAsc(vector<vector<string>>& database);
bool nameComparator(string a, string b);


int main()
{
    int N = 30;
    // cin >> N;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> databaseTable;

    // 30
    string inputList[] = {
      "riya riya@gmail.com",
      "julia julia@julia.me",
      "julia sjulia@gmail.com",
      "julia julia@gmail.com",
      "samantha samantha@gmail.com",
      "tanya tanya@gmail.com",
      "riya ariya@gmail.com",
      "julia bjulia@julia.me",
      "julia csjulia@gmail.com",
      "julia djulia@gmail.com",
      "samantha esamantha@gmail.com",
      "tanya ftanya@gmail.com",
      "riya riya@live.com",
      "julia julia@live.com",
      "julia sjulia@live.com",
      "julia julia@live.com",
      "samantha samantha@live.com",
      "tanya tanya@live.com",
      "riya ariya@live.com",
      "julia bjulia@live.com",
      "julia csjulia@live.com",
      "julia djulia@live.com",
      "samantha esamantha@live.com",
      "tanya ftanya@live.com",
      "riya gmail@riya.com",
      "priya priya@gmail.com",
      "preeti preeti@gmail.com",
      "alice1 alice@alicegmail.com",
      "alice2 alice@gmail.com",
      "alice3 gmail.alice@gmail.com" };



    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstNameEmailID_temp;
        firstNameEmailID_temp = inputList[N_itr];

        vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

        string firstName = firstNameEmailID[0];

        string emailID = firstNameEmailID[1];

        databaseTable.push_back(firstNameEmailID);
    }

    // printDatabase(databaseTable);

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
  regex rx("[\\w]*.[\\w]*@gmail.com");
  smatch match;
  vector<string> gmailNames;

  for (int i = 0; i < database.size(); i++) {
    regex_match(database[i][1], match, rx);
    if (match.size()) {
      gmailNames.push_back(database[i][0]);
    }
  }

  sort(gmailNames.begin(), gmailNames.end(), nameComparator);

  for (int i = 0; i < gmailNames.size(); i++) {
    cout << gmailNames[i] << endl;
  }
}

bool nameComparator(string a, string b) {
  return a < b;
}