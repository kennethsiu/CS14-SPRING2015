#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void do_work(string command, unsigned &place)
{
    vector<string> executable; //vector to hold all executables passed in a line
    vector<string> argumentlist;//vector to hold all arguments passed in a line
    vector<string> connectorCMD;//vector to hold all connectors passed in a line
    
    // parsing the user input in while loop
    while(place < command.size())
    {
        
        string Executable; // holds all executables
        string Argumentlist; // holds all arguments
        string ConnectorCMD; // holds all connectors
        //get rid of leading whitespace
        while((place < command.size()) && (command[place] == ' '))
        {
            place++;
        }
        
        //get executable
        if((place < command.size()) && command[place] != '#')
        {
            for(unsigned i = place; i < command.size() && CHKSp(command, i); i++)
            {
                Executable.push_back(command.at(i));
                place++;
            }
        }
        //goes over the extra space
        while((place < command.size()) && (command[place] == ' '))
        {
            place++;
        }
        
        //check if we are at end of command entered if not accept more
        //add into argument list
        if( place <  command.size())
        {
            if((command.at(place)!= ' ') && CHK(command, place))
            {
                for(unsigned i = place; (i < command.size()) && CHK(command, i); i++)
                {
 
                    // Argumentlist.push_back(command.at(i));
                    place++;

                    
                    //check if inside quotes ""
                    if ((i < command.size()) && (command.at(i) ==  '\"'))
                    {
                        i++;
                        while((i < command.size()) && (command.at(i) != '\"'))
                        {
                            Argumentlist.append(command,i,1);
                            i++;
                            place++;
                        }
                        if(i < command.size())
                        {
                            // Argumentlist.append(command,i,1);
                            place ++;
                            i++;
                        }
                    }
                    if(i < command.size())
                    {
                        Argumentlist.push_back(command.at(i));
                    }
                    
                }
            }
        }
    }
    
}

void rshell()
{
   string command;
   while (command != "exit")
   {
        //1. Print a command prompt (e.g. $)
        cout << "$ ";
        
        //2. Read in a command on one line. Commands will have the form
        getline(cin, command);
        unsigned place = 0;
        
        do_work(command, place);
    }
}

int main()
{
    rshell();
    return 0;
}