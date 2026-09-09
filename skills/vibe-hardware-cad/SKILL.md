---
name: vibe-hardware-cad
description: Create or review hardware enclosures, brackets, and printable mechanical parts from real board and component measurements. Use for CAD, STEP/STL, enclosure design, 3D printing, fit checks, tolerances, fasteners, or JLC3DP preparation.
---

# Vibe Hardware CAD

Read `../../docs/manufacturing-jlc.md` and the relevant case page before changing geometry.

1. Collect exact board revision, connector envelopes, keep-outs, fasteners, cable bend space, and measured dimensions.
2. Prefer editable STEP-first parametric geometry; export STL only for printing.
3. Keep calibration parameters for printer clearance, hole compensation, wall thickness, and press fits.
4. Validate units, closed solids, wall thickness, orientation, supports, left/right parts, and quantities.
5. Produce a model preview plus STEP/STL and a short measurement table.
6. Treat render/export success as a digital gate; require a physical fit test before claiming acceptance.

For JLC3DP, follow `../../docs/manufacturing-jlc.md#d-嘉立创-3d-打印`. Never upload or order until material, finish, quantity, dimensions, and review status are checked.
