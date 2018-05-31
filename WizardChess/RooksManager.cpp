/*
 * RooksManager class implementation
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
RooksManager::RooksManager(): Manager() {
  rooks[WHITE_ROOK][0] = Rook::Rook("A1");
  rooks[WHITE_ROOK][1] = Rook::Rook("H1");
  rooks[BLACK_ROOK][0] = Rook::Rook("A8");
  rooks[BLACK_ROOK][1] = Rook::Rook("H8");
};

// checkCandidates implementation
StackList <int> RooksManager::checkCandidates(const char * from, const char * destination){

  StackList <int> stack;
  stack.push(0);

  return stack;
};
