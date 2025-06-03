// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    freq = { T: 1, E: 1, A: 1, C: 1, H: 1}
    word = CHEAT
    input = "TRAIT"
    result = {B, B, B, B, B}
    step1, 2:
        result = {G, B, B, B, B}
    step 3: 
        freq = { T: 0, E: 1, A: 0, C: 1, H: 1}
        result = {G, B, G, B, B}
n = lengthOfString
TC: O(n)
SC: O(n)
*/
class WordFinder
{
    string wordOftheDay = "TEACH";
    unordered_map<char, int> freq;
public:
    WordFinder()
    {
        calculateFreq();   
    }
    
    void calculateFreq()
    {
        for (char c: wordOftheDay) freq[c] ++;
    }
    
    vector<string> matchWord(string input)
    {
        vector<string> result (5, "BLACK");
        unordered_map<char, int> freqCopy = freq;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == wordOftheDay[i])
            {
                result [i] = "GREEN";
                freqCopy[wordOftheDay[i]]--;
            }
        }
        
        for (int i = 0; i < input.length(); i++)
        {
            if (result[i] == "BLACK" and freqCopy[input[i]] > 0)
            {
                result[i] = "RED";
                freqCopy[input[i]]--;
            }
        }
        
        return result;
    }
    
};

int main() {
    // Write C++ code here
    
    WordFinder* obj = new WordFinder();
    vector<string> display;
    display = obj->matchWord("TRAIT");
    for (string s: display)
    {
        cout << s << endl;
    }

    return 0;
}
