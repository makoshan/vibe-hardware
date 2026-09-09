---
name: vibe-hardware
description: Guide beginners from a hardware idea to a reproducible prototype using development boards, modules, BOMs, PCB/PCBA, enclosures, and manufacturing. Use when selecting boards or modules, creating a hardware starter kit or BOM, adapting an open-source device, preparing JLCPCB/JLC3DP orders, or defining physical validation gates.
---

# Vibe Hardware

Treat the repository `docs/` folder as the detailed reference. Keep this skill focused on decisions and verification.

## Route the request

- Board or starter-kit selection: read `../../docs/boards.md`, `../../docs/starter-kit.md`, and `../../docs/buying.md`.
- Wiring or first prototype: read `../../docs/wiring.md`, `../../docs/safety.md`, and `../../docs/learning-path.md`.
- PCB, PCBA, parts, or 3D printing: read `../../docs/manufacturing-jlc.md`.
- Open Duck Mini: read `../../docs/cases/open-duck-mini.md`.
- General tool choices: read `../../docs/tools.md` and `../../docs/resources.md`.

## Work in physical gates

1. Restate one input, one decision, and one output.
2. Reuse a mature open-source design before creating a new PCB or enclosure.
3. Verify the exact board revision, module voltage, interface, pinout, dimensions, and power path.
4. Prove the smallest chain on USB power with an official example.
5. Add only one peripheral or risk at a time.
6. Separate generated/compiled/exported artifacts from real-device acceptance.
7. Before fabrication, review Gerber, drill, BOM, CPL, STEP/STL, quantities, materials, and tolerances.
8. Record what was actually flashed, wired, printed, assembled, measured, and still unverified.

## BOM rules

For every purchasable item include: exact name, manufacturer/model, variant, quantity, electrical/mechanical role, source link, observation date, substitute rule, and verification status. Treat prices and marketplace links as snapshots, never durable facts.

## Safety boundaries

- Do not guess battery wiring, mains wiring, motor current, GPIO voltage, or connector polarity.
- Do not power motors or speakers directly from a GPIO.
- Require a physical disconnect for moving mechanisms.
- Ask for datasheets, board photos, measurements, or a schematic when missing details could damage hardware.

## Output

Give the shortest usable checklist plus links to the relevant Wiki pages. State the next physical gate and name any unverified assumption.
