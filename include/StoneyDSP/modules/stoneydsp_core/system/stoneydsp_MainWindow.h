/**
 * @file Circle.h
 * @author StoneyDSP (nathanjhood@googlemail.com)
 * @brief
 * @version 1.0.0-init
 * @date 2023-08-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _STONEYDSP_MAINWINDOW_H_
#define _STONEYDSP_MAINWINDOW_H_

#include <string>
#include <iostream>

#include "stoneydsp_DpiScale.h"
#include "stoneydsp_BaseWindow.h"

class MainWindow : public BaseWindow<MainWindow>
{
public:
    MainWindow();
    ~MainWindow();

    PCWSTR ClassName () CONST;
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
    void CalculateLayout();
    HRESULT CreateGraphicsResources();
    void DiscardGraphicsResources();
    HRESULT OnCreate();
    void OnPaint();
    void Resize();
    void OnClose() CONST;
    void OnDestroy();
};

#endif /* _STONEYDSP_MAINWINDOW_H_ */
