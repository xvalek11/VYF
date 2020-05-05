#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image, image_out;
    image=imread("./source/PNG_transparency_demonstration_1.png");
    cvtColor(image, image_out, CV_BGR2Lab);
    imshow("sohi",image_out); waitKey(0);
    return 0;
}
