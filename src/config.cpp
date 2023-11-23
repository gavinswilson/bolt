#include <iostream>

class config
{
    public:
        int numcells;
        int stuff;

        void load_config()
        {
            std::cout << "Loading Configuration" << std::endl;
        }
}