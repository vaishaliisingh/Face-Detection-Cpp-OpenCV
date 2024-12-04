#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <sstream> // for string streams

using namespace std;
using namespace cv;

int main() {
    // Load the pre-trained Haar Cascade classifier for face detection
    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        cout << "Error: Could not load face cascade." << endl;
        return -1;
    }

    // Open the camera
    VideoCapture video(0);
    if (!video.isOpened()) {
        cout << "Error: Could not open video stream from the camera." << endl;
        return -1;
    }

    Mat img;
    vector<Rect> faces;
    int screenshotCount = 0; // Counter for naming screenshot files

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
        faceCascade.detectMultiScale(gray, faces, 1.1, 10, 0 | CASCADE_SCALE_IMAGE, Size(50, 50));

        // Draw rectangles around detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(img, faces[i], Scalar(255, 0, 255), 2);
        }

        // Display the number of faces detected
        stringstream ss;
        ss << "Faces: " << faces.size();
        putText(img, ss.str(), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

        // Show the frame with detected faces in a window named "Frame"
        imshow("Frame", img);

        // Wait for key press
        char key = (char)waitKey(1);

        if (key == 'q') { // Quit the application
            break;
        } else if (key == 's') { // Save a screenshot
            stringstream screenshotName;
            screenshotName << "screenshot_" << screenshotCount << ".jpg";
            imwrite(screenshotName.str(), img);
            cout << "Screenshot saved as " << screenshotName.str() << endl;
            screenshotCount++;
        }
    }

    return 0;
}

