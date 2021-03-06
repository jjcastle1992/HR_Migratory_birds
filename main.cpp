#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    int typeOneCount = 0;
    int typeTwoCount = 0;
    int typeThreeCount = 0;
    int typeFourCount = 0;
    int typeFiveCount = 0;
    int highestFrequencyType = 0;
    int typeFrequencies [5];
    int minType = 0;

    //Look at the array of "birds".
    for (int i = 0; i < arr.size(); i++) {
        //Set a counter for each of the 5 types
        int currentType = 0;
        currentType = arr[i];
        switch (currentType) {
            case 1:
                typeOneCount++;
                break;
            case 2:
                typeTwoCount++;
                break;
            case 3:
                typeThreeCount++;
                break;
            case 4:
                typeFourCount++;
                break;
            case 5:
                typeFiveCount++;
                break;
            default:
                std::cout << "ERROR: Type does not match allowed values [1-5]" << std::endl;
                break;
        }
    }

    //Compare counts of the 5 types. The type with the highest counts should be returned.
    //Since lowest with highest count should be returned, start with 5, and compare descending.

    //load the results into an ordered array with type 1 at index 0 and type 5 at index 4.
    typeFrequencies[0] = typeOneCount;
    typeFrequencies[1] = typeTwoCount;
    typeFrequencies[2] = typeThreeCount;
    typeFrequencies[3] = typeFourCount;
    typeFrequencies[4] = typeFiveCount;

    //If two types have the same count, return the lowest type.
    for (int j = 4; j >= 0; j--) {
        if (typeFrequencies[j] >= minType) {
            minType = typeFrequencies [j];
            highestFrequencyType = j + 1; //Adjusted so the type matches (1 index) matches the array index (0 index)
        }
    }

    return highestFrequencyType;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));
    if (arr_count >= 5 && arr_count <= 2e5) {
        vector<int> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);
            if (arr_item >= 1 && arr_item <= 5) {
                arr[i] = arr_item;
            }
        }

        int result = migratoryBirds(arr);

        fout << result << "\n";
    }

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
