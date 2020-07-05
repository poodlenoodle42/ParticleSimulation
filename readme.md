# What is Particle Simulation?

Particle Simulation is just an other Particle Simulation. I try to make it as efficient as I can, so one can run it with millions of particles on a Raspberry Pi. 

# What do diffrent commits and branches represent?

## drawingMethods

In the branch **drawingMethods** you will find multiple commits where you can explore the diffrent drawing Methods I tested.

## render_sfmlImage

This is the default branch. His name represents the drawing method I choose for continuing. The tag **v1.0** points to the first complete commit. Particle are not affecting each other so it is very fast. From there on I tried to get all particles affecting each other with decent performance.

# Whats planned, whats done?

- [x] Working Drawing
- [x] Particle Simulation
- [x] Color
- [x] Move Simulation in extra thread
- [ ] Particles affecting each other
- [ ] GPU acceleration (OpenCL or OpenGL Compute Shader)

# Build
To build it you must install SFML2.5 for your system.
Use QtCreator or the default QMake Build Steps for your System.
For Linux it is 
`bash
qmake ParticleSimulation.pro -spec linux-g++`

`bash make -j4`

and at the end 
`bash make clean -j4`
to clean your build enviroment.



