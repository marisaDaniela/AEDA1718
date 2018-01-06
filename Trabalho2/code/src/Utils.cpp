#include "Utils.hpp"

void trim(string &str) {
    int i = 0;
    int spacesBegin = 0;
  
    while (' ' == str[i++]) {
        spacesBegin++;
    }
    
    i = str.length();
    
    int spacesEnd = 0;
    
    while (' ' == str[--i]) {
        spacesEnd++;
    }
    int strLength;
    
    strLength = str.length() - spacesBegin - spacesEnd;
    
    str = str.substr(spacesBegin, strLength);
}

void pressKeyToContinue() {
    cout << "\n\nPressione enter para continuar.\n";
    
    cin.ignore();
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int read_number_Input() {
    string input;
    int option;
    getline(cin, input);
    
    if (!is_number(input) || 0 == (option = atoi(input.c_str())) ) { throw invalid_argument(input);}
    return option;
}

bool lessThan(string d1, string d2){
    stringstream ss;
    int data1;
    int data2;
    
    ss<<d1[6];
    ss<<d1[7];
    ss<<d1[8];
    ss<<d1[9];
    
    ss<<d1[3];
    ss<<d1[4];
    
    ss<<d1[0];
    ss<<d1[1];
    
    ss >> data1;
    
    ss.str(string());
    ss.clear();
    
    ss<<d2[6];
    ss<<d2[7];
    ss<<d2[8];
    ss<<d2[9];
    
    ss<<d2[3];
    ss<<d2[4];
    
    ss<<d2[0];
    ss<<d2[1];
    
    ss >> data2;
    
    ss.str(string());
    ss.clear();
    
    if(data1<data2){
        return true;
    }
    
    else {
        return false;
    }
}
