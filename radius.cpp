#include <cmath>
#include <iostream>

void handleMath();
void printArray();
double radiusArray[50][3];
using namespace std;
void handleMath() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) radiusArray[i][0] = i+1;
            else if (j == 1) {
                double volume = (4.0 / 3.0) * M_PI * pow(i+1, 3);
                radiusArray[i][1] = volume / 1000.0;
            }else {
                double surfaceArea = 4 * M_PI * pow(i+1, 2);
                radiusArray[i][2] = surfaceArea / 1000.0;
            }
        }
    }
}

void printArray() {
    cout << " RADIUS | VOLUME | SURFACE AREA" << endl;
    for (int i = 0; i < 50; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << radiusArray[i][j] << "      ";
        }
        cout << " |" << endl;
    }

}


int main()
{
    handleMath();
    printArray();

    return 0;

}
