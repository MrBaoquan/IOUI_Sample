
// IOUIDebugDlg.h : 头文件
//

#pragma once
#include "IODeviceController.h"

namespace IO = IOToolkit;

// CIOUIDebugDlg 对话框
class CIOUIDebugDlg : public CDialogEx
{
// 构造
public:
	CIOUIDebugDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IOUIDEBUG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
    void OnSampleAxis(float InValue);
    void OnKeyDown(const IO::FKey InKey);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
};
