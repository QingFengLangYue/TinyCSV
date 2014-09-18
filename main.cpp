#include <iostream>
#include "tinycsv.h"

using namespace std;

int main()
{

    /* load and print content */
    TinyCSV csv("test.csv");
    if (csv.isValid())
    {
        for (int i = 0; i < csv.rowCount(); ++i)
        {
            for (int j = 0; j < csv.colCount(); ++j)
            {
                cout << csv[i][j] << " ";
            }
            cout << endl;
        }

        /* modify */
        csv[1][2] = "70";
        csv[2][2] = std::to_string(std::stoi(csv[2][2]) + 20);  // add 20

        /* save */
        if (csv.save("test.csv"))
        {
            cout << "save ok" << endl;
        }
    }

    /* load and read */
    TinyCSV csv2;
    if (csv2.load("test2.csv"))
    {
        // do something...
    }

    return 0;
}

