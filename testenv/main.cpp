// 
// @rajeevp
//

#include <iostream>
#include <Eigen/Dense>
#include <boost/math/constants/constants.hpp>
#include <glog/logging.h>

int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = false;
    google::SetLogDestination(google::GLOG_INFO,"/mnt/c/Users/raj/Documents/code_dev/cv/cv/testenv/build/glogs/" );
    LOG(INFO) << "Eigen Demo ";
    Eigen::Matrix<float,8,1> v0;
    v0(0,0) = boost::math::constants::pi<float>();
    v0(1,0) = boost::math::constants::pi<float>()*2.0f;

    LOG(INFO) << " v0: " << v0;

    Eigen::Matrix3f A;
    A << 1,2,3, 4,5,6, 7,8,9;

    Eigen::Vector3f b;
    b << 3, 3, 4;

    //LOG(INFO) << "Matrix A: " << A;
    //LOG(INFO) << "Matrix b: " << b;

    Eigen::Vector3f x= A.colPivHouseholderQr().solve(b);
    //LOG(INFO) << "Solution of Ax = b is : x= " << x ;
    return 1;
}
