#include <memory>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "tinycsv.h"
using namespace std;

TinyCSV::TinyCSV():
    _filename(""),
    _isValid(false)
{
}

TinyCSV::TinyCSV(const string &filename):
    _filename(filename),
    _isValid(false)
{
    // save init() result in _isValid
    _isValid = init();
}

bool TinyCSV::load(const string &filename)
{
    _filename = filename;
    _isValid = init();
    return _isValid;
}

bool TinyCSV::save(const string &filename, const char delimiter)
{
    std::string savepath = filename.empty() ? _filename : filename;

    if (savepath.empty())
        return false;

    fstream outfs(savepath, ios_base::out | ios_base::trunc);
    if (outfs.is_open())
    {
        for (const auto &row : _data)
        {
            string line;
            for (const auto &col : row)
            {
                line += col + delimiter;
            }
            // remove the last redundant delimiter
            line.erase(std::prev(line.end()), line.end());
            outfs << line;
            outfs << endl;
        }
        outfs.close();
        return true;
    }
    outfs.close();
    return false;
}


vector<string> &TinyCSV::operator[](int row)
{
    return _data[row];
}

bool TinyCSV::init()
{
    if (_filename.empty())
        return false;

    std::fstream infs(_filename, std::ios_base::in);
    if (infs.is_open())
    {
        std::string line;
        // save the max column count
        int maxCol = 0;
        while (std::getline(infs, line))
        {
            int curCol = 0;
            std::vector<std::string> array;
            std::stringstream in(line);
            std::string word;
            while(std::getline(in, word, ','))
            {
                array.push_back(word);
                curCol += 1;
            }
            _data.push_back(array);
            maxCol = std::max<int>(maxCol, curCol);
        }
        infs.close();

        // resize each array to the same length
        for (auto &vec : _data)
            vec.resize(maxCol, "");

        return true;
    }

    infs.close();
    return false;
}


