---
name: vibe-hardware-pcb
description: Design, review, and prepare small hardware PCBs and PCB assemblies for fabrication. Use for schematics, footprints, layout, Gerber, drill files, BOM, CPL, LCSC part matching, EasyEDA, KiCad, JLCPCB, or PCBA orders.
---

# Vibe Hardware PCB

Read `../../docs/manufacturing-jlc.md` and `../../docs/safety.md`.

1. Keep the module prototype working while translating it into a schematic.
2. Verify every symbol-to-footprint mapping against the exact manufacturer datasheet.
3. Check power budget, regulator headroom, decoupling, protection, connector polarity, programming access, test points, mounting holes, and antenna keep-outs.
4. Run ERC/DRC, then inspect Gerber and drill output independently of the editor view.
5. For assembly, export Gerber, BOM, and CPL; match every populated row to an in-stock exact part or approved substitute.
6. Inspect IC pin 1, diode/LED polarity, connector direction, rotation, side, and DNP parts in the placement preview.
7. Stop at a populated quote page unless the user explicitly asks to place and pay for an order.

Report digital checks separately from manufactured-board and powered-hardware acceptance.
