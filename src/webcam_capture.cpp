
//opencv
#include "opencv2/opencv.hpp"

//std
#include <iostream>
#include <cstdlib>

// Ref: https://docs.opencv.org/2.4/doc/user_guide/ug_mat.html
//      https://docs.opencv.org/2.4/doc/tutorials/imgproc/threshold/threshold.html?highlight=cvtcolor

//main
int main(int argc, char *argv[])
{
    cv::VideoCapture camera;             // OpenCV video capture object
    cv::Mat image;                       // OpenCV image object
	cv::Mat gray_image;
	int cam_id;                          // camera id . Associated to device number in /dev/videoX
	cv::Scalar_<unsigned char> px_value; // pixel value (4-element vector)
	int user_key;                        // user pressed key to quit
	bool color;

	// check user args
	switch(argc)
	{
		case 1: // no argument provided, so try /dev/video0
			cam_id = 0;
			break;
		case 2: // an argument is provided. Get it and set cam_id
			cam_id = atoi(argv[1]);
			break;
		default:
			std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
			std::cout << "EXIT program." << std::endl;
			break;
	}

	// advertising to the user
	std::cout << "Opening video device " << cam_id << std::endl;

    // open the video stream and make sure it's opened
    if( !camera.open(cam_id) )
	{
        std::cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
        return -1;
    }

	color = true;

    // capture loop. Out of user press a key
    while(1)
	{
		// Read image and check it. Blocking call up to a new image arrives from camera.
        if(!camera.read(image))
		{
            std::cout << "No frame" << std::endl;
            cv::waitKey();
        }
	
		// Get the central pixel coordinates.(x,y)
		int central_pixel_y = image.rows/2;
		int central_pixel_x = image.cols/2;

		// Get pixel 3 channel values
		cv::Vec3b intensity = image.at<cv::Vec3b>(central_pixel_y, central_pixel_x);
		int blue  = intensity.val[0];
		int green = intensity.val[1];
		int red   = intensity.val[2];

		// Print image dimensions
		std::cout << "Image size is: " << image.cols << "x" << image.rows << std::endl;

		// Print central pixel coordinates
		std::cout << "The central pixel is at: " << central_pixel_x << "x" << central_pixel_y << std::endl;

		// Print central pixel 3 original channel values
		std::cout << "And its original 3 channel values are: " << std::endl;
		std::cout << "Blue: " << blue << " Green: " << green << " Red: " << red<<std::endl;

		// Set RGB color red to the central pixel and it's 8 neighbors
		for (int y = central_pixel_y - 4; y <= central_pixel_y + 4; y ++) 
		{    
			for (int x = central_pixel_x - 4; x <= central_pixel_x + 4; x ++) 
			{
        
				image.at<cv::Vec3b>(y, x)[0] = 0;   // B
				image.at<cv::Vec3b>(y, x)[1] = 0;   // G
				image.at<cv::Vec3b>(y, x)[2] = 255; // R
    		}
		}
		
		// If no color
		if (!color)
		{
			// Convert the image to Gray scale.
			cv::cvtColor( image, gray_image, CV_BGR2GRAY );
		}
		
        // show image in a window
        cv::imshow("Output Window", color ? image : gray_image);

		// Waits 30 millisecond to check if 'q' key has been pressed. If so, breaks the loop. Otherwise continues.
		unsigned char key = (unsigned char)(cv::waitKey(30) & 0xff);
		if (key == 'q') break;
		else if (key == 'g') color = false; 
		else if (key == 'c') color = true;
    	//if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break;
    }
}
