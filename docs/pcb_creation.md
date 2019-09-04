# PCB Design Guide

A small guide outlining how to design simple PCB's for use by the for the Oxford Brookes Racing Formula Student team. Recommendations are based on experience from the open-sassy project development. While this is a good starting point for PCB development, this is by no means a definitive guide and content in this guide could be wrong. Use at your own risk.

<center>
<img src=img/optical_sensor_daughter_boad.png width=200px>
</center>

- [Requirements](#requirements)
- [Software Setup](#software-setup)
  - [KiCAD](#kicad)
  - [freeRouter](#freerouter)
- [Design Objectives](#design-objectives)
  - [Outline Functionality of Circuit](#outline-functionality-of-circuit)
- [Psudo Scheming](#psudo-scheming)
- [Schematics](#schematics)
- [PCB Design](#pcb-design)
- [Manufacture](#manufacture)

## Requirements

The following types of software packages are required. There are other alternatives to the ones listed that function similarly, but open source options were selected to align with the project goals.

- Schematic Design
- SPICE Simulation
- PCB Layout
- Autorouting Tool
- Plotting

KiCAD is a suite of PCB design tools that has facilities for schematic design, spice simulation, PCB layout and plotting capabilities. There is manual routing capabilities in the PCB tool, but supplementing with an autorouting tool is **HIGHLY** recommended as learning how to manually route takes a lot of time and practice and requires some amount of guidance to learn. FreeRouter is a standalone routing tool that can accept exports from PcbNew, routed in freeRouter, and exported back to PcbNew.

## Software Setup

### KiCAD

For Debian based distributions such as Ubuntu, KiCAD can be installed via the system package manager

```bash
sudo apt-get install kicad
```

For other OS's and distro's please consult KiCAD's website: [kicad-pcb.org](http://www.kicad-pcb.org/)

### freeRouter

The easiest way to get freeRouter is to download [LayoutEditor](https://layouteditor.com) and extract the `freeRouter.jar` file from the `bin/` folder of the package. To run the standalone jar file just run:

```bash
java -jar freeRouter.jar
```

and free router will start.

## Design Objectives

### Outline Functionality of Circuit

## Psudo Scheming

## Schematics

## PCB Design

## Manufacture
