//
// Created by Jespe on 2024-12-15.
//

#ifndef PATH_H
#define PATH_H
#include <string>


class CellBlock {
    std::string pathName;
    std::string pathType;

public:
    CellBlock(std::string pathType);
    CellBlock(std::string pathType, std::string pathName);
    std::string getPathName();
    std::string getPathType();

};



#endif //PATH_H
