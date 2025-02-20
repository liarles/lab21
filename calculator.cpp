#include <windows.h>    
#include <stdio.h>

HWND firstnum, secondnum;
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    switch(Message) {
        case WM_CREATE: {
            HWND textfield, button1, button2, button3, button4;
            
            textfield = CreateWindow("STATIC", "Please input two numbers", WS_VISIBLE | WS_CHILD,
                                     15, 20, 200, 30, hwnd, NULL, NULL, NULL);

            button1 = CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD, 60, 120, 25, 25, hwnd, (HMENU)1, NULL, NULL);
            button2 = CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD, 90, 120, 25, 25, hwnd, (HMENU)2, NULL, NULL);
            button3 = CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD, 120, 120, 25, 25, hwnd, (HMENU)3, NULL, NULL);
            button4 = CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD, 150, 120, 25, 25, hwnd, (HMENU)4, NULL, NULL);

            firstnum = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    50, 60, 100, 20, hwnd, NULL, NULL, NULL);
            secondnum = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                     50, 90, 100, 20, hwnd, NULL, NULL, NULL);
            break;
        }

        case WM_COMMAND: {
            char num1[20], num2[20],transform[20];
            double numA,numB,sum;
            GetWindowText(firstnum, num1, 20);
            GetWindowText(secondnum, num2, 20);

            numA = atof(num1);
            numB = atof(num2);

            switch (LOWORD(wParam)) {
                case 1:
                    sum = numA+numB;
                    sprintf(transform, "%f", sum);
                    MessageBox(hwnd, transform, "Result", MB_OK);
                    break;
                case 2:
                    sum = numA-numB;
                    sprintf(transform, "%f", sum);

                    MessageBox(hwnd, transform, "Result", MB_OK);
                    break;
                case 3:
                    sum = numA*numB;
                    sprintf(transform, "%f", sum);

                    MessageBox(hwnd, transform, "Result", MB_OK);
                    break;
                case 4:
                    sum = numA/numB;
                    sprintf(transform, "%f", sum);

                    MessageBox(hwnd,transform, "Result", MB_OK);
                    break;
            }
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = {0};
    HWND hwnd;
    MSG msg;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(173, 216, 230)); // สีฟ้า    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "My Calculator", WS_VISIBLE | WS_SYSMENU,
                          CW_USEDEFAULT, CW_USEDEFAULT, 250, 200, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
