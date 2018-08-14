#ifndef MAP_H
#define MAP_H

#include "frame.h"
#include "mappoint.h"

namespace vo
{

class Map
{
public:
    typedef std::shared_ptr<Map> Ptr;
    Map();

    // manage keyframe and mappoint
    void insertKeyFrame(Frame::Ptr frame);
    void insertMapPoint(MapPoint::Ptr map_point);

private:
    // all keyframes
    std::unordered_map<unsigned long, Frame::Ptr> keyframes_;
    // all landmarks
    std::unordered_map<unsigned long, MapPoint::Ptr> map_points;
};

}

#endif // MAP_H

