#ifndef FRAME_H
#define FRAME_H

#include "common.h"
#include "camera.h"

namespace vo
{

// forward declare
class MapPoint;

// basic data unit
class Frame
{
public:
    typedef std::shared_ptr<Frame> Ptr;
    Frame();
    Frame(long id, double time_stamp = 0, Sophus::SE3 T_c_w = Sophus::SE3(), Camera::Ptr camera = nullptr,
          cv::Mat color = cv::Mat(), cv::Mat depth = cv::Mat());
    ~Frame();

    // factory function
    static Frame::Ptr createFrame();

    // find the depth in depth map
    double findDepth(const cv::KeyPoint& kp);

    // get camera center
    Eigen::Vector3d getCamCenter() const;

    // check if a point is in the frame
    bool isInFrame(const Eigen::Vector3d& pt_world); 

private:
    // id of this frame
    unsigned long id_;
    // time_stamp of this frame
    double time_stamp_;
    // transform from world to camera
    Sophus::SE3 T_c_w_;
    // pinhole RGB-D Camera model
    Camera::Ptr camera_;
    // color image
    cv::Mat color_;
    // depth image
    cv::Mat depth_;
};

}

#endif // FRAME_H

