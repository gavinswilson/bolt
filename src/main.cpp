#include <iostream>
#include "logging.cpp"
#include "config.cpp"

int exit_system()
{
    std::cout << "Exiting" << std::endl;
    exit(0);
}




int main()
{
    
    std::cout << "Starting System" << std::endl;


    logging log;
    //log.write_to_main_log();
    config conf;
    conf.load_config();

    exit_system();
}