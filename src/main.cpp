#include <iostream>
#include "logging.cpp"
#include "config.cpp"
#include "sudoku.cpp"

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

    sudoku sudoku1(9);
    sudoku1.set_knowns("100000000000000000000000000000000000400000000000000000000000000000000000000000000");
    sudoku1.set_knowns(2,2,8);
    sudoku1.set_knowns(3,5,7);
    sudoku1.remove_all_known_options();
    exit_system();
}