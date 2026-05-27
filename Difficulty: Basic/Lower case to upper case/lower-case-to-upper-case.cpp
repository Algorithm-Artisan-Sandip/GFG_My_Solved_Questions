
string to_upper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}