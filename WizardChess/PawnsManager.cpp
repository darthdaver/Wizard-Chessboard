/*
 * PawnsManager class implementation
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

#include "Manager.h"
#include "Managers.h"
#include "Pieces.h"
#include "Config.h"

// Constructor
PawnsManager::PawnsManager(): Manager() {
  
  pawns[WHITE_PAWN][0] = Pawn::Pawn("A2");
  pawns[WHITE_PAWN][1] = Pawn::Pawn("B2");
  pawns[WHITE_PAWN][2] = Pawn::Pawn("C2");
  pawns[WHITE_PAWN][3] = Pawn::Pawn("D2");
  pawns[WHITE_PAWN][4] = Pawn::Pawn("E2");
  pawns[WHITE_PAWN][5] = Pawn::Pawn("F2");
  pawns[WHITE_PAWN][6] = Pawn::Pawn("G2");
  pawns[WHITE_PAWN][7] = Pawn::Pawn("H2");
  pawns[BLACK_PAWN][0] = Pawn::Pawn("A7");
  pawns[BLACK_PAWN][1] = Pawn::Pawn("B7");
  pawns[BLACK_PAWN][2] = Pawn::Pawn("C7");
  pawns[BLACK_PAWN][3] = Pawn::Pawn("D7");
  pawns[BLACK_PAWN][4] = Pawn::Pawn("E7");
  pawns[BLACK_PAWN][5] = Pawn::Pawn("F7");
  pawns[BLACK_PAWN][6] = Pawn::Pawn("G7");
  pawns[BLACK_PAWN][7] = Pawn::Pawn("H7");
};

// checkCandidates implementation
StackList <int> PawnsManager::checkCandidates(const char * from, const char * destination){

  StackList <int> stack;
  stack.push(0);

  return stack;
};
