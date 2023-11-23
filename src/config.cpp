#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class config
{
    public:
        int numcells;
        int stuff;
        std::string filename = "config/main.cfg";

        void load_config()
        {
            std::cout << "Loading Configuration" << std::endl;
            
            std::ifstream cFile (filename);
            if (cFile.is_open())
            {
                std::string line;
                while(getline(cFile, line))
                {
                    line.erase(std::remove_if(line.begin(), line.end(), isspace),line.end());
                    if( line.empty() || line[0] == '#' )
                        {
                            continue;
                        }
                    auto delimiterPos = line.find("=");
                    auto name = line.substr(0, delimiterPos);
                    auto value = line.substr(delimiterPos + 1);
                    std::cout << name << " " << value << '\n';
                }
                cFile.close();
            }
            else 
            {
                std::cerr << "Couldn't open config file for reading.\n";
            }
        }
};