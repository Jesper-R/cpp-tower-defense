#ifndef PATH_H
#define PATH_H

#include <string>
#include <vector>
using namespace std;

struct BlockOdds {
    int odds;
    string blockName;
};

class CellBlock {
    string blockName;
    string blockType;
    vector<BlockOdds> odds = {
        {80, "flowers_1"},
        {80, "flowers_2"},
        {5, "pond"},
        {5, "stone"},
        {700, "grass"}
    };

public:
    ~CellBlock();
    CellBlock();
    CellBlock(string blockType);
    CellBlock(string blockType, string blockName);
    string getBlockName() const;
    string getBlockType() const;
};

#endif //PATH_H
