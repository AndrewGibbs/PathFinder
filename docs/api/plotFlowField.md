# plotFlowField

**Description:** Computes pressure gradient in a pipe flow.

**Inputs:**
- `velocity`: mean fluid velocity [m/s]
- `viscosity`: dynamic viscosity [Pa·s]
- `length`: pipe length [m]

**Output:**
- `dpdx`: pressure gradient [Pa/m]

**Example:**
```matlab
dpdx = computePressureGradient(0.2, 0.001, 5);
