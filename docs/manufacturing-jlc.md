# 嘉立创：PCB、贴片和 3D 打印

“一键下单”只负责把文件带到报价页，不等于设计正确，也不等于订单已付款生产。

## A. PCB 裸板：最短流程

1. 在嘉立创 EDA 专业版完成原理图、封装、板框、布局与布线。
2. 运行 ERC / DRC，人工检查接口方向、孔径、丝印、板厚和安装尺寸。
3. 在 PCB 编辑器使用 **下单 PCB / Order PCB**。系统会从当前 PCB 生成 Gerber 并上传到嘉立创报价页。
4. 核对板材、层数、尺寸、板厚、铜厚、阻焊、表面处理、数量和拼板方式。
5. 下载并保存一份 Gerber 备份；打开 Gerber 预览逐层检查。
6. 加入购物车、填写物流并付款。看到报价页不算下单完成。

官方：[EasyEDA Pro · Order PCB](https://prodocs.easyeda.com/en/pcb/order-order-pcb/) · [嘉立创 PCB](https://www.jlc.com/)

## B. PCBA / SMT：板和元件一起做

需要三类制造文件：

| 文件 | 作用 | 必查字段 |
|---|---|---|
| Gerber + 钻孔 | 制造裸板 | 层、板框、孔、开槽 |
| BOM | 买哪些元件 | Comment/Value、Designator、Footprint、厂商料号、立创商城编号 |
| CPL / Pick & Place | 贴在哪里 | Designator、X、Y、Rotation、Top/Bottom |

流程：

1. 先做“器件标准化”，给元件绑定正确的立创商城 / LCSC 编号。
2. 下单 PCB，开启 **PCB Assembly / SMT**；不要先单独支付裸板。
3. 上传或由 EDA 一键带入 Gerber、BOM、CPL。
4. 在元件匹配页逐行确认型号、封装、库存、数量、价格和替代料。
5. 在贴装预览中重点检查 IC 1 脚、二极管/LED 极性、连接器方向和底层镜像。
6. 未匹配、缺货或未勾选的器件可能默认不贴；明确标出 DNP / 手焊项。
7. 查看生产稿，确认后再付款；生产中继续查看订单状态。

官方：[PCBA 下单步骤](https://jlcpcb.com/help/article/how-do-i-place-a-pcba-order) · [EasyEDA 导出 BOM/CPL](https://jlcpcb.com/help/article/how-to-generate-the-bom-and-pick%26place-file-from-easyeda) · [元件匹配规则](https://jlcpcb.com/help/article/component-matching-guidelines-for-pcba-orders)

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
