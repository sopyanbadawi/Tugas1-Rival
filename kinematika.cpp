#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    double L1 = 10.0;
    double L2 = 5.0;
    double theta1_deg = 30.0;
    double theta2_deg = 10.0;
    double theta1_rad = theta1_deg * (M_PI / 180);
    double theta2_rad = theta2_deg * (M_PI / 180);

    double x = (L1 * cos(theta1_rad)) + (L2 * cos(theta1_rad + theta2_rad));
    double y = (L1 * sin(theta1_rad)) + (L2 * sin(theta1_rad + theta2_rad));

    cout << "Panjang L1       : " << L1 << " cm" << endl;
    cout << "Panjang L2       : " << L2 << " cm" << endl;
    cout << "Sudut Theta 1    : " << theta1_deg << " derajat" << endl;
    cout << "Sudut Theta 2    : " << theta2_deg << " derajat" << endl;
    cout << "--------------------------------------------------" << endl;
    
    cout << fixed << setprecision(2);
    cout << "Posisi End-Effector (X, Y) ada di titik : (" << x << " cm, " << y << " cm)" << endl;

    return 0;
}
