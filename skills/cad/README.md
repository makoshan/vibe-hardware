# CAD Skill · 本机使用版本快照

把自然语言需求、参考图或已有 STEP 变成可编辑参数化 CAD，并检查尺寸、几何和装配关系。

此目录是 Mako 本机安装的 `cad` Skill 在 **2026-09-09** 的源码快照。原项目为 [earthtojake/text-to-cad](https://github.com/earthtojake/text-to-cad)，作者为 earthtojake，采用 [MIT 许可证](LICENSE)。这不是 Mako 原创的 CAD 引擎，也不代表上游最新版。

保留了原有运行源码、参考文档与许可证；未包含 Python 缓存、安装元数据、个人项目模型或客户端认证配置。`SNAPSHOT.json` 记录每个原始文件的 SHA-256；无法从已安装目录确定准确上游提交，因此不虚构版本对应关系。

## 能做什么

- build123d 参数化建模，STEP 为主交付物。
- STEP 几何引用、尺寸、定位和装配检查。
- PNG / GIF 预览，以及 STL、3MF、GLB 等派生输出。
- 模型修正后重新生成、检查和预览。

本仓库另有 [Vibe Hardware CAD 工作流](../vibe-hardware-cad/SKILL.md)，用于硬件外壳、元件尺寸、打印公差和实装验收。

## 安装运行依赖

推荐为这个快照使用独立 Python 3.12 环境。依赖文件中的 build123d 等未锁定版本；它是源码快照，不是所有系统均可重现的完整环境镜像。

```sh
git clone https://github.com/makoshan/vibe-hardware.git
cd vibe-hardware/skills/cad
python3.12 -m venv .venv
. .venv/bin/activate
python -m pip install -r requirements.txt
python -m playwright install chromium
python scripts/step --help
python scripts/inspect --help
python scripts/snapshot --help
```

Windows 使用 `.venv\Scripts\activate` 激活环境。浏览器安装用于预览截图；仅查看命令帮助不验证浏览器截图能力。

把整个 `skills/cad` 目录放到你的代理支持的 Skill 目录，或让代理按本目录的 `SKILL.md` 工作。移动目录后应在新位置重新安装可编辑 Python 包。已有同名 Skill 时先保留旧版，不要覆盖正在使用的环境。

## 在自己的项目中使用

告诉代理：

> 使用 CAD Skill，根据我的板卡尺寸设计一个可拆外壳。先列尺寸和假设，保留壁厚、孔径与装配间隙参数，输出 Python 源文件、STEP、打印 STL 和预览，并报告实测前仍需确认的项目。

运行命令时用该环境的 Python 和 Skill 脚本绝对路径，工作目录设为实际项目目录。不要把用户模型写入 Skill 安装目录。

`SKILL.md` 中的 `cad-viewer`、`step-parts` 和 `dxf` 是独立的配套 Skill，不包含在本目录；可从上游项目获取。缺少配套 Skill 时应说明对应限制，不应宣称已经查到真实元件模型或完成交互预览。

## 发布验证

本次发布检查源码文件一致性、许可证、Python 语法及独立环境的命令入口。未将其等同于真实零件设计、物理装配或打印验证。

数字几何检查通过，仍需要实物试装。不同打印机、材料与硬件批次需要单独校准。
