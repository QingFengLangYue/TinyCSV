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
        const TinyCSV c_csv(csv);
        string str = c_csv[1][1];

        csv[2][2] = std::to_string(csv.getInt(2, 2) + 20);  // add 20

        cout << "getString(0,2):" << csv.getString(1, 2) << endl;

        cout << "getInt(1,2):" << csv.getInt(1,2) << endl;
        csv.setInt(1, 2, csv.getInt(1,2) + 100);
        cout << "getInt(1,2):" << csv.getInt(1,2) << endl;

        cout << "getFloat(2,2):" << csv.getFloat(2,2) << endl;
        csv.setFloat(2, 2, csv.getFloat(2, 2) + 50);
        cout << "getFloat(2,2):" << csv.getFloat(2,2) << endl;


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

