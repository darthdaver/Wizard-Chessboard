/*
 * BishopsManager class implementation
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
BishopsManager::BishopsManager(): Manager(){
  bishops[WHITE_BISHOP][0] = Bishop("C1");
  bishops[WHITE_BISHOP][1] = Bishop("F1");
  bishops[BLACK_BISHOP][0] = Bishop("C8");
  bishops[BLACK_BISHOP][1] = Bishop("F8");
};

// checkCandidates implementation
char * BishopsManager::checkCandidates(const char * from, const char * destination){
  QueueArray <int> stack;
  stack.push(0);

  return stack;
};

virtual bool checkPathIsFree(const char * from, const char * destination){
};