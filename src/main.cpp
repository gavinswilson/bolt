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
    logging mainlog("mainlog5");
    mainlog.write_to_main_log("Starting System");
    
    config conf;
    conf.load_config();
    

    exit_system();
}