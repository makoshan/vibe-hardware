# Vibe Hardware

面向没有硬件经验的人：用 AI + 便宜开发板，从第一个输入/输出做到可复现的硬件产品。

`docs/` 是完整 Wiki 的单一事实源；网站只做阅读入口，避免两份内容漂移。

## 快速入口

- [首页 / 地图](docs/Home.md)
- [思想](docs/philosophy.md)
- [路线图](docs/roadmap.md)
- [从零到产品 · 四段七步](docs/product-course.md)
- [Starter Kit](docs/starter-kit.md)
- [开发板怎么选](docs/boards.md)
- [采购链接](docs/buying.md)
- [六关学习路径](docs/learning-path.md)
- [工具平台地图](docs/tools.md)
- [嘉立创：PCB / PCBA / 3D 打印](docs/manufacturing-jlc.md)
- [完整案例：Open Duck Mini](docs/cases/open-duck-mini.md)
- [通用 Skill](skills/vibe-hardware/SKILL.md)
- [当前使用的 CAD Skill 源码快照](skills/cad/README.md)
- [3D 建模工作流](skills/vibe-hardware-cad/SKILL.md)
- [PCB / PCBA Skill](skills/vibe-hardware-pcb/SKILL.md)
- [固件与开发板 Skill](skills/vibe-hardware-firmware/SKILL.md)

## 本地浏览

直接打开 `docs/Home.md`，或：

```bash
npx --yes docsify-cli serve docs
```

在线入口：[Vibe Hardware](https://vibe-hardware-mako.makoshan.chatgpt.site/)

> 购买链接不是广告或返佣链接。价格、库存、版本和店铺可能变化，下单前以官方规格和结算页为准。

## 产品教程的内容源

`docs/product-course.json` 是七章产品教程的编辑源；`docs/course-files/` 是练习附件。网站构建前运行 `site/scripts/export-course.mjs`，生成 Wiki Markdown、网站内容和下载文件。请修改源文件后重新生成，不要直接改生成文件。其余 Wiki 继续直接编辑 Markdown。
