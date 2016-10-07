#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>


void printData (T data)
{
    // cin >> "insert your data here: " >> data;
    cout  << "You inserted either a beautiful double or a shiny float with value: " << data << endl;

}


template <>
void printData(int i)
{
    cout << "HolyMoly! What a nice integer: " << i << endl;
}

template <>
void printData(string s)
{
    cout << "Wow! Look at that string: " << s << endl;
}


int main()
{
    int i;
    string s;
    float f;
    double d;

    string typus;

    cout << "what type would you like to enter? Please specify here: \n";
    cin >> typus;

    while ((typus != "string") && (typus != "int") && (typus != "double") && (typus != "float"))
    {
        cout << "Oups! I don't recognize this type, please enter another: ";
        cin >> typus;
    }

    cout << "please enter of the previously specified type: \n";

    if (typus == "string")
    {
        cin >> s;
        printData(s);
    }
    else if (typus == "int")
    {
        cin >> i;
        printData(i);
    }
    else if (typus == "double")
    {
        cin >> d;
        printData(d);
    }
    else if (typus == "float")
    {
        cin >> f;
        printData(f);
    }
}