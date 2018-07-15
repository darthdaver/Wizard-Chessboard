/*
 * KingsManager class implementation
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
KingsManager::KingsManager(): Manager() {
  kings[WHITE_KING][0] = King::King("E1");
  kings[BLACK_KING][0] = King::King("E8");
};

// checkCandidates implementation
char * KingsManager::checkCandidates(const char * from, const char * destination){
  QueueArray <int> stack;
  stack.push(0);

  return stack;
};

virtual bool checkPathIsFree(bool * cbState, const char * from, const char * destination){
};