# 资源与案例

## 1. 最接近「Vibe Hardware」的项目

### vibe-hardware

[luckiday/vibe-hardware](https://github.com/luckiday/vibe-hardware) 与方向最接近，覆盖：

- 自然语言需求
- ESP32 固件
- KiCad PCB
- build123d 外壳
- JLCPCB 制造文件
- 浏览器检查
- 固件、PCB、结构尺寸同步

仓库仍早期，部分示例 PCB / 外壳为占位。**适合引用方法，不适合直接当学员教程。**

### autonomous-vibe

[autonomous-ai/autonomous-vibe](https://github.com/autonomous-ai/autonomous-vibe) 主打聊天生成 CAD、导出 STEP/STL 与 3D 打印。适合「AI 辅助建模」示范，**不覆盖电路、固件、PCB**。

### F13 Vibe Hardware Slides

[crafter-station/vibe-hardware-f13-slides](https://github.com/crafter-station/vibe-hardware-f13-slides) 约 27 页演讲，ESP32 小车案例：电源、引脚、传感器、万用表排障、真实验证。结构可参考；许可证未明确，README 仍要求替换占位图与补真实硬件证据。

## 2. 可贯穿全流程的开源手表

| 项目 | 可用材料 | 放进地图的位置 |
|---|---|---|
| [Watchy](https://github.com/sqfmi/Watchy) | ESP32、电子纸、固件、硬件文档、原理图、BOM | 「先基于成熟硬件做软件」 |
| [Open-SmartWatch](https://open-smartwatch.github.io/) | KiCad、Gerber、BOM、固件、3D 打印外壳 | 「从开源进入 PCB 和结构」 |
| [Gateway Smartwatch](https://github.com/RoboticWorx/Gateway-Smartwatch) | 代码、BOM、Gerber、组装资料 | 社区案例；许可证需单独核实 |

Watchy 最适合新手理解完整产品；Open-SmartWatch 适合展示真实原理图 / PCB / 制造文件。

## 2.1 可复现案例库

| 案例 | 核心材料 | 适合学习 |
|---|---|---|
| [Open Duck Mini v2](cases/open-duck-mini.md) | Onshape、STL、BOM、装配、运行时、强化学习 | 机器人整机与高风险执行器验证 |
| [Watchy](https://github.com/sqfmi/Watchy) | ESP32、电子纸、硬件资料、固件 | 从成熟开发板做功能和外壳 |
| [Open-SmartWatch](https://github.com/Open-Smartwatch/open-smartwatch) | KiCad、Gerber、BOM、固件、3D 外壳 | 从开源工程进入 PCB 和装配 |
| [Autonomous Vibe](https://github.com/autonomous-ai/autonomous-vibe) | 自然语言生成 CAD、STEP/STL、打印 | AI 辅助结构建模，不含电路链路 |

案例进入本 Wiki 的最低标准：有公开工程源文件或制造文件；能明确许可证和版本；把“作者演示成功”与“我们已经复现”分开。

## 3. 国内入门材料

### 立创实战派 ESP32-S3

[立创实战派 ESP32-S3 教程](https://wiki.lckfb.com/zh-hans/szpi-esp32s3/beginner/introduction.html) 最适合国内 **2 小时工作坊**。

板载集成：ESP32-S3（16MB Flash / 8MB PSRAM）、2 英寸触摸屏、摄像头、双麦与编解码/扬声器、六轴、TF、USB 调试。

教程覆盖按键、IMU、音视频、LVGL、摄像头、Wi-Fi / 蓝牙、语音唤醒、人脸检测。[课程目录](https://wiki.lckfb.com/zh-hans/szpi-esp32s3/beginner/prepare.html)

比「裸 ESP32 + 一堆杜邦线」更容易成功。面包板 [Starter Kit](starter-kit.md) 仍作电子基础实验包。

### PCB 设计与打板

[嘉立创 EDA 专业版快速入门](https://prodocs.lceda.cn/cn/quick-start.html) 覆盖：原理图、封装、布局布线、BOM、坐标文件、Gerber、STEP、一键下单。

视频：

- [小白入门：立创 EDA 设计简单 PCB](https://www.bilibili.com/video/BV1dU4y187fN/)
- [嘉立创 EDA 快速入门教程](https://www.bilibili.com/video/BV1Ww411e7zu/)

## 4. 官方文档

- [乐鑫 ESP32-S3-DevKitC-1](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/index.html)
- [Arduino-ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
- [ESP-IDF](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/)
- [ESP-SR](https://github.com/espressif/esp-sr)
- [nav.al/hardware](https://nav.al/hardware)

## 5. 风险与触发条件

- **30 分钟分享**：PCB / CAD 只讲流程，不承诺教会。
- **2 小时工作坊**：用集成 ESP32-S3 板，完成传感器、屏幕、语音链路。
- **自己画板并下单**：至少一天的 PCB 工作坊。
- **可佩戴手表**：电池安全、充电、功耗、公差、佩戴测试 → 独立项目。
- GitHub 上「Vibe Hardware」项目仍新：**未经验证的步骤不要写进教学 checklist。**
