#include <iostream>
#include <bitset>

class sudoku
{
    public:
        int size = 9;
        unsigned short int options[9][9];
        unsigned short int soln[9][9];
        unsigned short int boxes[9][9];

        sudoku(int gridsize)
        {
            size=gridsize;
            reset_options();
            set_boxes("std");
            //print_arrays(0);
            //print_arrays(1);
            //print_arrays(2);
        }

        int set_boxes(std::string type)
        {
            if (type == "std")
            {
                std::string list="111222333111222333111222333444555666444555666444555666777888999777888999777888999";
                int listlen = list.length();
                int x,y,i;
                i=0;
            
                for (x=0;x<size; x++)
                {
                    for (y=0; y<size; y++)
                    {
                        boxes[x][y] = list[i]-48;
                        i++;
                    }
                }
            }
            print_arrays(3);
            return 0;
        }

        int reset_options()
        {
            int x,y;
            for (x=0;x<size; x++)
            {
                for (y=0; y<size; y++)
                {
                    options[x][y] = 511;
                }
            }
            return 0;
        }

        int set_knowns(std::string list)
        {
            int listlen = list.length();
            int x,y,i;
            i=0;
            
            for (x=0;x<size; x++)
                {
                for (y=0; y<size; y++)
                    {
                        soln[x][y] = list[i]-48;
                        i++;
                    }
                }
            print_arrays(1);
            return 0;
        }
        
        int set_knowns(int r, int c, int val)
        {
            soln[r-1][c-1] = val;
            print_arrays(1);
            return 0;
        }

        int remove_all_known_options()
        {
            int x,y,p,q,b,k;
            for (x=0; x<size; x++)
            {
                for (y=0;y<size; y++)
                {
                    if(soln[x][y] == 0)
                    {
                        //remove_option(x,y,4);
                    }
                    else
                    {
                        b = boxes[x][y];
                        k = soln[x][y];
                        for (p=0; p<size; p++)
                        {
                            for (q=0;q<size; q++)
                            {
                                if (p==x || q==y || b==boxes[p][q])
                                {
                                    remove_option(p,q,k);
                                }
                            }
                        }    
                    }    
                }
            }
            print_arrays(2);
            return 0;
        }
        
        int remove_option(int row, int col, int opt)
        {
            options[row][col] = options[row][col]^(1<<(opt-1));
            return 0;
        }

        int print_arrays(int choice)
        {
            int x,y;
            std::cout << "---------------" << std::endl;
            for (x=0;x<size; x++)
            {    
                std::cout << "| ";
                for (y=0; y<size; y++)
                {
                    switch(choice)
                    {
                        case 0:
                            {
                                std::cout << options[x][y] << " ";
                                break;
                            }
                        case 1:
                            {
                                if (soln[x][y] == 0)
                                {
                                    std::cout << " " << " ";
                                }
                                else
                                {
                                    std::cout << soln[x][y] << " ";
                                }
                                break;
                            }
                        case 2:
                            {
                                std::cout << std::bitset<16>(options[x][y]) << " ";
                                break;
                            }   
                        case 3:
                            {
                                std::cout << boxes[x][y] << " ";
                                break;
                            }    
                        default:
                            {
                                std::cout << options[x][y] << " ";
                            }
                    }
                }                
                std::cout << "|" << std::endl;
            }
            std::cout << "---------------" << std::endl; 
            return 0;
        }
    //private:
        //stuff
};