# Vibe Hardware 入门地图

目标不是学完整电子工程，而是几小时内跑通：

**传感器输入 → ESP32 处理 / 调用 AI → 屏幕、灯光或声音反馈**

思想见 [philosophy.md](philosophy.md)。总览见 [从零到产品路线图](roadmap.md)。

## 三层材料（别混在一起）

| 层 | 用途 | 本仓库 |
|---|---|---|
| 1. 入门地图 | 路线、套件、工具、安全 | `docs/` |
| 2. 工作坊 | 2 小时：集成板或面包板 + 六关 | [学习路径](learning-path.md) |
| 3. 进阶制造 | PCB、外壳、打板、小批量 | [路线图](roadmap.md) 后半 |

## 一条真实路线

需求 → AI 辅助拆解 → **开发板验证** → 固件 → PCB → 外壳 → 打板与打印 → 实物验收

第一次项目通常先交付到「开发板验证 + 固件」，再决定是否画 PCB、做外壳。

## 目录

- [思想](philosophy.md)
- [从零到产品路线图](roadmap.md)
- [Starter Kit](starter-kit.md)
- [开发板怎么选](boards.md)
- [采购入口与核对方法](buying.md)
- [六关学习路径](learning-path.md)
- [最小接线约定](wiring.md)
- [硬件安全规则](safety.md)
- [工具平台地图](tools.md)
- [适合新手的项目](projects.md)
- [嘉立创 PCB / PCBA / 3D 打印](manufacturing-jlc.md)
- [完整案例：Open Duck Mini](cases/open-duck-mini.md)
- [资源与案例](resources.md)

## 简化原则

- 每人只配**基础包**
- 麦克风、喇叭、屏幕、NFC **按小组共享**
- 项目定了再加摄像头、电机或电池
- 想快速成功，优先选集成屏幕、麦克风和喇叭的板
