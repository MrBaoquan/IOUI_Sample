/** Copyright (c) 2018 Hefei And Technology Co.,Ltd
 *  Author: MrBaoquan
 *  CreateTime: 2018-506 10:44
 *  Email: mrma617@gmail.com
 */

#pragma once

#ifdef IOUI_EXPORTS
#define IOUI_API __declspec(dllexport)
#else
#define IOUI_API __declspec(dllimport)
#endif

typedef unsigned __int8 uint8;
typedef unsigned   char BYTE;

struct IOUI_API DeviceInfo
{
    /** ����ͨ������ */
    BYTE InputCount = 16;
    /** ���ͨ������ */
    BYTE OutputCount = 16;
    /** ģ����ͨ������ */
    BYTE AxisCount = 0;
};

extern "C"
{
    IOUI_API DeviceInfo* __stdcall Initialize();

    /**
     * �� External �豸
     * @param deviceIndex : �豸����
     * @return �ɹ�����1 ���򷵻� 0
     */
    IOUI_API int __stdcall OpenDevice(uint8 deviceIndex);
    
    /**
    * �ر� External �豸
    * @param deviceIndex : �豸����
    * @return �ɹ�����1 ���򷵻� 0
    */
    IOUI_API int __stdcall CloseDevice(uint8 deviceIndex);

    /**
    * ���� External �豸���״̬
    * @param deviceIndex : �豸����
    * @param InDOStatus : ���뿪����״̬ BYTE[32]
    * @return �ɹ�����1 ���򷵻� 0
    */
    IOUI_API int __stdcall SetDeviceDO(uint8 deviceIndex, short* InDOStatus);
    
    /**
    * ��ȡ External �豸���״̬
    * @param deviceIndex : �豸����
    * @param InDOStatus : ���������״̬ BYTE[32]
    * @return �ɹ�����1 ���򷵻� 0
    */
    IOUI_API int __stdcall GetDeviceDO(uint8 deviceIndex, short* OutDOStatus);

    /**
    * ��ȡ External �豸����״̬
    * @param deviceIndex : �豸����
    * @param InDOStatus : ���뿪����״̬ BYTE[32]
    * @return �ɹ�����1 ���򷵻� 0
    */
    IOUI_API int __stdcall GetDeviceDI(uint8 deviceIndex, BYTE* OutDIStatus);

    /**
    * ���� External �豸���״̬
    * @param deviceIndex : �豸����
    * @param OutADStatus : ���ģ����״̬ short[32] ȡֵ��Χ������[-1000,1000]
    * @return �ɹ�����1 ���򷵻� 0
    */
    IOUI_API int __stdcall GetDeviceAD(uint8 deviceIndex, short* OutADStatus);
};