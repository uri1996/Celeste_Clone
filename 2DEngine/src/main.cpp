// windows platform
#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include<windows.h>

// windows globals
static bool running = true;
static HWND window;

// windows functions
LRESULT CALLBACK window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	switch (msg)
	{
	case WM_CLOSE:
		running = false;
		break;
	default:
		// let windows handle the default input for me
		result = DefWindowProcA(window, msg, wParam, lParam);
	}
	return result;
}

bool platform_create_window(int width, int height, const char* title)
{
	HINSTANCE instance = GetModuleHandleA(0);

	WNDCLASSA wc = {};
	wc.hInstance = instance;
	wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// This means we decide the look of the cursor (arrow)
	wc.lpszClassName = title;						// This is not the title, just a unique identifier(ID)
	wc.lpfnWndProc = window_callback;				// Callback for Input into the window
	
	if (!RegisterClassA(&wc))
	{
		return false;
	}

	// WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
	int dwStyle = WS_OVERLAPPEDWINDOW;

	window = CreateWindowExA(0, title,		// This references lpszClassName
		title,		// This is the actual title
		dwStyle,	
		100,
		100,
		width,
		height,
		NULL,		// parent
		NULL,		// menu
		instance,
		NULL		// lpParam
	);

	if (window == NULL)
	{
		return false;
	}

	ShowWindow(window, SW_SHOW);
	return true;
}

void platform_update_window()
{
	MSG msg;

	while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);		// Calls the callback specified when creating the window
	}
}

#endif

int main()
{
	platform_create_window(1200, 720, "2DEngine");
	while (running)
	{
		// update
		platform_update_window();
	}
	return 0;
}