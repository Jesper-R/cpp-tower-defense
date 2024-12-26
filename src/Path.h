//
// Created by Jespe on 2024-12-15.
//

#ifndef PATH_H
#define PATH_H
#include <string>


class Path {
    std::string pathName;
    std::string pathType;

public:
    Path(std::string pathType);
    Path(std::string pathType, std::string pathName);
    std::string getPathName();
    std::string getPathType();

};



#endif //PATH_H
