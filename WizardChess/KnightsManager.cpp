/*
 * KnightsManager class implementation
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
KnightsManager::KnightsManager(): Manager() {
  knights[WHITE_KNIGHT][0] = Knight("B1");
  knights[WHITE_KNIGHT][1] = Knight("G1");
  knights[BLACK_KNIGHT][0] = Knight("B8");
  knights[BLACK_KNIGHT][1] = Knight("G8");
};

// checkCandidates implementation
char * KnightsManager::checkCandidates(bool cbState[][8], bool turn,bool cbState[][8], const char* from, const char* destination){
  
};

virtual bool checkPathIsFree(bool cbState[][8], bool * cbState, const char * from, const char * destination){
};
