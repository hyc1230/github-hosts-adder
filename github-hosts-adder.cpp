#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "SHLOBJ.H"
using namespace std;

/*
# GitHub Start

140.82.112.4       github.com
140.82.114.20      gist.github.com
185.199.110.154    github.githubassets.com
199.232.69.194     github.global.ssl.fastly.net
151.101.184.133    assets-cdn.github.com
151.101.184.133    raw.githubusercontent.com
151.101.184.133    gist.githubusercontent.com
151.101.184.133    cloud.githubusercontent.com
151.101.184.133    camo.githubusercontent.com
199.232.96.133     avatars.githubusercontent.com

# GitHub End
*/

int main(int argc, char* argv[])
{
	if (!(argc >= 2 && strcmp(argv[1], "admin") == 0))
	{
		ShellExecute(NULL, "runas", argv[0], "admin", NULL, SW_SHOWNORMAL);
		return 0;
	}
	char Path[1024];
	SHGetSpecialFolderPath(0, Path, CSIDL_WINDOWS, 0);
	cout << "Windows�ļ���: " << Path << endl;
	strcat(Path, "\\System32\\drivers\\etc\\hosts");
	cout << "Hosts�ļ�·��: " << Path << endl;
	cout << "  ��Hosts..." << endl;
	ofstream fout(Path, ios::app);
	cout << "  �Ѵ�Hosts" << endl;
	cout << "  д��GitHub��������Ϣ..." << endl;
	fout << "\n\n# GitHub Start\n\n140.82.112.4       github.com\n140.82.114.20      gist.github.com\n185.199.110.154    github.githubassets.com\n199.232.69.194     github.global.ssl.fastly.net\n151.101.184.133    assets-cdn.github.com\n151.101.184.133    raw.githubusercontent.com\n151.101.184.133    gist.githubusercontent.com\n151.101.184.133    cloud.githubusercontent.com\n151.101.184.133    camo.githubusercontent.com\n199.232.96.133     avatars.githubusercontent.com\n\n# GitHub End\n";
	cout << "  �ر�Hosts..." << endl;
	fout.close();
	cout << "�����" << endl;
	cout << "�밴������˳�...";
	_getch();
	return 0;
}

