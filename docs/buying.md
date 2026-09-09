# 采购入口与核对方法

价格、库存和短链会变化。本页不做返佣，优先给官方规格页、官方商店或平台搜索入口；观察日期：2026-09-09。

## 推荐入口

| 买什么 | 官方 / 稳定入口 | 国内补充入口 | 搜索词 |
|---|---|---|---|
| ESP32-S3-DevKitC-1 N8R8 | [乐鑫购买样品](https://www.espressif.com/en/company/contact/buy-a-sample) | [立创商城搜索](https://so.szlcsc.com/global.html?k=ESP32-S3-DevKitC-1-N8R8) | `ESP32-S3-DevKitC-1 N8R8` |
| XIAO ESP32S3 Sense | [Seeed 产品页](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html) | [矽递科技天猫](https://seeed.tmall.com/) | `XIAO ESP32S3 Sense 排针` |
| M5Stack Cardputer | [M5Stack 商店](https://shop.m5stack.com/products/m5stack-cardputer-kit-w-m5stamps3) | [M5Stack 淘宝搜索](https://s.taobao.com/search?q=M5Stack%20Cardputer) | `Cardputer 原装` |
| Raspberry Pi Zero 2 W | [官方经销商入口](https://www.raspberrypi.com/products/raspberry-pi-zero-2-w/) | [淘宝搜索](https://s.taobao.com/search?q=Raspberry%20Pi%20Zero%202%20W) | `Zero 2 W 带排针` |
| 传感器、连接器、芯片 | [立创商城](https://www.szlcsc.com/) | [淘宝搜索](https://s.taobao.com/) | 型号 + 电压 + 接口 |
| PCB / SMT | [嘉立创 PCB](https://www.jlc.com/) | [嘉立创 EDA 专业版](https://pro.lceda.cn/) | Gerber / BOM / CPL |
| 3D 打印 | [嘉立创 3D 打印](https://www.jlc3dp.cn/) | [JLC3DP 国际站](https://jlc3dp.com/) | STL / STEP / 材料 |

## Starter Kit 搜索清单

复制型号搜索，不用购买“超大全套”：

- `830孔 面包板`、`杜邦线 公公 公母 母母`、`USB-C 数据线`
- `BME280 I2C 3.3V`、`VL53L0X I2C`、`WS2812B 灯环`
- `INMP441 I2S 麦克风`、`MAX98357A I2S 功放`、`4Ω 3W 喇叭`
- `ILI9341 SPI 2.4寸` 或 `SSD1306 I2C 0.96寸`
- `数字万用表 自动量程`、`0.5mm 焊锡`、`恒温电烙铁`

## 下单前七项检查

1. 型号后缀：S3 / C3、N8R8、Sense 是否准确。
2. 工作电压与逻辑电平：ESP32 GPIO 只接受 3.3V。
3. 接口：I²C、SPI、I²S 不要只看商品标题里的“兼容 ESP32”。
4. 排针：是否焊好，间距是否 2.54 mm。
5. USB：接口类型与数据线是否匹配。
6. 文档：能否找到原理图、引脚图和官方示例。
7. 交付：截图保存 SKU、版本、数量、含税/运费与预计到货时间。

淘宝短链只作为社区 BOM 的历史快照，不作为永久推荐；失效时按精确型号重新搜索并核对数据手册。
