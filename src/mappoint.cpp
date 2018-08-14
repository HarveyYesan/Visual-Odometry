#include "mappoint.h"

namespace vo
{

MapPoint::mappoint()
    : id_(-1),
      pose_(Eigen::Vector3d(0,0,0)),
      norm_(Eigen::Vector3d(0,0,0)),
      observed_times_(0),
      correct_times_(0)
{

}

MapPoint::mappoint(long id, Eigen::Vector3d position, Eigen::Vector3d norm)
    : id_(id),
      pose_(position),
      norm_(norm),
      observed_times_(0),
      correct_times_(0)
{

}

MapPoint::Ptr MapPoint::createMapPoint()
{
    static long factory_id = 0;
    return MapPoint::Ptr (new MapPoint(factory_id++, Eigen::Vector3d(0,0,0), Eigen::Vector3d(0,0,0)));
}

}
