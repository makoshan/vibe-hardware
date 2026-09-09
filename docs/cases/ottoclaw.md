# 案例复刻：OttoClaw

OttoClaw 是一套运行在 ESP32-S3 上的桌面人形机器人系统。代码使用纯 C / FreeRTOS；一块板集成屏幕、麦克风、喇叭与功放、电源管理、电容触摸、Wi-Fi、蓝牙和 6 路舵机控制。

## 官方入口

- [源码与说明](https://github.com/FlashCat-Jordan/OttoClaw)
- [固件 Releases](https://github.com/FlashCat-Jordan/OttoClaw/releases)
- [PCB + 元件级 BOM](https://oshwhub.com/txp666/ottorobot)
- [MakerWorld 3D 打印模型](https://makerworld.com.cn/%40shanmaotech)
- [完整装配教程](https://www.shanmaotech.cn/ottodiy/)

## 先确认板型

| 板型 | 识别 | 固件 |
|---|---|---|
| OttoRobot AI | 板上无摄像头排线座 | `ottoclaw-full-v2.0-ai.bin` |
| OttoCam519 | 板上有摄像头排线座 | `ottoclaw-full-v2.0-cam519.bin` |

两块板的引脚不同。固件混刷会出现屏幕不亮、舵机不动等问题；摄像头板虽然有接口，仓库说明摄像头功能当前尚未启用。

## 代码

源码编译使用 ESP-IDF 5.5.2：

```bash
git clone https://github.com/FlashCat-Jordan/OttoClaw.git
cd OttoClaw
cp main/ottoclaw_secrets.h.example main/ottoclaw_secrets.h
idf.py set-target esp32s3
idf.py build
idf.py -p PORT flash
```

摄像头板先运行 `idf.py menuconfig`，在 `OttoClaw Board` 中选择 OttoCam519。也可以从 Releases 下载匹配板型的完整固件，从地址 `0x0` 烧录。

## 核心 BOM

这是用于检查采购范围的模块级清单；制造 PCB 时必须使用立创开源硬件项目中的元件级 BOM。

| 类别 | 物料 | 数量 | 说明 |
|---|---|---:|---|
| 主板 | OttoRobot AI 或 OttoCam519 | 1 | 二选一，不混刷固件 |
| 执行器 | PWM 舵机 | 6 | 型号、摆臂和结构件需匹配 |
| 显示 | LCD | 1 | 对应主板接口 |
| 声音输入 | 麦克风 | 1 | 对应主板接口 |
| 声音输出 | 功放 + 喇叭 | 1 套 | 对应主板接口 |
| 交互 | 电容触摸 | 1 | 对应主板接口 |
| 供电与烧录 | USB-C 数据线 / 5 V 电源 | 1 套 | 线必须支持数据 |
| 结构 | MakerWorld STL 打印件 | 1 套 | 按装配教程核对数量 |

## 3D 模型与 PCB

- [MakerWorld @shanmaotech](https://makerworld.com.cn/%40shanmaotech)：打开模型页预览并获取 STL。
- [立创开源硬件](https://oshwhub.com/txp666/ottorobot)：在线查看原理图、PCB、BOM 与 3D 板形。
- [装配教程](https://www.shanmaotech.cn/ottodiy/)：按顺序核对舵机方向、线束和外壳关系。

不要只按外形购买舵机。打印前先核对轴型、摆臂、孔距、舵机中位和输出方向；首次动作测试应拆下摆臂或限制角度。

## 最短复刻顺序

1. 看板上是否有摄像头排线座，确认板型。
2. USB 连接，烧录对应固件；先看屏幕和串口日志。
3. 单舵机测试方向、中位与安全角度。
4. 打印并干装结构件，再连接全部 6 个舵机。
5. 验收麦克风、喇叭、触摸与 Wi-Fi。
6. 最后配置大模型和消息通道；API Key 不进入代码仓库。

## 许可边界

仓库采用 CC BY-NC-SA 4.0：需署名、仅限非商业使用，修改与衍生作品使用相同许可。商业用途需联系原作者另行授权。
