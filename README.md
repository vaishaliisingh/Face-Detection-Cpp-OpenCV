# Face Detection in C++ using OpenCV
This project demonstrates real-time face detection using OpenCV in C++. The application captures video from the camera, detects faces, and displays 
the results with rectangles around the detected faces and the count of faces displayed on the video frame.

## Table of Contents
- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Setting Up OpenCV for Cpp](#setting-up-opencv-for-cpp)
- [Setting Up Visual Studio Code](#setting-up-visual-studio-code)
- [Project Details](#project-details)
- [How It Works](#how-it-works)

## Introduction
This project utilizes the Haar Cascade Classifier for face detection. 
OpenCV is a powerful library for computer vision tasks, and this project demonstrates its application in real-time video processing.

## Prerequisites
- Windows/Linux/MacOS
- C++ Compiler (e.g., MinGW for Windows, GCC for Linux/MacOS)
- OpenCV Library
- Visual Studio Code Community Edition

## Setting Up OpenCV for Cpp
1. **Download OpenCV:**
   - Go to the [OpenCV releases page](https://opencv.org/releases/) and download the latest version of OpenCV.
   - Extract the downloaded file to a convenient location on your system.
2. **Set Up Environment Variables (Windows):**
   - Open the Start Menu and search for "Environment Variables".
   - Click "Edit the system environment variables".
   - In the System Properties window, click the "Environment Variables" button.
   - Under "System variables", find and select the `Path` variable, then click "Edit".
   - Add the path to the `bin` directory of your OpenCV installation (e.g., `C:\opencv\build\x64\vc15\bin`).
3. **Configure OpenCV in Your Project:**
   - Add the OpenCV include directories to your compiler's include path.
   - Add the OpenCV library directories to your linker settings.
   - Link against the necessary OpenCV libraries (e.g., `opencv_world455.lib` for static linking on Windows).

## Setting Up Visual Studio Code
1. **Download and Install VS Code:**
   - Go to the [Visual Studio Code website](https://code.visualstudio.com/) and download the installer for your operating system.
   - Install Visual Studio Code by following the installer instructions.
2. **Install C++ Extensions:**
   - Open VS Code.
   - Go to the Extensions view by clicking on the Extensions icon in the Activity Bar on the side of the window or by pressing `Ctrl+Shift+X`.
   - Search for "C++" and install the "C/C++" extension by Microsoft.
3. **Configure Build Tasks:**
   - Create a `tasks.json` file in the `.vscode` directory of your project.
   - Define tasks to build and run your project.
4. **Configure Launch Settings:**
   - Create a `launch.json` file in the `.vscode` directory of your project.
   - Define the settings for debugging your project.

## Project Details
This project uses OpenCV's Haar Cascade Classifier for face detection. The classifier is trained to detect faces in real-time video streams. The application captures frames from the camera, converts them to grayscale, and uses the classifier to detect faces. Detected faces are highlighted with rectangles in the displayed video frames, and the number of detected faces is displayed on the screen.

## How It Works
1. **Initialize the Camera**: The program opens a video stream from the camera.
2. **Load Haar Cascade Classifier**: The pre-trained Haar Cascade Classifier is loaded for face detection.
3. **Capture Frames**: Continuously capture frames from the camera.
4. **Convert to Grayscale**: Convert each frame to grayscale to improve detection performance.
5. **Detect Faces**: Use the Haar Cascade Classifier to detect faces in the grayscale frame.
6. **Draw Rectangles and Display Count**: Draw rectangles around detected faces in the original frame and display the number of faces detected.
7. **Display the Frame**: Display the processed frame with detected faces and count.
