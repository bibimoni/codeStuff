/**
 * File              : donut.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 12.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
#include <cmath>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

int nxt() {int n; cin >> n; return n;}

const int PI = 3.14159265359;
const int screenWidth = 50, screenHeight = 20;

const float thetaSpacing = 0.003;
const float phiSpacing = 0.001;

const float R1 = 1, R2 = 2, K2 = 5;
const float K1 = screenWidth * K2 * 3 / (8 * (R1 + R2));

string luminaceCharacter = ".,-~:;=!*#$@";

void render(float A, float B) {
  float cosA = cos(A), sinA = sin(A), cosB = cos(B), sinB = sin(B);
  char output[screenWidth][screenHeight] = {' '};
  float zBuffer[screenWidth][screenHeight] = {0.0};

  for(float theta = 0; theta < 2 * PI; theta += thetaSpacing) {
    float cosTheta = cos(theta), sinTheta = sin(theta);
    for(float phi = 0; phi < 2 * PI; phi += phiSpacing) {
      float cosPhi = cos(phi), sinPhi = sin(phi);
      float circleX = R2 + R1 * cosTheta;
      float circleY = R1 * sinTheta;
      float x = circleX * (cosB * cosPhi + sinA * sinB * sinPhi) - circleY * cosA * sinB;
      float y = circleX * (sinB * cosPhi - sinA * cosB * sinPhi) + circleY * cosA * cosB;
      float z = K2 + cosA * circleX * sinPhi + circleY * sinA;
      float ooz = 1 / z;
      int xp = (int) ((float) screenWidth / 2.0 + K1 * ooz * x);
      int yp = (int) ((float) screenHeight / 2.0 - K1 * ooz * y );
      float L = cosPhi * cosTheta * sinB - cosA * cosTheta * sinPhi - sinA * sinTheta + cosB * (cosA * sinTheta - cosTheta * sinA * sinPhi);
      if(L > 0) {
        if(ooz > zBuffer[xp][yp]) {
          zBuffer[xp][yp] = ooz;
          int luminaceIndex = L * 8;
          output[xp][yp] = luminaceCharacter[luminaceIndex];
        }
      }
    }
  }
  printf("\x1b[23A");
  for(int j = 0; j < screenHeight; j++) {
    for(int i = 0; i < screenWidth; i++) {
      cout << output[i][j];
    }
    cout << '\n';
  }
}

int main() {
  float A = 0, B = 0;
  while(true) {
    render(A, B);
    A += 0.04; B += 0.07;
  }
}

