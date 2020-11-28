#include "../include/helper_functions.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string x = "hellooo";
    string * v = split(x, ' ');
    cout << v[0] << v[1] << endl;
    return 0;
}