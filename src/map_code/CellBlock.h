#ifndef PATH_H
#define PATH_H

#include <string>
using namespace std;

class CellBlock {
    string pathName;
    string pathType;
public:
    CellBlock(string pathType);
    CellBlock(string pathType, std::string pathName);
    string getPathName();
    string getPathType();
};

#endif //PATH_H
