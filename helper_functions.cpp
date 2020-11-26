#include <string>
#include <algorithm>
std::string removeSpaces(std::string x)
{
    x.erase(remove(x.begin(), x.end(), ' '), x.end()); 
    return x;
}

std::string * split(std::string x, const char * splitter)
{
    int pos = x.find(splitter);
    std::string * ret_val  = new std::string[2]; 
    if(pos != std::string::npos)
    {
        ret_val[0] = x.substr(0, pos);
        ret_val[1] = x.substr(pos+1);
    }
    else
    {
        ret_val[0] = x.erase(x.size()-1);
        ret_val[1] = std::string(" ");
    }
    return ret_val;
}

