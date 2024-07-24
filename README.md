# Face Detection in C++ using OpenCV
This project demonstrates real-time face detection using OpenCV in C++. 
The application captures video from the camera, detects faces, and displays the results with rectangles drawn around the detected faces.

## Table of Contents
- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Setting Up OpenCV for C++](#setting-up-opencv-for-c++)
- [Setting Up Visual Studio Code](#setting-up-visual-studio-code)
- [Main Code Explanation](#main-code-explanation)
- [Running the Project](#running-the-project)

## Introduction
This project utilizes the Haar Cascade Classifier for face detection. 
OpenCV is a powerful library for computer vision tasks, and this project demonstrates its application in real-time video processing.

## Prerequisites
- Windows/Linux/MacOS
- C++ Compiler (e.g., MinGW for Windows, GCC for Linux/MacOS)
- OpenCV Library
- Visual Studio Code Community Edition

## Setting Up OpenCV for C++
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
