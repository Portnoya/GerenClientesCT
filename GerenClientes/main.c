#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define ID_BUTTON_ADD_CLIENT 1
#define ID_BUTTON_VIEW_CLIENTS 2
#define ID_BUTTON_DELETE_CLIENT 3
#define ID_NAME_TEXTBOX 101
#define ID_DEVICE_TEXTBOX 102
#define ID_VALUE_TEXTBOX 103
#define ID_PHONE_TEXTBOX 104
#define ID_PROBLEM_TEXTBOX 110
#define ID_OK_BUTTON 105
#define ID_CANCEL_BUTTON 106
#define ID_DELETE_BUTTON 107
#define ID_CLIENT_LISTBOX 108

HINSTANCE hInstGlobal;
HWND hName, hDevice, hValue, hPhone, hProblem, hClientListBox;


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK AddClientWindowProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ViewClientsWindowProcedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DeleteClientWindowProcedure(HWND, UINT, WPARAM, LPARAM);


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    hInstGlobal = hInst;

    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) {
        return -1;
    }


    WNDCLASSW addClientClass = {0};
    addClientClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    addClientClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    addClientClass.hInstance = hInst;
    addClientClass.lpszClassName = L"myAddClientWindowClass";
    addClientClass.lpfnWndProc = AddClientWindowProcedure;

    if (!RegisterClassW(&addClientClass)) {
        return -1;
    }


    WNDCLASSW viewClientsClass = {0};
    viewClientsClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    viewClientsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    viewClientsClass.hInstance = hInst;
    viewClientsClass.lpszClassName = L"myViewClientsWindowClass";
    viewClientsClass.lpfnWndProc = ViewClientsWindowProcedure;

    if (!RegisterClassW(&viewClientsClass)) {
        return -1;
    }


    WNDCLASSW deleteClientsClass = {0};
    deleteClientsClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    deleteClientsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    deleteClientsClass.hInstance = hInst;
    deleteClientsClass.lpszClassName = L"myDeleteClientsWindowClass";
    deleteClientsClass.lpfnWndProc = DeleteClientWindowProcedure;

    if (!RegisterClassW(&deleteClientsClass)) {
        return -1;
    }

    CreateWindowW(L"myWindowClass", L"Gestão de Clientes", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 400, 200, NULL, NULL, hInst, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}


LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            CreateWindowW(L"Button", L"Adicionar Cliente", WS_VISIBLE | WS_CHILD, 50, 50, 150, 30, hWnd, (HMENU)ID_BUTTON_ADD_CLIENT, NULL, NULL);
            CreateWindowW(L"Button", L"Visualizar Clientes", WS_VISIBLE | WS_CHILD, 220, 50, 150, 30, hWnd, (HMENU)ID_BUTTON_VIEW_CLIENTS, NULL, NULL);
            CreateWindowW(L"Button", L"Excluir Cliente", WS_VISIBLE | WS_CHILD, 50, 100, 150, 30, hWnd, (HMENU)ID_BUTTON_DELETE_CLIENT, NULL, NULL);
            break;

        case WM_COMMAND:
            switch (LOWORD(wp)) {
                case ID_BUTTON_ADD_CLIENT:
                    CreateWindowW(L"myAddClientWindowClass", L"Adicionar Cliente", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 150, 150, 300, 300, hWnd, NULL, hInstGlobal, NULL);
                    break;

                case ID_BUTTON_VIEW_CLIENTS:
                    CreateWindowW(L"myViewClientsWindowClass", L"Visualizar Clientes", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 150, 150, 500, 400, hWnd, NULL, hInstGlobal, NULL);
                    break;

                case ID_BUTTON_DELETE_CLIENT:
                    CreateWindowW(L"myDeleteClientsWindowClass", L"Excluir Cliente", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 150, 150, 500, 400, hWnd, NULL, hInstGlobal, NULL);
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}


LRESULT CALLBACK AddClientWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            CreateWindowW(L"Static", L"Nome do Cliente:", WS_VISIBLE | WS_CHILD, 10, 10, 100, 20, hWnd, NULL, NULL, NULL);
            hName = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 10, 150, 20, hWnd, (HMENU)ID_NAME_TEXTBOX, NULL, NULL);

            CreateWindowW(L"Static", L"Aparelho:", WS_VISIBLE | WS_CHILD, 10, 50, 100, 20, hWnd, NULL, NULL, NULL);
            hDevice = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 50, 150, 20, hWnd, (HMENU)ID_DEVICE_TEXTBOX, NULL, NULL);

            CreateWindowW(L"Static", L"Valor do Serviço:", WS_VISIBLE | WS_CHILD, 10, 90, 100, 20, hWnd, NULL, NULL, NULL);
            hValue = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 90, 150, 20, hWnd, (HMENU)ID_VALUE_TEXTBOX, NULL, NULL);

            CreateWindowW(L"Static", L"Número de Contato:", WS_VISIBLE | WS_CHILD, 10, 130, 120, 20, hWnd, NULL, NULL, NULL);
            hPhone = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 130, 150, 20, hWnd, (HMENU)ID_PHONE_TEXTBOX, NULL, NULL);

            
             CreateWindowW(L"Static", L"Problema:", WS_VISIBLE | WS_CHILD, 10, 170, 100, 20, hWnd, NULL, NULL, NULL);
            hProblem = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 120, 170, 150, 20, hWnd, (HMENU)ID_PROBLEM_TEXTBOX, NULL, NULL);
            
            CreateWindowW(L"Button", L"OK", WS_VISIBLE | WS_CHILD, 50, 240, 80, 30, hWnd, (HMENU)ID_OK_BUTTON, NULL, NULL);
            CreateWindowW(L"Button", L"Cancel", WS_VISIBLE | WS_CHILD, 150, 240, 80, 30, hWnd, (HMENU)ID_CANCEL_BUTTON, NULL, NULL);
            break;

        case WM_COMMAND:
            switch (LOWORD(wp)) {
                case ID_OK_BUTTON: {
                    char name[100], device[100], value[20], phone[20], problem[100];  
                    GetWindowText(hName, name, 100);
                    GetWindowText(hDevice, device, 100);
                    GetWindowText(hValue, value, 20);
                    GetWindowText(hPhone, phone, 20);
                    GetWindowText(hProblem, problem, 100);  

                    FILE *file = fopen("dados_clientes.txt", "a");
                    if (file) {
                        fprintf(file, "Nome do Cliente: %s\r\n", name);
                        fprintf(file, "Aparelho: %s\r\n", device);
                        fprintf(file, "Valor do Serviço: R$ %s\r\n", value);
                        fprintf(file, "Número de Contato: %s\r\n", phone);
                        fprintf(file, "Problema: %s\r\n", problem);  
                        fprintf(file, "---------------------------------\r\n");
                        fclose(file);
                    }
                    DestroyWindow(hWnd);
                    break;
                }

                case ID_CANCEL_BUTTON:
                    DestroyWindow(hWnd);
                    break;
            }
            break;

        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}


LRESULT CALLBACK ViewClientsWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE: {
            HWND hTextView = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_READONLY | WS_VSCROLL, 10, 10, 460, 330, hWnd, NULL, NULL, NULL);

            FILE *file = fopen("dados_clientes.txt", "r");
            if (file) {
                char buffer[1024] = {0};
                fread(buffer, sizeof(char), 1024, file);
                fclose(file);
                SetWindowText(hTextView, buffer);
            }
            break;
        }
        case WM_DESTROY:
            DestroyWindow(hWnd);
            break;

        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}


void DeleteSelectedClient(const char *selectedClient) {
    FILE *file = fopen("dados_clientes.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (file && tempFile) {
        char line[256];
        char clientInfo[1024] = {0};


        char nome[100], aparelho[100], valor[50], telefone[50];
        char nomeAparelho[200]; 

        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "Nome do Cliente:") != NULL) {
                strcpy(nome, line); 

            } else if (strstr(line, "Aparelho:") != NULL) {
                strcpy(aparelho, line); 

            } else if (strstr(line, "Valor do Serviço:") != NULL) {
                strcpy(valor, line); 

            } else if (strstr(line, "Número de Contato:") != NULL) {
                strcpy(telefone, line); 

                
                snprintf(nomeAparelho, sizeof(nomeAparelho), "%s %s", nome, aparelho);
                snprintf(clientInfo, sizeof(clientInfo), "%s\n%s\n%s\n%s", nome, aparelho, valor, telefone);

               
                if (strcmp(nomeAparelho, selectedClient) != 0) {
                    fputs(nome, tempFile);
                    fputs(aparelho, tempFile);
                    fputs(valor, tempFile);
                    fputs(telefone, tempFile);
                }

              
                memset(clientInfo, 0, sizeof(clientInfo));
            }
        }

        fclose(file);
        fclose(tempFile);

       
        remove("dados_clientes.txt");
        rename("temp.txt", "dados_clientes.txt");
    }
}


LRESULT CALLBACK DeleteClientWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    static HWND hClientListBox;
    static HWND hDeleteButton;
    static HWND hCancelButton;

    switch (msg) {
        case WM_CREATE:
           
            hClientListBox = CreateWindowW(L"ListBox", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | LBS_NOTIFY, 10, 10, 460, 330, hWnd, (HMENU)ID_CLIENT_LISTBOX, NULL, NULL);

            FILE *file = fopen("dados_clientes.txt", "r");
            if (file) {
                char line[256];
                char nome[100], aparelho[100], valor[50], telefone[50];
                char nomeAparelho[200]; 

                while (fgets(line, sizeof(line), file)) {
                    if (strstr(line, "Nome do Cliente:") != NULL) {
                        strcpy(nome, line);
                    } else if (strstr(line, "Aparelho:") != NULL) {
                        strcpy(aparelho, line);
                    } else if (strstr(line, "Valor do Serviço:") != NULL) {
                        strcpy(valor, line);
                    } else if (strstr(line, "Número de Contato:") != NULL) {
                        strcpy(telefone, line);

                       
                        snprintf(nomeAparelho, sizeof(nomeAparelho), "%s %s", nome, aparelho);

                       
                        SendMessage(hClientListBox, LB_ADDSTRING, 0, (LPARAM)nomeAparelho);
                    }
                }
                fclose(file);
            }

         
            hDeleteButton = CreateWindowW(L"Button", L"Excluir", WS_VISIBLE | WS_CHILD, 120, 360, 80, 30, hWnd, (HMENU)ID_DELETE_BUTTON, NULL, NULL);
            hCancelButton = CreateWindowW(L"Button", L"Cancelar", WS_VISIBLE | WS_CHILD, 220, 360, 80, 30, hWnd, (HMENU)ID_CANCEL_BUTTON, NULL, NULL);
            break;

        case WM_COMMAND:
            switch (LOWORD(wp)) {
                case ID_DELETE_BUTTON: {
                   
                    int index = SendMessage(hClientListBox, LB_GETCURSEL, 0, 0);
                    if (index != LB_ERR) {
                    
                        char selectedClient[256];
                        SendMessage(hClientListBox, LB_GETTEXT, index, (LPARAM)selectedClient);

                    
                        FILE *file = fopen("dados_clientes.txt", "r");
                        FILE *tempFile = fopen("temp_clientes.txt", "w");
                        char line[256];
                        bool skipClient = false;
                        int currentIndex = 0;

                        while (fgets(line, sizeof(line), file)) {
                         
                            if (strstr(line, "Nome do Cliente:") != NULL) {
                                if (currentIndex == index) {
                                    skipClient = true; 
                                } else {
                                    skipClient = false; 
                                }
                                currentIndex++;
                            }

                            
                            if (!skipClient) {
                                fputs(line, tempFile);
                            }

                            
                            if (strstr(line, "---------------------------------") != NULL) {
                                skipClient = false;
                            }
                        }

                        fclose(file);
                        fclose(tempFile);

                        
                        remove("dados_clientes.txt");
                        rename("temp_clientes.txt", "dados_clientes.txt");

                        
                        SendMessage(hClientListBox, LB_DELETESTRING, index, 0);
                    }
                    break;
                }
                case ID_CANCEL_BUTTON:
                    DestroyWindow(hWnd);
                    break;
            }
            break;

        case WM_DESTROY:
            DestroyWindow(hWnd);
            break;

        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}