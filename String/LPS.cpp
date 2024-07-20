vector<int> LPS(string &text, string &pattern){
    string s;
    s += pattern;
    s += "$";
    s += text;
    int n = s.size();
    vector<int>lps(n);
    for(int i{1};i<n;i++){
        int prevInd = lps[i-1];
        while(prevInd > 0 && s[i] != s[prevInd]){
            prevInd = lps[prevInd-1];
        }
        lps[i] = prevInd + (s[i] == s[prevInd]);
    }
    return lps;
}

// prevInd is provinding length of proper prefix which is also suffix at index i for lps[i] as character we want to match (as we are using 0 based indexing)

// abababd
// ababd#abababd

// [0, 0, 1, 2, 0, 1, 2, 3, 4, ]