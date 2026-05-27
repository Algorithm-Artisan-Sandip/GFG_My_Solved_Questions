// User function Template for C++

/*
str: string containing english alphabet letters
*/
bool checkPangram(string &s) {
    vector<int> track(26, 0);
    for(auto i=0; i<s.size(); i++) {
        if(islower(s[i])) track[s[i]-'a'] = 1;
        else track[s[i]-'A'] = 1;
    }
    return accumulate(track.begin(), track.end(), 0) == 26;
}
