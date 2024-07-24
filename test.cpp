#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    // Load the pre-trained Haar Cascade classifier for face detection
    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        cout << "Error: Could not load face cascade." << endl;
        return -1;
    }

    // Attempt to open the camera (try index 0 if index 1 fails)
    VideoCapture video(1);
    if (!video.isOpened()) {
        cout << "Error: Could not open video stream from camera 1." << endl;
        cout << "Trying camera 0..." << endl;
        video.open(0);
        if (!video.isOpened()) {
            cout << "Error: Could not open video stream from camera 0 either." << endl;
            return -1;
        }
    }

    Mat img;  // Mat is a data type in C++ that represents an image
    vector<Rect> faces;

    while (true) {
        // Read a new frame from the camera
        video.read(img);

        // Check if the frame is empty
        if (img.empty()) {
            cout << "Error: Empty frame grabbed." << endl;
            break;
        }

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);

        // Detect faces in the frame
        faceCascade.detectMultiScale(gray, faces, 1.1, 4, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // Draw rectangles around detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i], Scalar(255, 0, 255), 2);
        }

        // Show the frame with detected faces in a window named "Frame"
        imshow("Frame", img);

        // Wait for 1 ms to see if the user presses a key
        if (waitKey(1) >= 0) {
            break;
        }
    }

    return 0;
}


