#include "Avtorizazia.h"
#include <Windows.h>

using namespace BallisticMovement;

[STAThreadAttribute]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Avtorizazia^ form = gcnew Avtorizazia();
	form->Show();
	Application::Run();
	return 0;
}