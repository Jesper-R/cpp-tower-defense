#ifndef MANAGER_H
#define MANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

template <typename T>
class Manager {
    vector<shared_ptr<T>> objects;
public:
    void addObject(shared_ptr<T> object) {
        objects.push_back(object);
    }

    void removeObject(shared_ptr<T> object) {
        objects.erase(remove(objects.begin(), objects.end(), object), objects.end());
    }

    vector<shared_ptr<T>> getObjects() const {
        return objects;
    }

    shared_ptr<T> findObject(const T& target) const {
        for (const auto& object : objects) {
            if (*object == target) {
                return object;
            }
        }
        return nullptr;
    }
};

#endif //MANAGER_H
