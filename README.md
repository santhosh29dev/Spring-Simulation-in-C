# Mass–Spring Simulation (Raylib)

This is a small **2D physics simulation** written in **C** using the **Raylib** graphics library.
It demonstrates how a mass attached to a spring moves back and forth when displaced from its resting position.

The simulation visualizes a **block connected to a spring fixed to a wall**. When the system starts, the block oscillates horizontally, gradually slowing down because of damping (friction). The behavior follows the principles of **Hooke’s Law** and basic **damped harmonic motion**.

This project is mainly intended as a **learning experiment** for understanding physics simulation, numerical integration, and simple rendering with Raylib.

---

## Features

* Real-time **mass–spring physics simulation**
* A **visual spring** made of connected line segments
* Simulation of **damped harmonic motion**
* Adjustable physics parameters in the code
* Built using the lightweight **Raylib** graphics library
* Smooth rendering at **120 FPS**

---

## Physics Behind the Simulation

The motion of the mass follows the equation:

**F = -k(x − x₀) − cv**

Where:

* **k** – spring stiffness (spring constant)
* **x** – current position of the mass
* **x₀** – spring’s rest position
* **v** – velocity of the mass
* **c** – damping coefficient (simulates friction)

In simple terms:

* The spring **pulls the mass back toward its rest position**.
* The damping term **reduces the motion over time**, causing the oscillations to slowly stop.

Each frame of the simulation:

1. The force acting on the mass is calculated.
2. Acceleration is derived from that force.
3. Velocity and position are updated using the frame’s time step.

---

## Parameters Used

| Parameter           | Value     | Description                                |
| ------------------- | --------- | ------------------------------------------ |
| FPS                 | 120       | Target frame rate                          |
| Window Size         | 900 × 600 | Size of the application window             |
| Spring Constant (K) | 20        | Controls how stiff the spring is           |
| Friction            | 0.5       | Damping factor                             |
| Spring Elements     | 15        | Number of segments used to draw the spring |
| Spring Length       | 70        | Length of each spring segment              |

These values can easily be modified in the source code to experiment with different behaviors.

---

## Project Structure

```
project/
│
├── main.c        # Source code for the simulation
└── README.md     # Project documentation
```

---

## Dependencies

To run this project you will need:

* **Raylib**
* A **C compiler** (GCC or Clang)

You can download Raylib from:

https://www.raylib.com/

---

## Build Instructions

### Linux / Mac

```bash
gcc main.c -o spring_sim -lraylib -lm
./spring_sim
```

### Windows (MinGW)

```bash
gcc main.c -o spring_sim.exe -lraylib -lopengl32 -lgdi32 -lwinmm -lm
spring_sim.exe
```

---

## What the Simulation Shows

When you run the program you’ll see:

* A **yellow square** representing the mass
* A **zig-zag spring** attached to it
* A **horizontal floor line** for reference
* The mass **oscillating back and forth**, slowly losing energy due to damping

---

## Concepts Demonstrated

This small project touches on several important ideas:

* Harmonic motion
* Hooke’s Law
* Damped oscillations
* Basic numerical integration
* Real-time physics simulation
* Simple graphics rendering with Raylib

---

## Ideas for Future Improvements

Some ideas if you want to expand the project:

* Allow the user to **drag the mass with the mouse**
* Add **controls to adjust spring stiffness and damping**
* Display **kinetic and potential energy**
* Add **multiple masses and springs**
* Plot a **real-time displacement graph**

---

## License

This project is open for **learning and experimentation**.
Feel free to modify, improve, and use it for educational purposes.
