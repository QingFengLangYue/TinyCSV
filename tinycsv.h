#ifndef TINYCSV_H
#define TINYCSV_H
#include <string>
#include <vector>

class TinyCSV
{
public:
    TinyCSV();
    /**
     * @brief TinyCSV
     * load csv file specified by "filename".
     * if load sucessfully isValid() return true,else return false.
     *
     * @param filename
     */
    TinyCSV(const std::string &filename);

    /**
     * @brief load
     * read csv file specified by "filename" and save data in "_data".
     *
     * @param filename
     * csv filename with absolute or relative path.
     *
     * @return
     * true - if load sucessfully, and isValid() return true.
     * false - load failed, and isValid() return false.
     */
    bool load(const std::string &filename);
    bool save(const std::string &filename = "", const char delimiter = ',');
    bool isValid() {return _isValid;}
    int  rowCount() {return _data.size();}
    int  colCount() {return _data[0].size();}

    std::vector<std::string> &operator[](int row);


protected:
    bool init();

private:
    std::vector<std::vector<std::string> > _data;
    std::string _filename;
    bool        _isValid;
};


#endif // TINYCSV_H
