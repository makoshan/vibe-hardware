# 开发板怎么选

先回答一个问题：你要运行的是**单片机固件**，还是**完整 Linux / Python / 本地模型**？前者选 ESP32，后者选 Raspberry Pi / Radxa。两类板不能只按算力比较，也不能直接互换。

## 一分钟选择

| 需求 | 默认选择 | 为什么 | 购买前注意 |
|---|---|---|---|
| 面包板、传感器、屏幕、语音联网 | **ESP32-S3-DevKitC-1 N8R8** | 官方板、GPIO 多、8 MB Flash + 8 MB PSRAM | 确认是 S3、N8R8；USB 线可传数据 |
| 小型穿戴、摄像头、数字麦克风 | **XIAO ESP32S3 Sense** | 体积小，Sense 扩展板含摄像头、麦克风、microSD | 默认无排针，通常需要焊接；摄像头批次可能不同 |
| 不想接屏幕、键盘、麦克风、喇叭 | **M5Stack Cardputer** | ESP32-S3 外设已集成，适合先做交互 | 屏幕仅 1.14 英寸；扩展主要走 Grove |
| 跑 Linux、Python、ONNX 和机器人运行时 | **Raspberry Pi Zero 2 W** | Open Duck Mini v2 的官方运行时基准板 | 512 MB RAM；排针可能未焊；micro-USB |
| 想做 Rockchip / ARM64 移植 | **Radxa ZERO 3W** | 最高 8 GB、USB 3 Host、Wi-Fi 6 | 是移植项目，不是 Pi Zero 2 W 的软件替代品 |

## 1. ESP32-S3-DevKitC-1 N8R8：通用默认板

- 适合：GPIO、I²C、SPI、I²S、Wi-Fi、BLE、屏幕、传感器、联网语音。
- N8R8 表示 8 MB Flash + 8 MB PSRAM；语音缓冲、摄像头和 LVGL 更从容。
- 面包板上可能占较宽空间，可准备两块小面包板或扩展底板。
- GPIO 是 3.3V 逻辑；5V 只用于明确支持 5V 供电的模块。
- 官方：[用户指南与引脚图](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/index.html) · [购买样品入口](https://www.espressif.com/en/company/contact/buy-a-sample)

## 2. XIAO ESP32S3 Sense：小型语音与视觉

- Sense 版本由 XIAO ESP32S3 + 扩展板组成，扩展板提供摄像头、数字麦克风和 microSD。
- 官方资料包含原理图、KiCad 工程、封装和 DXF 尺寸，适合后续做载板与外壳。
- 当前官方说明提示摄像头已从 OV2640 逐步切换为 OV3660；买到手先确认批次。
- 官方：[入门与开源工程](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) · [产品入口](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html)

## 3. M5Stack Cardputer：最短交互闭环

- 已集成 56 键键盘、1.14 英寸 TFT、数字麦克风、喇叭、microSD 和电池。
- 适合语音备忘、遥控器、小终端和桌面 AI 入口；不适合需要大量裸 GPIO 的面包板课程。
- 官方：[规格、原理图与结构文件](https://docs.m5stack.com/en/core/Cardputer) · [商店](https://shop.m5stack.com/products/m5stack-cardputer-kit-w-m5stamps3)

## 4. Raspberry Pi Zero 2 W：Linux 小电脑

- 四核 1 GHz Cortex-A53、512 MB RAM、2.4 GHz Wi-Fi、Bluetooth 4.2/BLE，尺寸 65 × 30 mm。
- 可跑 Linux、Python 和 ONNX Runtime；不是实时单片机，启动、文件系统和供电都要单独管理。
- 官方：[规格与授权经销商](https://www.raspberrypi.com/products/raspberry-pi-zero-2-w/)

## 5. Radxa ZERO 3W：进阶移植板

- RK3566 四核 Cortex-A55、1–8 GB RAM、Wi-Fi 6、USB 3 Host，尺寸同为 65 × 30 mm。
- 外形相近不等于软件兼容。树莓派 GPIO 编号、I²C 总线、镜像、Python 依赖和设备树都要重做。
- 用于 Open Duck Mini 时，先验证系统 → ONNX 推理 → USB 舵机板 → BNO055 → 足底 GPIO → 50 Hz 控制循环，再谈整机行走。
- 官方：[Radxa ZERO 3 文档](https://docs.radxa.com/en/zero/zero3)

## 收货后五项验收

1. 拍下板卡正反面、包装 SKU 和芯片丝印。
2. 使用可传数据的 USB 线，确认电脑能识别串口或 USB 设备。
3. 跑官方 Blink / 串口示例，不先改库。
4. 用万用表确认 3.3V、5V 和 GND；断电后再接模块。
5. 把实际板型、Flash/PSRAM、引脚和测试结果写进项目 README。
