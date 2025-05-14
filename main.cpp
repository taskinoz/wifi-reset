#include <windows.h>
#include <shellapi.h>
#include <string>
#include <iostream>

std::string wifiAdapterName = "Wi-Fi"; // Change if your adapter has a different name

bool isAdapterEnabled(const std::string& name) {
    std::string command = "netsh interface show interface name=\"" + name + "\" > temp.txt";
    system(command.c_str());

    FILE* file = fopen("temp.txt", "r");
    if (!file) return false;

    char buffer[1024];
    bool enabled = false;
    while (fgets(buffer, sizeof(buffer), file)) {
        std::string line(buffer);
        if (line.find(name) != std::string::npos && line.find("Enabled") != std::string::npos) {
            enabled = true;
            break;
        }
    }
    fclose(file);
    remove("temp.txt");
    return enabled;
}

void toggleAdapter(const std::string& name, bool enable) {
    std::string command = "netsh interface set interface name=\"" + name + "\" admin=" + (enable ? "enabled" : "disabled");
    system(command.c_str());
}

void playNotificationSound() {
    MessageBeep(MB_OK);
}

void showAlertBox() {
    MessageBox(NULL, "Wi-Fi adapter has been reset.", "Wi-Fi Reset", MB_OK | MB_ICONINFORMATION);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    bool showMessage = strstr(lpCmdLine, "message") != nullptr;

    if (isAdapterEnabled(wifiAdapterName)) {
        toggleAdapter(wifiAdapterName, false);
        Sleep(3000); // Wait 3 seconds to ensure it turns off
        toggleAdapter(wifiAdapterName, true);
    } else {
        toggleAdapter(wifiAdapterName, true);
    }

    if (showMessage) {
        showAlertBox();
    } else {
        playNotificationSound();
    }

    return 0;
}
