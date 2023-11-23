#include <iostream>
#include <string>
#include <fstream>

class logging
{
    public:
        std::string logdir = "logs";
        std::string filename;
        std::string loginstance;

        logging(std::string loginst)
        {
            loginstance = loginst;
            filename = logdir + "/" + loginstance + ".log";
        }
        
        void write_to_main_log(std::string logtext)
        {
            std::ofstream out(filename, std::ios_base::app);
            out << logtext;
            out << std::endl;
            out.close();
        }
};