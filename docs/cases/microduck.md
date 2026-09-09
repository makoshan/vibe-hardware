# 案例复刻：Microduck / Fanduck

Microduck 是约 25 cm、800 g 的双足机器人。官方把机载软件和强化学习训练拆成两个仓库；Fanduck 是中国地区的 1:1 个人研究复刻记录，补充公开下载包、国内采购状态、Robot HAT、打印件和装配资料。

> 截止 2026-09-09，Fanduck 页面标记为 5 / 7：机械装配完成，部分板端软件与相机已验证，Robot HAT 和其余电子件仍在验收。它不是 Pollen Robotics 官方授权、认证或商业项目。

## 代码

- [官方机载运行时](https://github.com/pollen-robotics/microduck)：Rust，RK3566 上的 50 Hz 控制环、15 个舵机、相机、无线与更新服务
- [官方强化学习仓库](https://github.com/pollen-robotics/microduck_rl)：PPO、MuJoCo / MJCF、BAM 执行器模型和 ONNX 导出
- [Fanduck 公开下载](https://duck.fandcode.com/)：强化学习代码、板端运行包、版本清单与 SHA-256

```bash
git clone https://github.com/pollen-robotics/microduck.git
git clone -b develop https://github.com/pollen-robotics/microduck_rl.git
```

训练不在 1 GB 主控上进行。先在模拟器验证策略与 50 Hz 时序，再进入单电机台架和真实整机。

## 核心 BOM

以下是 Fanduck “原版一致路线”的核心件快照，不是完整订单：

| 类别 | 物料 | 数量 | 2026-09-09 状态 |
|---|---|---:|---|
| 主控 | Radxa ZERO 3W，RK3566 / 1 GB | 1 | 软件烧录完成 |
| 执行器 | DYNAMIXEL XL330-M288-T | 16 | 已验收 |
| 电机通信 | U2D2 + U2D2 PHB | 1 套 | 已收货 |
| 扩展载板 | RPI Robot HAT C1 | 1 | 已到货、待验收 |
| 视觉 | IMX219，8 MP / 77° / 22Pin | 1 | 首次实拍通过 |
| 深度 | VL53L8CX，8×8 ToF | 1 | 待验证 |
| 姿态 | BMI088 + imu_to_dxl v2 | 2 路 | 部分待验证 |
| 供电 | NP-F550，2600 mAh | 2 | 待验证 |
| 声音 | 3525 腔体扬声器，4 Ω / 3 W | 1 | 待验证 |

完整 24 项采购状态、支出和可下载研究文档见 [Fanduck 复刻记录](https://duck.fandcode.com/)。页面显示的累计支出会继续变化，引用时必须带观察日期。

### 不要混进主 BOM 的项目

Fanduck 的国产舵机与国产化 Robot HAT 是单独的概念路线：未采购、未打样、未装机，也没有完成动力学、通信、电源和策略兼容验证。在单台电机台架通过前，不应扩量购买。

## 3D 模型与制造文件

| 资产 | 格式 / 内容 | 入口 |
|---|---|---|
| 官方仿真整机 | MJCF 与 meshes | [microduck_rl assets](https://github.com/pollen-robotics/microduck_rl/tree/develop/src/mjlab_microduck/robot/microduck/assets) |
| 步行件、测试台、滚轮附件 | STL / 3D 打印包 | [Fanduck 下载区](https://duck.fandcode.com/) |
| Robot HAT | KiCad、BOM、Gerber、STEP | [Fanduck 下载区](https://duck.fandcode.com/) |
| 装配与爆炸图 | 第三方装配体、图纸与脚本 | [Fanduck 下载区](https://duck.fandcode.com/) |

3D 模型及衍生资料仅限非商业使用。保留每个下载包内的来源和许可说明，不要脱离原包重新分发。

## 最短复刻顺序

1. 锁定软件、模型与 BOM 版本，保存 SHA-256。
2. 在电脑上运行仿真策略；记录 50 Hz 控制周期。
3. 完成 Radxa 启动、更新、模型推理和相机采集。
4. 单个 XL330 + U2D2 台架测试：ID、零位、限位、断电。
5. Robot HAT 只接逻辑电源验收，再接执行器电源。
6. 分别验收 IMU、ToF、相机、声音和手柄。
7. 支撑架上低增益整机联调；通过后才进入站立与行走。

## 许可与缺口

- 官方机载软件与训练代码：Apache-2.0。
- 官方 / 衍生 3D 资产：非商业、相同方式共享边界；以资产包内文本为准。
- `imu_to_dxl v2` 官方 PCB 当前未公开，Fanduck 兼容板是自行研究路径。
- 页面中的“已验证”只代表对应子项，不代表整机站立或行走通过。
