# 嘉立创：PCB、贴片和 3D 打印

“一键下单”只负责把文件带到报价页，不等于设计正确，也不等于订单已付款生产。

网页实操版：[EDA → PCB → SMT 完整教程](https://vibe-hardware.v2eth.workers.dev/manufacturing)

## 0. 嘉立创 EDA 专业版：从原理图到 PCB

1. 打开[嘉立创 EDA 专业版](https://pro.lceda.cn/editor)，选择 **文件 → 新建 → 工程**。默认板子已经包含原理图和 PCB。
2. 在原理图放置器件、连接导线并填写位号与数值。计划交给嘉立创贴片的元件，优先选择有立创商城编号、可贴片且有库存的型号。
3. 运行 **设计 → 检查 DRC**，修正错误后选择 **设计 → 更新/转换原理图到 PCB**。
4. 先绘制闭合板框和安装孔，再布局。连接器放在板边，去耦电容靠近芯片电源脚，并对照实物确认接口方向。
5. 设置设计规则，完成布线与铺铜；检查未连接飞线，再运行 PCB DRC。
6. 打开 2D / 3D 预览，复核板框、孔位、丝印、USB/FPC/排针方向，保存带版本号的工程副本。

官方：[快速入门](https://prodocs.lceda.cn/cn/quick-start.html) · [原理图设计](https://prodocs.lceda.cn/cn/private/designer/design-schematic.html) · [PCB 设计](https://prodocs.lceda.cn/cn/private/designer/design-pcb.html) · [官方视频教程](https://prodocs.lceda.cn/cn/faq/video-tutorial/index.html)

## A. PCB 裸板：最短流程

1. 在嘉立创 EDA 专业版完成原理图、封装、板框、布局与布线。
2. 运行 ERC / DRC，人工检查接口方向、孔径、丝印、板厚和安装尺寸。
3. 在 PCB 编辑器使用 **导出 → PCB 制板文件（Gerber）**；也可以选择 **下单 → PCB 下单**，让系统生成并上传 Gerber。
4. 核对板材、层数、尺寸、板厚、铜厚、阻焊、表面处理、数量和拼板方式。
5. 下载并保存一份 Gerber 备份；打开 Gerber 预览逐层检查。
6. 加入购物车、填写物流并付款。看到报价页不算下单完成。

官方：[导出 Gerber](https://prodocs.lceda.cn/cn/pcb/export-pcb-fabrication-file-gerber/) · [PCB 一键下单](https://prodocs.lceda.cn/cn/pcb/order-order-pcb/index.html) · [嘉立创 PCB](https://www.jlc.com/)

## B. PCBA / SMT：板和元件一起做

需要三类制造文件：

| 文件 | 作用 | 必查字段 |
|---|---|---|
| Gerber + 钻孔 | 制造裸板 | 层、板框、孔、开槽 |
| BOM | 买哪些元件 | Comment/Value、Designator、Footprint、厂商料号、立创商城编号 |
| CPL / Pick & Place | 贴在哪里 | Designator、X、Y、Rotation、Top/Bottom |

流程：

1. 先做“器件标准化”，给元件绑定正确的立创商城 / LCSC 编号。商城散件库存与 SMT 贴片库存不是同一个库存。
2. 下单 PCB，开启 **PCB Assembly / SMT**；不要先单独支付裸板。
3. 上传或由 EDA 一键带入 Gerber、BOM、CPL。
4. 在元件匹配页逐行确认型号、封装、库存、数量、价格和替代料。
5. 在贴装预览中重点检查 IC 1 脚、二极管/LED 极性、连接器方向和底层镜像。
6. 未匹配、缺货或未勾选的器件可能默认不贴；明确标出 DNP / 手焊项。
7. 查看生产稿，确认后再付款；生产中继续查看订单状态。

官方：[PCB / SMT 完整下单流程](https://docs.lceda.cn/cn/PCB/Order-PCB/index.html) · [导出 BOM](https://prodocs.lceda.cn/cn/pcb/export-bill-of-materials-bom/index.html) · [导出坐标文件](https://prodocs.lceda.cn/cn/pcb/export-pick-and-place-file/) · [PCBA 下单步骤](https://jlcpcb.com/help/article/how-do-i-place-a-pcba-order)

## C. 只买零件

在 EasyEDA Pro PCB 编辑器选择 **Export → Order Parts at LCSC**。先做器件标准化，再导出 BOM 到立创商城。注意：为 JLCPCB 贴片预订的“我的零件库”库存通常用于后续 PCBA，并不等同于寄到家里的散件。

官方：[Order Parts at LCSC](https://prodocs.easyeda.com/en/pcb/order-order-parts/) · [自有/预订库存说明](https://jlcpcb.com/help/article/how-to-use-my-own-parts-for-pcb-assembly-order)

## D. 嘉立创 3D 打印

1. 在 CAD 中按毫米建模；一个文件只放一个零件。
2. 优先上传 STL；需要保留精确曲面时同时准备 STEP/STP。
3. 检查法线、封闭实体、壁厚、螺丝孔、热熔螺母孔和装配间隙。
4. 上传到 3D 打印报价页，选择材料、颜色、表面处理和数量。
5. 查看系统给出的尺寸、重量、壁厚和可制造性检查。
6. 加入购物车后仍要等待人工审核；收到审核结果后复核并付款。

Open Duck Mini 官方建议主体标准 PLA、15% 填充；`foot_bottom_tpu.stl` 用 TPU、40% 填充。外包打印时把材料和填充率写进文件名或订单备注，不能只上传一堆 STL。

官方：[JLC3DP 下单帮助](https://jlc3dp.com/help/catalog/274-3D%20Printing%20Ordering) · [Open Duck Mini 打印说明](https://github.com/apirrone/Open_Duck_Mini/blob/v2/docs/print_guide.md)

## 制造前最后一次人工验收

- PCB：DRC、Gerber、钻孔、板框、层叠、阻抗、拼板。
- SMT：BOM、CPL、封装、库存、替代料、极性、贴装方向。
- 结构：单位、尺寸、壁厚、公差、材料、数量、左右件。
- 订单：收货地址、税费、运费、审核状态和最终付款状态。
