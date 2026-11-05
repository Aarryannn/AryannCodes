class Solution {
public:
    bool isValid(string k) {
        stack <char> s;
        string beg = "([{";
        string end = ")]}";
        for(char c : k){
        //    for beigning
        if(beg.contains(c)) s.push(c);
        else{
            if(s.empty() == true) return false;

            if( s.top() == '(' && c == ')' || 
                s.top() == '[' && c == ']' || 
                s.top() == '{' && c == '}' 
            ) s.pop();
            else return false;
        }}
        return s.empty() == true;
    }
};