//
// Created by vhund on 25.03.2019.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_CITY_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_CITY_H

#include <string>
#include "road.h"

using namespace std;

class city {

private:
    struct roads {
        road road;
        struct roads *next = nullptr;
    };
    typedef roads *Roads;
public:
    string name;

    Roads add(Roads begin, road road);

    void deleteRoad(Roads begin);

    void editRoad(Roads);

    void showRoad(Roads, bool);
};


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_CITY_H
