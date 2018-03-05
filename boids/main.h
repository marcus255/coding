#ifndef MAIN_H
#define MAIN_H

#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>     
#include <iostream>
#include <sstream>
#include <iomanip> //setprecision

using namespace std;

unsigned screenWidth = 1200;
unsigned screenHeight = 700;
unsigned totalBoids = 200;
float cohesionFactor = 0.02f;
float alignmentFactor = 0.05f;
float separationFactor = 0.1f;
static float *activeFactor;
static unsigned framesPerSecond = 60;
static string parametersText;
static void getParametersText();

#endif // MAIN_H