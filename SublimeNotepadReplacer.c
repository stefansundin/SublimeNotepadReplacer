#include <stdio.h>
#include <windows.h>
#include <shlwapi.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define APP_NAME      L"Sublime Notepad Replacer"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
  // Get path to sublime_text.exe
  wchar_t path[MAX_PATH];
  GetModuleFileName(NULL, path, ARRAY_SIZE(path));
  PathRemoveFileSpec(path);
  wcscat(path, L"\\sublime_text.exe");

  if (!PathFileExists(path)) {
    MessageBox(NULL, L"Could not find sublime_text.exe", APP_NAME, MB_ICONWARNING|MB_OK);
    return 1;
  }

  // wchar_t logpath[MAX_PATH];
  // GetModuleFileName(NULL, logpath, ARRAY_SIZE(logpath));
  // PathRemoveFileSpec(logpath);
  // wcscat(logpath, L"\\out.txt");
  // FILE *f = _wfopen(logpath, L"ab");
  // fwprintf(f, L"%s\n", lpCmdLine);
  // fclose(f);
  wchar_t args[MAX_PATH] = L"\"";

  wchar_t *start = lpCmdLine;
  if (*start == '-') {
    start++;
    start++;
    while (*start != '\0') {
      if (*start == ' ') {
        start++;
        wcscat(args, start);
        break;
      }
      start++;
    }
    wcscat(args, L"\"");
    ShellExecute(NULL, NULL, path, args, NULL, nCmdShow);
    return 0;
  }

  MessageBox(NULL, L"You have to setup the registry first, sorry.", APP_NAME, MB_ICONWARNING|MB_OK);

  return 0;
}
