# 完整案例：Open Duck Mini v2

这是一个约 42 cm 高的双足机器人开源项目。官方仓库同时提供 CAD、BOM、STL、装配说明、MuJoCo / 强化学习材料和 Raspberry Pi Zero 2 W 运行时；仓库也明确说明它仍是 working repo，装配文档存在未完成项。

## 官方入口

- [主仓库（v2）](https://github.com/apirrone/Open_Duck_Mini/tree/v2) · Apache-2.0
- [Onshape 可旋转整机 CAD 预览](https://cad.onshape.com/documents/64074dfcfa379b37d8a47762/w/3650ab4221e215a4f65eb7fe/e/0505c262d882183a25049d05)
- [STL 目录：点击单个文件可在 GitHub 旋转预览](https://github.com/apirrone/Open_Duck_Mini/tree/v2/print)
- [官方 BOM](https://docs.google.com/spreadsheets/d/1gq4iWWHEJVgAA_eemkTEsshXqrYlFxXAPwO515KpCJc/edit?usp=sharing)
- [中文 BOM / 飞书](https://zihao-ai.feishu.cn/wiki/AfAtw69vRigXaRk5UkbcrAiLnJw)
- [Tnkr 制作指南](https://tnkr.ai/explore/docs/open-duck-mini/open-duck-mini-v2#home)
- [中文教程空间](https://zihao-ai.feishu.cn/wiki/space/7488517034406625281)
- [官方运行时](https://github.com/apirrone/Open_Duck_Mini_Runtime/tree/v2)

## 系统结构

```text
手柄 / 高层命令
       ↓
Raspberry Pi Zero 2 W ── BNO055 姿态
       │                 足底微动开关
       ↓ USB / 串口
总线舵机控制板 ── 14 × STS3215（腿、躯干、头部）
       └──────── 2 × 9g 舵机（耳朵，可选表情）
```

走路主链和表情/语音附件应分开验收。先让主控、IMU、足底开关、单个舵机与急停可靠，再装完整机器人。

## 中文 BOM 快照

以下整理自用户提供的飞书表格导出，快照日期 2026-09-03；表内汇总约 **¥2,119.37**，未完整包含运费、耗材和所有工具。价格与短链会失效，以官方 BOM、实际库存和结算页为准。

| 类别 | 部件 | 规格 | 数量 | 快照小计 |
|---|---|---|---:|---:|
| 结构 | 3D 打印件 | PLA + TPU，见打印清单 | 1 套 | ¥170 |
| 电源 | 18650 电芯 | 3.7V，高放电；两节系统 | 1 组 | ¥68 |
| 电源 | 电池盒 + 2S BMS + 5V UBEC | 2 节串联、8.4V 充电 | 各 1 | ¥78.97 |
| 主控 | Raspberry Pi Zero 2 W | 512 MB | 1 | ¥125 |
| 存储 | microSD | 建议 32 GB 以上 | 1 | ¥65 |
| 姿态 | BNO055 IMU 模块 | I²C | 1 | ¥79 |
| 舵机控制 | 串口总线舵机驱动板 | 飞特 ST/SC 系列 | 1 | ¥24 |
| 主执行器 | Feetech STS3215-C001 | 7.4V 19 kg·cm | 14 | ¥1,316 |
| 表情 | 9g 塑料齿舵机 | 180° | 2 | ¥19.6 |
| 触地 | SS-10 微动开关 | 无柄 | 4 | ¥19.2 |
| 机械 | 6804-ZZ 轴承 | 20 × 32 × 7 mm | 3 | ¥16.5 |
| 紧固 | M3 热熔螺母、螺丝、螺柱 | 多长度 | 1 批 | 另计 |
| 语音 | I²S 麦克风 + MAX98357A + 喇叭 | 表情扩展，非先决条件 | 1 套 | 约 ¥40+ |
| 操作 | 兼容 Xbox 的手柄 | 社区表补充项 | 1 | 约 ¥79.9 |

### 电池安全

- 不建议新手自行焊裸 18650；优先使用带可靠保护、绝缘和固定的电池方案。
- 两节电池不可装反，不混用不同电量、不同批次或受损电芯。
- 舵机动力电源和主控供电必须按原方案核对，不能从 GPIO 给舵机供电。
- 第一次上电串联限流或使用带电流显示的电源，并准备物理断电方式。

## 3D 打印清单

官方打印说明要求主体 PLA 15% 填充，脚底 TPU 40% 填充。数量较多的左右件必须按官方清单核对；不要根据文件数猜数量。

| 组件组 | 代表文件 | 数量提示 |
|---|---|---|
| 脚 | `foot_top`, `foot_side`, `foot_bottom_pla`, `foot_bottom_tpu` | 各 ×2 |
| 小腿 | `knee_to_ankle_left/right_sheet` | 左右各 ×4 |
| 腿部连接 | `leg_spacer` | ×4 |
| 髋/滚转 | `left/right_roll_to_pitch`, `roll_motor_top/bottom` | 左右件 + 上下件 |
| 躯干 | `trunk_top`, `trunk_bottom`, `body_front/back/middle_*` | 各 ×1 |
| 头颈 | `neck_*`, `head*`, `antenna_holder`, `cache` | 左右件分别检查 |
| 表情 | `eye`, `bulb`, `flash_*`, `speaker_*` | 可在走路主链完成后添加 |

完整数量以 [官方 Print Guide](https://github.com/apirrone/Open_Duck_Mini/blob/v2/docs/print_guide.md) 为准。嘉立创打印流程见 [制造页](../manufacturing-jlc.md)。

## 分阶段复现

1. **文件审计**：锁定 v2 分支，保存 BOM、STL、运行时版本和修改记录。
2. **主控**：Zero 2 W 启动、SSH、依赖安装与 ONNX 模型单独推理。
3. **传感器**：BNO055 方向正确；四个足底开关能稳定触发。
4. **单舵机**：设置 ID / 零位 / 限位，低速、无负载验证，并测试急停。
5. **机械子组件**：脚、小腿、髋、躯干、头分别装配；记录螺丝和热熔螺母数量。
6. **整机静态**：线束不夹伤，关节不干涉，电池牢固，断电方式可达。
7. **低风险运动**：悬空或支撑架上测试，再逐步进入站立与行走。
8. **表情与语音**：眼灯、耳朵、麦克风和喇叭最后加入，避免干扰走路排障。

## 换成 Radxa ZERO 3W？

可以作为进阶移植，但不是直接替换。需要重做系统镜像、Python 版本、I²C/GPIO 映射、板型识别和时延测试。已有 Rockchip 社区分支可作线索：[feisuo/Open_Duck_Mini_Runtime_Rockchip](https://github.com/feisuo/Open_Duck_Mini_Runtime_Rockchip)，但不能据此认定 ZERO 3W 已通过整机行走验证。

最低验收顺序：启动与 SSH → CPU 推理 → USB 舵机板 1 Mbps → BNO055 → 足底 GPIO → 20 ms 控制周期 → 单舵机 → 整机。
