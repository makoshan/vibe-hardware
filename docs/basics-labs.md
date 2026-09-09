# 六个 ESP32-S3 入门实验

统一使用 ESP32-S3-DevKitC-1、Arduino-ESP32 3.x 和 USB 供电。每次只接一个实验，先运行成熟示例，再修改一个变量。完整代码、接线与验收标准见网站的 [入门教程](https://vibe-hardware.v2eth.workers.dev/learn)。

| 顺序 | 接口 | 实验 | 成熟教程 |
|---:|---|---|---|
| 01 | GPIO | 外接 LED 每秒闪烁 | [乐鑫 Blink 交互教程](https://docs.espressif.com/projects/arduino-esp32/en/latest/tutorials/blink.html) |
| 02 | PWM | LED 呼吸灯 | [乐鑫 LEDC / PWM](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html) |
| 03 | ADC | 读取 10 kΩ 电位器 | [乐鑫 ADC API](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html) |
| 04 | I²C | SSD1306 OLED 显示文字 | [Adafruit SSD1306](https://learn.adafruit.com/monochrome-oled-breakouts?view=all) · [乐鑫 I²C](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/i2c.html) |
| 05 | SPI | ST7789 彩屏显示文字 | [Adafruit ST7789 接线与测试](https://learn.adafruit.com/adafruit-1-3-and-1-54-240-x-240-wide-angle-tft-lcd-displays/arduino-wiring-test) · [乐鑫 SPI](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/spi.html) |
| 06 | UART | GPIO17 TX → GPIO18 RX 回环 | [乐鑫 Serial / UART](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/serial.html) |

## 统一安全边界

- GPIO 只接受 3.3 V 逻辑；ADC 输入不得超过 3.3 V。
- LED 必须串联 220–330 Ω 限流电阻。
- 屏幕先核对控制器、分辨率和供电电压；同样尺寸不代表驱动相同。
- I²C 不通先扫描地址；SPI 白屏先分别检查背光、CS、DC、RST 和分辨率。
- UART 外接模块前核对 TX/RX 电平，并交叉连接 TX → RX。
- 烧录成功只证明固件写入；必须观察 LED、屏幕或串口的实际结果。
