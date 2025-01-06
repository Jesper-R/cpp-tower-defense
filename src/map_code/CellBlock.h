#ifndef PATH_H
#define PATH_H

#include <string>
using namespace std;

class CellBlock {
    string pathName;
    string pathType;
public:
    CellBlock();
    CellBlock(string pathType);
    CellBlock(string pathType, string pathName);
    string getPathName() const;
    string getPathType() const;
};

#endif //PATH_H
