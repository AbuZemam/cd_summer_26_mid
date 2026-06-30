#include <iostream>
#include <string>   
using namespace std;


bool isNumeric(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!(input[i] >= 48 && input[i] <= 57)) {
            return false;
        }
    }
    return true;
}

bool isString(string input) {
    if (input.length() >= 2 && input[0] == '"' && input[input.length() - 1] == '"') {
        return true;
    }
    return false;
}

bool isValidIdentifier(string str) {
    if (str.empty() || (str[0] >= 48 && str[0] <= 57)) {
        return false;
    }
    for (int i = 0; i < str.length(); i++) {
        if (!((str[i] >= 65 && str[i] <= 90) ||
              (str[i] >= 97 && str[i] <= 122) ||
              (str[i] >= 48 && str[i] <= 57) ||
               str[i] == 95)) {
            return false;
        }
    }
    return true;
}
void detect(string token) {
	string keywords[] = {"cout", "endl", "return"};
    string operators[] = {"+", "-", "*", "/", "<<", ">>" };
    char punctuation[] = {';', ',', '(', ')', '{', '}'};

    for (string kw : keywords) {
        if (token == kw) {
            cout << token << " -> Keyword" << endl;
            return;
        }
    }

    for (string op : operators) {
        if (token == op) {
            cout << token << " -> Operator" << endl;
            return;
        }
    }
    if (token.length() == 1) {
        for (char p : punctuation) {
            if (token[0] == p) {
                cout << token << " -> Punctuation" << endl;
                return;
            }
        }
    }
 
    if (isNumeric(token)) {

		cout << token << " -> Numeric Constant" << endl;

		return;

	}
 
    if (isValidIdentifier(token)) {
		cout << token << " -> Identifier" << endl;
		return;
	}
 
    if (isString(token)) {

    	cout << token << " -> String" << endl;

		return;

    }
	cout << token << " -> Unknown Token" << endl;
 
}


void tokenization(string s) {
    int start = 0;
    int i = 0;

    while (i < s.length()) {
        if (s[i] == ' ') {
            detect(s.substr(start, i - start));
            start = i + 1;
        }
        i++;
    }
    if (start < s.length()) {

		detect(s.substr(start));

    }
}





int main() {


string z;
cout << "Input: ";
getline(cin, z);
    tokenization(z);
    return 0;

}