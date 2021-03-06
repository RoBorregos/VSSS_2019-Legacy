#include <opencv2/highgui/highgui.hpp> // image & screen
#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <iostream>
#include <fstream>

// Scalar constants
#define ORANGE cv::Scalar(0,165,255)
#define BLUE cv::Scalar(255,0,0)
#define YELLOW cv::Scalar(0,255,255)
#define RED cv::Scalar(0,0,255)
#define GREEN cv::Scalar(0,255,0)
#define PINK cv::Scalar(147,20,255)
#define WHITE cv::Scalar(255,255,255)

class Calibration{
  public:
    Calibration(std::string screenName, cv::Mat &image);

    // Listen to key inputs, returns true if 'ESC'
    static bool listenKey();
    // Shows an image with just the filtered colors
    static void update();

    static cv::Mat result;
    static std::string screenName;

  private:
    // Trackbar callbacks
    static void onHueMinTrackBar(int, void*);
    static void onHueMaxTrackBar(int, void*);
    static void onSatMinTrackBar(int, void*);
    static void onSatMaxTrackBar(int, void*);
    static void onValMinTrackBar(int, void*);
    static void onValMaxTrackBar(int, void*);

    // Shows in the screen the current color and when it's been saved
    static void log(); 
    // Rewrites the current color's hsv range in the values.txt file
    static void saveColor();
    // Updates the trackbars with the values inside the values.txt file of a specific color
    static void readColor(std::string targetColor);

    static int hueMin, hueMax, satMin, satMax, valMin, valMax;
    static cv::Mat hsv_image, mask, *original;
    static std::string logText, currentColor;
    static std::ifstream infile;
    static cv::Scalar scalarColor;
};