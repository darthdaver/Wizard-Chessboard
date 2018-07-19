/*
 * Manager abstract class implementation.
 *
 * Copyright (c) 2018 Davide Molinelli.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the   hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Manager.h"

Manager::Manager(){};

bool Manager::checkSource(Cell * cbState[][8], bool turn, const char * from, char type){
    // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
    int row = from[0] - 65;
    // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
    int col = from[1] - 49;
    if(cbState[row][col]->getBusy()){
      if((turn && cbState[row][col]->getColor() == 'B' || !turn && cbState[row][col]->getColor() == 'W') && 
            cbState[row][col]->getPiece() == type){
        return true;
      }
    }
    return false;
}
