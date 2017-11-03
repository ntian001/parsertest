#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void parse(string str)
{
    
    cout << "We will be parsing: \n\"" << str << "\"\n\n";
    
    // connectors we're concerned with, # is different so it's not included
    vector<string> connector{"&&", "||", ";"};
    
    // the vector containing connectors and commands, respectively
    vector<string> con;
    vector<string> cmd;
    // string that stores the current connector, if the string has one
    string current;
    
    // tries to find the first instance of #
    size_t pos = str.find("#");
    if(pos != string::npos)
    {
        // if found, then keep everything before the # and throw away everything else
        cout << "Found a \"#\" at index " << pos << ", removing everything after.\n";
        str = str.substr(0, pos);
        cout << "We will be parsing: \n\"" << str << "\"\n\n";
    }
    // reset pos just in case
    pos = 0;
    
    // set up a bool that will return true when str has one of the specified connectors
    bool connector_found = true;
    while(connector_found)
    {
        // stores positions of the three connectors, order is the same as the connector vector above
        // &&, ||, ;
        vector<int> positions{-1, -1, -1};
        // find the first occurence of &&, ||, and ; (will be -1 if not found)
        for(int i = 0; i < positions.size(); ++i)
        {
            positions.at(i) = str.find(connector.at(i));
        }
        // checks if all of the positions are -1
        // if they are, then there are no connectors and the loop needs to stop
        if (all_of(positions.begin(), positions.end(), [](int i){return i==-1;}) )
        {
            cout << "Connector not found. Ending process.." << endl;
            cmd.push_back(str);
            connector_found = false;
            break;
        }
        
        // now finds the first occurence of all three (smallest positive number in the vector)
        int place = 0;
        int min = INT_MAX;
        for(int i = 0; i < positions.size(); ++i)
        {
            if(positions.at(i) >= 0 && positions.at(i) < min)
            {
                min = positions.at(i);
                place = i;
            }
        }
        // fair warning: lots of text output here to make the process clearer
        // if we found a connector, identify it and save into current
        current = connector.at(place);
        cout << "Found a connector: \"" << current << "\"\n";
        // find where the connector is
        pos = str.find(current);
        // displays length of connector and where it is in the string
        cout << "\"" << current << "\" is " << current.length() << " characters long, found at index " << pos << endl;
        
        // push_back the command before connector into cmd
        cout << "Adding \"" << str.substr(0, pos) << "\" to commands.." << endl;
        cmd.push_back(str.substr(0, pos));
        
        // push_back the connector itself into con
        cout << "Adding \"" << str.substr(pos, current.length()) << "\" to connectors.." << endl;
        con.push_back(str.substr(pos, current.length()));
        
        // delete everything before the first connector found and the connector itself
        // (we already saved the command and connector earlier, no need to keep)
        str.erase(0, pos + current.length());
        cout << endl;
    }
    // print out the entire cmd vector, separated by four spaces per command
    cout << endl << endl;
    cout << "Printing cmd (commands): \n";
    for(int i = 0; i < cmd.size(); ++i)
    {
        cout << "\"" << cmd.at(i) << "\"    ";
    }
    // same with the con vector for connectors
    cout << "\nPrinting con (connectors): \n";
    for(int i = 0; i < con.size(); ++i)
    {
        cout << "\"" << con.at(i) << "\"    ";
    }
    cout << endl;
    return;
}

int main()
{
    // the string that we're going to pass in to parse
    // this will be changed into an actual string later
    string str = "";
    // string str = "ls -a && git status || cd ..; echo hello # comments";
    bool start = true;
    int choice = 0;
    while(start)
    {
        cout << "Type 1 for manual input, 2 for preset string: ";
        cin >> choice;
        // manually input a string
        if(choice == 1)
        {
            start = false;
            cout << "Enter your string: ";
            cin.ignore();
            getline(cin, str);
            parse(str);
        }
        // use the preset string (defined in this else if branch)
        else if(choice == 2)
        {
            start = false;
            str = "; this || is && a ; command # but now # this is where the comments && are";
            // alternate test case
            // str = "command 1&& command 3; yes || command 4 | ; & another command @&& 3";
            cout << "Using preset string: \"" << str << "\"";
            cout << endl;
            parse(str);
        }
        else
        {
            cout << "Try again.\n";
        }
    }
    
    
    return 0;
}


// old code, used to find a separator one at a time (pound in this case)
/*
    string s = "";
    string pound = "#";
    getline(cin, s);
    cout << s << endl;
    size_t pos = 0;
    vector<string> token;
    while ((pos = s.find(pound)) != std::string::npos)
    {
        token.push_back(s.substr(0, pos));
        s.erase(0, pos + pound.length());
    }
    for(int i = 0; i < token.size(); ++i)
    {
        cout << token.at(i) << ' ';
    }
    cout << endl;
    */
    
    
// old code, could find the first occurence of all three but gives priority to && then || then ;
/*
// use iterator it to find the first occurrence of &&, || or ;
        // VERY IMPORTANT: this was taken from the stackoverflow link down below
        // https://stackoverflow.com/questions/19952155/pass-multiple-strings-to-the-stringfind-function
        auto it = find_if(begin(connector), end(connector),
                      [&](const string& s)
                      {
                          return str.find(s) != std::string::npos;
                      });
                      
        // if there are no occurences, stop immediately, put the entire string as one element in cmd, quit the loop
        if(it == connector.end())
        {
            cout << "No connectors found, treating entire string as one command." << endl;
            cmd.push_back(str);
            connector_found = false;
            break;
        }
        */