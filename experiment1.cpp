#include <iostream>
#include <map>
using namespace std;

void opt(string inp) {
    map<char, string> opterator= {{
        '+', "Addition"},
        {'-', "Subtraction"},
        {'*', "Multiplication"},
        {'/', "Division"},
        {'%', "Modulus"},
        {'=', "Equal"},
        };

        int x=1;
        for (int i = 0; i < inp.length(); i++)
        {
            if (opterator.find(inp[i]) != opterator.end())
            {
                cout << "Operator " << x << ": " << inp[i]<<" (" << opterator[inp[i]] << ")" << endl;
                x++;
            }
        }
    }


void check(string yo)
{
    bool flag = false;
    for (int i = 0; i < yo.length(); i++)
    {
        if (yo[i] < '0' || yo[i] > '9')
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        cout << "Not numeric" << endl;
    }
    else
    {
        cout << "numeric constant" << endl;
    }
}
void commnt(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == 47 && i+1 < x.length() && x[i + 1] == 47)
        {
            cout << "Single Line Comment" << endl;
            break;
        }
        else if (x[i] == 47 && i+1 < x.length() && x[i + 1] == 42)
        {
            cout << "Multi Line Comment" << endl;
            break;
        }
    }
    cout << "Not a comment" << endl;
}

void valid(string w)
{
    int d=0;
    int end = w.length()-1;

    while (w [d] == 32 && d <= w.length()-1) {
        d++;
    }
    while (w [end] == 32 && end >= 0) {
        end--;
    }

    bool flag = true;
    if (end < 0) {
        flag = false;
    }
     else{
        if (w[d]>=48 && w[d]<=57) {
            flag = false;
        }
        for (int i=0;i<=end && flag;i++){
            if(w[i]==32){
                flag = false;
                break;
            }
            if (!((w[i]>=48 && w[i]<=57) || (w[i]>=65 && w[i]<=90) || (w[i]>=97 && w[i]<=122) || w[i]==95)) {
                flag = false;
                break;
            }
        }
     }
     if (flag) {
        cout << "Valid identifier" << endl;
     }
        else {
            cout << "Invalid identifier" << endl;
        }
}
int main()
{
    cout<<int(' ')<< ":";
    string n;
    cout << "Enter your txt :";
    cin >> n;
    check(n);
    cout<<"Drop the Math here: ";
    cin>>n;
    opt(n);
    cout<<"Drop the comment here: ";
    cin>>n;
    commnt(n);
    cout<<"Drop the identifier here: ";
    cin>>n;
    valid(n);
    
}