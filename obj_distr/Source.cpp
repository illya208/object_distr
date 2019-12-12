#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

void set_biggerpixel(HDC hDC, int x, int y) {
	SetPixel(hDC, x, y, RGB(255, 0, 0));
	SetPixel(hDC, x, y + 1, RGB(255, 0, 0));
	SetPixel(hDC, x, y - 1, RGB(255, 0, 0));
	SetPixel(hDC, x + 1, y, RGB(255, 0, 0));
	SetPixel(hDC, x - 1, y, RGB(255, 0, 0));
}

void set_coloredbiggerpixel(HDC hDC, int x, int y, int color) {

	if (color == 0) {  //red
		SetPixel(hDC, x, y, RGB(255, 0, 0));
		SetPixel(hDC, x, y + 1, RGB(255, 0, 0));
		SetPixel(hDC, x, y - 1, RGB(255, 0, 0));
		SetPixel(hDC, x + 1, y, RGB(255, 0, 0));
		SetPixel(hDC, x - 1, y, RGB(255, 0, 0));
	}
	if (color == 1) {  //green
		SetPixel(hDC, x, y, RGB(71, 250, 0));
		SetPixel(hDC, x, y + 1, RGB(71, 250, 0));
		SetPixel(hDC, x, y - 1, RGB(71, 250, 0));
		SetPixel(hDC, x + 1, y, RGB(71, 250, 0));
		SetPixel(hDC, x - 1, y, RGB(71, 250, 0));
	}
	if (color == 2) {  //blue
		SetPixel(hDC, x, y, RGB(0, 21, 250));
		SetPixel(hDC, x, y + 1, RGB(0, 21, 250));
		SetPixel(hDC, x, y - 1, RGB(0, 21, 250));
		SetPixel(hDC, x + 1, y, RGB(0, 21, 250));
		SetPixel(hDC, x - 1, y, RGB(0, 21, 250));
	}
	if (color == 3) {  //centre
		SetPixel(hDC, x, y, RGB(204, 68, 0));
		SetPixel(hDC, x, y + 1, RGB(204, 68, 0));
		SetPixel(hDC, x, y - 1, RGB(204, 68, 0));
		SetPixel(hDC, x + 1, y, RGB(204, 68, 0));
		SetPixel(hDC, x - 1, y, RGB(204, 68, 0));
	}
}const int size_A = 100;
const int size_of_y = 2;
void clasterA() {

	float **A = new float *[size_A];
	for (int i = 0; i < size_A; i++)
		A[i] = new float[size_of_y];
	for (int i = 0; i < size_A; i++) {

		A[i][0] = 31 + rand() % 451; // 31-181
		A[i][1] = 100 + rand() % 151; // 31-181

	}
	float max_in_A = 1;
	int pos_i_A = -1, pos_j_A = -1;
	for (int i = 0; i < size_A; i++) {
		for (int j = i + 1; j < size_A - 1; j++) {

			if (sqrt(pow((A[i][0] - A[j][0]), 2) + pow((A[i][1] - A[j][1]), 2)) > max_in_A)
			{
				max_in_A = sqrt(pow((A[i][0] - A[j][0]), 2) + pow((A[i][1] - A[j][1]), 2));
				pos_i_A = i;
				pos_j_A = j;
			}
		}
	}
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 0, 250, NULL);
	LineTo(hDC, 635, 250);
	MoveToEx(hDC, 30, 0, NULL);
	LineTo(hDC, 30, 270);
	int x0 = 30;// centre koordinate
	int y0 = 250;
	MoveToEx(hDC, 10 * (-1) + x0, -10 * (-39) + y0, NULL);
	LineTo(hDC, 10 * (-2) + x0, -10 * (-25) + y0);
	for (int i = 0; i < size_A; i++) {
		set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 0);
	}
	int i1 = 1 + rand() % 98;//1 point
	int j2 = 1 + rand() % 98;//2 point

	int i1_1 = 1 + rand() % 98;//1 point
	int j2_1 = 1 + rand() % 98;//2 point

	int i1_2 = 1 + rand() % 98;//1 point
	int j2_2 = 1 + rand() % 98;//2 point
	//line in claster
	MoveToEx(hDC, A[i1][0], A[i1][1], NULL);
	LineTo(hDC, A[j2][0], A[j2][1]);
	MoveToEx(hDC, A[i1_1][0], A[i1_1][1], NULL);
	LineTo(hDC, A[j2_1][0], A[j2_1][1]);
	MoveToEx(hDC, A[i1_2][0], A[i1_2][1], NULL);
	LineTo(hDC, A[j2_2][0], A[j2_2][1]);
	float  AA = 0, BB = 0, CC = 0;
	float k = (A[j2][1] - A[i1][1]) / (A[j2][0] - A[i1][0]);
	AA = -1 * k;
	float shirp = k * A[i1][0];
	BB = 1;
	CC = shirp - A[i1][1];
	system("pause");
	system("cls");

	float lyambda = sqrt(1 / (AA*AA + BB * BB));
	if (CC > 0) {
		lyambda *= -1;
	}
	AA *= lyambda;
	BB *= lyambda;
	CC *= lyambda;
	cout << "A " << AA << "  BB" << BB << "  CC" << CC << endl;
	float  AA_1 = 0, BB_1 = 0, CC_1 = 0;
	float k_1 = (A[j2_1][1] - A[i1_1][1]) / (A[j2_1][0] - A[i1_1][0]);
	AA_1 = -1 * k_1;
	float shirp_1 = k_1 * A[i1_1][0];
	BB_1 = 1;
	CC_1 = shirp_1 - A[i1_1][1];

	float lyambda_1 = sqrt(1 / (AA_1*AA_1 + BB_1 * BB_1));
	if (CC_1 > 0) {
		lyambda_1 *= -1;
	}
	AA_1 *= lyambda_1;
	BB_1 *= lyambda_1;
	CC_1 *= lyambda_1;
	cout << "A " << AA_1 << "  BB" << BB_1 << "  CC" << CC_1 << endl;
	float  AA_2 = 0, BB_2 = 0, CC_2 = 0;
	float k_2 = (A[j2_2][1] - A[i1_2][1]) / (A[j2_2][0] - A[i1_2][0]);
	AA_2 = -1 * k_2;
	float shirp_2 = k_2 * A[i1_2][0];
	BB_2 = 1;
	CC_2 = shirp_2 - A[i1_2][1];

	float lyambda_2 = sqrt(1 / (AA_2*AA_2 + BB_2 * BB_2));
	if (CC_2 > 0) {
		lyambda_2 *= -1;
	}
	AA_2 *= lyambda_2;
	BB_2 *= lyambda_2;
	CC_2 *= lyambda_2;
	cout << "A " << AA_2 << "  BB" << BB_2 << "  CC" << CC_2 << endl;
	system("pause");
	system("cls");
	MoveToEx(hDC, 0, 250, NULL);
	LineTo(hDC, 635, 250);
	MoveToEx(hDC, 30, 0, NULL);
	LineTo(hDC, 30, 270);
	MoveToEx(hDC, 10 * (-1) + x0, -10 * (-39) + y0, NULL);
	LineTo(hDC, 10 * (-2) + x0, -10 * (-25) + y0);

	for (int i = 0; i < size_A; i++) {
		set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 0);
	}
	system("pause");
	system("cls");
	MoveToEx(hDC, 0, 250, NULL);
	LineTo(hDC, 635, 250);
	MoveToEx(hDC, 30, 0, NULL);
	LineTo(hDC, 30, 270);
	MoveToEx(hDC, A[i1][0], A[i1][1], NULL);
	LineTo(hDC, A[j2][0], A[j2][1]);
	MoveToEx(hDC, A[i1_1][0], A[i1_1][1], NULL);
	LineTo(hDC, A[j2_1][0], A[j2_1][1]);
	/*MoveToEx(hDC, A[i1_2][0], A[i1_2][1], NULL);
	LineTo(hDC, A[j2_2][0], A[j2_2][1]);*/
	for (int i = 0; i < size_A; i++) {
		float d = AA * A[i][0] + BB * A[i][1] + CC;
		float d_1 = AA_1 * A[i][0] + BB_1 * A[i][1] + CC_1;
		float d_2 = AA_2 * A[i][0] + BB_2 * A[i][1] + CC_2;
		/*	if (d*d_1 < 0) {
				set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 1);
			}
			if (d*d_1 >0) {
				set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 2);
			}*/
			//if (d < 0 || d_1 < 0||d_2<0) {
			//	set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 1);
			//}
			//else {
			//	set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 2);
			//}
		if (d < 0) {
			set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 1);
		}
		if (d_1 < 0) {
			set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 1);
		}
		//if (d_2 <0) {
		//	set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 1);
		//}
		if (d > 0) {
			set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 2);
		}
		if (d_1 > 0) {
			set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 2);
		}
		//if (d_2 >0) {
		//	set_coloredbiggerpixel(hDC, A[i][0], A[i][1], 2);
		//}
	}
}

int main() {

	clasterA();
	system("pause");
	return 0;
}
