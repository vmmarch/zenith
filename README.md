# Zenith 3D游戏引擎

![LOGO](https://github.com/orvals/zenith/blob/master/resources/zlogo.png)

zenith 3D游戏引擎

# GIT Clone

    git clone --recursive <url>

# 代码风格

- 所有类名首字母大写
- 所有类名的方法首字母大写
- 成员变量命名使用m_开头然后紧跟着成员名，成员名首字母大写，例如: m_Name
- 宏定义使用双下划线开头，并以双下划线结尾
- 普通方法命名全小写，除非一些特殊单词。比如GLFW。单词之间使用下划线分割
- 常量命名全大写，并使用下划线分割单词。
- 类型定义，如果是方法就使用f开头，如果是基本类型就使用v开头，例如：v_int

# 注意(使用/构建前必看)
- 平台：目前仅支持windows-x64
- Cmake版本：3.20.0-rc4或以上。
- MinGW-W64-builds-4.3.5或以上。
- 子模块ImGui分支切换到docking分支。
