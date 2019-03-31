//
// Created by vhund on 25.03.2019.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_ROAD_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_ROAD_H


class road {
private:
    struct connectedRoads {
        int aRoadNum=0,bRoadNum=0;
        struct connectedRoads *next = nullptr;
    };
    typedef connectedRoads *connectedRoad;
    road *startPoint;
    road *endPoint;

public:
    int roadNum;
    bool isRailroad;
    unsigned int length;

    connectedRoad add(connectedRoad begin, road road);

    void deleteRoad(connectedRoad begin);

    void editRoad(connectedRoad);

    void showRoad(connectedRoad , bool);
};


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_ROAD_H
