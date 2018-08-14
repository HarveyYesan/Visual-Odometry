#ifndef MAPPOINT_H
#define MAPPOINT_H

#include "common.h"

namespace vo
{

class Frame;
class MapPoint
{
public:
    typedef std::shared_ptr<MapPoint> Ptr;
    MapPoint();
    MapPoint(long id, Eigen::Vector3d position, Eigen::Vector3d norm);

    // factory function
    static MapPoint::Ptr createMapPoint();

private:
    // id of the mappoint
    unsigned long id_;
    // position in the world
    Eigen::Vector3d pose_;
    // normal of viewing direction
    Eigen::Vector3d norm_;
    // descriptor of matching point
    cv::Mat descriptor_;
    // being observed by feature matching algorithm
    int observed_times_;
    // being an inliner in pose estimation
    int correct_times_;

}

}

#endif // MAPPOINT_H

