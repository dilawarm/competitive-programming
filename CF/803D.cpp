/*
D. Magazine Ad
*/
#include <bits/stdc++.h>
using namespace std;

bool total_lines(int len, int k, vector<int> &word_len)
{
    int lines = 1;
    int len_counter = 0;
    for (size_t i = 0; i < word_len.size(); ++i)
    {
        if (word_len[i] > len)
            return false;

        len_counter += word_len[i];
        if (len_counter > len)
        {
            ++lines;
            len_counter = word_len[i];
        }
    }
    return lines <= k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    string line;
    getline(cin, line);
    getline(cin, line);

    vector<int> words_len;
    int curr_len = 0;
    for (size_t i = 0; i < line.size(); ++i)
    {
        ++curr_len;
        if (line[i] == ' ' || line[i] == '-')
        {
            words_len.push_back(curr_len);
            curr_len = 0;
        }
    }
    words_len.push_back(curr_len);

    int l = 0, r = 1e5;
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (total_lines(mid, k, words_len))
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l << "\n";

    return 0;
}
