/*
 * Configuration header.
 *
 * Copyright (c) 2018 Davide Molinelli.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_H
#define CONFIG_H

// NEMA 17 pins
#define EN 8 // stepper motor enable , active low
#define X_DIR 5 // X -axis stepper motor direction control
#define Y_DIR 6 // y -axis stepper motor direction control
#define X_STP 2 // x -axis stepper control
#define Y_STP 3 // y -axis stepper control

// Relay pin to control the switching on and off of the electromagnet
#define POWER_MAGNET 7
// Relay pin to control the switching on and off of the CNC shield V3
#define POWER_CNC 9

// Bluetooth pins
#define BT_RX 10
#define BT_TX 11

// White chessboard
#define WHITE 0

// Black chessboard
#define BLACK 1

// Number of steps to cross a cell and go to the next
#define STEPS 130

#endif
