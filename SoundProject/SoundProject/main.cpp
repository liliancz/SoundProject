#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	bool played = PlaySound(TEXT("arm_tool.wav"), NULL, SND_SYNC);
	cout << "Success or not:" << played;
	return 0;
}