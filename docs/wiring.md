# 最小接线约定

为减少不同项目冲突，建议统一使用下列引脚（ESP32-S3-DevKitC-1）。

## I²C 传感器（BME280 / VL53L0X / PN532 等）

| 信号 | GPIO |
|---|---|
| SDA | GPIO1 |
| SCL | GPIO2 |

## INMP441 麦克风

| 信号 | 连接 |
|---|---|
| BCLK | GPIO4 |
| WS | GPIO5 |
| SD | GPIO6 |
| VDD | 3.3V |

## MAX98357A 功放

| 信号 | 连接 |
|---|---|
| BCLK | GPIO4 |
| LRC | GPIO5 |
| DIN | GPIO7 |
| VIN | 5V |

## ILI9341 显示屏

| 信号 | GPIO |
|---|---|
| RST | GPIO8 |
| DC | GPIO9 |
| CS | GPIO10 |
| MOSI | GPIO11 |
| SCK | GPIO12 |

## WS2812 灯环

| 信号 | GPIO |
|---|---|
| DIN | GPIO15 |

## 必须

所有模块连接**共同的 GND**。

改线前先断电。细节见 [safety.md](safety.md)。
