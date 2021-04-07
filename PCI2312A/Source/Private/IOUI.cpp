/** Copyright (c) 2018 Hefei And Technology Co.,Ltd
 *  Author: MrBaoquan
 *  CreateTime: 2018-5-16 10:44
 *  Email: mrma617@gmail.com
 */

#include "IOUI.h"
#include "PCIManager.hpp"
#include "PCI2312A.h"

#ifdef WIN_64
#pragma comment(lib,"PCI2312A_64.lib")
#else
#pragma comment(lib,"PCI2312A_32.lib")
#endif

/** �豸������Ϣ */
DeviceInfo g_DeviceInfo; 

IOUI_API DeviceInfo* __stdcall Initialize()
{
    g_DeviceInfo.InputCount = 16;
    g_DeviceInfo.OutputCount = 16;
    g_DeviceInfo.AxisCount = 16;

    return &g_DeviceInfo;
}

IOUI_API int __stdcall OpenDevice(uint8 deviceIndex)
{
    HANDLE hHandle = PCI2312A_CreateDevice(deviceIndex);
    if (hHandle!=INVALID_HANDLE_VALUE)
    {
		PCIManager::Instance().AddDevice(deviceIndex, DeviceData(hHandle, g_DeviceInfo));
        return 1;
    }
    return 0;
}

IOUI_API int __stdcall CloseDevice(uint8 deviceIndex)
{
    HANDLE hHandle = PCIManager::Instance().GetHandle(deviceIndex);
    return PCI2312A_ReleaseDevice(hHandle) ? 1 : 0;
}

IOUI_API int __stdcall SetDeviceDO(uint8 deviceIndex, short* InDOStatus)
{
	const DeviceData* _devData = PCIManager::Instance().GetDeviceData(deviceIndex);
	if (!_devData) { return 0; }
	CopyTo(InDOStatus, _devData->DOStatus(),g_DeviceInfo.OutputCount);
    return PCI2312A_SetDeviceDO(_devData->handle, _devData->DOStatus()) ? 1 : 0;
}

IOUI_API int __stdcall GetDeviceDO(uint8 deviceIndex, short* OutDOStatus)
{	
	const DeviceData* _devData = PCIManager::Instance().GetDeviceData(deviceIndex);
	if (!_devData) { return 0; }
    int _retCode = PCI2312A_GetDeviceDO(_devData->handle, _devData->DOStatus()) ? 1 : 0;
	CopyTo(_devData->DOStatus(), OutDOStatus, g_DeviceInfo.OutputCount);
	return _retCode;
}

IOUI_API int __stdcall GetDeviceDI(uint8 deviceIndex, BYTE* OutDIStatus)
{
    HANDLE hHandle = PCIManager::Instance().GetHandle(deviceIndex);
	ZeroMemory(OutDIStatus, g_DeviceInfo.InputCount);
    int _retCode = PCI2312A_GetDeviceDI(hHandle, OutDIStatus) ? 1 : 0;
	return _retCode;
}

IOUI_API int __stdcall GetDeviceAD(uint8 deviceIndex, short* OutADStatus)
{
    return 0;
}
