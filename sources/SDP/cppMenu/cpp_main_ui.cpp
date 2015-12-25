#include "cpp_main.h"

void ui()
{
    int way;
    cout <<"Choose a task:" <<endl;
    cout <<"1. Summ of digits." <<endl;
    cout <<"2. Search for multiples." <<endl;
    cout <<"3. Reversion of given number." <<endl;
    //cout <<"4. Matrix turn.";
    //cout <<"5. Search of text constructs." <<endl;
    cout <<"6. Unlimited integers." <<endl;
    cout <<"0. Exit" <<endl;
    cout <<"Your choice: ";
    cin >>way;
    if (cin.fail())
    {
        puts("Error. Wrong input data type.\n");
        ui();
        system("cls");
    }
    else
    {
        switch(way)
        {
            case 0:
            {
                system("cls");
                break;
            }
            case 1:
            {
                system("cls");
                cpp_sum_of_digits_inp inp1;
                inp1.cpp_number_inp();
                ui();
                break;
            }
            case 2:
            {
                system("cls");
                cpp_multiples_inp inp2;
                inp2.cpp_numbers_inp();
                ui();
                break;
            }
            case 3:
            {
                system("cls");
                cpp_reversed_num_inp inp3;
                inp3.cpp_number_inp();
                ui();
                break;
            }
            /*case 4:
                system("cls");
                c_matrix_turn_ui();
                break;
            case 5:
                system("cls");
                c_keys_in_text_ui();
                break;*/
            case 6:
            {
                system("cls");
                cpp_int_unlim_inp inp6;
                inp6.cpp_iu_inp();
                ui();
                break;
            }
            default:
            {
                system("cls");
                puts("\nError.There's no such task.\n");
                ui();
                break;
            }
        }
    }
}
