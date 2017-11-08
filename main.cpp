#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main(int argc, char** argv)
{
    std::vector<double> theta = {0, M_PI/4, M_PI/2, 3*M_PI/4}; // 4 orientations for the Gabor
    int n = 15; //size of the filter
    Size gsize = {n,n};
    Mat my_img,gkernel,respf;

    my_img = imread("you.jpg",0); // Reads a jpg image and converts it to grayscale
    my_img.convertTo(my_img,CV_32F);

    for (int i=1;i<=4;i++)
    {
        Mat fimage;

        gkernel = getGaborKernel(gsize,10,theta[i],10.0,1.0,0.0,CV_32F); // apply Gabor function with lambda = 2*sigma_x/pr
        // Convolute image with Gabor filter
        // filter2D computes correlation
        // for convolution the kernel has to be fliped horizontally

        flip(gkernel,gkernel,1);
        filter2D(my_img,respf,CV_32F,gkernel,Point(-1,-1));
        namedWindow("Gabor filter "+std::to_string(i),WINDOW_AUTOSIZE);
        namedWindow("Image "+std::to_string(i),WINDOW_AUTOSIZE);
        // Show Gabor filter
        flip(gkernel,gkernel,1);
        resize(gkernel,gkernel,Size(336,448));
        imshow("Gabor filter "+std::to_string(i),gkernel);
        // Show filtered Image
        normalize(respf,fimage,0,255.0, NORM_MINMAX);
        fimage.convertTo(fimage, CV_8U);
        imshow("Image "+std::to_string(i),fimage);
    }
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}