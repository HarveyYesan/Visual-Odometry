#ifndef CONFIG_H
#define CONFIG_H

#include "common.h"

namespace vo
{

Class Config
{
public:
    ~Config();

    // set a new config file
    static void setParameterFile(const std::string& filename);
    // access the parameter value
    template <typename T>
    static T get(const std::string& key)
    {
        return T(Config::config_->file_[key]);
    }

private:
    static std::shared_ptr<Config> config_;
    cv::FileStorage file_;

    // private constructor makes a singleton
    Config();
};

}

#endif // CONFIG_H

