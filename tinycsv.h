#ifndef TINYCSV_H
#define TINYCSV_H
#include <string>
#include <vector>
#include <assert.h>

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

    inline bool isValid()  const {return _isValid;}
    inline int  rowCount() const {return _data.size();}
    inline int  colCount() const {return _data[0].size();}

    int   getInt(int row, int col) const;
    float getFloat(int row, int col) const;
    inline std::string getString(int row, int col) const { return _data[row][col];}
    inline void  setInt(int row, int col, int value) { _data[row][col] = std::to_string(value);}
    inline void  setFloat(int row, int col, float value) { _data[row][col] = std::to_string(value);}
    inline void  setString(int row, int col, std::string value) { _data[row][col] = value;}

    inline std::vector<std::string> &operator[](int row) { return _data[row];}
    inline const std::vector<std::string> &operator[](int row) const { return _data[row];}

protected:
    bool init();

private:
    bool isNum(const std::string &strNum) const;

private:
    std::vector<std::vector<std::string> > _data;
    std::string _filename;
    bool        _isValid;
};

#endif // TINYCSV_H
